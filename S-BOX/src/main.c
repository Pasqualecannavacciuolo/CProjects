#include "shared.h"
#include "core.h"
#include "utils.h"

int main(void)
{
    init_s_box();     // 🔑 OBBLIGATORIO
    init_inv_s_box(); // 🔑 OBBLIGATORIO

    uint8_t *encrypted_hex_array = encrypt();
    if (!encrypted_hex_array)
    {
        perror("Error allocating encrypted_hex_array");
        return 1;
    }

    print_encrypted_hex(encrypted_hex_array);

    char *decrypted = decrypt(encrypted_hex_array);
    if (!decrypted)
    {
        free(encrypted_hex_array);
        return 1;
    }

    printf("%s\n", decrypted);

    free(encrypted_hex_array);
    free(decrypted);

    return 0;
}
