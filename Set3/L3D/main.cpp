/* CSCI 261: Assignment L3D - Array Ops
 *
 * Author: Nick Willis
 * Resources used (Office Hours, Tutoring, Other Students, etc & in what capacity):
 *     // list here any outside assistance you used/received while following the
 *     // CS@Mines Collaboration Policy and the Mines Academic Code of Honor
 *     // In class lectures
 *     // cplusplus.com for proper syntax and functionality of libraries
 *
 * Test suite for a variety of functions that perform different operations on arrays
 */
#include <iostream>
using namespace std;

#include "test_suite.h"

int main() {

    cout << "Testing your functions..." << endl << endl;
    if( run_all_tests() ) {
        cout << "ALL TESTS PASSED!" << endl;
    } else {
        cout << "Not all tests are passing, errors remain..." << endl;
    }

    return 0;
}