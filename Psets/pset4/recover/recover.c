#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>


int main(int argc, char *argv[])
{
    if(argc != 2)
    {
        printf("Usage: ./recover IMAGE\n");
        return 1;
    }

    FILE *input_file = fopen(argv[1],"r");

    if(input_file == NULL)
    {
        printf("No se logro abrir el archivo");
        return 2;
    }

    unsigned char buffer[512];

    FILE *output_file = NULL;

    char *filename = malloc(8 * sizeof(char));

    int cont = 0;

    while(fread(buffer, sizeof(char), 512, input_file))
    {
        if(buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            if(cont > 0)
            {
                fclose(output_file);
            }
            sprintf(filename, "%03i.jpg", cont);
            output_file = fopen(filename, "w");
            cont++;
        }

        if(output_file != NULL)
        {
            fwrite(buffer, sizeof(char), 512, output_file);
        }
    }

    free(filename);
    fclose(output_file);
    fclose(input_file);

    return 0;
}