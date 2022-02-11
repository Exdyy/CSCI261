#ifndef PPM_FUNCTIONS_H
#define PPM_FUNCTIONS_H

#include <fstream>
#include <stdlib.h>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
using namespace std;

void test();

int print_file_options();

int print_operation_options();

int get_user_input(int, int);

bool open_files(int, int);

bool read_header_information(ifstream&, int&, int&, int&);

void write_header_information(ofstream&, int, int, int);

void read_and_write_modified_pixels(ifstream&, ofstream&, int, int, int, int);

#endif