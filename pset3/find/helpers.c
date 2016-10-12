/**
 * helpers.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Helper functions for Problem Set 3.
 */
       
#include <cs50.h>

#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{

    int left = 0;
    int right = n - 1;
    
    // binary search algorithm
   while (left <= right) {
        //look at the middle of the list
       int middle = left + right / 2;
       //if you find the needle, return true
       if (values[middle] == value) {
           return true;
       } else if (values[middle] > value) {
           right = middle - 1; //adjust the right value to just below middle
       } else {
           left = middle + 1; //adjust the left value to just above middle
       } 
   }
        return false;
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    // sort using bubble algorithm
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n - 1; j++) {
            if (values[i] < values[j]) {
                int temp = values[i];
                values[i] = values[j];
                values[j] = temp;
            }
        }
    }
    return;
}