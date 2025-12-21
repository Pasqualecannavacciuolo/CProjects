#include "shared.h"

// definizione reale (UNA SOLA VOLTA)
uint8_t s_box[16] = {
    0xE, 0x4, 0xD, 0x1,
    0x2, 0xF, 0xB, 0x8,
    0x3, 0xA, 0x6, 0xC,
    0x5, 0x9, 0x0, 0x7};

uint8_t inv_s_box[16];

char plain[] = "parola";
size_t plain_size;

void init_inv_s_box(void)
{
    for (uint8_t i = 0; i < 16; i++)
    {
        inv_s_box[s_box[i]] = i;
    }
}
