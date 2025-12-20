#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    // 4 bit 0...15 hexadecimal
    uint8_t s_box[16] = {
        0xE, 0x4, 0xD, 0x1,
        0x2, 0xF, 0xB, 0x8,
        0x3, 0xA, 0x6, 0xC,
        0x5, 0x9, 0x0, 0x7};

    uint8_t byte = 0XAB; // esempio 8 bit = 10101011

    // 0X0F = 0000 1111                       // 0000 1111
    uint8_t high_nibble = (byte >> 4) & 0X0F; // 0000 1010
                                              // ---------
                                              // 0000 1010

    // 0X0F = 0000 1111               // 0000 1011
    uint8_t low_nibble = byte & 0X0F; // 0000 1111
                                      // ---------
                                      // 0000 1011

    high_nibble = s_box[high_nibble];
    low_nibble = s_box[low_nibble];

    uint8_t encrypted = (high_nibble << 4) | low_nibble;

    printf("Byte originale : %02X\n", byte);
    printf("Byte cifrato   : %02X\n", encrypted);

    return 0;
}
