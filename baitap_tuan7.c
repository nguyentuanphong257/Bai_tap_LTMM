#include <stdio.h>

#define     m      0b10011    //Chon da thuc toi gian la m(x) = x^4+2+1

int a;  //phan tu a(x)
int b;  //phan tu b(x)

void Gia_tri_phan_tu_thu_nhat()
{
    int a0, a1, a2, a3;
    printf("Nhap gia tri phan tu thu nhat: ");
    scanf("%d %d %d %d", &a3, &a2, &a1, &a0);
    a = (a3 << 3) | (a2 << 2) | (a1 << 1) | a0;
}

void Gia_tri_phan_tu_thu_hai()
{
    int b0, b1, b2, b3;
    printf("Nhap gia tri phan tu thu hai: ");
    scanf("%d %d %d %d", &b3, &b2, &b1, &b0);
    b = (b3 << 3) | (b2 << 2) | (b1 << 1) | b0;
}

// Ham nhan hai phan tu trong GF(2^4)
int Nhan_da_thuc(int a, int b)
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
        if (bit) a ^= (m & 0b1111);
        b >>= 1;
    }
    return c;
}

int main()
{
    int ket_qua = 0;
    Gia_tri_phan_tu_thu_nhat();
    Gia_tri_phan_tu_thu_hai();
    printf("Gia tri cua phan tu thu nhat: %d", a);
    printf("Gia tri cua phan tu thu hai: %d", b);

    ket_qua = Nhan_da_thuc(a, b);
    printf("Ket qua nhan hai phan tu: %d", ket_qua);
    return 0;
}