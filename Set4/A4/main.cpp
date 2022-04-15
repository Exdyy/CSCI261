#include "fileFunctions.h"

int main() {
    vector<string> allComments;
    vector<float> allVertices;
    vector<int> allFaces;
    LinkedList<string> stringList;
    LinkedList<vector<float>> vertexList;
    LinkedList<vector<int>> faceList;

    string FILENAME = prompt_user_for_filename();
    ifstream input;
    if (open_file(input, FILENAME) == false) {
        cout << "Could not open file. Shutting down..." << endl;
        return -1;
    }
    vector<int> counts = read_file(input, *&allComments, *&allVertices, *&allFaces, *&stringList, *&vertexList, *&faceList);
    print_results(counts, faceList, allFaces, allVertices);

    return 0;
}