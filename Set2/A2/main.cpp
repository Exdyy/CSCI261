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
    
    ofstream grayscale("decipheredMessage.txt");
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
            switch (c) {
                case '~':
                printf("DEBUG: case ~\n");
                if ( decipheredMessage.fail() ) {
                    cerr << "Error opening output file~";
                    return -1;
                }
                decipheredMessage << ' ';
                break;

                case '\n':
                printf("DEBUG: case \\n\n");
                if ( decipheredMessage.fail() ) {
                    cerr << "Error opening output file\\n";
                    return -1;
                }
                decipheredMessage << '\n';
                break;

                default:
                printf("DEBUG: default case\n");
                if ( decipheredMessage.fail() ) {
                    cerr << "Error opening output file-d";
                    return -1;
                }
                cout << "DEBUG: modified c = " << char(c + 1) << '\n';
                decipheredMessage << (char)(c + 1);
                break;

            }
        }

    }

        originalImage.close();
        decipheredMessage.close();


        return 0;
}
}