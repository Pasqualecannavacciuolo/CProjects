#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// DJB2 Hashing Function
unsigned long hash(unsigned char *str)
{
    unsigned long hash = 5381;       // ✨ Magic number
    unsigned long salt = 2654435761; // Golden ratio 2^32
    int c;

    while ((c = *str++))
    {
        salt = salt * 65599 ^ c; // 65599 = costante empirica usata in hash type “sdbm”
        hash ^= (hash >> 13);
        hash = hash * 33 + c + salt;
        hash ^= (hash << 7);
    }

    return hash;
}

int main(void)
{
    const char *plain = "CIAO";

    unsigned long hashed = hash((unsigned char *)plain);
    printf("Hash of \"%s\" = %lu\n", plain, hashed);

    return 0;
}
