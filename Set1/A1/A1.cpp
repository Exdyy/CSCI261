/* CSCI 261: Assignment 1: A1 - Rock Paper Scissor Throw Down!
 *
 * Author: Nick Willis
 * Resources used:
 *     // list here any outside assistance you used/received while following the
 *     // CS@Mines Collaboration Policy and the Mines Academic Code of Honor
 *     // https://youtu.be/KJgsSFOSQv0 - C++ tutorial video
 *     // Stackexchange for some syntax information for switch cases
 *
 * XXXXXXXX (Detailed description)
 * User inputs value of r (rock), p (paper), or s (scissors). Program accepts both upper and lower case, and reprompts user if 
 * invalid characters are input. A randomly generated computer response is then generated, and the player and computer choices are 
 * compared to determine win, loss, or tie. Counters are implemented for each condition. User is then prompted to enter (Y/N) to continue
 * playing or to end the game. If 'y' or 'Y' is entered, the game restarts, keeping track of # of wins/losses/ties. If 'n' or 'n' is 
 * entered, the game ends, and prints a statement of how many wins/losses/ties the user achieved. If anything other than n, N, y, or Y
 * is entered, the user is notified of an invalid response and asked to input Y/N again.
 */
// The include section adds extra definitions from the C++ standard library.

#include <iostream> // For cin, cout, etc.
#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>
#include <random>
#include <vector>


int main()
{
   char playAgain;
   int winCount = 0;
   int lossCount = 0;
   int tieCount = 0; 
while(playAgain != 'N'){ 
    /* While loop used to continue game or end the program */

   char pChoice;
   printf("\nWelcome one and all to a round of Rock, Paper, Scissors! (Enter P, R, or S)\n");
   tryAgain:
   printf("Player: ");
   scanf(" %c", &pChoice);


   /* Player entered values for rock, paper, or scissors */
   switch(pChoice){
    /* CAPITAL INPUT CASES */
    case 'R':
        printf("Player chooses Rock\n");
        break;
    case 'P':
        printf("Player chooses Paper\n");
        break;
    case 'S':
        printf("Player chooses Scissors\n");
        break;
    /* LOWERCASE INPUT CASES */
    case 'r':
        printf("Player chooses Rock\n");
        break;
    case 'p':
        printf("Player chooses Paper\n");
        break;
    case 's':
        printf("Player chooses Scissors\n");
        break;
    default:
        printf("Invalid selection, please try again.\n\n");
        goto tryAgain;
   }

    /* Computer randomly chooses rock, paper, or scissors */
    int choiceList[3] = {0,1,2};
    int randIndex = rand() % 4;
    int cChoice = choiceList[randIndex];
    /* If else statements comparing randomly generated
       Computer selection against user input to evaluate win/loss/tie.
       Counters are also implemented to track # of wins/losses/ties. */
    if (cChoice == 0) {
        printf("Computer chooses Rock\n");
        if(pChoice == 'R' || pChoice == 'r') {
            tieCount++;
            printf("You tied!\n\n");
        } else if (pChoice == 'P' || pChoice == 'p') {
            winCount++;
            printf("Paper beats rock!\n");
            printf("You win!\n\n");
        } else {
            lossCount++;
            printf("Rock beats scissors!\n");
            printf("Computer Wins!\n\n");
        }
    } else if (cChoice == 1) {
        printf("Computer chooses Paper\n");
        if(pChoice == 'R' || pChoice == 'r') {
            lossCount++;
            printf("Paper beats rock!\n");
            printf("You lose!\n\n");
        } else if (pChoice == 'P' || pChoice == 'p') {
            tieCount++;
            printf("You tie!\n\n");
        } else {
            winCount++;
            printf("Scissors beats paper!\n");
            printf("You Win!\n\n");
            }
    } else {
        printf("Computer chooses Scissors\n");
        if(pChoice == 'R' || pChoice == 'r') {
            winCount++;
            printf("Rock beats scissors!\n");
            printf("You win!\n\n");
        } else if (pChoice == 'P' || pChoice == 'p') {
            lossCount++;
            printf("Scissors beats paper!\n");
            printf("Computer Wins!\n\n");
        } else {
            tieCount++;
            printf("You tie!\n\n");
            }
            
        }
    /* User input to determine whether to end or continue game*/

    invalidSelection:
    printf("Do you want to play again? (Y/N) ");
    scanf(" %c", &playAgain);
    switch (playAgain) {
        case 'Y':
            break;
        case 'y':
            break;
        case 'N':
            break;
        case 'n':
            playAgain = 'N';
            break;
        default:
            printf("Invalid selection. Please try again.\n");
            goto invalidSelection;


    } 
    
   }
   /* Outputs number of games won, lost, or tied into the console */

   printf("You won %d game(s), lost %d game(s), and tied %d game(s).", winCount, lossCount, tieCount);
    return 0;
}

