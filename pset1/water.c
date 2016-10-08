#include <stdio.h>
#include <cs50.h>

int main(void) {
    printf("How long do you typically shower, in minutes?: ");
    int time = GetInt();
    int bottles = time * 12;
    
    printf("minutes: %d\n", time);
    printf("bottles: %d\n", bottles);
}