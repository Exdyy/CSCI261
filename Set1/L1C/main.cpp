/* CSCI 261: Assignment 1: Lab 1C - Random Generation and Classification
 *
 * Author: Nick Willis
 * Resources used:
 *     // list here any outside assistance you used/received while following the
 *     // CS@Mines Collaboration Policy and the Mines Academic Code of Honor
 *     // https://youtu.be/KJgsSFOSQv0 - C++ tutorial video
 *     // In class lectures
 *
 * XXXXXXXX (Detailed description)
 * This program accepts user input for a minimum and maximum value. Each quartile between the minimum and maximum value is calculated, and then
 * a random value within the range is generated. The random value is compared to the different quartile values to determine which quartile the random
 * number falls into within the range between min and max numbers input. A message is then printed in the console telling the user what the random
 * value is, as well as which quartile it falls into.
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