// Copyright 2019 David Boyd
#include <iostream>
#include <string>




//===================
//=== Globar Vars ===
//===================
const int   NUM_MONKEYS  = 3,
      DAYS_OF_WEEK = 7;
enum  DAYS_NAME[DAYS_OF_WEEK] = { 
            "Monkey",
            "SUN", "MON", "TUE", "WED",
            "THU", "FRI", "SAT"
       };
float M_FOOD[NUM_MONKEYS][DAYS_OF_WEEK];

//===========================
//=== Function Prototypes ===
//===========================


//============
//=== Main ===
//============
int main(void) {
    
    // Declare variables


    

    // Get data
    std::cout << "Enter pounds of food eaten by monkey " << " 1 "
              << " on " << " SUN " <<  ": ";
    std::cin >> M_FOOD[0][0];
    

    // Calculate data


    // Display data
    for ( auto:i < 
    std::cout << "    1    ";
    std::cout << M_FOOD[0][0] << std::endl;



    return 0;
}
