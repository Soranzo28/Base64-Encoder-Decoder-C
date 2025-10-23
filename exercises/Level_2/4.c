/*
Objetivo: Contar quantos bits estão setados para 1.
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

int countSetBits(unsigned char byte){
    int counter = 0;
    for (int i = 0; i < 8; i ++){
        if ((byte >> i) & 1) counter++;
    }
    return counter;
}

int main(void){
    printBits(0xFF);
    int count = countSetBits(0xFF);
    printf("%d\n", count);
}