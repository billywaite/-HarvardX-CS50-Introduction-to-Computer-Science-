#include <stdio.h>
#include <cs50.h>

int main(void) {
    int height = 0;
    
    do {
        printf("How high do you want to make Mario's pyramid?: ");
        height = GetInt();
        if (height == 0) {
            return 0;
        }
        } while (height < 1 || height > 23);
        
            for (int i = 0; i<height; i++) {
                for (int k = 0; k<height-i-1; k++) {
                printf(" ");
                }
            for (int j = 0; j<i + 2; j++) {
                printf("#");
                }
            printf("\n");
            }
        return 0;
    }

