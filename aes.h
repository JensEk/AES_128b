/*
AES encryption implementation
Made by: Jens Ekenblad
Based on: https://nvlpubs.nist.gov/nistpubs/FIPS/NIST.FIPS.197.pdf
https://en.wikipedia.org/wiki/Advanced_Encryption_Standard

Length of key (K): 128 bits ->
Key length Nk = 4
Block size Nb = 4
Rounds Nr = 10
*/

#ifndef AES_H
#define AES_H

#include <vector>
#include <cstdint>

extern const uint8_t sBox[256];
extern const uint8_t rCon[256];
extern const uint8_t galois2[256];
extern const uint8_t galois3[256];

class AES
{
private:
    int Nk = 4;
    int Nb = 4;
    int Nr = 10;

public:
    uint8_t key[4][4];       // Cipher key
    uint8_t keyExpan[44][4]; // Hold 10x round keys
    uint8_t block[4][4];     // The State matrix with 4 bytes in each column

    void keyExpansion();
    void encrypt();

    void addRoundKey(int round);
    void subBytes();
    void shiftRows();
    void mixColumns();
};

#endif