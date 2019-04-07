// Copyright 2019 David Boyd
#pragma once
#include <iostream>
#include <string>

class Date {

  private: 
    
    int _day, 
        _monthNumber, 
        _year;
    std::string _monthName;
    
    void _setDay(int);
    void _setMonthName();
    void _setMonthNumber(int);
    void _setYear(int);

  public: 

    Date();
    int getDay() const;
    std::string getMonthName() const;
    int getMonthNumber() const;
    int getYear() const;
    void printAmerican() const;
    void printEuropean() const;
    void printNumeric() const;
    void set(int, int, int);
}; 
