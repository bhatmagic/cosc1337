// Copyright 2019 David Boyd
#include <iostream>
#include <iomanip>
#include <string>

// Global var
int NUM_EMP = 4; 
double FTH = 40;   // full-time hours
double OTP = 1.5;  // overtime pay
double TAX = 0.15;

struct Employee {
    int id;
    std::string name;
    double payRate;  // per hour
    bool type;       // 0 = union, 1 = mgmt
};

struct Timecard {
    double hours,
           grossPay,
           taxes,
           netPay;
};

// Function protoypes
void calculatePay(Employee*, Timecard*, double, double);
void getEmpInfo(Employee*);
double getGrossPay(Employee*, Timecard*); 
void getHours(Employee*, Timecard*);
//void display(Employee* empPtr);

//============
//=== Main ===
//============
int main () {

    Employee* emp = new Employee[NUM_EMP]; 
    Timecard* tc  = new Timecard[NUM_EMP];
    double totalGrossPay = 0,
           totalNetPay   = 0;

    std::cout << "Armadillo Automotive Group - Payroll\n\n";

    getEmpInfo(emp);
    getHours(emp, tc); 
    calculatePay(emp, tc, totalGrossPay, totalNetPay);
    
    for (int i=0; i<NUM_EMP; ++i) 
        totalGrossPay += tc[i].grossPay;
        totalNetPay   += tc[i].netPay;
    std::cout<<"\nTotal Gross Pay $" << totalGrossPay 
             <<"\nTotal Net Pay   $" << totalNetPay;
    //display(emp);
    
    return 0;
}

//====================
//=== Calulate Pay ===
//====================
void calculatePay(Employee* emp, Timecard* tc, 
     double totalGrossPay, double totalNetPay) {

    for (int i=0; i<NUM_EMP; ++i) {
       tc[i].grossPay = getGrossPay(emp, tc);
       tc[i].taxes = (tc[i].grossPay * TAX);
       tc[i].netPay = (tc[i].grossPay - tc[i].taxes);
       std::cout << "GrossPay: " << tc[i].grossPay << std::endl;
    }
}

//================================
//=== Get Employee Information ===
//================================
void getEmpInfo(Employee* emp) {
    for (int i=0; i<NUM_EMP; ++i) {
        std::cout << "Enter information for employee " << i+1 << std::endl;
        std::cout << "Employee id: ";
        std::cin >> emp[i].id;
        std::cout << "Employee name: ";
        std::cin.ignore();
        std::getline(std::cin, emp[i].name); 
        std::cout << "Pay rate: ";
        std::cin >> emp[i].payRate;
        std::cout << "Type: ";
        std::cin >> emp[i].type;
        std::cout << std::endl;
    }
}

//=====================
//=== Get Gross Pay ===
//=====================
double getGrossPay(Employee* emp, Timecard* tc) { 
    if (emp->type == 0 && tc->hours > FTH) {
            double regPay  = (emp->payRate * FTH);
            double otHours = (tc->hours - FTH);
            double otPay   = (OTP * otHours * emp->payRate);
            return (regPay + otPay);
        } else {
            return (emp->payRate * tc->hours);
     } 
}

//=================
//=== Get Hours ===
//=================
void getHours(Employee* emp, Timecard* tc) {
    std::cout << "Enter timecard information for each employee:\n";

    for (int i=0; i<NUM_EMP; ++i) {
        std::cout << "Hours worked for " << emp[i].name << ": ";
        std::cin >> tc[i].hours;
    }
}

//========================
//=== TimeCard Display ===
//========================
// void display(Employee* empPtr) {
//   Employee emp[NUM_EMP] = &empPtr;
//   std::cout << std::left <<  std::setw(4) << "ID"
//          << std::setw(20) << "Name"
//          << std::right << std::setw(10) 
//          << "Gross Pay" << "Tax" << "Net Pay\n";
//     for (int i=0; i<NUM_EMP; ++i) {
//         std::cout << std::left << std::setw(4) << emp[i]->id
//              << std::setw(20)  << emp[i]->name 
//              << std::right     << std::setw(10)
//              << tc->grossPay   << tc->taxes 
//              << tc->netPay     << std::endl;
//     }
// }
