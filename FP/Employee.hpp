#include <string>
#include <iostream>
using namespace std;

class Employee{
    private:
    string mFirst;
    string mLast;
    double mPay;
    string mPhone;

    public:
    string note;
    string getName() const;
    void setName();
    double getPay() const;
    void setPay();
    string getPhone() const;
    void setPhone();
    void makeNote();
};

string Employee::getName() const{
    string name = mFirst + " " + mLast;
    char c;
    int i = 0;
    while (name[i]){
        c = toupper(name[i]);
        name[i] = c;
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

double Employee::getPay() const{
    return mPay;
}

void Employee::setPay(){
    cout << "EMPLOYEE WAGE: ";
    cin >> mPay;
}

string Employee::getPhone() const{
    return mPhone;
}

void Employee::setPhone(){
    cout << "EMPLOYEE PHONE: ";
    cin >> mPhone;
}

void Employee::makeNote(){
    string temp;
    cout << "Add employee note here: ";
    getline(cin >> ws, temp);
    note = note + temp;
}