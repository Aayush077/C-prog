// WAP to pick random number.
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
    srand(time(0));

    int RanNum = rand() % 100 + 1;
    int Guesses = 0, guessed;

    do
    {
        printf("Guess the number: ");
        scanf("%d", &guessed);
        if (guessed > RanNum)
        {
            printf("Enter a lower number\n");
        }
        else
        {
            printf("Enter a higher number\n");
        }
        Guesses++;
    } while (guessed != RanNum);

    printf("You guessed the number in %d attempts\n", Guesses);
}
