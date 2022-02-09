int main(){

#include <iostream> 
#include <fstream>
#include <string>
#include <stdlib.h>
using namespace std;

string imageSelection;
int userSelection;

int main() {
    printf("which image to load?\n");
    printf("1: Brick\n");
    printf("2: Wallpaper\n");
    printf("3: Private\n");
    invalidSelection:
    cscan("%d", &userSelection);

    switch(userSelection) {
        case 1: imageSelection = "brick";
        case 2: imageSelection = "wallpaper";
        case 3: imageSelection = "private";
        default:
            printf("Invalid selection. Please try again")
            goto invalidSelection;
    }
    
    ofstream grayscale("grayscale_%s.txt", imageSelection);
    ifstream originalImage("%s.txt", imageSelection);
    char c;
    
    if (!originalImage) {
        cerr << "Error opening input file";
        return -1;
    }


    if (originalImage.is_open()) {
        printf("DEBUG: originalImage is open\n");
        while (!originalImage.eof()) {
            originalImage.get(c);
            printf("c: %c\n", c);

            }
        }

    }

        originalImage.close();
        decipheredMessage.close();


        return 0;
}
}