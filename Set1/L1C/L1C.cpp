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

#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>
#include <random>
#include <ctime>

int main(){
    float minVal, maxVal, randVal;

    printf("\nPlease enter the minimum allowable value: ");
    scanf("%f",&minVal);
    printf("Please enter the maximum allowable value: ");
    scanf("%f",&maxVal);

    srand(time(0));
    randVal = rand() / (float)RAND_MAX * (maxVal - minVal) + minVal;
;
    printf("A random value is: %f\n", randVal);

    float quart1 = (maxVal - minVal) / 4 + minVal;
    float quart2 = 2 * (maxVal - minVal) / 4 + minVal;
    float quart3 = 3 * (maxVal - minVal) / 4 + minVal;
    if (randVal <= quart1) {
        printf("This is in the first quartile.\n");
    } else if (randVal <= quart2) {
        printf("This is in the second quartile.\n");
    } else if (randVal <= quart3) {
        printf("This is in the third quartile.\n");
    } else {
        printf("This is in the fourth quartile.\n");
    }


    return(0);
}