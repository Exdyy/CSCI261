#include <cstdlib>
#include <iostream>
#include <cmath>
/* CSCI 261: Lab 2C
 *
 *     //Author: Nick Willis
 *     //cplusplus.com for information on string, vector, and stringstream methods
 *     //lecture materials
 *     //https://youtu.be/KJgsSFOSQv0 - C++ tutorial video
 * 
 * Asks user for input to determine their conversion type. Depending on user input, calls one of two functions defined below to go from polar to cartesian coordinates or vice versa.
 */

double r, theta, x, y;
char convChoice;
//Function to take in r and theta polar coordinates, and solve for cartesian coordinates x and y
void polar_to_cartesian(const double r, const double theta, double& x, double& y){
    x = r*cos(theta);
    y = r*sin(theta);
}

//Function to take in x and y cartesian coordinates, and solve for polar coordinates r and theta
void cartesian_to_polar(const double x,const double y, double& r, double& theta){
    r = sqrt(x*x + y*y);
    theta = atan(y/x);
    if (y > 0 && x < 0) {
        theta += 3.14159265358979;      //Quadrant 2: add pi to theta
    } else if (y < 0 && x < 0) {
        theta += 3.14159265358979;      //Quadrant 3: Add pi to theta
    } else if (y < 0 && x > 0) {
        theta += 2*3.14159265358979;    //Quadrant 4: add 2*pi to theta
    }

}

int main(){ 

    printf("CHOOSE CONVERSION TYPE\n");
    printf("\t1: Polar -> Cartesian\n");        //User selects '1' for polar to cartesian conversion
    printf("\t2: Cartesian -> Polar\n\t\t");    //User selects '2' for cartesian to polar conversion
    invalidChoice:
    scanf(" %c",&convChoice);                   //Take in user's choice

    switch(convChoice){
        case '1':                                               //Choice for polar to cartesian conversion    
            printf("\tEnter value for radius: ");               //Asks user for radius value
            scanf("\t\t%lf", &r);                               //Takes in radius value from input
            printf("\tEnter value for theta (in radians): ");   //Asks user for theta value, measured in radians
            scanf("\t\t%lf", &theta);                           //Takes in theta value from input

            polar_to_cartesian(r, theta, x, y);                 //Runs function, using user inputs as arguments
            printf("\n\t***CONVERTED TO CARTESIAN COORDINATES***\n\n");
            printf("\tx value: %lf\n\ty value: %lf\n", x, y);   //Prints out cartesian coordinates to console
            break;

        case '2':                                               //Choice for cartesian to polar conversion
            printf("\tEnter value for x: ");                    //Asks user for x value
            scanf("\t\t%lf", &x);                               //Takes in x value from input
            printf("\tEnter value for y: ");                    //Asks user for y value
            scanf("\t\t%lf", &y);                               //Takes in y value from input

            cartesian_to_polar(x, y, r, theta);                 //Runs function, using user inputs as arguments
            printf("\n\t***CONVERTED TO POLAR COORDINATES***\n\n");
            printf("\tr value: %lf\n\ttheta value: %lf radians\n", r, theta); //Prints out polar coordinates to console
            break;

        default:        
            printf("\tInvalid choice. Choose option 1 or 2\n\t\t");
            goto invalidChoice;                                 //If user inputs an invalid response, sends user back to line 33
            break;
    }


    return 0;
}