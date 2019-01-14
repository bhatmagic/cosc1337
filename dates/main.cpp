//***************************************************************
//  Programmer: David Boyd
//  Program: Date Class
//  Purpose: Store and display dates in 3 different formats.
//  Date: 2019.01.13
//***************************************************************

#include <iostream>
#include "./dateClass/Date.h"

void displayDates(Date&);

//============
//=== Main ===
//============
int main() {

  int day, month, year;
  Date test1;
  Date test2;
  Date test3;
  Date userDate;

  std::cout << "Enter month, day, year: ";
  std::cin >> month;
  std::cin >> day;
  std::cin >> year;

  userDate.set(day, month, year);
  test1.set(0, 0, 0);
  test2.set(9999, 9999, 9999);
  test3.set(15, 3, 2016);

  std::cout << "\nDisplay User's Input:\n";
  displayDates(userDate);
  std::cout << "\nDisplay Month = 0, Day = 0, Year = 0\n";
  displayDates(test1);
  std::cout << "\nDisplay Month = 9999, Day = 9999, Year = 9999\n";
  displayDates(test2);
  std::cout << "\nDisplay Month = 3, Day = 1, Year = 2016\n";
  displayDates(test3);

  return 0;
}

//=====================
//=== Display Dates ===
//=====================
void displayDates(Date& d) {
  d.printNumeric();
  std::cout << std::endl;
  d.printAmerican();
  std::cout << std::endl;
  d.printEuropean();
  std::cout << std::endl;
}
