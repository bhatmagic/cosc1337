// Copyright 2019 David Boyd
#include <iostream>
#include <string>




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


    // Get data
    for (int monkey=0; monkey<NUM_MONKEYS; ++monkey) {
        for (auto day : DAYS_NAME) {
            std::cout << "Enter pounds of food eaten by monkey "
                      << monkey+1 << " on " << day <<  ": ";
            std::cin >> M_FOOD[NUM_MONKEYS][DAYS_IN_WEEK];
        }
        std::cout << std::endl;
    }
    

    // Calculate data


    // Display data
    std::cout << std::endl;
    for (auto day : DAYS_NAME)
        std::cout << day << " ";
    std::cout << std::endl;



    return 0;
}
