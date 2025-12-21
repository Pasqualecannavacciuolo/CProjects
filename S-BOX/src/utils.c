#include "shared.h"

void print_encrypted_text(const uint8_t *byte_array)
{
    for (size_t i = 0; i < plain_size; i++)
    {
        char c = 32 + (byte_array[i] % 95);
        printf("%c", c);
    }
    printf("\n");
}

void print_encrypted_hex(const uint8_t *byte_array)
{
    for (size_t i = 0; i < plain_size; i++)
    {
        printf("%02X ", byte_array[i]);
    }
    printf("\n");
}
