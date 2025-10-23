/*
Objetivo: Inverter os 4 bits superiores com os 4 inferiores.
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

unsigned char swapNibbles(unsigned char byte){
    unsigned char upperNibble = (byte >> 4) & 0xF;
    byte = byte << 4;
    return byte | upperNibble;
}

int main(void){
    printBits(0xAB);
    unsigned char result = swapNibbles(0xAB);
    printBits(result);
}