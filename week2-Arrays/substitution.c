#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


bool check_command_line(int argc, string argv[]);
bool is_valid_key(string key);
bool is_key_alpha(string key);
bool is_repeated_key(string key);
void encrypt(string text, string key);


int main(int argc, string argv[])
{
    if (!check_command_line(argc, argv))
    {
        return 1;
    }

    string key = argv[1];
    string text = get_string("plaintext: ");
    encrypt(text, key);
    printf("ciphertext: %s\n", text);
}


bool check_command_line(int argc, string argv[])
{
    bool has_two_arguments = argc == 2;
    if (!has_two_arguments)
    {
        printf("Usage: ./substitution Key\n");
        return false;
    }

    string key = argv[1];
    if (!is_valid_key(key))
    {
        return false;
    }

    return true;
}


bool is_valid_key(string key)
{
    bool has_twenty_six_letters = strlen(key) == 26;
    if (!has_twenty_six_letters)
    {
        printf("Key must contain 26 characters.\n");
        return false;
    }

    if (!is_key_alpha(key))
    {
        return false;
    }

    if (is_repeated_key(key))
    {
        return false;
    }

    return true;
}


bool is_key_alpha(string key)
{
    for (int i = 0, n = strlen(key); i < n; i++)
    {
        if (!isalpha(key[i]))
        {
            printf("Key must contain alphabetic characters.\n");
            return false;
        }
    }
    return true;
}


bool is_repeated_key(string key)
{
    int key_length = strlen(key);
    for (int i = 0; i < key_length; i++)
    {
        for (int j = i + 1; j < key_length; j++)
        {
            if (key[i] == key[j])
            {
                printf("The key cannot contain repeated characters.\n");
                return true;
            }
        }
    }
    return false;
}


void encrypt(string text, string key)
{
    int key_index;
    int text_len = strlen(text);
    for (int i = 0; i < text_len; i++)
    {
        if (isalpha(text[i]))
        {
            if (islower(text[i]))
            {
                key_index = tolower(text[i]) - 'a';
                text[i] = tolower(key[key_index]);
            }
            else
            {
                key_index = toupper(text[i]) - 'A';
                text[i] = toupper(key[key_index]);
            }
        }
    }
}