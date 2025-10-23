/*
Objetivo: Setar o bit na posição n para 1 (sem alterar os outros bits).
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

unsigned char setNBit(unsigned char byte, size_t n) { 
    return byte | (1 << n);
}

int main() {
    printBits(10);
    unsigned char volta = setNBit(10, 4);
    printBits(volta);
    return 0;
}