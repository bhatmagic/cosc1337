// Copyright 2019 David Boyd
#include <iostream>
#include <string>
#include <iomanip>

//===================
//=== Globar Vars ===
//===================
const int   NUM_MONKEYS  = 3,
            DAYS_IN_WEEK = 7,
            FUNCTIONS    = 3;
std::string DAYS_NAME[DAYS_IN_WEEK] = {
            "SUN", "MON", "TUE", "WED",
            "THU", "FRI", "SAT"       };
float M_FOOD[NUM_MONKEYS][DAYS_IN_WEEK]    = {0};

//===========================
//=== Function Prototypes ===
//===========================
float getEatDailyAvg();
float getEatDailyGreatest();
float getEatDailyLeast();
void displayInput();
void displayTotals(float, float, float);
void setMonkeyFood();

//============
//=== Main ===
//============
int main(void) {
    // Declare var
    float avg = 0,
          least = 0,
          greatest = 0;
    
    // Set format to 1 dec
    std::cout << std::fixed << std::setprecision(1);

    // Get data
    setMonkeyFood();

    // Calculate data
    avg      = getEatDailyAvg();
    least    = getEatDailyLeast();
    greatest = getEatDailyGreatest();

    // Display data
    std::cout << std::endl;
    displayInput();
    std::cout << std::endl;
    displayTotals(avg, least, greatest);
    std::cout << std::endl;

    return 0;
}

//===========================
//=== Get Eaten Daily Avg ===
//===========================
float getEatDailyAvg() {
    float sum = 0;
    for (int i=0; i<NUM_MONKEYS; ++i) { 
        for (int j=0; j<DAYS_IN_WEEK; ++j) {
            sum += M_FOOD[i][j];
        }
    }
    return (sum/DAYS_IN_WEEK);
}

//=============================
//=== Get Eaten Daily Least ===
//=============================
float getEatDailyLeast() {
    float least = M_FOOD[0][0];

    // Iterate through 2D array
    for (int i=0; i<DAYS_IN_WEEK; ++i) { 
        for (int j=0; j<NUM_MONKEYS; ++j) {
            if (least > M_FOOD[j][i])
                least = M_FOOD[j][i];
        }
    }
    return least;
}

//================================
//=== Get Eaten Daily Greatest ===
//================================
float getEatDailyGreatest() {
    float great = M_FOOD[0][0];

    // Iterate through 2D array
    for (int i=0; i<DAYS_IN_WEEK; ++i) {
        for (int j=0; j<NUM_MONKEYS; ++j) {
            if (great < M_FOOD[j][i])
                great = M_FOOD[j][i];
        }
    }
    return great;
}

//====================
//=== Display Data ===
//====================
void displayTotals(float avg, float least, float greatest) {
    // Display calculated data
    std::cout << "The average food eaten per day by all monkeys         : "
              << avg << std::endl;
    std::cout << "The least amount of food eaten by any monkey          : "
              << least << std::endl;
    std::cout << "The largest amount of food eaten per day by any monkey: "
              << greatest << std::endl;
}

//=====================
//=== Display Input ===
//=====================
void displayInput() {
    // Display HEADER
    std::cout << "Pounds of Food Eaten by Monkey and Day of Week\n";

    // Display header row
    std::cout << "\nMonkey";
    for (auto day : DAYS_NAME)
        std::cout << "\t" << day ;
    std::cout << std::endl;
    // Display monkey# | foodEaten | ...
    for (int i=0; i<3; ++i) {
        std::cout << std::right << std::setw(6) << i+1;
        for (int j=0; j<7; ++j)
            std::cout << "\t" << M_FOOD[i][j];
        std::cout << std::endl;
    }
}
//=======================
//=== Set Monkey Food ===
//=======================
void setMonkeyFood() {
    for (int i=0; i<NUM_MONKEYS; ++i) {
        for (int j=0; j<DAYS_IN_WEEK; ++j) {
            do {
                std::cout << "Enter pounds of food eaten by monkey "
                          << i+1 << " on " << DAYS_NAME[j] <<  ": ";
                std::cin >> M_FOOD[i][j];
                } while (M_FOOD[i][j] < 0);
        }
        std::cout << std::endl;
    }
}
