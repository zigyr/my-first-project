#include <STC89C5xRC.H>
#define SMG_EN P36

typedef unsigned char u8;

// 数字0-9的编码
static u8 codes[10] = {
    0x3F, // 0
    0x06, // 1
    0x5B, // 2
    0x4F, // 3
    0x66, // 4
    0x6D, // 5
    0x7D, // 6
    0x07, // 7
    0x7F, // 8
    0x6F, // 9
}



void DigitalTube_DisplaySingle(u8 position, u8 num_code){
    // 位选
     P1 = (P1 & 0xC7) | (position << 3);

     // 段选
     P0 = num_code;
}

void main (){
    SMG_EN = 0;
    DigitalTube_DisplaySingle(0, codes[2]);
    while(1);
}