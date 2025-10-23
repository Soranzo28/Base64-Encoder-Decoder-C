/*
Objetivo: Pegar os 4 bits mais à direita de um byte.
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

unsigned char getLowNibble(unsigned char byte){
    return byte & 0xF;
}

int main(void){
    printBits(0xAB);
    unsigned char result = getLowNibble(0xAB);
    printBits(result);
}