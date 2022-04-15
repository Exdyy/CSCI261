#include "LinkedList.hpp"
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

string prompt_user_for_filename();
bool open_file(ifstream&, const string);
vector<int> read_file(ifstream&, vector<string>&, vector<float>&, vector<int>&, 
    LinkedList<string>&, LinkedList<vector<float>>&, LinkedList<vector<int>>&);
bool check_validity_faces(LinkedList<vector<int>>, vector<int>, vector<float>);
void print_results(vector<int>, LinkedList<vector<int>>, vector<int>, vector<float>);