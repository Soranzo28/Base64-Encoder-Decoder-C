/*
Ex 1.1: Ler bit na posição N
Objetivo: Retornar o valor (0 ou 1) do bit na posição n.

readNBit(10, 0) → deve retornar 0
readNBit(10, 1) → deve retornar 1
readNBit(10, 3) → deve retornar 1
readNBit(15, 2) → deve retornar 1
readNBit(0, 5) → deve retornar 0

*/

#include <stdio.h>
#include <stdbool.h>

bool readNBit(unsigned char target, size_t n){
    bool bit;
    bit = (target >> n) & 1;
    printf("%d\n", bit);
    return bit;
}

int main(void){
    readNBit(10, 0);
    readNBit(10, 1);
    readNBit(10, 3);
    readNBit(15, 2);
    readNBit(0, 5);
}