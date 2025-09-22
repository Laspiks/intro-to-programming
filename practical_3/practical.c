#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

int main() {
    while (true) {
        char letter;
        printf("Enter a letter: ");
        scanf(" %c", &letter);

        // Todo: your code here
        if (isalpha(letter)) {
            letter = tolower(letter);
            printf("The letter %c is at position %d in the alphabet.\n", letter, letter - 'a' + 1);

        } else {
            printf("Invalid input. Stopping…\n");
            return 0;
        }
    }
    return 0;
}