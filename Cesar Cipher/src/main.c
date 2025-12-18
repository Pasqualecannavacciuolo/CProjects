#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25
// A B C D E F G H I J K  L  M  N  O  P  Q  R  S  T  U  V  W  X  Y  Z

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        fprintf(stderr, "Uso: %s <shift> <testo>\n", argv[0]);
        return 1;
    }

    int shift = atoi(argv[1]);
    char *plain = argv[2];

    char *encrypted = malloc(strlen(plain));

    int size = strlen(plain);
    int i = 0;

    while (i < size)
    {
        encrypted[i] = plain[i] + shift;
        i++;
    }
    encrypted[size] = '\0';

    printf("%s\n", encrypted);

    free(encrypted);

    return 0;
}
