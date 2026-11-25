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

 //Test vector 1
    uint64_t plaintext1 = 0x0123456789ABCDEF;
    uint64_t key1 = 0x133457799BBCDFF1;
    uint64_t ciphertext1 = 0x85E813540F0AB405;

//Test vector 2
    uint64_t plaintext2 = 0x0000000000000000;
    uint64_t key2 = 0x0000000000000000;
    uint64_t ciphertext2 = 0x8CA64DE9C1B123A7;

//Test vector 3
    uint64_t plaintext3 = 0x8787878787878787;
    uint64_t key3 = 0x0E329232EA6D0D73;
    uint64_t ciphertext3 = 0x0000000000000000;

int main(){
    int choice;

    uint64_t plaintext;
    uint64_t key;
    uint64_t expected_ciphertext;

    printf("Chon test vector (1-3):\n");
    scanf("%d",&choice);

    switch (choice)
    {
        case 1: 
            plaintext = plaintext1;
            key = key1;
            expected_ciphertext = ciphertext1;
            break;
        case 2:
            plaintext = plaintext2;
            key = key2;
            expected_ciphertext = ciphertext2;
            break;
        case 3:
            plaintext = plaintext3;
            key = key3;
            expected_ciphertext = ciphertext3;
            break;
        default:
            printf("Lua chon khong hop le!\n");
            return 1;
    }

    printf("Thong tin test vector:\n");
    printf("Plaintext = %llX\n",plaintext);
    printf("Key= %llX\n",key);
    printf("Expected  = %llX\n",expected_ciphertext);
    printf("\nPlaintext binary:\n");
    print_binary64(plaintext);

    uint64_t k[16];

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