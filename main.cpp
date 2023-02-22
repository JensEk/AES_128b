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

#include <cstdio>
#include <iostream>
#include "aes.h"

using namespace std;

int main()
{

    // Create AES object with matrix of 4x4 and start read key then continue reading blocks
    AES aes;
    int res = fread(aes.key, 4, 4, stdin);
    if (res > 0)
    {
        aes.keyExpansion();
        while (!feof(stdin))
        {
            res = fread(aes.block, 4, 4, stdin);
            if (res > 0)
            {
                aes.encrypt();

                (void)fwrite(aes.block, 4, 4, stdout);
            }
        }
    }
    else
    {
        cout << "Error reading key" << endl;
        return 1;
    }

    return 0;
}
