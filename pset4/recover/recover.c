#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>

int main(int argc, char *argv[])
{
    //Check Usage
    if (argc != 2)
    {
        printf("Usage: recover infile\n");
        return 1;
    }

    // Open Forensic Image
    FILE *input = fopen("card.raw", "r");
    if (input == NULL)
    {
        printf("Error opening 'card.raw'.\n");
        return 1;
    }

    //Temp
    unsigned char buffer[512];

    // Count for JPEG Filename
    int jpgcounter = 0;
    FILE *image = NULL;

    // Check if start of a new JPEG
    int jpg_found = false;

    // Iterate through memory card
    while (fread(buffer, 512, 1, input) == true)
    {
        //Check JPEG format
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xe0) == 0xe0)
        {
            if (jpg_found == true)
            {
                // Close current image
                fclose(image);
            }
            else
            {
                // New JPEG found
                jpg_found = true;
            }

            char filename[8];
            sprintf(filename, "%03d.jpg", jpgcounter);
            image = fopen(filename, "a");
            jpgcounter++;
        }
        if (jpg_found == true)
        {
            // Write JPEG contents
            fwrite(&buffer, 512, 1, image);
        }
    }

    // Cleanup
    fclose(input);
    fclose(image);

    return 0;

}
