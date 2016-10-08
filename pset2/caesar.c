#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>

int main (int argc, string argv[]) {
    //check the number of arguments
    if (argc != 2) {
        printf("Usage: /pset2/caesar <key> \n");
        return 1;
    } else {
        //prompt for the message to encrypt
        string message = GetString();
        
        //convert string to integer
        int k = atoi(argv[1]);
        
        //find ascii character conversion, add key with equation using modulus %, convert back to character and print as string
        for (int i = 0, n = strlen(message); i < n; i++) {
            if (isalpha(message[i])) {
                if (islower(message[i])) {
                    int a = (((message[i] - 97 + k) % 26) + 97);
                    printf("%c", a);
                } else if (isupper(message[i])) {
                    int b = (((message[i] - 65 + k) % 26) + 65);
                    printf("%c", b);
                }
            } else {
                printf("%c", message[i]);
                }
            }
        printf("\n");
    }
}