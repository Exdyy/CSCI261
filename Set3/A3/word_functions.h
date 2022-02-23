#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <fstream>

using namespace std;

string prompt_user_for_filename();

bool open_file(ifstream&, string);

vector<string> read_words_from_file(ifstream&);

void remove_punctuation(vector<string>&, string);
 
void capitalize_words(vector<string>&);

vector<string> filter_unique_words(vector<string>);

void count_letters(unsigned int[26], vector<string>);

void print_letter_counts(unsigned int[26]);