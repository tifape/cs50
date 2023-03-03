#include <cs50.h>
#include <stdio.h>
#include <string.h>

void print_flag(unsigned long int num);
int cont_digits(unsigned long int num);
bool is_visa(unsigned long int num);
bool is_amex(unsigned long int num);
bool is_mastercard(unsigned long int num);
bool check_leading_digits(unsigned long int num, string bandeira);
bool check_size(unsigned long int num, string bandeira);
bool check_luhn(unsigned long int num);
bool is_last_digit_zero(int sum);
int first_digit(unsigned long int num);
int first_two_digits(unsigned long int num);

#define FIRST_DIGIT_VISA 4
#define FIRST_DIGIT_AMEX 3
#define FIRST_DIGIT_MASTERCARD 5

int main(void)
{
    unsigned long int number = get_long("Number: ");
    print_flag(number);
}

void print_flag(unsigned long int num)
{
    int first_digit_user = first_digit(num);
    if (first_digit_user == FIRST_DIGIT_VISA)
    {
        if (is_visa(num))
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else if (first_digit_user == FIRST_DIGIT_MASTERCARD)
    {
        if (is_mastercard(num))
        {
            printf("MASTERCARD\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else if (first_digit_user == FIRST_DIGIT_AMEX)
    {
        if (is_amex(num))
        {
            printf("AMEX\n");
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

bool is_visa(unsigned long int num)
{
    string card = "visa";
    return check_leading_digits(num, card) && check_size(num, card) && check_luhn(num);
}

bool is_amex(unsigned long int num)
{
    string card = "amex";
    return check_leading_digits(num, card) && check_size(num, card) && check_luhn(num);
}

bool is_mastercard(unsigned long int num)
{
    string card = "mastercard";
    return check_leading_digits(num, card) && check_size(num, card) && check_luhn(num);
}

bool check_leading_digits(unsigned long int num, string bandeira)
{
    if (strcmp(bandeira, "visa") == 0)
    {
        return first_digit(num) == 4;
    }
    else if (strcmp(bandeira, "amex") == 0)
    {
        int first_digits = first_two_digits(num);
        return first_digits == 34 || first_digits == 37;
    }
    else if (strcmp(bandeira, "mastercard") == 0)
    {
        int first_digits = first_two_digits(num);
        return first_digits >= 51 && first_digits <= 55;
    }
    return false;
}

bool check_size(unsigned long int num, string bandeira)
{
    if (strcmp(bandeira, "visa") == 0)
    {
        return cont_digits(num) == 13 || cont_digits(num) == 16;
    }
    else if (strcmp(bandeira, "amex") == 0)
    {
        return cont_digits(num) == 15;
    }
    else if (strcmp(bandeira, "mastercard") == 0)
    {
        return cont_digits(num) == 16;
    }
    return false;
}

int cont_digits(unsigned long int num)
{
    int cont = 1;
    while (num >= 10)
    {
        num = num / 10;
        cont++;
    }
    return cont;
}

bool check_luhn(unsigned long int num)
{
    int total_sum = 0;
    int digit_index = 0;

    while (num > 0)
    {
        int current_digit = num % 10;
        if (digit_index % 2 == 0)
        {
            total_sum += current_digit;
        }
        else
        {
            int double_digit = current_digit * 2;
            total_sum += double_digit > 9 ? (double_digit % 10) + (double_digit / 10) : double_digit;
        }

        num /= 10;
        digit_index++;
    }

    return  total_sum % 10 == 0;
}

int first_digit(unsigned long int num)
{
    for (int i = 0, n = cont_digits(num); i < n - 1; i++)
    {
        num /= 10;
    }
    return num;
}

int first_two_digits(unsigned long int num)
{
    for (int i = 0, n = cont_digits(num); i < n - 2; i++)
    {
        num /= 10;
    }
    return num;
}