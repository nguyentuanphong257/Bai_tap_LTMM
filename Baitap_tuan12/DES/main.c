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

int main(){

    uint64_t plaintext;
    plaintext = Nhap_plaintext();
    print_binary64(plaintext);
    uint64_t daura_IP = IP_function(plaintext);
    print_binary64(daura_IP);
    return 0;
}