#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int altura;
    int direccion = 0;

    do
    {
        altura = get_int("Ingrese altura: ");
    }
    while (altura < 1 || altura > 8);

    for (int i = 0; i < altura; i++)//controlar altura
    {
        for (int j = altura -1; j >= 0; j --)//x cd iteracion pintar #
        {
            if ( j <= i)
            {
                printf("#");
            }
            else if (j > i && direccion == 0)
            {
                printf(" ");
            }

            if ( j <= 0 && direccion == 0)//cambiar al lado derecho de la piramide
            {
                printf("  ");
                direccion = 1;
                j = altura;
            }
        }
        direccion = 0;
        printf("\n");
    }
}