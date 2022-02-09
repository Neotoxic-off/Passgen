#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

static size_t is_number(char *string)
{
    for (int i = 0; string[i] != '\0'; i++)
        if (string[i] < '0' && string[i] > '9') 
            return (-1);
    return (1);
}

static char *build(int size)
{
    char *password = malloc(size + 1);

    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        password[i] = 33 + (rand() % 90);
    }

    return (password);
}

int main(int ac, char **argv)
{
    int size = 0;
    char *password = NULL;

    if (ac == 2) {
        if (is_number(argv[1]) == 1) {
            size = atoi(argv[1]);
            password = build(size);
            printf("Password: %s\n", password);
            free(password);
        }
    }
}
