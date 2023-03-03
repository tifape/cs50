#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int calculate_grade(string text);
int count_words(string text);
int count_letters(string text);
int count_sentences(string text);
bool is_end_of_sentence(char c);
void print_grade(int grade);

int main(void)
{
    string text = get_string("Text: ");
    int grade = calculate_grade(text);
    print_grade(grade);
}

int calculate_grade(string text)
{
    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);

    float L = (float) letters / (float) words * 100;
    float S = (float) sentences / (float) words * 100;
    float index = 0.0588 * L - 0.296 * S - 15.8;
    int grade = round(index);

    return grade;
}

int count_letters(string text)
{
    int letters = 0;
    int text_length = strlen(text);

    for (int i = 0; i < text_length; i++)
    {
        if (isalpha(text[i]))
        {
            letters++;
        }
    }
    return letters;
}

int count_words(string text)
{
    int words = 1;
    int text_length = strlen(text);

    for (int i = 0; i < text_length; i++)
    {
        if (isspace(text[i]))
        {
            words++;
        }
    }
    return words;
}

int count_sentences(string text)
{
    int sentences = 0;
    int text_length = strlen(text);

    for (int i = 0; i < text_length; i++)
    {
        if (is_end_of_sentence(text[i]))
        {
            sentences++;
        }
    }
    return sentences;
}

bool is_end_of_sentence(char c)
{
    return c == '.' || c == '?' || c == '!';
}

void print_grade(int grade)
{
    if (grade > 16)
    {
        printf("Grade 16+\n");
    }
    else if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", grade);
    }
}