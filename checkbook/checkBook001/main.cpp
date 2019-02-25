//***************************************************************
//  Programmer: David Boyd
//  Purpose: Balance your checkbook at the end of the month.
//  Date: 2019.01.11
//***************************************************************

#include <iostream>
#include <iomanip>
#include <string>

// Function prototypes
bool endProgram(double&, double&);
bool processCheck(double&, double&);
bool processDeposit(double&, double&);
void displayMenu(void);
void displayTitle(void);
void processTransactions(double&, double&);
double begBalance();

// Global variables
double SERV_CHARGE = 0.35;

//============
//=== Main ===
//============
int main () {
    
    // Declare variables
    double balance,
          totalCharges = 0.00;

    // Format displayed numbers to two decimal places
    std::cout << std::fixed << std::showpoint << std::setprecision(2); 

    // Display title and menu
    balance = begBalance();
    displayMenu();
    processTransactions(balance, totalCharges);

    endProgram(balance, totalCharges); 
    std::cout << std::endl;

    return 0;
}

//===================
//=== End Program ===
//===================
bool endProgram(double& balance, double& totalCharges) {

    balance = (balance - totalCharges);
    std::cout << "Processing end of month";
    std::cout << "\nFinal balance: $" << balance;

    return 1;
}

//=====================
//=== Process Check ===
//=====================
bool processCheck (double &balance, double &totalCharges) {

    double transAmt;

    std::cout << "Enter transaction amount: ";
    std::cin  >> transAmt;

    if (transAmt <= 0) {
        std::cout << "\nInvalid transaction amount.";
        std::cout << "Canceling trasaction.";
        return 0;
    } else {  
        std::cout << "Processing check for $" << transAmt;

        balance -= transAmt;
        totalCharges += SERV_CHARGE; 

        std::cout << "\nBalance: $" << balance;
        std::cout << "\nService charge: $" << SERV_CHARGE << " for a check";
        std::cout << "\nTotal service charges: $" << totalCharges;
        return 1;
    }
    return 0;
}

//=======================
//=== Process Deposit ===
//=======================
bool processDeposit(double &balance, double &totalCharges) {

    double transAmt;

    std::cout << "Enter transaction amount: ";
    std::cin  >> transAmt;

    if (transAmt <= 0) {
        std::cout << "\nInvalid transaction amount.";
        std::cout << "\nCanceling trasaction.";
        return 0;
    } else {  
        std::cout << "Processing deposit for $" << transAmt;

        balance += transAmt;

        std::cout << "\nBalance: $" << balance;
        std::cout << "\nTotal service charges: $" << totalCharges;
        return 1;
    }

    return 0;
}

//====================
//=== Display Menu ===
//====================
void displayMenu(void) {

    std::cout << "\nCommands:\n";
    std::cout << "C - process a check\n";
    std::cout << "D - process a deposit\n";    
    std::cout << "E - end the programn";    
}

//==============
//=== Choose ===
//==============
void processTransactions(double &balance, double &totalCharges) {
    char command;

    do {
        std::cout << "\n\nEnter transaction type: ";
        std::cin  >> command;
        command = tolower(command);

        switch(command) {
            case 'c': processCheck(balance, totalCharges); break;
            case 'd': processDeposit(balance, totalCharges); break;
            case 'e': break;
            default : std::cout << "\nNot a valid command.\n"; break;
        } 
    } while (command != 'e');
}

//=====================
//=== Display Title ===
//=====================
void displayTitle(void) {
    std::string prgmTitle = "Checkbook Balancing Program"; 
    std::cout << prgmTitle << std::endl;
}
//=========================
//=== Beginning Balance ===
//=========================
double begBalance() {
    double balance;
    std::cout << "Enter beginning balance: ";
    std::cin >> balance;
    return balance;
}
