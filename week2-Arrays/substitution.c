#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

bool check_command_line(int argc, string argv[]);

int main(int argc, string argv[])
{
    if (!check_command_line(argc, argv))
    {
        return 1;
    }

    string text = get_string("plaintext: ");

    string alphabet_lower = "abcdefghijklmnopqrstuvwxyz";
    string alphabet_upper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    for (int i = 0, n = strlen(text); i < n; i++)
    {
        for (int j = 0, alphabet = 26; j < alphabet; j++)
        {
            if (text[i] == alphabet_lower[j] || text[i] == alphabet_upper[j])
            {
                if (islower(text[i]))
                {
                    text[i] = tolower(argv[1][j]);
                    break;
                }
                else
                {
                    text[i] = toupper(argv[1][j]);
                    break;
                }
            }
        }
    }

    printf("ciphertext: %s\n", text);
}

bool check_command_line(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./substitution Key\n");
        return false;
    }

    if (strlen(argv[1]) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return false;
    }

    for (int i = 0, n = strlen(argv[1]); i < n; i++)
    {
        if (!isalpha(argv[1][i]))
        {
            printf("Key must contain alphabetic characters.\n");
            return false;
        }
    }

    int penultimate = strlen(argv[1]) - 1;
    int descending = penultimate;
    char current_position, front_position;
    for (int i = 0; i < penultimate; i++, descending--)
    {
        current_position = argv[1][i];
        for (int j = 0; j < descending; j++)
        {
            front_position = argv[1][j + i + 1];
            if (current_position == front_position)
            {
                printf("Key must not contain repeated characteres.\n");
                return false;
            }
        }
    }

    return true;
}