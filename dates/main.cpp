// Copyright 2019 David Boyd
#include <iostream>
#include "./dateClass/Date.h"

//===========================
//=== Function Prototypes ===
//===========================
void displayDates(Date&);

//============
//=== Main ===
//============
int main() {

  // Declare variables
  int day, month, year;
  Date test1;
  Date test2;
  Date test3;
  Date userDate;

  // Get Data
  std::cout << "Enter month, day, year: ";
  std::cin >> month;
  std::cin >> day;
  std::cin >> year;

  // Sample Data
  userDate.set(day, month, year);
  test1.set(0, 0, 0);
  test2.set(9999, 9999, 9999);
  test3.set(15, 3, 2016);

  // Display Data
  std::cout << "\nDisplay User's Input:\n";
  displayDates(userDate);
  std::cout << "\nDisplay Default Data001:"
            << "\nMonth = 0, Day = 0, Year = 0\n";
  displayDates(test1);
  std::cout << "\nDisplay Default Data002:"
            << "\nMonth = 9999, Day = 9999, Year = 9999\n";
  displayDates(test2);
  std::cout << "\nDisplay Default Data003:"
            << "\nMonth = 3, Day = 1, Year = 2016\n";
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
