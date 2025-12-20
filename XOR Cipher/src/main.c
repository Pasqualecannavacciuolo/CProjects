#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25
// A B C D E F G H I J K  L  M  N  O  P  Q  R  S  T  U  V  W  X  Y  Z

int main(void)
{
    char *plain = malloc(strlen("CIAO") + 1);
    if (!plain)
    {
        perror("Errore in allocazione PLAIN");
        return 1;
    }
    strcpy(plain, "CIAO");

    char key[] = "KJW";

    char *encrypted = malloc(strlen(plain) + 1);
    if (!encrypted)
    {
        perror("Errore in allocazione ENCRYPTED");
        return 1;
    }

    size_t len = strlen(plain);
    size_t key_len = strlen(key);
    for (size_t i = 0; i < len; i++)
    {
        encrypted[i] = plain[i] ^ key[i % key_len];
    }

    encrypted[len] = '\0';

    for (size_t i = 0; i < len; i++)
    {
        printf("%02X ", (unsigned char)encrypted[i]);
    }
    printf("\n");

    free(plain);
    free(encrypted);

    return 0;
}
