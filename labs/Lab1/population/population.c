#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    // TODO: Prompt for start size
    int pin;
    int years=0;
    do{
        pin = get_int("start size: ");
    }while(pin < 9);

    // TODO: Prompt for end size
    int pfin;
    do{
        pfin = get_int("end size: ");
    }while(pfin < pin);



    // TODO: Calculate number of years until we reach threshold
    int n = pin;

    if(pfin == pin)
    {
        printf("Years: 0");
    }
    do{
        n = round(n + (n / 3) - (n / 4));
        years++;
    }while(n < pfin);

    // TODO: Print number of years
    printf("Years: %i\n", years);
}