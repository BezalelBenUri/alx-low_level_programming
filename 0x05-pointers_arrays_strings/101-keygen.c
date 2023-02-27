#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main(void)
{
    char password[64];
    int i, sum, diff;

    srand(time(NULL));

    /* Generate 63 printable ASCII characters */
    for (i = 0, sum = 0; i < 63; i++) {
        password[i] = rand() % 94 + 32; /*  printable ASCII range is 32 to 126 */
        sum += password[i];
    }

    /* Adjust the sum to be equal to 2772 */
    diff = sum - 2772;
    password[62] -= diff;

    printf("%s", password);

    return 0;
}