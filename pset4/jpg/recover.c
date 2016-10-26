/**
 * recover.c
 *
 * Computer Science 50
 * Problem Set 4
 *
 * Recovers JPEGs from a forensic image.
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef uint8_t BYTE;

int main(void)
{
    // store 512 bytes
    BYTE block[512];
    // count for naming the jpegs
    int count = 0;
    // declare global file name for img
    char img[10];
    
    // open the memory card
    FILE* file = fopen("card.raw", "r");

    if (file == NULL)
    {
        fclose(file);
        printf("Couldn't open %s.\n", "card.raw");
        return 2;
    }
    
    // initialize outfile before loop
    FILE *outfile = NULL;
    
    // contain everything within a loop that needs to run 50 times
    while (!feof(file))
    {
        // find the beginning of the jpg
        fread(&block, sizeof(BYTE), 512, file);
        
        // if loop identifies if you found a new jpg - first 3 bytes are 0xff 0xd8 0xff
        if (block[0] == 0xff && block[1] == 0xd8 && block[2] == 0xff && block[3] >= 0xe0 && block[3] <= 0xef)
        {
            if (outfile == NULL) // first time
            {
                // sprintf prints into the current directory
                sprintf(img, "%03d.jpg", count);
                // open the current file
                outfile = fopen(img, "w");
                // write 512 bytes
                fwrite(&block, sizeof(BYTE), 512, outfile);
                count++;
            }
            else
            {
                fclose(outfile);
                sprintf(img, "%03d.jpg", count);
                outfile = fopen(img, "w");
                fwrite(&block, sizeof(BYTE), 512, outfile);
                count++;
            }
        }
             else
        {
            if (count == 0)
                continue;
                fwrite(block, sizeof(BYTE), 512, outfile);
        } 
    }
    // close infile
    fclose(file);
    
    // close img
    fclose(outfile);
    
    // end
    return 0;
}