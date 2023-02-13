#include "digit.h"
#include <stdio.h>


const int MAX_LENGTH = 16;
const int MIN_LENGTH = 13;
const int AMEX_LENGTH = 15;
const int MASTERCARD_LENGTH = 16;
const int VISA_LENGTH1 = 13;
const int VISA_LENGTH2 = 16;

typedef enum
{
    true = 1, false = 0
}
bool;

bool luhn_algorithm(long number, int count);


int main(void)
{
    const long n = get_long("Credit card number: ");
    int count = digit_count(n);

    if (count == MIN_LENGTH || count == AMEX_LENGTH || count == MAX_LENGTH)
    {
        if (luhn_algorithm(n, count))
        {
            int p, p1, p2;
            switch (count)
            {
                case AMEX_LENGTH:
                    p = prefix(n, 2, count);
                    if (p == 34 || p == 37)
                    {
                        printf("AMERICAN EXPRESS\n");
                    }
                    else
                    {
                        printf("INVALID\n");
                    }
                    break;
                case VISA_LENGTH1:
                    p = prefix(n, 1, count);
                    if (p == 4)
                    {
                        printf("VISA\n");
                    }
                    else
                    {
                        printf("INVALID\n");
                    }
                    break;
                case MAX_LENGTH:
                    p1 = prefix(n, 1, count);
                    p2 = prefix(n, 2, count);
                    if (p1 == 4)
                    {
                        printf("VISA\n");
                    }
                    else if (p1 == 5 && (p2 > 50 && p2 < 56))
                    {
                        printf("MASTERCARD\n");
                    }
                    else
                    {
                        printf("INVALID\n");
                    }
                    break;
            }
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}


bool luhn_algorithm(long n, int count)
{
    int odd_sum = 0;
    for (int i = 1; i <= count; i += 2)
    {
        odd_sum += digit_extractor(n, i);
    }

    int even_sum = 0;
    for (int j = 2; j <= count; j += 2)
    {
        int even_mul_digit = digit_extractor(n, j) * 2;
        if (even_mul_digit > 9)
        {
            for (int k = 1; k <= digit_count(even_mul_digit); k++)
            {
                even_sum += digit_extractor(even_mul_digit, k);
            }
        }
        else
        {
            even_sum += even_mul_digit;
        }
    }
    int checksum = even_sum + odd_sum;
    return (checksum % 10 != 0) ? false : true;
}