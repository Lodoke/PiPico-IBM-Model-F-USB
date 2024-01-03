#ifndef LUT
#define LUT

char *lut;

char layer0[] PROGMEM {
  0x00, //not used
  0x29, //escape
  0x1e, //1
  0x1f, //2
  0x20, //3
  0x21, //4
  0x22, //5
  0x23, //6
  0x24, //7
  0x25, //8
  0x26, //9
  0x27, //0
  0x2d, //-
  0x2e, //+
  0x2a, //backspace
  0x2b, //tab
  0x14, //q
  0x1a, //w
  0x08, //e
  0x15, //r
  0x17, //t
  0x1c, //y
  0x18, //u
  0x0c, //i
  0x12, //o
  0x13, //p
  0x2f, //{
  0x30, //}
  0x28, //enter
  0xe0, //ctrl
  0x04, //a
  0x16, //s
  0x07, //d
  0x09, //f
  0x0a, //g
  0x0b, //h
  0x0d, //j
  0x0e, //k
  0x0f, //l
  0x33, //;:
  0x34, //"`
  0x31, //~' (#~) (Changed to match uk layout)
  0xe1, //lshift
  0x64, //|
  0x1d, //z
  0x1b, //x
  0x06, //c
  0x19, //v
  0x05, //b
  0x11, //n
  0x10, //m
  0x36, //<
  0x37, //>
  0x38, //?
  0xe5, //rshift
  0x46, //printscreen
  0xe2, //lalt
  0x2c, //space
  0x39, //caps lock
  0x3a, //f1
  0x3b, //f2
  0x3c, //f3
  0x3d, //f4
  0x3e, //f5
  0x3f, //f6
  0x40, //f7
  0x41, //f8
  0x42, //f9
  0x43, //f10
  0x53, //numlock
  0x47, //scroll lock
  0x5f, //num 7
  0x60, //num 8
  0x61, //num 9
  0x56, //num -
  0x5c, //num 4
  0x5d, //num 5
  0x5e, //num 6
  0x57, //num +
  0x59, //num 1
  0x5a, //num 2
  0x5b, //num 3
  0x62, //num 0
  0x63, //num del
  0x55, //num *
};

char layer1[] PROGMEM {
  layer0[0], //not used
  layer0[1], //escape
  layer0[2], //1
  layer0[3], //2
  layer0[4], //3
  layer0[5], //4
  layer0[6], //5
  layer0[7], //6
  layer0[8], //7 
  layer0[9], //8 
  layer0[10], //9
  layer0[11], //0
  layer0[12], //-
  layer0[13], //+
  layer0[14], //backspace
  layer0[15], //tab
  layer0[16], //q
  layer0[17], //w
  layer0[18], //e
  layer0[19], //r
  layer0[20], //t
  layer0[21], //y
  layer0[22], //u
  layer0[23], //i
  layer0[24], //o
  layer0[25], //p
  layer0[26], //[
  layer0[27], //]
  layer0[28], //enter
  layer0[29], //ctrl
  layer0[30], //a
  layer0[31], //s
  layer0[32], //d
  layer0[33], //f
  layer0[34], //g
  layer0[35], //h
  layer0[36], //j
  layer0[37], //k
  layer0[38], //l
  layer0[39], //;:
  layer0[40], //'@
  layer0[41], //#~
  layer0[42], //shift
  layer0[43], //|
  layer0[44], //z
  layer0[45], //x
  layer0[46], //c
  layer0[47], //v
  layer0[48], //b
  layer0[49], //n
  layer0[50], //m
  layer0[51], //,
  layer0[52], //.
  layer0[53], //?
  layer0[54], //rshift
  layer0[55], //printscreen
  layer0[56], //lalt
  layer0[57], //space
  layer0[58], //caps lock
  0x44, //f1 - f11
  0x45, //f2 - f12
  0x68, //f3 - f13
  0x69, //f4 - f14
  0x6a, //f5 - f15
  0x6b, //f6 - f16
  0x6c, //f7 - f17
  0x6d, //f8 - f18
  0x6e, //f9 - f19
  0x6f, //f10 - f20
  layer0[69], //numlock
  layer0[70], //scrolllock
  layer0[71], //num 7
  0x80, //num 8 - vol up
  layer0[73], //num 9
  layer0[74], //num -
  layer0[75], //num 4 - prev track
  layer0[76], //num 5 - play/pause
  layer0[77], //num 6 - next track
  layer0[78], //num +
  layer0[79], //num 1
  0x81, //num 2 - vol down
  layer0[81], //num 3
  layer0[82], //num 0
  layer0[83], //num del
  layer0[84]  //num *
};

#endif