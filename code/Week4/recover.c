#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int file_count = 0;
    char file_name[8];
    FILE *img = NULL;

    // Check only one command line arguement is given
    if (argc != 2)
    {
        printf("Usage: ./recover [file name]");
        return 1;
    }

    // Open the memory card
    FILE *card = fopen(argv[1], "r");
    if (card == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    // Create a buffer for a block of data
    uint8_t buffer[512];

    // While there's still data to read
    while (fread(buffer, 1, 512, card) == 512)
    {
        // Detect the start of a JPEG
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff)
        {
            // Close previous file if open
            if (img != NULL)
            {
                fclose(img);
            }

            // Name the JPEG file and open it
            sprintf(file_name, "%03i.jpg", file_count++);
            img = fopen(file_name, "w");
        }
        // Write into the new JPEG file
        if (img != NULL)
        {
            fwrite(buffer, sizeof(uint8_t), 512, img);
        }
    }

    // Close the files
    if (img != NULL)
    {
        fclose(img);
    }
    fclose(card);
}
