#include "LinkedList.hpp"
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

string prompt_user_for_filename();
bool open_file(ifstream&, const string);
void read_file(ifstream&);
void print_results();