#include <cs50.h>
#include <stdio.h>
#include <math.h>


int main(void)
{
    long tarjeta = get_long("Ingrese N Tarjeta: ");
    int i = 0;
    long longitud = tarjeta;

    while(longitud > 0)
    {
        longitud = longitud / 10;
        i++;
    }

    //verificando longitud
    if( i != 13 && i != 15 && i != 16)
    {
        printf("INVALID\n");
        return 0;
    }

    int sum1 = 0, sum2 = 0, luhn = 0;
    int dgt1, dgt2, dgt3, dgt4;

    long tarjeta2 = tarjeta;

    do
    {
        dgt3 = tarjeta % 10;
        tarjeta2 = tarjeta2 / 10;
        sum1 = sum1 + dgt3;

        //remover penultimo digitos
        dgt4 = tarjeta2 % 10;
        tarjeta2 = tarjeta2 / 10;
        //agregamos dos digitos a suma2
        dgt4 = dgt4 * 2;
        dgt1 = dgt4 % 10;
        dgt2 = dgt4 / 10;
        sum2 = sum2 + dgt1 + dgt2;
    }
    while ( tarjeta2 > 0);
    luhn = sum1 + sum2;

    //verificando con luhn
    if(luhn % 10 != 0)
    {
         printf("INVALID\n");
    }

    //averiguando tipo de tarjeta
    long Digit;
    Digit = tarjeta;

    do
    {
        Digit = Digit / 10;
    }
    while (Digit > 100);

    if((Digit / 10 == 3) && (Digit % 10 == 4 || Digit % 10 == 7))
    {
        printf("AMEX\n");
    }
    else if ((Digit / 10 == 5 ) && (0 < Digit % 10 && Digit % 10 < 6))
    {
        printf("MASTERCARD\n");
    }
    else if (Digit / 10 == 4)
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }
}