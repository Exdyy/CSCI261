#include "word_functions.h"
#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <fstream>

using namespace std;

using namespace std;
string fileName;
string word;
ifstream input;
vector<string> wordsInFile;
string punc;

string prompt_user_for_filename()
{
    cout << "Please enter a file name: ";
    cin >> fileName;
    cout << endl;

    return fileName;
}

bool open_file(ifstream& input, string fileName)
{
    input.open(fileName);
    if (input.fail())
    {
        cout << "Error opening file: " << fileName << endl;
        return false;
    } else
    {
        cout << "File: " << fileName << " - OPEN" << endl;
        return true;
    }
}

vector<string> read_words_from_file(ifstream& input)
{

    string temp;
    while (getline(input, temp))
    {
       stringstream lineReader (temp);
       while (lineReader >> word)
       {
           wordsInFile.push_back(word);
       }
       

    }
    return wordsInFile;
}

void remove_punctuation(vector<string> allWords, string punc)
{
    for (unsigned int i = 0; i < allWords.size(); i++){
        for (unsigned int j = 0; j < punc.length(); j++){
            if (allWords[i].find(punc[j]) != string::npos){
                int found = (allWords[i].find(punc[j]));
                allWords[i].erase(found);
                cout << allWords[i] << endl;
            } else {
                break;
            }


        }
    }
    
}


void capitalize_words(vector<string>);

vector<string> filter_unique_words(vector<string>);

void count_letters(unsigned int[26], vector<string>);

void print_letter_counts(unsigned int[26]);
