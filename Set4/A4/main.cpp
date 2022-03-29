#include "fileFunctions.h"

int main() {
    string FILENAME = prompt_user_for_filename();
    ifstream input;
    if (open_file(input, FILENAME) == false) {
        cout << "Could not open file. Shutting down..." << endl;
        return -1;
    }
    read_file(input);
    print_results();

}