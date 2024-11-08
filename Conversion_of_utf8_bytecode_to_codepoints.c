//convert from utf-8 into codepoints! 

typedef unsigned codepoint;
const codepoint U8_EOSTR = ~0U;

const codepoint win1252[64] = {
0x20ac,0x81,  0x201A,0x192, 0x201E,0x2026,0x2020,0x2021,
0x2C6, 0x2030,0x160, 0x2039,0x152, 0x8D,  0x17D, 0x8F,
0x90,  0x2018,0x2019,0x201C,0x201D,0x2022,0x2013,0x2014,
0x2DC, 0x2122,0x161, 0x203A,0x153, 0x9D,  0x17E, 0x178,
0xA0,0xA1,0xA2,0xA3,0xA4,0xA5,0xA6,0xA7,0xA8,0xA9,0xAA,0xAB,0xAC,0xAD,0xAE,0xAF,
0xB0,0xB1,0xB2,0xB3,0xB4,0xB5,0xB6,0xB7,0xB8,0xB9,0xBA,0xBB,0xBC,0xBD,0xBE,0xBF
};

enum u8_bycl {
        u8_ascii = 0, // ascii byte
        u8_cont = 1,   // utf-8 continuation byte
        u8_2start = 2, // start of a 2-byte utf-8 codepoint
        u8_3start = 3, // start of a 3-byte utf-8 codepoint
        u8_4start = 4, // start of a 4-byte utf-8 codepoint
        u8_inval = 5 // invalid byte in utf-8
};

char u8_bycl[256] = { // byte classification
        0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, // 020
        0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, // 040
        0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, // 060 ascii
        0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, // 100
        0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, // 120
        0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, // 140
        0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, // 160
        0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, // 200
        1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, // 220 continuation
        1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, // 240
        1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, // 260
        1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, // 300
        2,2,2,2, 2,2,2,2, 2,2,2,2, 2,2,2,2, // 320 2 byte start
        2,2,2,2, 2,2,2,2, 2,2,2,2, 2,2,2,2, // 340
        3,3,3,3, 3,3,3,3, 3,3,3,3, 3,3,3,3, // 360 3 byte start
        4,4,4,4, 4,4,4,4, 5,5,5,5, 5,5,5,5, // 400 4 byte start
};

/* parameters:
s : (read only) char string containing utf 8 data
i : (read+write) pointer to byte index variable to begin reading at within the string. byte index variable will be updated to the beginning of the next utf-8 code
n : (read only) length of the string data in bytes.
*/
codepoint u8s_getch(const char *s_, size_t *i_, size_t n){
        const unsigned char*s = s_;
        if(!s||!i_||*i_>=n)return U8_EOSTR;
        size_t i = *i_;
        int c4,c3,c2,c=s[i];
        char bc = u8_bycl[c&0xFF];
        switch(bc){
                case u8_inval:
                case u8_ascii: *i_=i+1; return c;
                case u8_cont: *i_=i+1; return win1252[c-0x80]; // handle incorrect bytes as if Latin-1
                case u8_2start: goto _2s;
                case u8_3start: goto _3s;
                case u8_4start: goto _4s;
        }
        _2s: if(i+1>=n)goto fail;
        c2=s[i+1];
        if(c2<0200||c2>=0300)goto fail;
        *i_=i+2;
        return ((c&037)<<6)|(c2&077);
        _3s: if(i+2>=n)goto fail;
        c2=s[i+1];
        c3=s[i+2];
        if(c2<0200||c2>=0300)goto fail;
        if(c3<0200||c3>=0300)goto fail;
        *i_=i+3;
        return (c&017)<<12|(c2&077)<<6|(c3&077);
        _4s: if(i+3>=n)goto fail;
        c2=s[i+1];
        c3=s[i+2];
        c4=s[i+3];
        if(c2<0200||c2>=0300)goto fail;
        if(c3<0200||c3>=0300)goto fail;
        if(c4<0200||c4>=0300)goto fail;
        *i_=i+4;
        return (c&007)<<18|(c2&077)<<12|(c3&077)<<6|(c4&077);
        fail:*i_=i;
        return c;
}

//The u8s_getch function demonstrates a basic algorithm for reading utf 8 data one code point at a time.
//does this help much? 


//Oren Watson (he/him)
//orenwatson at tutanota.com

