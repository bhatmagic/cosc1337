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
float M_FOOD[NUM_MONKEYS][DAYS_IN_WEEK]    = {0},
      M_FOOD_CALC[FUNCTIONS][DAYS_IN_WEEK] = {0};

//===========================
//=== Function Prototypes ===
//===========================
float getEatDailyAvg(float *);
float getEatDailyGreatest(float *);
float getEatDailyLeast(float *);
void  display(float *);
void  setMonkeyFood(float *);

//============
//=== Main ===
//============
int main(void) {
    
    // Declare variables
    float sum      = 0,
          totSum   = 0,
          avg      = 0,
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
    for (int i=0; i<DAYS_IN_WEEK; ++i) { 
        for (int j=0; j<NUM_MONKEYS; ++j) {
            M_FOOD_CALC[0][i] += M_FOOD[j][i];
        }
        M_FOOD_CALC[0][i] = (M_FOOD_CALC[0][i]/NUM_MONKEYS);
    }

    std::cout << std::endl;
    std::cout << "The average food eaten per day by all monkeys          : ";
    for (int i=0; i<7; ++i)
        std::cout << M_FOOD_CALC[0][i] << ",  ";
    
    // getLeastEatenDay
    for (int i=0; i<DAYS_IN_WEEK; ++i) { 
        // set least val = 1st monkey per day/col
        M_FOOD_CALC[1][i] = M_FOOD[0][i];
        for (int j=0; j<NUM_MONKEYS; ++j) {
            // if val 1 > val 2, then val 1 = val 2
            if (M_FOOD_CALC[1][i] > M_FOOD[j][i]) {
                M_FOOD_CALC[1][i] = M_FOOD[j][i];
            }
        }
    }

    std::cout << std::endl;
    std::cout << "The least amount of food eaten by any monkey           : ";
    for (int i=0; i<7; ++i)
        std::cout << M_FOOD_CALC[1][i] << ",  ";

    // getGreatestEatenDay
    for (int i=0; i<DAYS_IN_WEEK; ++i) { 
        // set greatest val = 1st monkey per day/col
        M_FOOD_CALC[2][i] = M_FOOD[0][i];
        for (int j=0; j<NUM_MONKEYS; ++j) {
            // if val 1 < val 2, then val 1 = val 2
            if (M_FOOD_CALC[2][i] < M_FOOD[j][i]) {
                M_FOOD_CALC[2][i] = M_FOOD[j][i];
            }
        }
    }

    std::cout << std::endl;
    std::cout << "The largest amount of food eaten per day by any monkey : ";
    for (int i=0; i<7; ++i)
        std::cout << M_FOOD_CALC[2][i] << ",  ";

    // Display data
    std::cout << "\nMonkey ";
    for (auto day : DAYS_NAME)
        std::cout << day << " ";
    std::cout << std::endl;


    // End program
    return 0;
}

//===========================
//=== Get Eaten Daily Avg ===
//===========================
float getEatDailyAvg(float *) {
    
}

//=============================
//=== Get Eaten Daily Least ===
//=============================
float getEatDailyLeast(float *) {
    
}

//================================
//=== Get Eaten Daily Greatest ===
//================================
float getEatDailyGreatest(float *) {
    
}


//====================
//=== Display Data ===
//====================
void display(float *) {
    
}

//=======================
//=== Set Monkey Food ===
//=======================
void setMonkeyFood(float *) {
    
}
