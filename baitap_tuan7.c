#include <stdio.h>

#define     m4      0b10011    //Chon da thuc toi gian la m(x) = x^4+x+1
#define     m8      0b100011011  //Chon da thuc toi gian la m(x) = x^8+x^4+x^3+x+1

int a;  //phan tu a(x)
int b;  //phan tu b(x)
int mode; // 0: GF(2^4), 1: GF(2^8)


void Nhap_gia_tri_phan_tu_thu_nhat()
{
    int u[8];
    printf("Nhap gia tri phan tu thu nhat: ");
    if (mode == 0)
    {
        scanf("%d %d %d %d", &u[3], &u[2], &u[1], &u[0]);
        a = (u[3]<<3) | (u[2]<<2) | (u[1]<<1) |(u[0]);
    }
    else if (mode == 1)
    {
        scanf("%d %d %d %d %d %d %d %d",&u[7], &u[6], &u[5], &u[4], &u[3], &u[2], &u[1], &u[0]);
        a = (u[7]<<7) | (u[6]<<6) | (u[5]<<5) |(u[4]<<4) | (u[3]<<3) | (u[2]<<2) | (u[1]<<1) |(u[0]);
    }
};

void Nhap_gia_tri_phan_tu_thu_hai()
{
    int u[8];
    printf("Nhap gia tri phan tu thu hai: ");
    if (mode == 0)
    {
        scanf("%d %d %d %d", &u[3], &u[2], &u[1], &u[0]);
        b = (u[3]<<3) | (u[2]<<2) | (u[1]<<1) |(u[0]);
    }
    else if (mode == 1)
    {
        scanf("%d %d %d %d %d %d %d %d",&u[7], &u[6], &u[5], &u[4], &u[3], &u[2], &u[1], &u[0]);
        b = (u[7]<<7) | (u[6]<<6) | (u[5]<<5) |(u[4]<<4) | (u[3]<<3) | (u[2]<<2) | (u[1]<<1) |(u[0]);
    }
};

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
    
    Nhap_gia_tri_phan_tu_thu_nhat();
    Nhap_gia_tri_phan_tu_thu_hai();

    if (mode == 0)
    {
        ket_qua = Nhan_da_thuc_GF4(a, b);
    } else ket_qua = Nhan_da_thuc_GF8(a, b);

    in_so_nhi_phan(ket_qua);
    return 0;
}