#include <cs50.h>
#include <stdio.h>

#define MIN_HEIGHT 1
#define MAX_HEIGHT 8

int get_valid_height(void);
void print_pyramid(int height);
void print_row(int spaces, int hashes);
void print_characters(char character, int n);

int main(void)
{
    int height = get_valid_height();
    print_pyramid(height);
}

int get_valid_height(void)
{
    int height;
    do
    {
        height = get_int("Height: ");
    }
    while (height < MIN_HEIGHT || height > MAX_HEIGHT);

    return height;
}

void print_pyramid(int height)
{
    int hashes = 1;
    int spaces = height - hashes;
    while(height != 0)
    {
        print_row(spaces, hashes);

        hashes++;
        spaces--;
        height--;
    }
}

void print_row(int spaces, int hashes)
{
    print_characters(' ', spaces);
    print_characters('#', hashes);
    print_characters(' ', 2);
    print_characters('#', hashes);
    printf("\n");
}

void print_characters(char character, int n)
{
    for (int j = 0; j < n; j++)
    {
        printf("%c", character);
    }
}
