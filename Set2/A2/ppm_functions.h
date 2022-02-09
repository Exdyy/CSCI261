#include <string>
#include <iostream>
#include <fstream>


void print_file_options(int);

void print_operation_options(int);

int get_user_input(int, int);

bool open_files(ifstream, ofstream, int, int);

bool read_header_information(ifstream, int, int, int);

void write_header_information(ofstream, int, int, int);

void read_and_write_modified_pixels(ifstream, ofstream, int, int, int, int);
