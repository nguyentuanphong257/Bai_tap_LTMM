#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdint.h>

extern int IP[64];

uint64_t IP_function(uint64_t plaintext);
uint64_t IP_inverse_function(uint64_t input);

//Hàm vòng f
uint32_t P_function(uint32_t input);
uint64_t E_function(uint32_t input);
uint32_t f_function(uint32_t R, uint64_t ki);
uint64_t PC1_function(uint64_t key);
uint64_t PC2_function(uint64_t input);
uint64_t left_shift(uint64_t input, int s);
void gen_subkey(uint64_t key, uint64_t k[16]);

#endif