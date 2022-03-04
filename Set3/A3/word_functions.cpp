/* CSCI 261: Assignment 3: A3 - Green Eggs and Ham
 *
 * Author: Nick Willis
 * Resources used (Office Hours, Tutoring, Other Students, etc & in what capacity):
 *     // list here any outside assistance you used/received while following the
 *     // CS@Mines Collaboration Policy and the Mines Academic Code of Honor
 *     // In class lectures
 *     // cplusplus.com for proper syntax and functionality of libraries
 *     // stackoverflow.com for troubleshooting and help with syntax errors
 *
 * This program reads in an input file, removes all punctuation characters, capitalizes all characters, counts number of unique words in input file's text,
 * and then prints statistics to the user's console about various things
 */
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
    cout << "Please enter a file name: ";       //Prompt user for filename
    cin >> fileName;                            //Store user input into fileName
    cout << endl;

    return fileName;                            //Return string fileName
}

bool open_file(ifstream& input, const string FILENAME){
    
    input.open(FILENAME);                                       //Open inpuut file
    if (input.fail()){
        cout << "Error opening file: " << FILENAME << endl;     //Check if input file opens succesfully, alert user if it doesn't
        return false;
    } else{
        cout << "File: " << FILENAME << " - OPEN" << endl;      //Alert user of successful file opening
        return true;
    }
}

vector<string> read_words_from_file(ifstream& input){
    string word;
    vector<string> wordsInFile;
    string temp;
    while (getline(input, temp)){           //Pull each line in file, store in temp
       stringstream lineReader (temp);      //Turn string temp (each line of text) into stream of strings
       while (lineReader >> word){          //Pull each word from line, store in word
           wordsInFile.push_back(word);     //Append word to vector wordsInFile
       }
       

    }
    return wordsInFile;                     //Return final vector containing all words in file
}

void remove_punctuation(vector<string> &allWords, string punc){
    for (unsigned int i = 0; i < allWords.size(); i++){                     //Loop through each element of vector containing all words
        unsigned int j = 0;
        for (j = 0; j < punc.length(); j++){
            if (allWords[i].find(punc[j]) != string::npos){                 //Nested if statements remove punctuation from each word, up to three punctuations per word
                int found = allWords[i].find(punc[j]);                      //P.S. I know there is a cleaner way to do this that allows for any amount of punctuation, but I'm tired and do not want to rewrite this
                allWords[i] = allWords[i].erase(found, 1);
                if (allWords[i].find(punc[j], found) != string::npos){
                    int found2 = allWords[i].find(punc[j], found);
                    allWords[i] = allWords[i].erase(found2, 1);
                    if (allWords[i].find(punc[j], found2) != string::npos){
                        int found3 = allWords[i].find(punc[j], found2);
                        allWords[i] = allWords[i].erase(found3, 1);
                    }
                }
            }
        }
    }
}

void capitalize_words(vector<string> &allWords){                    //Nested for loop to access every word, and every character in each word, then capitalizes all letters
    for (unsigned int i = 0; i < allWords.size(); i++){
        for (unsigned int j = 0; j < allWords[i].length(); j++){
            allWords[i][j] = toupper(allWords[i][j]);
            }
    }
}

vector<string> filter_unique_words(const vector<string> ALL_WORDS){
    vector<string> uniques;
    uniques.push_back(ALL_WORDS[0]);                                //Initialize uniques vector with first word of file, which must be unique
    for (unsigned int i = 0; i < ALL_WORDS.size(); i++){            //Parse through every word within vector of all words
        unsigned int j = 0;
        bool isUnique = true;                                       //Boolean variable to determine if a word is or is not unique by end of ALL_WORDS vector
        for (j = 0; j < uniques.size(); j++){                       //Parse through every word that has been added to the vector of unique words
            if (ALL_WORDS[i] == uniques[j]){                        //If selected word is already in uniques, boolean retains false value, and word is not added to uniques
                isUnique = false;
                break;
            } else {
                isUnique = true;                                    //If selected word is not in uniques vector, boolean is switched to true
            }
        }
        if (isUnique == true){                                      //If boolean is true, word is added to uniques vector
            uniques.push_back(ALL_WORDS[i]);
        }
    }
    return uniques;                                                 //Returns final vector containing all unique words in text
}

void count_letters(unsigned int letters[26], const vector<string> ALL_WORDS){
    for (unsigned int i = 0; i < ALL_WORDS.size(); i++){            //Parse through each word in text
        for (unsigned int j = 0; j < ALL_WORDS[i].length(); j++){   //Parse through each letter of selected word
            switch (ALL_WORDS[i][j]){                               //Switch statement that adds one to the selected letter's current counter
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

    cout << "A" << right << setw(6) << letters[0] << endl;          //Prints each letter, as well as its associated count held in the letters[] array
    cout << "B" << right << setw(6) << letters[1] << endl;
    cout << "C" << right << setw(6) << letters[2] << endl;
    cout << "D" << right << setw(6) << letters[3] << endl;
    cout << "E" << right << setw(6) << letters[4] << endl;
    cout << "F" << right << setw(6) << letters[5] << endl;
    cout << "G" << right << setw(6) << letters[6] << endl;
    cout << "H" << right << setw(6) << letters[7] << endl;
    cout << "I" << right << setw(6) << letters[8] << endl;
    cout << "J" << right << setw(6) << letters[9] << endl;
    cout << "K" << right << setw(6) << letters[10] << endl;
    cout << "L" << right << setw(6) << letters[11] << endl;
    cout << "M" << right << setw(6) << letters[12] << endl;
    cout << "N" << right << setw(6) << letters[13] << endl;
    cout << "O" << right << setw(6) << letters[14] << endl;
    cout << "P" << right << setw(6) << letters[15] << endl;
    cout << "Q" << right << setw(6) << letters[16] << endl;
    cout << "R" << right << setw(6) << letters[17] << endl;
    cout << "S" << right << setw(6) << letters[18] << endl;
    cout << "T" << right << setw(6) << letters[19] << endl;
    cout << "U" << right << setw(6) << letters[20] << endl;
    cout << "V" << right << setw(6) << letters[21] << endl;
    cout << "W" << right << setw(6) << letters[22] << endl;
    cout << "X" << right << setw(6) << letters[23] << endl;
    cout << "Y" << right << setw(6) << letters[24] << endl;
    cout << "Z" << right << setw(6) << letters[25] << endl;
    
}

void print_max_min_letter(unsigned int letters[26]){

    unsigned int max = letters[0];
    unsigned int min = letters[0];
    unsigned int maxIndex = 0;
    unsigned int minIndex = 0;
    float totalLetters = 0;
    string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    for (unsigned int i = 0; i < 26; i++){
        if (letters[i] > max){                          //Loop through to find the maximum integer stored in letters[] array
            max = letters[i];
            maxIndex = i;
        }
        if (letters[i] < min){                          //Loop through to find the minimum integer stored in letters[] array
            min = letters[i];
            minIndex = i;
        }
        totalLetters += letters[i];
    }
    float fMax = max;
    float fMin = min;
    float maxFreq = 100 * (fMax / totalLetters);        //Calculate percentage of maximum letter's occurence throughout file
    float minFreq = 100 * (fMin / totalLetters);        //Calculate percentage of minimum letter's occurence throughout file
    
    cout << right << setw(23) << "Least Frequent Letter: " << alphabet[minIndex] << ' ';        //Prints and formats minimum/maximum letter statistic to user's console
    cout << right << setw(6) << min << ' ';
    cout << '(' << right << setw(7) << fixed << setprecision(3) << minFreq << "%)" << endl; 
    cout << right << setw(23) << "Most Frequent Letter: " << alphabet[maxIndex] << ' ';
    cout << right << setw(6) << max << ' ';
    cout << '(' << right << setw(7) << fixed << setprecision(3) << maxFreq << "%)" << endl; 
}