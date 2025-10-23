/*
Objetivo: Pegar apenas os bits 0-1 (os 2 bits mais à direita).
*/

#include <stdio.h>

//HELPER FUNC
void printBits(unsigned char byte){
    printf("Binário: ");
    for(int i = 7; i >= 0; i--) {
        printf("%d", (byte >> i) & 1);
    }
    printf("\n");
}

unsigned char getLower2Bits(unsigned char byte){
    return byte & 0b11;
}

int main(void){
    printBits(0xFF);
    char result = getLower2Bits(0xFF);
    printBits(result);
}