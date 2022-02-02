/* CSCI 261: Lab 1-D: A1 -      
      .-'` /     \'-'/     \ `'-.
     /    |      |   |      |    \
    ;      \_  _/     \_  _/      ;
   |         ``         ``         |
   |                               |
    ;    .-.   .-.   .-.   .-.    ;
     \  (   '.'   \ /   '.'   )  /
      '-.;         V         ;.-'
          `                 `
 *
 * Author: Nick Willis
 * Resources used:
 *     // list here any outside assistance you used/received while following the
 *     // CS@Mines Collaboration Policy and the Mines Academic Code of Honor
 *     // https://youtu.be/KJgsSFOSQv0 - C++ tutorial video
 *
 * XXXXXXXX (Detailed description)
 * Prints out the Batman song to the console using three different looping methods (for-loop, while-loop, do while-loop)
 */
// The include section adds extra definitions from the C++ standard library.
#include <stdlib.h>
#include <stdio.h>

int main(){
    printf("First, using a for-loop:\n");
    for (int i = 0; i<4; i++){  
        printf("nana-nana\n");
    }
    printf("BATMAN\n\n");

    printf("Now, using a while loop:\n");
    int j = 0;
    while(j<4){
        printf("nana-nana\n");
        j++;
    }
    printf("BATMAN\n\n");

    printf("And finally, using a do-while loop:\n");
    int k = 0;
    do {
        printf("nana-nana\n");
        k++;
    } while (k<4);
    printf("BATMAN\n\n");




    return 0;

}