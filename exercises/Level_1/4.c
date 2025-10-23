/*
Objetivo: Inverter (toggle) o bit na posição n (0→1 ou 1→0).
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

unsigned char toggleBit(unsigned char byte, int n) {
    return byte ^ (1 << n);
}

int main(void) {
    printBits(15);
    unsigned char result = toggleBit(15, 2);
    printBits(result);
}