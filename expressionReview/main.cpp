// Copyright 2018 David Boyd
#include <iostream>
#include <cstring>
#include <iomanip>

int main () {

    // Declare variables
    int value1,
        value2;
    std::string fpQuot = "Floating-point quotient ";
    int wSize = fpQuot.length();

    // Get data
    std::cout << "Input first interger: ";
    std::cin  >> value1;
    std::cout << "Input second interger: ";
    std::cin  >> value2;

    // Calculate data
    int sum      = (value1+value2);
    int product  = (value1*value2);
    int quotient = (value1/value2);
    int remain   = (value1%value2);
    float fquot  = (static_cast<float>(value1)/value2);
    float avg    = ((static_cast<float>(value1)+value2)/2);

    // Display results
    std::cout << std::left
    << std::setw(wSize) << "\nSum"     << " is " << sum
    << std::setw(wSize) << "\nProduct" << " is " << product
    << std::setw(wSize) << "\nInteger quotient"  << " is " << quotient
    << std::setw(wSize) << "\nInteger remainder" << " is " << remain
    << std::endl << std::setw(wSize) << fpQuot   << "is "  << fquot
    << std::setw(wSize) << "\nAverage"           << " is " << avg
    << std::endl;

    return 0;
}
