#include <stdio.h>

#define     m      0b10011    //Chon da thuc toi gian la m(x) = x^4+2+1

int a;  //phan tu a(x)
int b;  //phan tu b(x)

void Gia_tri_phan_tu_thu_nhat()
{
    int a0, a1, a2, a3;
    printf("Nhap gia tri phan tu thu nhat: ");
    scanf("%d %d %d %d", &a0, &a1, &a2, &a3);
    for (int i = 0; i < 4; i++)
    {
        if (!i) a = a0;
        else {
            a = (a<<1) | (i == 1 ? a1 : (i == 2 ? a2 : a3));
        }
    }
}

void Gia_tri_phan_tu_thu_hai()
{
    int b0, b1, b2, b3;
    printf("Nhap gia tri phan tu thu hai: ");
    scanf("%d %d %d %d", &b0, &b1, &b2, &b3);
    for (int i = 0; i < 4; i++)
    {
        if (!i) b = b0;
        else {
            b = (b<<1) | (i == 1 ? b1 : (i == 2 ? b2 : b3));
        }
    }
}



int main()
{
    Gia_tri_phan_tu_thu_nhat();
    Gia_tri_phan_tu_thu_hai();
    printf("Gia tri cua phan tu thu nhat: %d", a);
    printf("Gia tri cua phan tu thu hai: %d", b);
    return 0;
}