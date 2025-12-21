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

        uint8_t high_nibble = (byte >> 4) & 0X0F;
        uint8_t low_nibble = byte & 0X0F;

        high_nibble = s_box[high_nibble];
        low_nibble = s_box[low_nibble];

        uint8_t encrypted = (high_nibble << 4) | low_nibble;

        byte_array[i] = encrypted;
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
        uint8_t byte = encrypted[i];

        uint8_t high = (byte >> 4) & 0x0F;
        uint8_t low = byte & 0x0F;

        high = inv_s_box[high];
        low = inv_s_box[low];

        plain_out[i] = (high << 4) | low;
    }

    plain_out[plain_size] = '\0';
    return plain_out;
}
