#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>

int main (int argc, string argv[]) {
    //check the number of arguments
    if (argc != 2) {
        printf("Usage: /pset2/vigenere <key> \n");
        return 1;
    } else {
        //variable for checking if the cipher is alphabetical
        int count = 0;
        
        //create variable for the cipher argument
        string cipher = argv[1];
        
        //alphabetical test for the command line cipher argument
        for (int i = 0, n = strlen(cipher); i < n; i++) {
            if (isalpha(cipher[i])) {
                count++;
            } else {
                printf("Usage: /pset2/vigenere <key> \n");
                return 1;
            }
        }
        
        //if the alphabetical test is passed, proceed with the cipher
        if (strlen(cipher) == count) {
            //prompt for secret message
            string message = GetString();
            
            //vigenere's cipher
            for (int j = 0, k = 0; j < strlen(message); j++) {
                //create key
                int key = k % strlen(cipher);
                
                    if (isalpha(message[j])) {
                        if (isupper(message[j])) {
                            if (isupper(cipher[key])) {
                                int a = (((message[j] - 'A') + (cipher[key] - 'A')) % 26) + 'A';
                                printf("%c", a);
                            } else {
                                int a = (((message[j] - 'A') + (cipher[key] - 'a')) % 26) + 'A';
                                printf("%c", a);
                            }
                        } else if (islower(message[j])) {
                            if (isupper(cipher[key])) {
                                int a = (((message[j] - 'a') + (cipher[key] - 'A')) % 26) + 'a';
                                printf("%c", a);
                            } else {
                                int a = (((message[j] - 'a') + (cipher[key] - 'a')) % 26) + 'a';
                                printf("%c", a);
                            }
                        }
                        k++;
                        } else {
                            printf("%c", message[j]);
                        }
                    }
            printf("\n");
            return 0;
        }
    } 
}