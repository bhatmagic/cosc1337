//***************************************************************
//  Programmer: David Boyd
//  Program: Date Class header file.
//  Date: 2019.01.13
//***************************************************************

#include <iostream>
#include <string>

#ifndef DATE_H
#define DATE_H

class Date {

  private: 
    
    int _day, 
        _monthNumber, 
        _year;
    // enum _monthName { January, February, March, April, 
    //                  May, June, July, August, September, 
    //                  October, November, December };
    std::string _monthName;
    
    void _setDay(int);
    void _setMonthNumber(int);
    void _setMonthName();
    void _setYear(int);

  public: 

    Date();
    int getDay() const;
    int getMonthNumber() const;
    std::string getMonthName() const;
    int getYear() const;
    void printNumeric() const;
    void printAmerican() const;
    void printEuropean() const;
    void set(int, int, int);

}; 
#endif
