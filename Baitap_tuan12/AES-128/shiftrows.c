#include "main.c"

void ShiftRows(uint8_t state[4][4])
{
    //Dịch vòng hàng 1 sang trái 1 phần tử
    uint8_t temp;
    temp = state[1][0];

    state[1][0] = state[1][1];
    state[1][1] = state[1][2];
    state[1][2] = state[1][3];
    state[1][3] = temp;

    //Dịch vòng hàng 2 sang trái 2 phần tử
    uint8_t temp0 = state[2][0];
    uint8_t temp1 = state[2][1];

    state[2][0] = state[2][2];
    state[2][1] = state[2][3];
    state[2][2] = temp0;
    state[2][3] = temp1;

    //Dịch vòng hàng 3 sang trái 3 phần tử = dịch sang phải 1 phần tử
    temp = state[3][3];

    state[3][3] = state[3][2];
    state[3][2] = state[3][1];
    state[3][1] = state[3][0];
    state[3][0] = temp;
}