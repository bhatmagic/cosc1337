// Copyright 2019 David Boyd
#include <iostream>
#include <iomanip>

// class Package{}

//========================
//=== Global Variables ===
//========================

double WEIGHT_TO_COST [][14] = { 
    {1, 1.50},   {2, 2.10},   {3, 4.00},   {5, 6.75},
    {7, 9.90},   {10, 14.95}, {13, 19.40}, {16, 24.20},
    {25, 31.90}, {30, 38.50}, {40, 44.80}, {45, 47.40}, {50, 55.20} }; 

int main(void) {
   
    // Format number display
    std::cout << std::fixed << std::showpoint << std::setprecision(2);

    // Declare variables
    double package_weight, 
           d1, d2, d3;  // Package dimensions
    int transaction_counter = 0;
    int shipping_weight;  // will be referenced to WEIGHT_TO_COST[x][]
    double shipping_cost; // will be referenced to WEIGHT_TO_COST[][x]
    bool status;

    
// WHILE INPUT != -1  ========================================================
    // Get User Data
    std::cout << "Enter package weight and 3 dimension: ";
    std::cin  >> package_weight, d1, d2, d3; 

    transaction_counter++;
    status = 1;  // if dimensions are within requirements

    // Calculate Data
    


    
    // Display Results

    std::cout << "Transaction: " << transaction_counter << std::endl;
    std::cout << "Status: " << status << std::endl; 
    std::cout << "Weight: " << shipping_weight << std::endl;
    std::cout << "Cost: "   << shipping_cost   << std::endl;
// END WHILE ==================================================================

    return 0;
}
