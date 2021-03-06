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
#ifndef TEST_SUITE_H
#define TEST_SUITE_H

#include <string>
using namespace std;

/** 
 * @brief Test suite. Runs all tests.
 * @return true if all tests pass, false otherwise
 */
bool run_all_tests();

/**
 * @brief A generic test function, that simply prints "PASSED" if LHS equals RHS 
 * and otherwise prints FAILED. Do not modify this function.
 * 
 * @param testNum Number of the test.  Value will be incremented upon completion
 * @param MESSAGE description of test
 * @param LHS computed result
 * @param RHS expected result
 * @return 1 if test passed, 0 otherwise
 */
int test_int_pointer(int &testNum, const string MESSAGE, const int* LHS, const int* RHS);

/**
 * @brief A generic test function, that simply prints "PASSED" if LHS does not equal RHS 
 * and otherwise prints FAILED. Do not modify this function.
 * 
 * @param testNum Number of the test.  Value will be incremented upon completion
 * @param MESSAGE description of test
 * @param LHS computed result
 * @param RHS expected result
 * @return 1 if test passed, 0 otherwise
 */
int test_int_pointer_not(int &testNum, const string MESSAGE, const int* LHS, const int* RHS);

/**
 * @brief A generic test function, that simply prints "PASSED" if LHS equals RHS 
 * and otherwise prints FAILED. Do not modify this function.
 * 
 * @param testNum Number of the test.  Value will be incremented upon completion
 * @param MESSAGE description of test
 * @param LHS computed result
 * @param RHS expected result
 * @return 1 if test passed, 0 otherwise
 */
int test_int(int &testNum, const string MESSAGE, const int LHS, const int RHS);

/**
 * @brief A generic test function, that simply prints "PASSED" if LHS equals RHS 
 * and otherwise prints FAILED. Do not modify this function.
 * 
 * @param testNum Number of the test.  Value will be incremented upon completion
 * @param MESSAGE description of test
 * @param LHS computed result
 * @param RHS expected result
 * @return 1 if test passed, 0 otherwise
 */
int test_unsigned_long(int &testNum, const string MESSAGE, const unsigned long LHS, const unsigned long RHS);

#endif