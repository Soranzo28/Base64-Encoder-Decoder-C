/*
Objetivo: Pegar os 4 bits mais à esquerda de um byte.
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

unsigned char getHighNibble(unsigned char byte){
    return (byte>>4) & 0xF;
}

int main(void){
    printBits(0xAB);
    char result = getHighNibble(0xAB);
    printBits(result);
}
