#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    char password[16];
    int i;

    srand(time(NULL));

    /* Generate 15 random characters */
    for (i = 0; i < 15; i++) {
        int r = rand() % 62;
        if (r < 26) {
            /* Uppercase letter */
            password[i] = 'A' + r;
        } else if (r < 52) {
            /* Lowercase letter */
            password[i] = 'a' + (r - 26);
        } else {
            /* Digit */
            password[i] = '0' + (r - 52);
        }
    }

    /* Add null terminator */
    password[15] = '\0';

    /* Make sure the password contains at least one uppercase letter,*/
    /* one lowercase letter, and one digi*/t
    int has_uppercase = 0;
    int has_lowercase = 0;
    int has_digit = 0;
    for (i = 0; i < 15; i++) {
        if (password[i] >= 'A' && password[i] <= 'Z') {
            has_uppercase = 1;
        } else if (password[i] >= 'a' && password[i] <= 'z') {
            has_lowercase = 1;
        } else if (password[i] >= '0' && password[i] <= '9') {
            has_digit = 1;
        }
    }
    if (!has_uppercase || !has_lowercase || !has_digit) {
        /* Regenerate password if it doesn't meet the requirements */
        return main();
    }

    /* Print the password */
    printf("%s", password);

    return 0;
}

