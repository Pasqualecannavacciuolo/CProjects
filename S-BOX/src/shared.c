#include "shared.h"

// S-box 8-bit pseudo casuale
uint8_t s_box[256];
uint8_t inv_s_box[256];
char plain[] = "parola";
size_t plain_size;

void init_s_box(void) // inizializza S-box con permutazione semplice
{
    for (int i = 0; i < 256; i++)
        s_box[i] = (i + 101) % 256; // esempio semplice
}

void init_inv_s_box(void)
{
    for (int i = 0; i < 256; i++)
        inv_s_box[s_box[i]] = i;
}
