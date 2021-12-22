#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <getopt.h>

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    //check if the command line take one arrgument
    if (argc != 2)
    {
        printf("Usage:./recover image");
        return 1;
    }

    //open the file
    FILE *memo = fopen(argv[1], "r");
    if (memo == NULL)
    {
        printf("Error.\n");
        return 1;
    }

    //create pointer for the new file
    FILE *recovered = NULL;
    

    int pic_counter = 0;

    //array to read the first 4 bytws
    unsigned char header [512];

    //read the head if the files
    while (fread(&header, sizeof(512), 1, memo) == 1)
    {
       
        //check if the first 4 bytes are JPEG
        if (header[0] == 0xff && header[1] == 0xd8 && header[2] == 0xff && (header[3] & 0xf0) == 0xe0)
        {
            
            if (recovered != NULL)
            {
                fclose(recovered);
            }
            //creat the name for the output file
            char filename [8];

            //print the name on each image we found
            sprintf(filename, "%03d.jpg", pic_counter);

            //open the output file
            recovered = fopen(filename, "w+");

            //cheack if it return NULL?
            if (recovered == NULL)
            {
                fclose(memo);
                fprintf(stderr, "something went wrong dude!!\n");
                return 1;
            }

            //write inside the new file
            fwrite(&header, sizeof(512), 1, recovered);

            //count the images we found to added to the name
            pic_counter++;


        }
        else if (pic_counter > 0)
        {
            fwrite(&header, sizeof(512), 1, recovered);
            
        }
        

    }

    fclose(memo);
    fclose(recovered);
    printf("all images are recovered\n");

}