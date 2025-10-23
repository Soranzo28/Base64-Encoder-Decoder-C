/*
Objetivo: Este é o coração do Base64! Pegar 3 bytes (24 bits) e dividir em 4 valores de 6 bits cada.
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

void splitInto6BitGroups(unsigned char byte1, unsigned char byte2, unsigned char byte3, unsigned char output[4]){
    output[0] = byte1 >> 2;
    output[1] = ((byte1 & 0b11) << 4) | (byte2 >> 4);
    output[2] = (byte2 & 0b1111)<< 2| (byte3 >> 6);
    output[3] = byte3 & 0x3f;
}

int main(void){
    unsigned char output[4];
    
    // Teste 1: "Man"
    printf("=== Teste 1: M(77) a(97) n(110) ===\n");
    splitInto6BitGroups(0x4D, 0x61, 0x6E, output);
    printf("Esperado: 19, 22, 5, 46\n");
    printf("Resultado: %d, %d, %d, %d\n\n", output[0], output[1], output[2], output[3]);
    
    // Teste 2: Todos zeros
    printf("=== Teste 2: 0x00 0x00 0x00 ===\n");
    splitInto6BitGroups(0x00, 0x00, 0x00, output);
    printf("Esperado: 0, 0, 0, 0\n");
    printf("Resultado: %d, %d, %d, %d\n\n", output[0], output[1], output[2], output[3]);
    
    // Teste 3: Todos uns
    printf("=== Teste 3: 0xFF 0xFF 0xFF ===\n");
    splitInto6BitGroups(0xFF, 0xFF, 0xFF, output);
    printf("Esperado: 63, 63, 63, 63\n");
    printf("Resultado: %d, %d, %d, %d\n\n", output[0], output[1], output[2], output[3]);
    
    return 0;
}