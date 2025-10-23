/*
Objetivo: Pegar 2 bits inferiores do primeiro byte e 4 bits superiores do segundo, formando 6 bits.
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

unsigned char combine2And4Bits(unsigned char byte1, unsigned char byte2){
    char lower2 = byte1 & 0b11;
    char upper4 = (byte2 >> 4) & 0b1111;
    return (lower2 << 4) | upper4;
}


int main(void){
    printBits(0x61);
    printBits(0x6E);
    unsigned char result = combine2And4Bits(0x61, 0x6E);
    printBits(result);
    printf("Total: %d\n", result);
}

//010110