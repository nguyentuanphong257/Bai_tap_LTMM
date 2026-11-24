#include "main.h"

int PC1[56] = {
    57, 49, 41, 33, 25, 17, 9,
    1, 58, 50, 42, 34, 26, 18,
    10, 2, 59, 51, 43, 35, 27,
    19, 11, 3, 60, 52, 44, 36,
    63, 55, 47, 39, 31, 23, 15,
    7, 62, 54, 46, 38, 30, 22,
    14, 6, 61, 53, 45, 37, 29,
    21, 13, 5, 28, 20, 12, 4
};

int PC2[48] = {
    14, 17, 11, 24, 1, 5,
    3, 28, 15, 6, 21, 10,
    23, 19, 12, 4, 26, 8,
    16, 7, 27, 20, 13, 2,
    41, 52, 31, 37, 47, 55,
    30, 40, 51, 45, 33, 48,
    44, 49, 39, 56, 34, 53,
    46, 42, 50, 36, 29, 32
};

int shift_table[16] = {1, 1, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 2, 1};

//Hàm hoán vị PC1
uint64_t PC1_function(uint64_t key)
{
    uint64_t result = 0;
    for (int i = 0; i < 56; i++)
    {
        uint16_t bit = (key >> (64 - PC1[i])) & 1;
        result = (result << 1) | bit;
    }
    return result;
}

//Hàm hoán vị PC2
uint64_t PC2_function(uint64_t input)
{
    uint64_t result = 0;
    for (int i = 0; i < 48; i++)
    {
        uint16_t bit = (input >> (56 - PC2[i])) & 1;
        result = (result << 1) | bit;
    }
    return result;
}

//Hàm dịch vòng trái
uint64_t left_shift(uint64_t input, int s)
{
    uint64_t result = (input << s)| (28 - s) & (2^28 - 1);
    return result;
}

//Hàm tạo ra 16 key:k1-k16
void gen_subkey(uint64_t key, uint64_t subkey[16])
    {
        uint64_t v;
        uint64_t C;
        uint64_t D;

        v = PC1_function(key);
        C = (v >> 28) & 0x0FFFFFFF;
        D = v & 0x0FFFFFFF;

        for (int i=0; i<1;i++){
            C = left_shift(C, shift_table[i]);
            D = left_shift(D, shift_table[i]);
            subkey[i] = PC2_function((C << 28) | D);
        }
    }