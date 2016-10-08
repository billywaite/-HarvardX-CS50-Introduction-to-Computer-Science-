#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void) {
    int count = 0;
    //prompt user for change, type float
    printf("How much change are you owed?: ");
    float change = GetFloat();
    //make sure the answer is positive
    if (change < 0) {
        printf("how much change are you owed?: ");
        change = GetFloat();
    }

    //round from dollars to cents
    int total = round(change * 100);
    
    //Compare to change, edit the count
    while (total > 0) {
    if ((total - 25) >= 0) {
        count++;
        total -= 25;
    } else if ((total - 10) >= 0) {
        count++;
        total -= 10;
    } else if ((total - 5) >= 0) {
        count++;
        total -= 5;
    } else if ((total - 1) >= 0) {
        count++;
        total -= 1;
    }
    }
    printf("%d\n", count);
}
