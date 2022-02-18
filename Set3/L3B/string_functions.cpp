#include "string_functions.h"

int string_length(const string STR)  {
    int result = -1;
    result = STR.length();

    return result;
}

char string_char_at(const string STR, const int IDX) {
    char result = STR.at(IDX);

    return result;
}

string string_append(const string LEFT, const string RIGHT)  {
    string result = LEFT + RIGHT;
    
    return result;
}

string string_insert(const string STR, const string TO_INSERT, const int IDX) {
    string result = STR;
    result.insert(IDX, TO_INSERT);
    
    return result;
}

int string_find(const string STR, const char C)  {
    int result = STR.find(C);
    
    return result;
}

string string_substring(const string STR, const int IDX, const int LEN) {
    string result = STR.substr(IDX, LEN);
    
    return result;
}

string string_replace(const string STR, const string TEXT_TO_REPLACE, const string REPLACE_WITH) {
    string result = STR;
    if (result.find(TEXT_TO_REPLACE) != string::npos) {
        result.replace(result.find(TEXT_TO_REPLACE), TEXT_TO_REPLACE.size(), REPLACE_WITH);
    }

    return result;
}

string string_first_word(const string STR)  {
    string result = STR.substr(0, STR.find(' '));

    return result;
}

string string_remove_first_word(const string STR)  {
    
    string result = STR;
    string temp;
    stringstream stream (result);
    vector<string> words = {};
    if (result.find(" ") != string::npos){
        while (stream >> temp){
            words.push_back(temp);
        }
        result.clear();
        words.erase(words.begin());
        for (unsigned int i = 0; i < words.size() - 1; i++){
            result += words[i] + " ";
        }
        result += words[words.size() - 1];
    } else {
        result.clear();
    }

    return result;
}

string string_second_word(const string STR)  {

    string result = STR;
    string temp;
    stringstream stream (result);
    vector<string> words;

    while (stream >> temp){
        words.push_back(temp);
    }
    if (words.size() > 1){
        result = words[1];
    } else {
        result.clear();
    }

    return result;
}

string string_third_word(const string STR)  {

    string result = STR;
    string temp;
    stringstream stream (result);
    vector<string> words;
    while (stream >> temp){
        words.push_back(temp);
    }
    if (words.size()>2){
        result = words[2];
    } else {
        result.clear();
    }

    return result;
}

string string_nth_word(const string STR, const int N)  {
    
    string result = STR;
    string temp;
    stringstream stream (result);
    vector<string> words;
    while (stream >> temp){
        words.push_back(temp);
    }
    result = words[N-1];

    return result;
}

string string_substitute(const string STR, const char TARGET, const char REPLACEMENT)  {
    string result = STR;
    for (unsigned int i = 0; i < STR.length(); i++) {
        if (result[i] == TARGET){
            result[i] = REPLACEMENT;
        }
    }

    return result;
}

string string_to_lower(const string STR) {

    string result = STR;
    for (unsigned int i = 0; i < result.length(); i++) {
        result[i] = tolower(result[i]);
    }

    return result;
}

string string_to_upper(const string STR) {

    string result = STR;
    for (unsigned int i = 0; i < result.length(); i++){
        result[i] = toupper(result[i]);
    }

    return result;
}

int string_compare(const string LHS, const string RHS) {
    int result = 0;
    if (LHS == RHS){
        result = 0;
    } else if (LHS < RHS){
        result = -1;
    } else {
        result = 1;
    }

    return result;
}