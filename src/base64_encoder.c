
#include "base64.h"
#include <string.h>

const char* alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

void base64_encode(Base64* base64){
    unsigned char input_bytes [4]  = {0};
    unsigned char output_bytes[4]       ;
    unsigned char output_chars[5]  = {0};
    int           readed_bytes          ;

    while((readed_bytes = fread(input_bytes, 1, 3, base64->input)) > 0){

        base64->size_input_bytes += readed_bytes;

        output_bytes[0] =   input_bytes[0]           >> 2;
        output_bytes[1] = ((input_bytes[0] & 0b11)   << 4) | (input_bytes[1] >> 4);
        output_bytes[2] =  (input_bytes[1] & 0b1111) << 2  | (input_bytes[2] >> 6);
        output_bytes[3] =   input_bytes[2] & 0x3f;

        output_chars[0] = alphabet[output_bytes[0]];
        output_chars[1] = alphabet[output_bytes[1]];

        switch(readed_bytes){
            case 3:
                output_chars[2] = alphabet[output_bytes[2]];
                output_chars[3] = alphabet[output_bytes[3]];
                break;
            case 2:
                output_chars[2] = alphabet[output_bytes[2]];
                output_chars[3] = '=';
                break;
                case 1:
                output_chars[2] = '=';
                output_chars[3] = '=';
                break;
        }
        
        fwrite(output_chars, 1, 4, base64->output);
        memset(input_bytes, 0, 4);
    }

    base64->size_output_bytes = ((base64->size_input_bytes + 2) / 3) * 4;
}
