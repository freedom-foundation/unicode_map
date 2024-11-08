//some simple C sourcecode that converts a unicode codepoint to a string in utf-8.


    const char *u8ch_tostr(unsigned ch){
            static unsigned char buf[5]; // every utf-8 character is <=4 bytes
            buf[4]=0;
            if(ch<0200){ // ascii is a subset of utf-8
                    buf[3]=ch;
                    return buf+3;
            }
            if(ch<04000){ // characters under 0x7ff are 2 bytes
                    buf[3]=(ch&077) + 0200;
                    buf[2]=(ch/0100) + 0300;
                    return buf+2;
            }
            if(ch<0200000){ // characters >= 0xFFFF are 3 bytes
                    buf[3]=(ch&077) + 0200;
                    buf[2]=(ch/0100&077) + 0200;
                    buf[1]=(ch/010000) + 0340;
                    return buf+1;
            }
            buf[3]=(ch&077) + 0200; // all other characters are 4 bytes
            buf[2]=(ch/0100&077) + 0200;
            buf[1]=(ch/010000&077) + 0200;
            buf[0]=(ch/01000000) + 0360;
            return buf;
    }
    ---
    //Oren Watson (he/him)
    //orenwatson@tutanota.com
