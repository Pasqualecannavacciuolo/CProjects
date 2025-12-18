#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25
// A B C D E F G H I J K  L  M  N  O  P  Q  R  S  T  U  V  W  X  Y  Z

int main(int argc, char *argv[])
{
    // char c = 'C';
    // int integer_value = (c - 'A') % 26; // Ogni lettera dell'alfabeto viene mappata ad un numero da 0 a 25
    // printf("%d\n", integer_value);

    if (argc != 3)
    {
        fprintf(stderr, "Uso: %s <plain_text> <worm_phrase>\n", argv[0]);
        return 1;
    }

    char *plain = argv[1];
    char *worm = argv[2];

    size_t i = 0;
    size_t size = strlen(plain);
    size_t worm_len = strlen(worm);

    char *encrypted = malloc(strlen(plain) + 1);
    if (!encrypted)
    {
        perror("Error allocating ENCRYPTED");
        return 1;
    }
    // ASCII => A=65 : Z=90

    while (i < size)
    {
        char plain_char = plain[i];

        // Converti minuscole in maiuscole, ignora altri caratteri
        if (plain_char >= 'a' && plain_char <= 'z')
            plain_char -= 'a' - 'A';
        if (plain_char < 'A' || plain_char > 'Z')
        {
            encrypted[i] = plain_char;
            continue;
        }

        int plain_integer_value = (plain[i] - 'A');
        int shift = (worm[i % worm_len] - 'A');

        int encrypted_value = (plain_integer_value + shift) % 26;
        char encrypted_char = encrypted_value + 'A';

        encrypted[i] = encrypted_char;

        i++;
    }

    encrypted[size] = '\0';

    printf("%s\n", encrypted);
    free(encrypted);

    return 0;
}
