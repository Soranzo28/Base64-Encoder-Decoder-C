/*
Objetivo: Setar o bit na posição n para 0 (sem alterar os outros bits).
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

unsigned char unsetNBit(unsigned char byte, size_t n) { 
    unsigned mask = 0xFF;
    mask = mask ^ (1<<n);
    return byte & mask;
}

int main() {
    printBits(10);
    unsigned char volta = unsetNBit(10, 3);
    printBits(volta);
    return 0;
}