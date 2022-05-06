/* CSCI 261: Final Project
 *
 * Author: Nick Willis
 * Resources used (Office Hours, Tutoring, Other Students, etc & in what capacity):
 *     // list here any outside assistance you used/received while following the
 *     // CS@Mines Collaboration Policy and the Mines Academic Code of Honor
 *     // cplusplus.org
 *     // stackoverflow for error troubleshooting
 *     // Lecture slides
 *     // https://www.youtube.com/watch?v=TGveA1oFhrc Video tutorial on sorting linked lists. Still did not get this feature to work properly
 * This program is meant for small business owners who want to quickly add employee information to an existing report,
 * or generate a new report with employee information. Upon starting the program, the user is prompted with the option 
 * to add a new employee, edit employee data, or generate a report and exit the program.
 */

#include "Employee.hpp"
#include "LinkedList.hpp"
#include "Node.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
int min;
int max;

int get_user_input(int min, int max){
    int userSelection;
    bool valid = false;                                         //Initialize boolean variable that checks for input validity
    while (valid == false)
    {
        cin >> userSelection;                                   //User inputs a value
        if (userSelection < min || userSelection > max)         //If value is below min or above max, boolean returns false and user is notified. Loop repeats
        {
            valid = false;
            printf("Invalid selection. Please try again.\n");
        } else 
        {
            valid = true;                                       //User inputs a valid value, boolean returns true and breaks out of loop
        }
    }
    return userSelection;
}
int menu(){
    cout << "\t1: Add Employee" << endl;
    cout << "\t2: Edit Employee" << endl;
    cout << "\t3: Generate Report and Exit" << endl;
    int userSelection = get_user_input(1, 3);
    return userSelection;
}

int main(){
    LinkedList<Employee> empList;
    int userSelection = 0;
    while (userSelection != 3){
        userSelection = menu();
        //User selects 1, option to add employee to list
        if (userSelection == 1){
            //Create new employee, user types name, pay, phone number, and is given the option to add a note.
            Employee newEmp;
            newEmp.setName();
            newEmp.setPay();
            newEmp.setPhone();
            cout << "Do you want to add a note for this employee?" << endl;
            cout << "\t1: Yes" << endl;
            cout << "\t2: No" << endl;
            int noteSelection = get_user_input(1,2);

            if (noteSelection == 1){
                newEmp.makeNote();
            }
            empList.pushBack(newEmp);
        }
        //User selects 2, option to Edit employee information
        else if (userSelection == 2){
            //Print list of added employee's names
            empList.print();
            //Get input to select which employee to edit
            int empSelection = get_user_input(1, empList.size());
            //Print menu for what aspect of employee to edit
            cout << "1: Edit name" << endl;
            cout << "2: Edit pay" << endl;
            cout << "3: Edit phone number" << endl;
            cout << "4: Add Note" << endl;
            cout << "5: Back to main menu" << endl;
            //Get input to select what action to take
            int editSelection = get_user_input(1,5);
            //Take appropriate action depending on above user input
            if (editSelection == 1){
                empList.at(empSelection - 1).setName();
            } else if (editSelection == 2){
                empList.at(empSelection - 1).setPay();
            } else if (editSelection == 3){
                empList.at(empSelection - 1).setPhone();
            } else if (editSelection == 4){
                empList.at(empSelection - 1).makeNote();
            } else {
                continue; //Takes user back to main menu
            }
        }
        //User selects 3, program writes new employee information to EmployeeReport.txt output file
        else if (userSelection == 3){
            if (empList.size() == 0){
                cout << "No Employees to report. Aborting..." << endl;
                return 0;
            } else {
                ofstream empReport;
                LinkedList<Employee> temp = empList;
                //Creates output file if none exists, otherwise appends new data to existing output file
                empReport.open("EmployeeReport.txt", std::ofstream::app);
                //Abort if output file cannot be opened
                if (empReport.is_open() == false){
                    cout << "Error opening output file" << endl;
                    return -1;
                //File opens successfully, traverse LinkedList<Employee> and writes employee information to output file
                } else {
                    Node<Employee>* n = empList.getHead();
                    //Traverse through linked list, append employee information to output file
                    while (n != nullptr){
                        empReport << "Name: " << n->value.getName() << endl;
                        empReport << "Pay: " << n->value.getPay() << endl;
                        empReport << "Phone #: " << n->value.getPhone() << endl;
                        empReport << "Employee Notes: " << n->value.note << endl;
                        empReport << endl;
                        n = n->pNext;
                    }                
                }
            }
        }
    }
    return 0;
}