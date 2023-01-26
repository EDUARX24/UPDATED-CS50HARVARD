#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    if(argc != 2)
    {
        printf("./caesar K");
        return 1;
    }
    else
    {
        for(int i = 0; i < strlen(argv[1]); i++)
        {
            if(!isdigit(argv[1][i]))
            {
                printf("Usage: ./caesar key\n");
                return 1;
            }
        }

        int k = atoi(argv[1]);

        string p = get_string("plaintext: ");
        printf("ciphertext: ");

          for(int i = 0; i < strlen(p); p++)
          {
            if(isupper(p[i])) //validacion para abecedario en minuscula
            {
                printf("%c", (p[i] - 65 + k) % 26 + 65);//implementacion de form & validacion de las minusculas
            }
            else if(islower(p[i]))//val de ltrs mayusculas
            {
                printf("%c", (p[i] - 97 + k) % 26 + 97); //valis letras mayusculas
            }
            else
            {
                printf("%c", p[i]);
            }
        }
        printf("\n");
        return 0;
    }
}