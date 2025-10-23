#include "base64.h"
#include <stdlib.h>
#include <string.h>

void null_pointer_check(FILE* a, FILE* b){
    if (!a || !b){
        fprintf(stderr, "Unable to open/create specified file, check your path and try again.\n");
        exit(1);
    }
}

int main(int argc, char* argv[]) {

    if (argc != 4){
        fprintf(stderr, "Usage: %s <encode/decode> <input_path_file> <output_path_file>\n", argv[0]);
        exit(1);
    }
    
    const char* path_input = argv[2];
    const char* path_output = argv[3];

    
    FILE *pointer_input, *pointer_output;
    if (!strcmp(argv[1], "encode")){
        
        pointer_input = fopen(path_input, "rb");
        pointer_output = fopen(path_output, "w");
        null_pointer_check(pointer_input, pointer_output);
    
        Base64 base64 = {
            .input = pointer_input,
            .output = pointer_output
        };

        base64_encode(&base64);  
        printf("Generated new base64 encoded file at: %s\n", path_output); 
        printf("Bytes readed: %lld\nBytes writed: %lld\n", base64.size_input_bytes, base64.size_output_bytes); 
    }

    else if(!strcmp(argv[1], "decode")){
        pointer_input = fopen(path_input, "r");
        pointer_output = fopen(path_output, "wb");
        null_pointer_check(pointer_input, pointer_output);
    
        Base64 base64 = {
            .input = pointer_input,
            .output = pointer_output
        };

        base64_decode(&base64);
        printf("Generated new base64 decoded file at: %s\n", path_output); 
        printf("Bytes readed: %lld\nBytes writed: %lld\n", base64.size_input_bytes, base64.size_output_bytes); 
    }
    fclose(pointer_input);
    fclose(pointer_output);
    return 0;
}