#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define USAGE "Usage: ./caesar key\n"
#define ERROR "Enter an integer between 0 and 2147483647\n"

bool is_valid_command_line(int argc, string argv[]);
bool has_int_overflow(string key_str);
string encrypt(string text, int key);
bool is_key_numeric(string key);

int main(int argc, string argv[])
{
    if (!is_valid_command_line(argc, argv))
    {
        return 1;
    }

    string plaintext = get_string("plaintext: ");
    int key = atoi(argv[1]);
    string ciphertext = encrypt(plaintext, key);

    printf("ciphertext: %s\n", ciphertext);
}

bool is_valid_command_line(int argc, string argv[])
{
    if (argc != 2)
    {
        printf(USAGE);
        return false;
    }

    string key = argv[1];
    if (!is_key_valid(key))
    {
        printf(ERROR);
        return false;
    }

    return true;
}

bool is_key_valid(string key)
{
    if (!is_key_numeric(key) || has_int_overflow(key))
    {
        return false;
    }
    return true;
}

bool is_key_numeric(string key_str)
{
    int key_length = strlen(key_str);
    for (int i = 0; i < key_length; i++)
    {
        if (!isdigit(key_str[i]))
        {
            return false;
        }
    }
    return true;
}

bool has_int_overflow(string key_str)
{
    int key_length = strlen(key_str);
    if (key_length == 10)
    {
        string int_max = "2147483647";
        for (int i = 0; i < key_length; i++)
        {
            if (key_str[i] > int_max[i])
            {
                return true;
            }
        }
    }
    else if (key_length > 10)
    {
        return true;
    }

    return false;
}

string encrypt(string text, int key)
{
    // It is necessary to convert the key to a long type,
    // so that the calculation does not overflow
    // if someone enters a very high number
    long key_l = key;
    int text_length = strlen(text);

    for (int i = 0; i < text_length; i++)
    {
        if (isalpha(text[i]))
        {
            if (islower(text[i]))
            {
                text[i] = 'a' + ((text[i] - 'a') + key_l) % 26;
            }
            else
            {
                text[i] = 'A' + ((text[i] - 'A') + key_l) % 26;
            }
        }
    }
    return text;
}