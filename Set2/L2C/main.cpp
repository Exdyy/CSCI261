#include <cstdlib>
#include <iostream>
#include <cmath>


double r, theta, x, y;
char convChoice;

void polar_to_cartesian(const double r, const double theta, double& x, double& y){
    x = r*cos(theta);
    y = r*sin(theta);
}

void cartesian_to_polar(const double x,const double y, double& r, double& theta){
    r = sqrt(x*x + y*y);
    theta = atan(y/x);
    if (y > 0 && x < 0) {
        theta += 3.14159265358979;
    } else if (y < 0 && x < 0) {
        theta += 3.14159265358979;
    } else if (y < 0 && x > 0) {
        theta += 2*3.14159265358979;
    }

}

int main(){ 

    printf("CHOOSE CONVERSION TYPE\n");
    printf("\t1: Polar -> Cartesian\n");
    printf("\t2: Cartesian -> Polar\n\t\t");
    invalidChoice:
    scanf(" %c",&convChoice);

    switch(convChoice){
        case '1':
            printf("\tEnter value for radius: ");
            scanf("\t\t%lf", &r);
            printf("\tEnter value for theta (in radians): ");
            scanf("\t\t%lf", &theta);

            polar_to_cartesian(r, theta, x, y);
            printf("\n\t***CONVERTED TO CARTESIAN COORDINATES***\n\n");
            printf("\tx value: %lf\n\ty value: %lf\n", x, y);
            break;

        case '2':
            printf("\tEnter value for x: ");
            scanf("\t\t%lf", &x);
            printf("\tEnter value for y: ");
            scanf("\t\t%lf", &y);

            cartesian_to_polar(x, y, r, theta);
            printf("\n\t***CONVERTED TO POLAR COORDINATES***\n\n");
            printf("\tr value: %lf\n\ttheta value: %lf radians\n", r, theta);
            break;

        default:
            printf("\tInvalid choice. Choose option 1 or 2\n\t\t");
            goto invalidChoice;
            break;
    }


    return 0;
}