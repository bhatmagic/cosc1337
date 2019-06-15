// Copyright 2019 David Boyd
#include "Date.h"
/*
 * Private:
 */

//================
//=== _Set Day ===
//================
void Date::_setDay(int day) {
  	(day > 0 && day < 32) ? (this->_day = day) : (this->_day = 1);
}

//==================
//=== _Set Month ===
//==================
void Date::_setMonthNumber(int month) {
    (month > 0 && month < 13) ?
        (this->_monthNumber = month) : (this->_monthNumber = 1);
}

//=======================
//=== _Set Month Name ===
//=======================
void Date::_setMonthName() {
    switch(this->_monthNumber) {
      case 1:  this->_monthName = "January";  break;
      case 2:  this->_monthName = "February"; break;
      case 3:  this->_monthName = "March";    break;
      case 4:  this->_monthName = "April";    break;
      case 5:  this->_monthName = "May";      break;
      case 6:  this->_monthName = "June";     break;
      case 7:  this->_monthName = "July";     break;
      case 8:  this->_monthName = "August";   break;
      case 9:  this->_monthName = "September";break;
      case 10: this->_monthName = "October";  break;
      case 11: this->_monthName = "November"; break;
      case 12: this->_monthName = "December"; break;
      default: this->_monthName = "January";  break;
    }
}

//=================
//=== _Set Year ===
//=================
void Date::_setYear(int year) {
  this->_year = (year > 1949 && year < 2021) ? (year) : (2001);
}

/* 
 * Public:
 */

//==============
//=== Date() ===
//==============
Date::Date() {
    _setDay(1);
    _setMonthNumber(1);
    _setMonthName();
    _setYear(1950);
}

//===============
//=== Get Day ===
//===============
int Date::getDay() const {
    return _day;
}

//=================
//=== Get Month ===
//=================
int Date::getMonthNumber() const {
    return _monthNumber;
}

//======================
//=== Get Month Name ===
//======================
std::string Date::getMonthName() const {
    return (_monthName);
}

//================
//=== Get Year ===
//================
int Date::getYear() const {
    return _year;
}

//=====================
//=== Print Numeric ===
//=====================
void Date::printNumeric() const {
    std::cout << getMonthNumber() << "/"
              << getDay()         << "/"
              << getYear();
}

//======================
//=== Print American ===
//======================
void Date::printAmerican() const {
    std::cout << getMonthName() << " "
              << getDay()       << " "
              << getYear();
}

//======================
//=== Print European ===
//======================
void Date::printEuropean() const {
    std::cout << getDay()       << " "
              << getMonthName() << " "
              << getYear();
}

//===========
//=== Set ===
//===========
void Date::set(int day, int month, int year) {
  _setDay(day);
  _setMonthNumber(month);
  _setMonthName();
  _setYear(year);
}
