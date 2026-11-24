#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdint.h>

extern int IP[64];

uint64_t IP_function(uint64_t plaintext);
uint64_t IP_inverse_function(uint64_t input);

#endif