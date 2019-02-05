//***************************************************************
//  Programmer: David Boyd
//  Purpose: Balances your checkbook at the end of the month.
//  Update: Addt'l charges and altered user's layout.
//  Date: 2019.01.13
//***************************************************************

#include <iostream>
#include <iomanip>
#include <string>

// Function prototypes
bool endProgram(double&, double&);
bool insuffFunds(double&, double&);
bool lowBalance(double&, double&);
bool processCheck(double&, double&, bool&);
bool processDeposit(double&, double&);

// Global variables
double SERVICE_CHARGE = 0.35,  // For check processing
       LOW_BAL_CHARGE = 10.00, // Balance < 1000.00
       INSUFF_FUNDS_CHARGE = 30.00, // Balance < 0.00
       LIMIT_LOWBAL = 1000.00; 

//============
//=== Main ===
//============
int main () {
    
    // Declare variables
    char command;
    double balance, 
           totalCharges = 0.00;
    bool lowBal_count;
    std::string prgmTitle = "Checkbook Balancing Program"; 

    // Format displayed numbers to two decimal places
    std::cout << std::fixed << std::showpoint << std::setprecision(2); 

    // Display title and menu
    std::cout << prgmTitle << std::endl;
    std::cout << "\nEnter the beginning balance: ";
    std::cin  >> balance;

    std::cout << "\nCommands:\n";
    std::cout << "C - process a check\n";
    std::cout << "D - process a deposit\n";    
    std::cout << "E - end the programn";    
        
    do {
        std::cout << "\n\nEnter transaction type: ";
        std::cin  >> command;
        command = tolower(command);

        switch(command) {
            case 'c': processCheck(balance, totalCharges, lowBal_count); break;
            case 'd': processDeposit(balance, totalCharges); break;
            case 'e': break;
            default : std::cout << "\nNot a valid command.\n"; break;
        } 
    } while (command != 'e');

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

//==========================
//=== Insufficient Funds ===
//==========================
bool insuffFunds(double& balance, double& totalCharges) {
    if (balance < 0) {
      totalCharges += INSUFF_FUNDS_CHARGE;
      std::cout << "\nService charge: $" << INSUFF_FUNDS_CHARGE
           << " insufficient funds";
      return 1;
    }
    
    return 0;
}

//===================
//=== Low Balance ===
//===================
bool lowBalance(double& balance, double& totalCharges) {
    
    if (balance < LIMIT_LOWBAL) {
      totalCharges += LOW_BAL_CHARGE;
      std::cout << "\nService charge: $" << LOW_BAL_CHARGE 
                << " balance below $1000.00";
      return 1;
    }

    return 0;
}

//=====================
//=== Process Check ===
//=====================
bool processCheck (double &balance, double &totalCharges, bool& lowBal_count) {

    double transAmt;

    //std::cout << "Enter transaction amount: ";
    std::cin  >> transAmt;

    if (transAmt <= 0) {
        std::cout << "\nInvalid transaction amount.";
        std::cout << "Canceling trasaction.";
        return 0;
    } else {  
        std::cout << "Processing check for $" << transAmt;

        // Calculate transactions
        balance -= transAmt;
        std::cout << "\nBalance: $" << balance;
        totalCharges += SERVICE_CHARGE;
        insuffFunds(balance, totalCharges);
        if (lowBal_count != 1) { 
          lowBal_count = lowBalance(balance, totalCharges); 
        }
        
        std::cout << "\nService charge: $" << SERVICE_CHARGE << " for a check";
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

    //std::cout << "Enter transaction amount: ";
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
