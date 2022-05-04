#include <string>
#include <iostream>
using namespace std;

class Employee{
    private:
    string mFirst;
    string mLast;
    double mPay;
    string mPhone;
    int mID;

    public:
    string note;
    string getName();
    void setName();
    double getPay();
    void setPay();
    void makeNote();
};

string Employee::getName(){
    string name;
    int i = 0;
    while (mFirst[i]){
        name += toupper(mFirst[i]);
        i++;
    }
    name += ' ';
    while (mLast[i]){
        name += toupper(mLast[i]);
        i++;
    }
    return name;
}

void Employee::setName(){
    string tempName;

    cout << "EMPLOYEE FIRST NAME: ";
    cin >> tempName;
    mFirst = tempName;

    cout << "EMPLOYEE LAST NAME: ";
    cin >> tempName;
    mLast = tempName;
}

double Employee::getPay(){
    return mPay;
}

void Employee::setPay(){
    cout << "EMPLOYEE WAGE: ";
    cin >> mPay;
}

void Employee::makeNote(){
    string temp;
    cout << "Add employee note here: ";
    cin >> temp;
    note = note + temp;
}