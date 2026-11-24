#include "main.h"

void print_binary64(uint64_t value)
{
    for (int i = 63; i >= 0; i--)
    {
        printf("%llu", (value >> i) & 1);
    }
    printf("\n");
}

uint64_t Nhap_plaintext()
{
    uint64_t plaintext;
    printf("Nhap plaintext (hex): ");
    scanf("%llx", &plaintext);
    return plaintext;
}

uint64_t Nhap_key()
{
    uint64_t key;
    printf("Nhap key (hex): ");
    scanf("%llx", &key);
    return key;
}

uint64_t round_16(uint64_t input, uint64_t k[16])
{
    uint32_t L = (input >> 32) & 0xFFFFFFFF;
    uint32_t R = input & 0xFFFFFFFF;

    for (int i = 0; i<16; i++)
    {
        uint32_t tmp = R;
        R = L ^ f_function(R, k[i]);
        L = tmp;
    }

    return ((uint64_t)R << 32) | L;
}

int main(){

    uint64_t plaintext;
    plaintext = Nhap_plaintext();
    print_binary64(plaintext);
    uint64_t daura_IP = IP_function(plaintext);
    print_binary64(daura_IP);
    return 0;
}