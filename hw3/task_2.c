#include <stdio.h>
#include <ctype.h>

int main() {
    int n, shift;
    char ch, encrypted;

    printf("Enter the number of characters to encrypt: ");
    
    if (scanf("%d", &n) != 1) {
        printf("Invalid input: not an integer\n");
        return -1;
    }

    printf("Enter encryption key [-128, 127]: ");
    scanf("%d", &shift);

    if (shift < -128 || shift > 127){
        printf("Encryption key must be in [-128, 127]\n");
        return -1;
    }
    

    for (int i = 0; i < n; i++) {
        do {
            printf("Enter character #%d: ", i + 1);
            scanf(" %c", &ch);

            ch = tolower(ch);
            
            if (isalpha(ch)){
                break;
            }else
            {
                printf("Invalid input: must be a valid alphabetic character\n");
            }
            
        } while (1);
        
        shift = shift % 26;
        if (shift < 0){
            shift += 26;
        }
        encrypted = ((ch - 'a' + shift) % 26) + 'a';

        printf("Encrypted character: %c\n", encrypted);

    }

    return 0;
}