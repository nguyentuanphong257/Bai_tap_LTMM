#include <stdio.h>

#define     m4      0b10011    //Chon da thuc toi gian la m(x) = x^4+x+1
#define     m8      0b100011011  //Chon da thuc toi gian la m(x) = x^8+x^4+x^3+x+1

int a;  //phan tu a(x)
int b;  //phan tu b(x)
int mode; // 0: GF(2^4), 1: GF(2^8)

void Gia_tri_phan_tu_thu_nhat_G4()
{
    int a0, a1, a2, a3;
    printf("Nhap gia tri phan tu thu nhat: ");
    scanf("%d %d %d %d", &a3, &a2, &a1, &a0);
    a = (a3 << 3) | (a2 << 2) | (a1 << 1) | a0;
}

void Gia_tri_phan_tu_thu_hai_G4()
{
    int b0, b1, b2, b3;
    printf("Nhap gia tri phan tu thu hai: ");
    scanf("%d %d %d %d", &b3, &b2, &b1, &b0);
    b = (b3 << 3) | (b2 << 2) | (b1 << 1) | b0;
}

// Ham nhan hai phan tu trong GF(2^4)
int Nhan_da_thuc_GF4(int a, int b)
{
    int c = 0;
    int bit;

    for (int i = 0; i < 4; i++)
    {
        if (b & 1) c ^= a;
        bit = a & 0b1000;

        // Dich trai a va giu lai 4 bit
        a = (a << 1) & 0b1111;

        // Neu co bit tran, giam modulo da thuc toi gian
        if (bit) a ^= (m4 & 0b1111);
        b >>= 1;
    }
    return c;
}

void Gia_tri_phan_tu_thu_nhat_G8()
{
    int a0, a1, a2, a3, a4, a5, a6, a7;
    printf("Nhap gia tri phan tu thu nhat: ");
    scanf("%d %d %d %d %d %d %d %d", &a7, &a6, &a5, &a4, &a3, &a2, &a1, &a0);
    a = (a7 << 7) | (a6 << 6) | (a5 << 5) | (a4 << 4) | (a3 << 3) | (a2 << 2) | (a1 << 1) | a0;
}

void Gia_tri_phan_tu_thu_hai_G8()
{
    int b0, b1, b2, b3, b4, b5, b6, b7;
    printf("Nhap gia tri phan tu thu hai: ");
    scanf("%d %d %d %d %d %d %d %d", &b7, &b6, &b5, &b4, &b3, &b2, &b1, &b0);
    b = (b7 << 7) | (b6 << 6) | (b5 << 5) | (b4 << 4) | (b3 << 3) | (b2 << 2) | (b1 << 1) | b0;
}

int Nhan_da_thuc_GF8(int a, int b)
{
    int c = 0;
    int bit;

    for (int i = 0; i < 8; i++)
    {
        if (b & 1) c ^= a;
        bit = a & 0b10000000;

        // Dich trai a va giu lai 8 bit
        a = (a << 1) & 0b11111111;

        // Neu co bit tran, giam modulo da thuc toi gian
        if (bit) a ^= (m8 & 0b11111111);
        b >>= 1;
    }
    return c;
}

void in_so_nhi_phan(int n)
{
    int m;
    if (mode == 0)
    {
        m = 3;
    }
    else if (mode == 1)
    {
        m = 7;
    }
    for (int i = m;i >= 0; i--)
    {
        printf("%d", (n>>i) &1);
    }
}

int main()
{
    int ket_qua = 0;
    printf("Nhap che do (0: GF(2^4), 1: GF(2^8)): ");
    scanf("%d", &mode);
    if (mode == 0)
    {
        Gia_tri_phan_tu_thu_nhat_G4();
        Gia_tri_phan_tu_thu_hai_G4();
        ket_qua = Nhan_da_thuc_GF4(a, b);
    }
    else if (mode == 1)
    {
        Gia_tri_phan_tu_thu_nhat_G8();
        Gia_tri_phan_tu_thu_hai_G8();
        ket_qua = Nhan_da_thuc_GF8(a, b);
    }

    in_so_nhi_phan(ket_qua);
    return 0;
}