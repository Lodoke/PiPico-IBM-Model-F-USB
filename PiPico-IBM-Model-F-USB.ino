#include "PluggableUSBHID.h"
#include "USBKeyboard.h"
#include "keymaps.h"

#define CLK 27
#define DAT 28
#define ROLLOVER 6
//#define _DEBUG


#ifdef _DEBUG
char str_buf[32]{ 0 };
#endif

static char bit_count;
static char data_buffer;
static char has_read_bit;
static char target;
static char modifiers;
char active_keys[ROLLOVER]{ 0 };
char sent_active_keys[ROLLOVER] {0};
HID_REPORT report_buffer;
USBKeyboard kb;

static uint last_print = 0;

int search_array(char* value, char array[], int length) {
  for (int i = 0; i < length; i++) {
    if (array[i] == *value) {
      return i;
    }
  }
  return -1;
}

/* The function called on the clock line falling edge interrupt - Reads the data
*  Received from the keyboards serial interface */
void clock_low() {
  //read the data regardless of if it has already been done to ensure it is not missed
  register char data = digitalRead(DAT);
  if (!has_read_bit) {
    //shift data into buffer and increment counters
    if (bit_count > 1) data_buffer |= data << bit_count - 2;
    has_read_bit = 1;
    bit_count++;
  }
  return;
}

void usb_send() {
  //disable the keyboard output & disable input interrupts
  pinMode(CLK, OUTPUT);
  digitalWrite(CLK, HIGH); //forcing the clock high is the same as not providing a CTS to the keyboard
  noInterrupts();

  //write data into the report and send over usb
  report_buffer.data[0] = 1;
  report_buffer.data[1] = modifiers;
  report_buffer.data[2] = 0;
  for (int i = 3; i < ROLLOVER + 3; i++) {
    report_buffer.data[i] = lut[active_keys[i - 3]];
  }
  report_buffer.length = ROLLOVER + 3;

  //using the blocking variety to ensure tx is complete before re-enabling interrupts
  kb.send(&report_buffer);

  interrupts();
  pinMode(CLK, INPUT);

  return;
}


void setup() {

  #ifdef _DEBUG
  Serial.begin(9600);
  #endif

  //some knock-off model f's use 9 bits instead of 10, apparently this is how
  //to differentiate them.
  target = (digitalRead(DAT) == LOW) ? 10 : 9;
  bit_count = 0;
  has_read_bit = 0;
  modifiers = 0;
  lut = layer0;

  pinMode(DAT, INPUT);
  pinMode(CLK, INPUT);

  //blocks until ready, just here for safety
  kb.wait_ready();

  //interrupt on clock falling edge to capture the keyboard data
  attachInterrupt(digitalPinToInterrupt(CLK), clock_low, FALLING);
  interrupts();
}

void loop() {

  //prevents it re reading the pin constantly when it already knows it has gone high
  if (has_read_bit == 1 && digitalRead(CLK) == HIGH) has_read_bit = 0;

  if (bit_count == target) {

    #ifdef _DEBUG
    sprintf(str_buf, "key=0x%x - mods=0x%x", data_buffer, modifiers);
    Serial.println(str_buf);
    #endif

    switch (data_buffer) {
      case 0x2a:
        /* Shift Key Press*/
        modifiers |= KEY_SHIFT;
        break;

      case 0xaa:
        /* Shift Key Release */
        modifiers &= ~KEY_SHIFT;
        break;

      case 0x38:
        /* Alt Key Press */
        modifiers |= KEY_ALT;
        break;

      case 0xb8:
        /* Alt Key Release */
        modifiers &= ~KEY_ALT;
        break;

      case 0x1d:
        /* Control Key Press */
        modifiers |= KEY_CTRL;
        break;

      case 0x9d:
        /* Control Key Release */
        modifiers &= ~KEY_CTRL;
        break;

      case 0x36:
        /* Right Shift Press */
        modifiers |= KEY_SHIFT;
        break;

      case 0xb6:
        /* Right Shift Release */
        modifiers &= ~KEY_SHIFT;
        break;

      case 0x46:
        /* Scroll Lock Press */
        lut = layer1;
        data_buffer = 0;
        break;

      case 0xc6:
        /* Scroll Lock Release */
        lut = layer0;
        data_buffer = 0;
        break;

      case 0x37:
        /* Print Screen Asterisk Press */
        if (kb.lock_status() & 1) data_buffer = 0x54;
        break;

      case 0xb7:
        /* Print Screen Asterisk Release */
        if (kb.lock_status() & 1) data_buffer = 0xd4;
        break;
    }

    if (data_buffer < 0x80 && data_buffer != 0 && search_array(&data_buffer, active_keys, ROLLOVER) == -1) {
      //if not already active && is a press code
      active_keys[strlen(active_keys)] = data_buffer;  //strlen effectively provides the first available slot in the array
    } 
    else if (data_buffer >= 0x80) {
      char temp = data_buffer - 0x80;
      register char index = search_array(&temp, active_keys, ROLLOVER);
      if (index != -1) {
      active_keys[index] = 0;
      }
    }
    bit_count = 0;
    data_buffer = 0;
  }

  if (memcmp(active_keys, sent_active_keys, ROLLOVER) != 0) {
    //if the actie keys have changed then send the new keys to the host & update sentkeys
    usb_send();
    memcpy(sent_active_keys, active_keys, ROLLOVER);
  }

}
