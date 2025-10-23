#ifndef BASE64_LIB
#define BASE64_LIB

#include <stdio.h>

extern const char* alphabet;
typedef struct {
    FILE* input;
    FILE* output;
    unsigned long long int size_input_bytes;
    unsigned long long int size_output_bytes;
} Base64;

void base64_encode(Base64 *base64);
void base64_decode(Base64 *base64);

#endif