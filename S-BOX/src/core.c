#include "shared.h"

uint8_t *encrypt(void)
{
    plain_size = strlen(plain);
    uint8_t *byte_array = malloc(plain_size);
    if (!byte_array)
    {
        perror("Error: malloc for byte_array failed");
        return NULL;
    }

    for (size_t i = 0; i < plain_size; i++)
    {
        uint8_t byte = plain[i];
        byte_array[i] = s_box[byte]; // applica S-box 8-bit direttamente
    }

    return byte_array;
}

char *decrypt(const uint8_t *encrypted)
{
    char *plain_out = malloc(plain_size + 1);
    if (!plain_out)
    {
        perror("malloc failed");
        return NULL;
    }

    for (size_t i = 0; i < plain_size; i++)
    {
        plain_out[i] = inv_s_box[encrypted[i]]; // usa S-box inversa
    }

    plain_out[plain_size] = '\0';
    return plain_out;
}
