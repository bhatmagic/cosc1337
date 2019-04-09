// Copyright 2019 David Boyd
#include <iostream>
#include <string>
#include <iomanip>

//===================
//=== Globar Vars ===
//===================
const int   NUM_MONKEYS  = 3,
            DAYS_IN_WEEK = 7;
std::string DAYS_NAME[DAYS_IN_WEEK] = { 
            "SUN", "MON", "TUE", "WED",
            "THU", "FRI", "SAT"       };
float M_FOOD[NUM_MONKEYS][DAYS_IN_WEEK];

//===========================
//=== Function Prototypes ===
//===========================


//============
//=== Main ===
//============
int main(void) {
    
    // Declare variables
    float sum      = 0,
          least    = 0,
          greatest = 0;

    // Set format to 1 dec
    std::cout << std::fixed << std::setprecision(1);

    // Get data
    for (int i=0; i<NUM_MONKEYS; ++i) {
        for (int j=0; j<DAYS_IN_WEEK; ++j) {
            std::cout << "Enter pounds of food eaten by monkey "
                      << i+1 << " on " << j+1 <<  ": ";
            std::cin >> M_FOOD[i][j];
        }
        std::cout << std::endl;
    }
    

    // Calculate data

    // getAvgEatenDay
    for (int i=0; i<NUM_MONKEYS; ++i) { 
        for (int j=0; j<DAYS_IN_WEEK; ++j) {
            sum += M_FOOD[i][j];
        }
        std::cout << std::endl;
    }

    std::cout << "\nSum = " << sum << std:: endl;
    
    // getLeastEatenDay

    // getGreatestEatenDay


    // Display data
    std::cout << "\nMonkey ";
    for (auto day : DAYS_NAME)
        std::cout << day << " ";
    std::cout << std::endl;



    // End program
    return 0;
}
