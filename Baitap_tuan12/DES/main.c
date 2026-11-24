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
//Đổi chỗ L và R
    return ((uint64_t)R << 32) | L;
}

int main(){

    uint64_t plaintext;
    uint64_t key;
    uint64_t k[16];
    plaintext = Nhap_plaintext();
    key = Nhap_key();

    //Sinh 16 subkey từ key
    gen_subkey(key, k);

    //Đi qua hàm hoán vị IP
    uint64_t IP_output = IP_function(plaintext);
    printf("IP output binary: ");
    print_binary64(IP_output);
     printf("\n");

    //Đi qua 16 vòng Feistel
    uint64_t round_output = round_16(IP_output, k);
    printf("Round 16 output binary: ");
    print_binary64(round_output);
    printf("\n");

    //Đi qua hàm hoán vị ngược IP^-1
    uint64_t ciphertext = IP_inverse_function(round_output);
    printf("Ciphertext: %llx\n", ciphertext);
    printf("Ciphertext in binary: ");
    print_binary64(ciphertext);

    return 0;
}