#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TOKENS 64

int tokenizer(char *command)
{
    char delimiter[] = " ";
    char *token;

    token = strtok(command, delimiter);

    // While i have a token continue
    while (token != NULL)
    {
        printf("Token: %s\n", token);
        // Passing NULL to get next token
        token = strtok(NULL, delimiter);
    }

    return 0;
}

int main(void)
{
    char *command = NULL;
    size_t size = 0;
    ssize_t len;

    while (1)
    {
        printf("$PSH: ");
        fflush(stdout);

        len = getline(&command, &size, stdin);
        if (len == -1)
        {
            break; // Errore
        }

        // Se presente newline finale lo rimuovo
        if (len > 0 && command[len - 1] == '\n')
        {
            command[len - 1] = '\0';
        }

        // printf("Length: %zd\n", strlen(command));
        // printf("Buffer size: %zu\n", size);

        tokenizer(command);
    }

    free(command);
    return 0;
}
