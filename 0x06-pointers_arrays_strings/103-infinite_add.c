#include "main.h"
#include <stdio.h>
#include <string.h>

/**
 * infinite_add - adds two numbers
 * @n1: first number
 * @n2: second number
 * @r: buffer to store the result
 * @size_r: size of the buffer
 *
 * Return: pointer to the result, or 0 if the result can't be stored in r
 */
char *infinite_add(char *n1, char *n2, char *r, int size_r)
{
    int i, j, k, l, m, n, sum;
    char tmp;

    i = strlen(n1) - 1;
    j = strlen(n2) - 1;
    k = 0;
    l = 0;

    while (i >= 0 || j >= 0)
    {
        sum = k;

        if (i >= 0)
            sum += n1[i] - '0';

        if (j >= 0)
            sum += n2[j] - '0';

        r[l] = (sum % 10) + '0';
        k = sum / 10;

        i--;
        j--;
        l++;

        if (l >= size_r)
            return (0);
    }

    if (k != 0 && l < size_r)
    {
        r[l] = k + '0';
        l++;
    }

    m = 0;
    n = l - 1;

    while (m < n)
    {
        tmp = r[m];
        r[m] = r[n];
        r[n] = tmp;

        m++;
        n--;
    }

    r[l] = '\0';

    return (r);
}

