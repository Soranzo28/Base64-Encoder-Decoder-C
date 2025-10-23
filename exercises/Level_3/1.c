/*
Objetivo: Pegar os bits 2-7 (os 6 bits mais à esquerda).
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

unsigned char getUpper6Bits(unsigned char byte){
    return (byte >> 2) & 0x3f;
}

int main(void){
    printBits(0b10101010);
    char result = getUpper6Bits(0b10101010);
    printBits(result);
}