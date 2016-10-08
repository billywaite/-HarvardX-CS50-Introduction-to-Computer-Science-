#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(void) {
    
    //prompt for name
    string name = GetString();
    
    //print the first initial & convert to uppercase
    printf("%c", toupper(name[0]));
    
    //loop through the name, find the whitespace characters and print the character right after the whitespace character.
    for (int i = 0; i < strlen(name); i++) {
        if (name[i] == ' ') {
            printf("%c", toupper(name[i + 1]));
        }
    }
    //print new line to finish
    printf("\n");
}