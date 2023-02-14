#include "digit.h"
#include <stdio.h>
#include <stdlib.h>


int digit_extractor(long n, int digit)
{
    int base = 10;
    int less = digit - 1;
    long p = pow(base, digit);
    long lp = pow(base, less);
    digit = ((n % p) - (n % lp)) / lp;
    return digit;
}

int digit_count(long n)
{
    int count = 0;
    while (n != 0)
    {
        n /= 10;
        count++;
    }
    return count;
}

double pow(double n, double p)
{
    if (p == 0)
    {
        return 1;
    }
    else
    {
        double ans = n;
        for(int i = 0; i < p - 1; i++)
        {
            ans *= n;
        }
        return ans;
    }
}

long get_long(char *text)
{
    char buffer[40];
    long n;
    char *endptr;
    while (1)
    {
        printf("%s", text);
        fgets(buffer, 40, stdin);
        n = strtol(buffer, &endptr, 10);
        if (*endptr == '\n' && n != 0)
        {
            break;
        }
    }
    return n;
}

int prefix(long n, int start, int count)
{
    int p = 0;
    for (int i = 0; i < start; i++)
    {
        p += (digit_extractor(n, count - start + i + 1) * pow(10, i));
    }
    return p;
}
