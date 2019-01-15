#include <stdio.h>
#include <math.h>

int main(void)
{
    float change;
    int a = 0, b = 0, c = 0, d = 0;

    // this prompts the user to give an input which can have floating point.
    do{
        printf("Change owed: ");
        while (scanf("%f", &change) != 1)
        {
            printf("Change owed: ");
            while(getchar() != '\n');            
        }
    }
    while(change < 0);
    
    // converting dollars i.e, float into coins i.e, int
    int cents = round(change * 100);
    
    
    // logic
    // checks the input, if greater or equal to 25, then it divides it from 25 else the loop breaks.
    while (cents >= 25)
    {
        a = cents / 25;
        break;
    }

    // checks the previous result (a), if greater or equal to 10 and smaller than 25, then it divides it from 10 else the loop breaks.
    while ((cents % 25) >= 10 && (cents % 25) < 25)
    {
        b = (cents % 25) / 10;
        break;
    }

    // checks the previous result (b), if greater or equal to 5 and smaller than 10, then it divides it from 5 else the loop breaks.
    while (((cents % 25) % 10) >= 5 && ((cents % 25) % 10) < 10)
    {
        c = ((cents % 25) % 10) / 5;
        break;
    }

    // checks the previous result (c), if less than 5, then it divides it from 1 else the loop breaks.
    while ((((cents % 25) % 10) % 5) < 5)
    {
        d = (((cents % 25) % 10) % 5) / 1;
        break;
    }

    // this prints the final output.
    printf("%i\n", a + b + c + d);
    return 0;
}
