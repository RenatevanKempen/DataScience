#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

// define one byte
typedef uint8_t BYTE;

// define the number of bytes to use to read and write the JPEG
const int WRITE_JPEG = 512;


int main(int argc, char *argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: ./recover image \n");
        return 1;
    }

    // Open memory card
    FILE *file = fopen(argv[1], "r");

    // Check for usage
    if (file == NULL)
    {
        fprintf(stderr, "Could not open the image.\n");
        return 1;
    }

    // read and repeat until end of card with 512 bytes at a time
    BYTE bytes[WRITE_JPEG];

    // set a counter
    int count = 0;

    // set a char with the name of the JPG
    char jpg[7]; // 7 chars as the file name should be "###.jpg"

    // print the first jpg name
    sprintf(jpg, "%03i.jpg", count);

    // Create an output file
    FILE *output = fopen(jpg, "w");

    while (fread(bytes, sizeof(WRITE_JPEG), 1, file))
    {
        // if start of JPEG, create a JPEG file
        if (bytes[0] == 0xff && bytes[1] == 0xd8 && bytes[2] == 0xff && (bytes[3] & 0xf0) == 0xe0)
        {
            //check if this is the first JPEG
            if (count == 0;)
            {
                 // write to the first JPEG
                 fwrite(&bytes, sizeof(BYTE), 512, output);

            }
            else
            {
                // close the previous file
                fclose(output);
                count++;

                // open a new file, while adding 1 to the name
                sprintf(jpg, "%03i.jpg", count);
                output = fopen(jpg, "w");

                // start writing a block to the new JPEG
                fwrite(&bytes, sizeof(BYTE), 512, output);


            }
        }
        // if not a start of a new JPEG, keep writing blocks
        else
        {
            // Check if there is already a JPEG
            // keep writing a new block to this 512 bytes at a time

        }

    }

    // close all remaining files
    fclose(file);
    fclose(output);
    return 0;

}
