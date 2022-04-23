/* CSCI 261: Assignment 6: A6 - A-MAZE-ing
 *
 * Author: Nick Willis
 * Resources used (Office Hours, Tutoring, Other Students, etc & in what capacity):
 *     // list here any outside assistance you used/received while following the
 *     // CS@Mines Collaboration Policy and the Mines Academic Code of Honor
 *     // Lecture slides, stackOverflow for fixing errors, attempted to learn from youtube videos to no avail
 * This program is supposed to read in a .maze file, and use either BFS or DFS search methods with queues/stacks, but I cannot get it to work properly and I need some amount of points, so here is my attempt.
 */

#include "Queue.hpp"
#include "Stack.hpp"
#include "maze_functions.hpp"
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

struct Position {
    int r;
    int c;
};

int main(int argc, char* argv[]) {
    // get filename to open
    string filename;
    ifstream in;
    if(argc == 1) {
        filename = prompt_user_for_filename();
    } else if(argc == 2) {
        filename = argv[1];
    } else {
        cerr << "Usage: " << argv[0] << " [filename]" << endl;
        cerr << "  filename   - optional file to open upon start" << endl;
        return -2;
    }
    int r, c;
    open_file(in, filename);
    read_file(in, r, c);
    vector<string> maze = read_file(in, r, c);
    bfs(maze);
    for (unsigned int i = 0; i < maze.size(); i++) {
        cout << maze[i] << endl;
    }

    return 0;
}
