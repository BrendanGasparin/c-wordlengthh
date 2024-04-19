/*
    wordlengthh.c
    Author: BrendanGasparin <Brendan.Gasparin@gmail.com>
    Date: 19 April 2024
    Program to read the standard input and then output the
    length of each word to a horizontal histogram.
*/

#include <stdio.h>

#define IN  1   // inside a word
#define OUT 0   // outside a word
#define MAX_LENGTH  45  // maximum length of a word

int main()
{
    int word_lengths[MAX_LENGTH];
    int letter_count, state, c;
    letter_count = 0;
    state = OUT;
    for (int i = 0; i < MAX_LENGTH; i++)
        word_lengths[i] = 0;

    // Read standard input until EOF
    // and store word lengths in an array
    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\n' || c == '\t') {
            if (letter_count > MAX_LENGTH)
                letter_count = MAX_LENGTH;
            if (letter_count > 0)
                word_lengths[letter_count - 1]++;
            letter_count = 0;
            state = OUT;
        }
        else if (state == OUT) {
            state = IN;
            letter_count++;
        }
        else
            letter_count++;
    }

    // print histogram
    for (int i = 0; i < MAX_LENGTH; i++) {
        printf("%2d", i + 1);
        if (i == MAX_LENGTH - 1)
            printf("+");
        printf(":");

        for (int j = 0; j < word_lengths[i]; j++)
            printf("#");
        printf("\n");
    }
}
