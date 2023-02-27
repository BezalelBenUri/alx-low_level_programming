#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    char password[16]; /* 15 characters plus null terminator */
    const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()_+-=[]{}|;':\",./<>?"; /* list of possible characters */

    srand(time(NULL)); /* seed random number generator with current time */

    for (int i = 0; i < 15; i++) {
        password[i] = charset[rand() % (sizeof(charset) - 1)]; /* pick a random character from charset and add it to password */
    }
    password[15] = '\0'; /* add null terminator to end of password */

    printf("%s", password);

    return 0;
}

