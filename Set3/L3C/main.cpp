
#include <iostream>
using namespace std;


int main()
{
    int iNum = 9;               //Step 1
    double dNum = 14.25;        //Step 2
    int *pINum1, *pINum2;       //Step 3
    double *pDNum;              //Step 4
    pINum1 = &iNum;             //Step 5

    cout << "Step 6 - iNum address: " << pINum1 << " (Printed using pointer variable, pINum1)" << endl;             //Step 6.1
    cout << "Step 6 - iNum address: " << &iNum << " (Printed using reference operator, &iNum)" << endl;             //Step 6.2
    cout << "Step 7 - iNum value: " << *pINum1 << " (Printed using dereference pointer variable, *pINum1)" << endl; //Step 7
    
    //pINum2 = &dNum;           //Step 8
    //Error:
    //main.cpp:18:15: error: cannot convert 'double*' to 'int*' in assignment
    //pINum2 = &dNum;
    //         ^~~~

    pDNum = &dNum;              //Step 9
    cout << "Step 10 - dNum address: " << pDNum << " (Printed using pointer variable, pDNum)" << endl;              //Step 10.1
    cout << "Step 10 - dNum value: " << *pDNum << " (Printed using dereferenced pointer variable, *pDNum)" << endl; //Step 10.2

    iNum = 7;                   //Step 11
    cout << "Step 12 - iNum value: " << *pINum1 << " (Printed using dereference pointer variable, *pINum1)" << endl;//Step 12
    
    pINum2 = pINum1;            //Step 13
    cout << "Step 14 - pINum2 address: " << pINum2 << endl;                 //Step 14
    cout << "Step 15 - value pointed to by pINum2: " << *pINum2 << endl;    //Step 15

    *pINum2 = 12;               //Step 16
    cout << "Step 17 - iNum contents: " << *pINum1 << " (Printed using dereferenced pointer, *pINum1)" << endl;     //Step 17.1
    cout << "Step 17 - iNum contents: " << *pINum2 << " (Printed using dereferenced pointer, *pINum2)" << endl;     //Step 17.2
    cout << "Step 17 - iNum contents: " << iNum << " (Printed using direct call to variable, iNum)" << endl;        //Step 17.3



    
}