// Copyright 2019 David Boyd
#include <iostream>
#include <string>
#include <iomanip>

//==================
//=== Structures ===
//==================
struct Employee {
    int    id,
           type;  // union=0, mgmt=1
    double payRate;
    std::string name;
};

struct Timecard {
    double hours,
           grossPay,
           netPay,
           tax;
};

struct CompanyTimecard {
    double totalHours    = 0,
           totalGrossPay = 0,
           totalNetPay   = 0,
           totalTax      = 0;
};

//===========================
//=== Function Prototypes ===
//===========================
void   calculateData(Employee *,
               Timecard *, CompanyTimecard *);
void   displayPayroll(Employee *, Timecard *);
void   displayPayrollMenu();
void   displayTotals(CompanyTimecard);
void   getEmployeeData(Employee *);
double getGrossPay(Employee, Timecard);
double getTax(Timecard);
void   getTimecardData(Employee *,
              Timecard *, CompanyTimecard *);

//========================
//=== Global Variables ===
//========================
int    NUM_EMP   = 4;
double FTHOURS   = 40,
       OTPAYRATE = 1.5,
       TAX       = 0.15;

//============
//=== Main ===
//============
int main() {

    // Declare Variables
    Employee        emp[NUM_EMP];
    Timecard        tc[NUM_EMP];
    CompanyTimecard ctc;

    // Set Currency Format
    std::cout << std::fixed << std::setprecision(2);

    // Run Program
    getEmployeeData(emp);
    getTimecardData(emp, tc, &ctc);
    calculateData(emp, tc, &ctc);
    std::cout << std::endl;
    displayPayrollMenu();
    displayPayroll(emp, tc);
    displayTotals(ctc);
    std::cout << std::endl;
    std::cout << "\nPress any key to continue...\n";

    return 0;
}

//======================
//=== Calculate Data ===
//======================
void calculateData(Employee *emp, Timecard *tc, CompanyTimecard *ctc) {
    for (int i=0; i<NUM_EMP; ++i) {
        tc[i].grossPay = getGrossPay(emp[i], tc[i]);
        tc[i].tax      = getTax(tc[i]);
        tc[i].netPay   = (tc[i].grossPay - tc[i].tax);
        ctc->totalGrossPay += tc[i].grossPay;
        ctc->totalTax      += tc[i].tax;
        ctc->totalNetPay   += tc[i].netPay;
    }
}

//=======================
//=== Display Payroll ===
//=======================
void displayPayroll(Employee *emp, Timecard *tc) {
    for (int i=0; i<NUM_EMP; ++i) {
        std::cout << std::left
                  << std::setw(4)  << emp[i].id
                  << std::setw(20) << emp[i].name
                  << std::right
                  << std::setw(15) << tc[i].grossPay
                  << std::setw(8)  << tc[i].tax
                  << std::setw(9)  << tc[i].netPay
                  << std::endl;
    }
}

//===================================
//=== Display Payroll Menu ===
//===================================
void displayPayrollMenu() {
    std::cout << "Payroll Report\n\n";
    std::cout << std::left;
    std::cout << std::setw(4)  << "ID"
              << std::setw(20) << "Name "
              << std::right
              << std::setw(15) << "Gross Pay"
              << std::setw(8)  << "Tax"
              << std::setw(9)  << "Net Pay"
              << std::endl;
}

//======================
//=== Display Totals ===
//======================
void   displayTotals(CompanyTimecard ctc) {
    std::cout << std::endl;
    std::cout <<   "Total Gross Pay $ " << ctc.totalGrossPay
              << "\nTotal Net Pay   $ " << ctc.totalNetPay;
}

//=========================
//=== Get Employee Data ===
//=========================
void getEmployeeData(Employee *emp) {
    for (int i=0; i<NUM_EMP; ++i) {
        do {
            std::cout<<"Enter information for employee " << i;
            std::cout<<"\nEmployee id: ";
            std::cin >> emp[i].id;
        } while (emp[i].id < 1);

        std::cout<<"Employee name: ";
        std::cin.ignore();
        std::getline(std::cin, emp[i].name);

        do {
            std::cout<<"Pay rate: ";
            std::cin >> emp[i].payRate;
        } while ( emp[i].payRate <= 0 );

        do {
            std::cout<<"Type: ";
            std::cin >> emp[i].type;
        } while ( emp[i].type !=0 && emp[i].type !=1 );

        std::cout << std::endl;
    }
}

//=====================
//=== Get Gross Pay ===
//=====================
double getGrossPay(Employee emp, Timecard tc) {
    double regPay  = 0,
           otHours = 0,
           totalOTPay = 0;

    // Union emp & > FT Hours
    if (emp.type == 0 && tc.hours > 40) {
        otHours    = tc.hours - FTHOURS;
        totalOTPay = (emp.payRate * OTPAYRATE * otHours);
        regPay     = (emp.payRate * FTHOURS);
        return (regPay + totalOTPay);
    } else {
        return (emp.payRate * tc.hours);
    }
}

//===============
//=== Get Tax ===
//===============
double getTax(Timecard tcard) {
    return (tcard.grossPay * TAX);
}

//=========================
//=== Get Timecard Data ===
//=========================
void getTimecardData(Employee *emp, Timecard *tc,
                     CompanyTimecard *ctc) {
    for (int i=0; i<NUM_EMP; ++i) {
        std::cout<<"Hours worked for " << emp[i].name << ": ";
            std::cin >> tc[i].hours;
        ctc->totalHours += tc[i].hours;
    }
}
