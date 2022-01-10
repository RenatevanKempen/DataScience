

//OLD CODE

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

    // Open input file and check for usage
    FILE *file = fopen(argv[1], "r");
    if (file == NULL)
    {
        fprintf(stderr, "Could not open the image.\n");
        return 1;
    }

    // open the raw and check the top row and column block (512 bytes at a time) for a header

    // Check if the image is a JPEG
    BYTE bytes[512];

    // read the card 512 bytes at the time
    fread(&bytes, sizeof(WRITE_JPEG), 1, file);
    
    for (int i = 0, i < )

    if (bytes[0] == 0xff && bytes[1] == 0xd8 && bytes[2] == 0xff && (bytes[3] & 0xf0) == 0xe0)
    {
        // return the name of the JPEG, start with '000' and count up
        char jpg[7]; //as the file name should be "###.jpg"
        
        // now create a loop to go over the memory card and extract the jpg input until there is another jpeg header
        int i = 0;
        
        // Once found, open a new JPEG file to write to:
        FILE *output = fopen(jpg, "w");
        
        if (!(bytes[0] == 0xff && bytes[1] == 0xd8 && bytes[2] == 0xff && (bytes[3] & 0xf0) == 0xe0))
        {
            sprintf(jpg, "%03i.jpg", i);
            fwrite(&bytes, sizeof(BYTE), 512, output);
        }
        else
        {
            i++;
        }
        // if you find another header, you must stop, as this is a new JPEG file

        // make sure to update via sprintf the jpg file name with 1;
    }
    else
    {
        printf("nothing found\n")
    }


    // close the file
    fclose(file);


}