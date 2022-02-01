/* CSCI 261: Lab 1A - Math Equation Solver
 *
 * Author: Nick Willis
 * Resources used: Lecture from 1/14/2022
 *
 * This program takes inputs from the user, and calculates solutions based on these input values.
 */
#include <iostream>
using namespace std;

int main(){
float voltage, resistance, force, acceleration, current, stress;

    cout << "Input a voltage value: ";
    cin >> voltage;
    cout << "Input a resistance value: ";
    cin >> resistance;

    current = voltage/resistance;

    cout << "The calculated current value is: " << current << endl;

    cout << "\nInput a force value: ";
    cin >> force;
    cout << "Input an area value: ";
    cin >> acceleration;

    stress = force/acceleration;

    cout << "The calculated stress value is: " << stress << endl;
    
    return 0;
}