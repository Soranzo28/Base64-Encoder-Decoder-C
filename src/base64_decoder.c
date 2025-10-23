#include "base64.h"
#include <string.h>

int base64_char_to_value(char c) {
    if (c >= 'A' && c <= 'Z') return c - 'A';           // 0-25
    if (c >= 'a' && c <= 'z') return c - 'a' + 26;      // 26-51
    if (c >= '0' && c <= '9') return c - '0' + 52;      // 52-61
    if (c == '+') return 62;
    if (c == '/') return 63;
    if (c == '=') return 0;  // padding
    return -1;  // caractere inválido
}

void base64_decode(Base64 *base64){
    unsigned char input[4] = {0};
    unsigned char output[3] = {0};
    unsigned char treated_input[5] = {0};

    int readed_bytes = 0;
    while((readed_bytes = fread(input, 1, 4, base64->input)) > 0) {

        base64->size_input_bytes+=readed_bytes;

        for (int i = 0; i < 4; i ++){
            treated_input[i] = base64_char_to_value(input[i]);
        }

        output[0] = (treated_input[0] << 2) | ((treated_input[1] >> 4) & 0b11);
        output[1] = ((treated_input[1] & 0b1111) << 4) | ((treated_input[2] >> 2) & 0b1111);
        output[2] = ((treated_input[2] & 0b11) << 6) | treated_input[3];
        int valid_bytes = 3;
        base64->size_output_bytes+= valid_bytes;
        if (input[3] == '=') valid_bytes--;
        if (input[2] == '=') valid_bytes--;
        fwrite(output, 1, valid_bytes, base64->output);
        memset(input, 0, 4);
        memset(treated_input, 0, 4);
    }
}
