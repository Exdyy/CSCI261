#include "word_functions.h"
#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

string prompt_user_for_filename(){
    string fileName;
    cout << "Please enter a file name: ";
    cin >> fileName;
    cout << endl;

    return fileName;
}

bool open_file(ifstream& input, const string FILENAME){
    
    input.open(FILENAME);
    if (input.fail()){
        cout << "Error opening file: " << FILENAME << endl;
        return false;
    } else{
        cout << "File: " << FILENAME << " - OPEN" << endl;
        return true;
    }
}

vector<string> read_words_from_file(ifstream& input){
    string word;
    vector<string> wordsInFile;
    string temp;
    while (getline(input, temp)){
       stringstream lineReader (temp);
       while (lineReader >> word){
           wordsInFile.push_back(word);
       }
       

    }
    return wordsInFile;
}

void remove_punctuation(vector<string> &allWords, string punc){
    for (unsigned int i = 0; i < allWords.size(); i++){
        unsigned int j = 0;
        for (j = 0; j < punc.length(); j++){
            if (allWords[i].find(punc[j]) != string::npos){
                int found = allWords[i].find(punc[j]);
                allWords[i] = allWords[i].erase(found, 1);
            }
        }
    }
}

void capitalize_words(vector<string> &allWords){
    for (unsigned int i = 0; i < allWords.size(); i++){
        for (unsigned int j = 0; j < allWords[i].length(); j++){
            allWords[i][j] = toupper(allWords[i][j]);
            }
    }
}

vector<string> filter_unique_words(const vector<string> ALL_WORDS){
    vector<string> uniques;
    uniques.push_back(ALL_WORDS[0]);
    for (unsigned int i = 0; i < ALL_WORDS.size(); i++){
        unsigned int j = 0;
        bool isUnique = true;
        for (j = 0; j < uniques.size(); j++){
            if (ALL_WORDS[i] == uniques[j]){
                isUnique = false;
                break;
            } else {
                isUnique = true;
            }
        }
        if (isUnique == true){
            uniques.push_back(ALL_WORDS[i]);
        }
    }
    return uniques;
}

void count_letters(unsigned int letters[26], const vector<string> ALL_WORDS){
    for (unsigned int i = 0; i < ALL_WORDS.size(); i++){
        for (unsigned int j = 0; j < ALL_WORDS[i].length(); j++){
            switch (ALL_WORDS[i][j]){
                case 'A':
                    letters[0]++;
                    break;
                case 'B':
                    letters[1]++;
                    break;
                case 'C':
                    letters[2]++;
                    break;
                case 'D':
                    letters[3]++;
                    break;
                case 'E':
                    letters[4]++;
                    break;
                case 'F':
                    letters[5]++;
                    break;
                case 'G':
                    letters[6]++;
                    break;
                case 'H':
                    letters[7]++;
                    break;
                case 'I':
                    letters[8]++;
                    break;
                case 'J':
                    letters[9]++;
                    break;
                case 'K':
                    letters[10]++;
                    break;
                case 'L':
                    letters[11]++;
                    break;
                case 'M':
                    letters[12]++;
                    break;
                case 'N':
                    letters[13]++;
                    break;
                case 'O':
                    letters[14]++;
                    break;
                case 'P':
                    letters[15]++;
                    break;
                case 'Q':
                    letters[16]++;
                    break;
                case 'R':
                    letters[17]++;
                    break;
                case 'S':
                    letters[18]++;
                    break;
                case 'T':
                    letters[19]++;
                    break;
                case 'U':
                    letters[20]++;
                    break;
                case 'V':
                    letters[21]++;
                    break;
                case 'W':
                    letters[22]++;
                    break;
                case 'X':
                    letters[23]++;
                    break;
                case 'Y':
                    letters[24]++;
                    break;
                case 'Z':
                    letters[25]++;
                    break;

            }
        }
    }
}

void print_letter_counts(unsigned int letters[26]){

    cout << "A" << right << setw(10) << letters[0] << endl;
    cout << "B" << right << setw(10) << letters[1] << endl;
    cout << "C" << right << setw(10) << letters[2] << endl;
    cout << "D" << right << setw(10) << letters[3] << endl;
    cout << "E" << right << setw(10) << letters[4] << endl;
    cout << "F" << right << setw(10) << letters[5] << endl;
    cout << "G" << right << setw(10) << letters[6] << endl;
    cout << "H" << right << setw(10) << letters[7] << endl;
    cout << "I" << right << setw(10) << letters[8] << endl;
    cout << "J" << right << setw(10) << letters[9] << endl;
    cout << "K" << right << setw(10) << letters[10] << endl;
    cout << "L" << right << setw(10) << letters[11] << endl;
    cout << "M" << right << setw(10) << letters[12] << endl;
    cout << "N" << right << setw(10) << letters[13] << endl;
    cout << "O" << right << setw(10) << letters[14] << endl;
    cout << "P" << right << setw(10) << letters[15] << endl;
    cout << "Q" << right << setw(10) << letters[16] << endl;
    cout << "R" << right << setw(10) << letters[17] << endl;
    cout << "S" << right << setw(10) << letters[18] << endl;
    cout << "T" << right << setw(10) << letters[19] << endl;
    cout << "U" << right << setw(10) << letters[20] << endl;
    cout << "V" << right << setw(10) << letters[21] << endl;
    cout << "W" << right << setw(10) << letters[22] << endl;
    cout << "X" << right << setw(10) << letters[23] << endl;
    cout << "Y" << right << setw(10) << letters[24] << endl;
    cout << "Z" << right << setw(10) << letters[25] << endl;
    
}

void print_max_min_letter(unsigned int letters[26]){

    unsigned int max = letters[0];
    unsigned int min = letters[0];
    unsigned int maxIndex = 0;
    unsigned int minIndex = 0;
    float totalLetters = 0;
    string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    for (unsigned int i = 0; i < 26; i++){
        if (letters[i] > max){
            max = letters[i];
            maxIndex = i;
        }
        if (letters[i] < min){
            min = letters[i];
            minIndex = i;
        }
        totalLetters += letters[i];
    }
    float fMax = max;
    float fMin = min;
    float maxFreq = 100 * (fMax / totalLetters);
    float minFreq = 100 * (fMin / totalLetters);
    
    cout << right << setw(23) << "Least Frequent Letter: " << alphabet[minIndex] << ' ';
    cout << right << setw(10) << min << ' ';
    cout << '(' << right << setw(7) << fixed << setprecision(3) << minFreq << "%)" << endl; 
    cout << right << setw(23) << "Most Frequent Letter: " << alphabet[maxIndex] << ' ';
    cout << right << setw(10) << max << ' ';
    cout << '(' << right << setw(7) << fixed << setprecision(3) << maxFreq << "%)" << endl; 
}