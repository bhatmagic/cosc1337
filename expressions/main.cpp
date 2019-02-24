//***************************************************************
//  Programmer: David Boyd
//
//  Purpose:
//  This program reads 2 integer values from the keyboard. Then calculates and displays on the screen:
//    the sum of the integers
//    the product of the integers
//    the result of dividing the first integer by the second using integer division (integer quotient)
//    the remainder after dividing the first integer by the second (integer remainder)
//    the result of dividing the first integer by the second using floating-point division (floating-point quotient)
//    the average of the integers (use floating-point division) 
//
//  Date: 2019.01.10
//***************************************************************

#include <iostream>
#include <cstring>
#include <iomanip>

int main () {

    // Declare and get variables
    int value1, value2;
    std::string longestStr = "Floating-point quotient ";
    int wSize = longestStr.length();

    std::cout << "Input first interger: ";
    std::cin  >> value1;
    std::cout << "\nInput second interger: ";
    std::cin  >> value2;

    // Calculate data
    int sum = (value1+value2); 
    int product = (value1*value2);
    int quotient = (value1/value2);
    int remainder = (value1%value2);
    float fquot = (static_cast<float>(value1)/value2);
    float average = ((static_cast<float>(value1)+value2)/2);

    // Display results
    std::cout << std::endl;
    std::cout << std::left << std::setw(wSize) << "Sum" << "is " << sum << std::endl;
    std::cout << std::left << std::setw(wSize) << "Product" << "is " << product << std::endl;
    std::cout << std::left << std::setw(wSize) << "Integer quotient" << "is " << quotient << std::endl;
    std::cout << std::left << std::setw(wSize) << "Integer remainder" << "is " << remainder << std::endl;
    std::cout << std::left << std::setw(wSize) << longestStr << "is " << fquot << std::endl;
    std::cout << std::left << std::setw(wSize) << "Average" << "is " << average << std::endl;    

    return 0;
}
