#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <fstream>

using namespace std;
/**
 * @brief Prompt user for name of file to open.
 * 
 * @return String containing the name of file
 */
string prompt_user_for_filename();

/**
 * @brief Open file using filename provided by user as an ifstream object. 
 * 
 * @param input ifstream to read from file
 * @param fileName string containing file name and extension
 * @return Boolean false if file is not successfully opened. Boolean true if file is successfully opened.
 * 
 */
bool open_file(ifstream&, const string);

/**
 * @brief Read all words from file and store in a vector of strings.
 * 
 * @param input ifstream object to read in words from file.
 * 
 * @return A vector of strings that contains every word in the file.
 */
vector<string> read_words_from_file(ifstream&);

/**
 * @brief Removes all punctuation from every word in the file.
 * 
 * @param allWords Vector of strings containing all words in file.
 * @param punc String containing all special characters that are considered punctuation
 */
void remove_punctuation(vector<string>&, string);

/**
 * @brief Capitalize every word in file.
 * 
 * @param allWords Vector of strings containing all words in file
 */
void capitalize_words(vector<string>&);

/**
 * @brief Counts number of unique words within the file.
 * 
 * @param allWords Vector of strings containing all words in file.
 * @return New vector of strings. Contains only one of each word used in file.
 */
vector<string> filter_unique_words(const vector<string>);

/**
 * @brief Counts number of times each individual letter is used within file.
 * 
 * @param letters Array of integers associated with the occurences of each letter in the alphabet.
 * @param allWords Vector of strings containing all words in file.
 */
void count_letters(unsigned int[26], const vector<string>);

/**
 * @brief Prints count for each indidual letter to console.
 * 
 * @param letters Array of integers associated with the occurences of each letter in the alphabet.
 */
void print_letter_counts(unsigned int[26]);

/**
 * @brief Checks for which letter is used most/least frequently in the file. Calculates percentage min/max letter is used. Prints min/max letter statistics to console.
 * 
 * @param letters Array of integers associated with the occurences of each letter in the alphabet.
 */
void print_max_min_letter(unsigned int[26]);