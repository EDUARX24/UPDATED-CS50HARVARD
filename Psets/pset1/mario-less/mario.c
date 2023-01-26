#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int alt;

    do
    {
        alt = get_int("Ingrese la altura: ");

    }
    while (alt < 1 || alt > 8);

    for (int rs = 0; rs < alt; rs++)
    {

        for (int c = 0; c < alt; c++)
        {

            if (rs + c < alt - 1)
            {

                printf(" ");
            }
            else
            {
                printf("#");
            }
        }
        printf("\n");
    }

}
