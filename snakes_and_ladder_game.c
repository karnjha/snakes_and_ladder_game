#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int dice;
int currentPos1 = 0;
int currentPos2 = 0;

int rollDice() {
    return (rand() % 6) + 1;
}

void displayBoard(int currentPosition, const char player[]) {
    int i, j, t, c;
	int shift = 0;
	int diceResult;

    if (currentPosition == 100) {
        printf("***** Congratulations *****\n\n\nPlayer %s wins\n", player);
        exit(0);
    }

    for (i = 10; i > 0; i--) {
        t = i - 1;
        if ((shift % 2) == 0) {
            c = 0;
            for (j = 10; j >= 1; j--) {
                diceResult = (i * j) + (t * c++);
                if (currentPosition == diceResult)
                    printf("%s\t", player);
                else
                    printf("%d\t", diceResult);
            }
            shift++;
        } else {
            c = 9;
            for (j = 1; j <= 10; j++) {
                diceResult = (i * j) + (t * c--);
                if (currentPosition == diceResult)
                    printf("%s\t", player);
                else
                    printf("%d\t", diceResult);
            }
            shift++;
        }
        printf("\n\n");
    }
    printf("--------------------------------------------------------------------------\n");
}

void player1() {
    int playAgain = 1;
    while (playAgain) {
        dice = rollDice();
        printf("\t\t\t\tDice = %d\n\n", dice);
        currentPos1 += dice;
        if (currentPos1 < 101) {
          
            if (currentPos1 == 99) currentPos1 = 1;  
            else if (currentPos1 == 65) currentPos1 = 40;  
            else if (currentPos1 == 25) currentPos1 = 9;  
            else if (currentPos1 == 70) currentPos1 = 93;  
            else if (currentPos1 == 60) currentPos1 = 83;  
            else if (currentPos1 == 13) currentPos1 = 42;  
            displayBoard(currentPos1, "$P1$");
        } else {
            currentPos1 -= dice;
            printf("Range exceeded for Player 1.\n");
            displayBoard(currentPos1, "$P1$");
        }
        printf("Player 2 position is %d\n", currentPos2);

        if (dice == 6) {
            printf("You rolled a 6! You get another chance to play.\n");
            printf("Press Enter to roll again...");
            getchar();  
            getchar();  
        } else {
            playAgain = 0;  
        }
    }
}

void player2() {
    int playAgain = 1;
    while (playAgain) {
        dice = rollDice();
        printf("\t\t\t\tDice = %d\n\n", dice);
        currentPos2 += dice;
        if (currentPos2 < 101) {
        
            if (currentPos2 == 99) currentPos2 = 1;  
            else if (currentPos2 == 65) currentPos2 = 40;  
            else if (currentPos2 == 25) currentPos2 = 9;  
            else if (currentPos2 == 70) currentPos2 = 93;  
            else if (currentPos2 == 60) currentPos2 = 83; 
            else if (currentPos2 == 13) currentPos2 = 42;  
            displayBoard(currentPos2, "$P2$");
        } else {
            currentPos2 -= dice;
            printf("Range exceeded for Player 2.\n");
            displayBoard(currentPos2, "$P2$");
        }
        printf("Player 1 position is %d\n", currentPos1);


        if (dice == 6) {
            printf("You rolled a 6! You get another chance to play.\n");
            printf("Press Enter to roll again...");
            getchar();
            getchar(); 
        } else {
            playAgain = 0;
        }
    }
}

int main() {
    int choice;
    printf("** SNAKE AND LADDER GAME ** \nCoded By Aditya Gokarn \n");

    srand(time(0));

    while (1) {
        printf("Snakes: 99 to 1, 65 to 40, 25 to 9.\nLadders: 13 to 42, 60 to 83, 70 to 93.\n");
        printf("Choose your option--\n");
        printf("1. Player 1 plays\n");
        printf("2. Player 2 plays\n");
        printf("3. Exit\n");
        scanf(" %d", &choice);
        getchar();  

        switch (choice) {
            case 1:
                player1();
                break;

            case 2:
                player2();
                break;

            case 3:
                exit(0);
                break;

            default:
                printf("Incorrect choice. Try Again.\n");
        }
    }
    return 0;
}

