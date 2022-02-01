#include <iostream> 
#include <fstream>

using namespace std;

int main() {
    ofstream decipheredMessage("decipheredMessage.txt");
    ifstream secretMessage("secretMessage.txt");
    char c;
    
    if (!secretMessage) {
        cerr << "Error opening input file";
        return -1;
    }


    if (secretMessage.is_open()) {
        printf("DEBUG: secretMessage is open\n");
        while (!secretMessage.eof()) {
            secretMessage.get(c);
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
                cout << "DEBUG: modified c = " << char(c + 2) << '\n';
                decipheredMessage << (char)(c + 1);
                break;

            }
        }

    }

        secretMessage.close();
        decipheredMessage.close();


        return 0;
}