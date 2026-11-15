#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define Length 4
#define MAX_ATTEMPTS 6

int main(){
    int number[Length];
    int guess[Length];
    int result[Length];
    int used[Length];
    char input[20];
    int i, j, attempts, green ,valid ;
    int won = 0 ;

    srand(time(NULL));
    for (i = 0; i < Length; i++) {
        number[i] = rand() % 10;
    }

    printf("Welcome to the Number Guessing Game!\n");
    printf("You have %d attempts to guess the %d-digit number.\n", MAX_ATTEMPTS, Length);
    printf("green = correct digit in the correct position, yellow = correct digit in the wrong position.\n");
    printf("white= digit not in number.\n");

    for (attempts = 1; attempts <= MAX_ATTEMPTS && !won ; attempts++) {
        do {
            valid = 1;
        printf("Attempt %d %d : Enter your guess: ", attempts , MAX_ATTEMPTS);
        scanf("%19s", input);

        if (strlen(input) != Length) {
            valid = 0;
        } else {
            for (i = 0; i < Length; i++) {
                if (!isdigit(input[i])) {
                    valid = 0;
                }
            }
        }
        if (!valid) {
            printf("Invalid input. Please enter a 4 -digit number.\n", Length);
        }
        } while (!valid);

        for (i = 0; i < Length; i++) {
            guess[i] = input[i] - '0';
        }

        for (i = 0; i < Length; i++) {
            result[i] = 0; 
            used[i] = 0;
        }
        
        green = 0;
        for (i = 0; i < Length; i++) {
            if (guess[i] == number[i]) {
                result[i] = 2; 
                used[i] = 1; 
                green++;
            }
        }

        for (i = 0; i < Length; i++) {
            if (result[i] == 2) continue; 
                for (j = 0; j < Length; j++) {
                    if (!used[j] && guess[i] == number[j]) {
                        result[i] = 1; 
                        used[j] = 1; 
                        break;
                    }
                }
            }
        printf("           ");
        for (i = 0; i < Length; i++) {
            if (result[i] == 2) 
                printf("\033[4;32m%d\033[0m ", guess[i]);
             else if (result[i] == 1) 
                printf("\033[4;33m%d\033[0m ", guess[i]);
             else 
                printf("%d", guess[i] );
        }
        printf("\n\n");

        if (green == Length) {
            won = 1;
        }
    }

        if(won) {
             printf("Congratulations! You've guessed the number!\n");
           }   
           else { printf("game over! The correct number was: ");}

           for (i = 0; i < Length; i++) {
            printf("%d", number[i]);
           }
            printf("\n");

            return 0;
        }