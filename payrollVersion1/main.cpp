// Copyright 2019 David Boyd
#include <iostream>
#include <string>
#include <iomanip>

struct Employee {
    int    id;
    double payRate;
    bool   type;  // union=0, mgmt=1
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

// Function Prototypes
double getGrossPay(Employee, Timecard);
double getTax(Timecard);

// Global Variables
int    NUM_EMP   = 4;
double FTHOURS   = 40,
       OTPAYRATE = 1.5,
       TAX       = 0.15;

int main() {

    // Declare Variables
    Employee        emp[NUM_EMP];
    Timecard        tc[NUM_EMP];
    CompanyTimecard ctc; 
    char c;
    
    // Get Employee Data
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
        std::cout<<"Type: ";
            std::cin >> emp[i].type;
    }
    // Get Timecard data
    for (int i=0; i<NUM_EMP; ++i) {
        std::cout<<"\nHours worked for " << emp[i].name << ": ";
            std::cin >> tc[i].hours;
        ctc.totalHours += tc[i].hours;
    }
    // Calculate data
    for (int i=0; i<NUM_EMP; ++i) {
        tc[i].grossPay = getGrossPay(emp[i], tc[i]);
        tc[i].tax      = getTax(tc[i]);
        tc[i].netPay   = (tc[i].grossPay - tc[i].tax);
        ctc.totalGrossPay += tc[i].grossPay;
        ctc.totalTax      += tc[i].tax;
        ctc.totalNetPay   += tc[i].netPay;
    }

    // Set Currency Format
    std::cout << std::fixed << std::setprecision(2);

    // Display Payroll Report
    std::cout << "Payroll Report\n\n";
    std::cout << std::left;
    std::cout << std::setw(4)  << "ID"
              << std::setw(20) << "Name "
              << std::right
              << std::setw(15) << "Gross Pay"
              << std::setw(8)  << "Tax"
              << std::setw(9)  << "Net Pay"
              << std::endl;
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
    // Display Totals
    std::cout << std::endl;
    std::cout <<   "Total Gross Pay $ " << ctc.totalGrossPay
              << "\nTotal Net Pay   $ " << ctc.totalNetPay
              << std::endl;
    
    std::cout << "\nPress any key to continue...";
    std::cin;
    std::cout << std::endl;

    return 0;
}

//=====================
//=== Get Gross Pay ===   
//=====================
double getGrossPay(Employee emp,
                   Timecard tc) {
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
