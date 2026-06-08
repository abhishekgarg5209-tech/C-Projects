#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int randomNumber, guessed_number;
    int no_of_guesses = 0;

    srand(time(NULL));
    randomNumber = rand() % 100 + 1;

    printf("=================================\n");
    printf("    NUMBER GUESSING GAME\n");
    printf("=================================\n");
    printf("I have selected a number between 1 and 100.\n");
    printf("Try to guess it!\n\n");

    do
    {
        printf("Enter your guess: ");
        scanf("%d", &guessed_number);

        no_of_guesses++;

        if (guessed_number > randomNumber)
        {
            printf("Too high! Try a lower number.\n\n");
        }
        else if (guessed_number < randomNumber)
        {
            printf("Too low! Try a higher number.\n\n");
        }
        else
        {
            printf("\nCongratulations! You guessed the number.\n");
        }

    } while (guessed_number != randomNumber);

    printf("You guessed the number in %d attempts.\n", no_of_guesses);

    return 0;
}