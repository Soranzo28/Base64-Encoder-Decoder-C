# Exercícios de Bitwise - Do Básico ao Base64

## 📌 Como usar este guia
1. Faça os exercícios **em ordem**
2. Tente sozinho por 15-20 minutos antes de buscar ajuda
3. Desenhe os bits no papel
4. Teste com os exemplos fornecidos
5. Quando dominar um nível, vá para o próximo

---

## 🎯 Nível 1: Entendendo Bits Individuais

### Ex 1.1: Ler bit na posição N
**Objetivo:** Retornar o valor (0 ou 1) do bit na posição `n`.

```c
int getBit(unsigned char byte, int n);
```

**Exemplos:**
```
getBit(10, 0) → 0   // 10 = 00001010, bit 0 (direita) = 0
getBit(10, 1) → 1   // bit 1 = 1
getBit(10, 3) → 1   // bit 3 = 1
getBit(15, 2) → 1   // 15 = 00001111, bit 2 = 1
getBit(8, 3) → 1    // 8 = 00001000, bit 3 = 1
```

---

### Ex 1.2: Ligar bit na posição N
**Objetivo:** Setar o bit na posição `n` para 1 (sem alterar os outros bits).

```c
unsigned char setBit(unsigned char byte, int n);
```

**Exemplos:**
```
setBit(10, 0) → 11   // 00001010 → 00001011
setBit(10, 2) → 14   // 00001010 → 00001110
setBit(0, 5) → 32    // 00000000 → 00100000
setBit(15, 0) → 15   // 00001111 → 00001111 (já estava ligado)
```

---

### Ex 1.3: Desligar bit na posição N
**Objetivo:** Setar o bit na posição `n` para 0 (sem alterar os outros bits).

```c
unsigned char clearBit(unsigned char byte, int n);
```

**Exemplos:**
```
clearBit(11, 0) → 10   // 00001011 → 00001010
clearBit(15, 2) → 11   // 00001111 → 00001011
clearBit(255, 7) → 127 // 11111111 → 01111111
clearBit(10, 0) → 10   // 00001010 → 00001010 (já estava desligado)
```

---

### Ex 1.4: Inverter bit na posição N
**Objetivo:** Inverter (toggle) o bit na posição `n` (0→1 ou 1→0).

```c
unsigned char toggleBit(unsigned char byte, int n);
```

**Exemplos:**
```
toggleBit(10, 0) → 11   // 00001010 → 00001011
toggleBit(11, 0) → 10   // 00001011 → 00001010
toggleBit(15, 4) → 31   // 00001111 → 00011111
toggleBit(0, 3) → 8     // 00000000 → 00001000
```

---

## 🎯 Nível 2: Trabalhando com Grupos de Bits

### Ex 2.1: Extrair 4 bits inferiores (nibble baixo)
**Objetivo:** Pegar os 4 bits mais à direita de um byte.

```c
unsigned char getLowNibble(unsigned char byte);
```

**Exemplos:**
```
getLowNibble(0xAB) → 0x0B  // 10101011 → 00001011
getLowNibble(0x3F) → 0x0F  // 00111111 → 00001111
getLowNibble(0xF0) → 0x00  // 11110000 → 00000000
getLowNibble(0x25) → 0x05  // 00100101 → 00000101
```

---

### Ex 2.2: Extrair 4 bits superiores (nibble alto)
**Objetivo:** Pegar os 4 bits mais à esquerda de um byte.

```c
unsigned char getHighNibble(unsigned char byte);
```

**Exemplos:**
```
getHighNibble(0xAB) → 0x0A  // 10101011 → 00001010
getHighNibble(0x3F) → 0x03  // 00111111 → 00000011
getHighNibble(0xF0) → 0x0F  // 11110000 → 00001111
getHighNibble(0x25) → 0x02  // 00100101 → 00000010
```

---

### Ex 2.3: Trocar nibbles
**Objetivo:** Inverter os 4 bits superiores com os 4 inferiores.

```c
unsigned char swapNibbles(unsigned char byte);
```

**Exemplos:**
```
swapNibbles(0xAB) → 0xBA  // 10101011 → 10111010
swapNibbles(0x12) → 0x21  // 00010010 → 00100001
swapNibbles(0xF0) → 0x0F  // 11110000 → 00001111
swapNibbles(0x5A) → 0xA5  // 01011010 → 10100101
```

---

### Ex 2.4: Contar bits ligados
**Objetivo:** Contar quantos bits estão setados para 1.

```c
int countBits(unsigned char byte);
```

**Exemplos:**
```
countBits(7) → 3     // 00000111 = 3 bits ligados
countBits(15) → 4    // 00001111 = 4 bits ligados
countBits(10) → 2    // 00001010 = 2 bits ligados
countBits(255) → 8   // 11111111 = 8 bits ligados
countBits(0) → 0     // 00000000 = 0 bits ligados
```

---

## 🎯 Nível 3: Preparando para Base64

### Ex 3.1: Extrair 6 bits superiores
**Objetivo:** Pegar os bits 2-7 (os 6 bits mais à esquerda).

```c
unsigned char getUpper6Bits(unsigned char byte);
```

**Exemplos:**
```
getUpper6Bits(0b11111100) → 0b00111111  // 63
getUpper6Bits(0b10101010) → 0b00101010  // 42
getUpper6Bits(0xFF) → 0x3F              // 11111111 → 00111111 (63)
getUpper6Bits(0x4D) → 0x13              // 01001101 → 00010011 (19)
```

**Visual:**
```
Byte: 11111100
      ^^^^^^-- (pegar estes 6)
Resultado: 00111111
```

---

### Ex 3.2: Extrair 2 bits inferiores
**Objetivo:** Pegar apenas os bits 0-1 (os 2 bits mais à direita).

```c
unsigned char getLower2Bits(unsigned char byte);
```

**Exemplos:**
```
getLower2Bits(0b11111100) → 0b00000000  // 0
getLower2Bits(0b10101011) → 0b00000011  // 3
getLower2Bits(0xFF) → 0x03              // 11111111 → 00000011 (3)
getLower2Bits(0x61) → 0x01              // 01100001 → 00000001 (1)
```

---

### Ex 3.3: Combinar 2 bits + 4 bits
**Objetivo:** Pegar 2 bits inferiores do primeiro byte e 4 bits superiores do segundo, formando 6 bits.

```c
unsigned char combine2And4Bits(unsigned char byte1, unsigned char byte2);
```

**Exemplos:**
```
combine2And4Bits(0b10101011, 0b11001100) → 0b00110011
// byte1 últimos 2 bits: 11
// byte2 primeiros 4 bits: 1100
// Resultado: 111100 = 00111100

combine2And4Bits(0x61, 0x6E) → 0x16  // 22 em decimal
// 0x61 = 01100001 (últimos 2: 01)
// 0x6E = 01101110 (primeiros 4: 0110)
// Resultado: 010110 = 00010110
```

---

### Ex 3.4: Dividir 3 bytes em 4 grupos de 6 bits (DESAFIO!)
**Objetivo:** Este é o coração do Base64! Pegar 3 bytes (24 bits) e dividir em 4 valores de 6 bits cada.

```c
void splitInto6BitGroups(unsigned char byte1, unsigned char byte2, unsigned char byte3, 
                         unsigned char output[4]);
```

**Exemplo visual:**
```
Input bytes:
byte1 = 0x4D = 01001101
byte2 = 0x61 = 01100001
byte3 = 0x6E = 01101110

Concatenado: 01001101 01100001 01101110 (24 bits)

Dividido em grupos de 6:
Grupo 1: 010011 = 19
Grupo 2: 010110 = 22
Grupo 3: 000101 = 5
Grupo 4: 101110 = 46

output[0] = 19
output[1] = 22
output[2] = 5
output[3] = 46
```

**Mais exemplos:**
```
splitInto6BitGroups(0x4D, 0x61, 0x6E, output)
→ output = [19, 22, 5, 46]

splitInto6BitGroups(0x00, 0x00, 0x00, output)
→ output = [0, 0, 0, 0]

splitInto6BitGroups(0xFF, 0xFF, 0xFF, output)
→ output = [63, 63, 63, 63]
```

---

## 🎯 Nível 4: Base64 Completo

### Ex 4.1: Encoder Base64
**Objetivo:** Implementar um encoder completo que converte bytes para string Base64.

```c
char* base64_encode(unsigned char *data, size_t input_length);
```

**Tabela Base64:**
```
Valor → Char
0-25  → A-Z
26-51 → a-z
52-61 → 0-9
62    → +
63    → /
(padding) → =
```

**Exemplos:**
```
base64_encode("Man", 3) → "TWFu"
base64_encode("Ma", 2) → "TWE="
base64_encode("M", 1) → "TQ=="
base64_encode("hello", 5) → "aGVsbG8="
```

---

### Ex 4.2: Decoder Base64 (Desafio Extra!)
**Objetivo:** Fazer o processo inverso - converter string Base64 para bytes originais.

```c
unsigned char* base64_decode(char *encoded, size_t *output_length);
```

**Exemplos:**
```
base64_decode("TWFu") → "Man"
base64_decode("TWE=") → "Ma"
base64_decode("TQ==") → "M"
base64_decode("aGVsbG8=") → "hello"
```

---

## 💡 Dicas Gerais

### Operadores Bitwise Essenciais
```c
& (AND)   → Extrair/ler bits específicos
| (OR)    → Ligar bits
^ (XOR)   → Inverter bits
~ (NOT)   → Inverter todos os bits
<< (SHL)  → Mover bits para esquerda
>> (SHR)  → Mover bits para direita
```

### Máscaras Úteis
```c
0x01 = 00000001  // bit 0
0x02 = 00000010  // bit 1
0x04 = 00000100  // bit 2
0x08 = 00001000  // bit 3
0x0F = 00001111  // 4 bits baixos
0xF0 = 11110000  // 4 bits altos
0x3F = 00111111  // 6 bits baixos
0xFC = 11111100  // 6 bits altos
```

### Função útil para debug
```c
void printBinary(unsigned char byte) {
    for(int i = 7; i >= 0; i--) {
        printf("%d", (byte >> i) & 1);
    }
    printf("\n");
}
```

---

## 📝 Metodologia de Estudo

1. **Leia o exercício** e entenda o que é pedido
2. **Desenhe no papel** os bits de entrada e saída esperada
3. **Tente sozinho** por 15-20 minutos
4. **Se travar**, revise as dicas e máscaras
5. **Ainda travado?** Busque ajuda, mas peça explicação, não código pronto
6. **Entendeu?** Reescreva do zero sem olhar
7. **No dia seguinte**, tente novamente de memória

---

## ✅ Checklist de Progresso

- [ ] Nível 1 completo (exercícios 1.1 a 1.4)
- [ ] Nível 2 completo (exercícios 2.1 a 2.4)
- [ ] Nível 3 completo (exercícios 3.1 a 3.4)
- [ ] Ex 4.1 completo (encoder)
- [ ] Ex 4.2 completo (decoder)
- [ ] Consegui explicar a lógica para alguém
- [ ] Consegui fazer do zero sem consultar

---

**Boa sorte! 💪 Lembre-se: frustração = crescimento acontecendo!**