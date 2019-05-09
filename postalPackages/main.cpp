// Copyright 2019 David Boyd
#include <iostream>
#include <iomanip>

// struct Package{}

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
    int transaction_counter = 0,
        transaction_accepted = 0,
        transaction_rejected = 0;
    double shipping_weight;  // will be referenced to WEIGHT_TO_COST[x][]
    double shipping_cost; // will be referenced to WEIGHT_TO_COST[][x]
    bool status = 0;
    double girth,
           largest_dim;

    // Display Menu
    std::cout << std::endl;
    std::cout << "For each transaction, enter package "
              << "weight and 3 dimensions.\n"
              << "Enter -1 to quit.\n" << std:: endl;
    
    do {
        // Get User Data
        do { // dim checker
            std::cout << "Enter package weight and 3 dimension: ";
            std::cin  >> package_weight;
            if (package_weight == -1) break; 
            if (package_weight > 50) // if weight>50 pounds
            status = 0;
            std::cin  >> d1;
            std::cin  >> d2;
            std::cin  >> d3;
            if (d1 < 0 || d2 < 0 || d3 < 0)
                std::cout << "Dimensions must be greater than 0.\n\n";
        } while (d1 < 0 || d2 < 0 || d3 < 0);     // if dim<0 in

        // Calculate Data
        transaction_counter++;
        if (d1 > d2) largest_dim = d1;
        else largest_dim =d2;
        if (d3 > largest_dim) largest_dim = d3;
        girth = 2*(d1+d2+d3-largest_dim);

        // if dim>3ft || girth>5th
        if (d1 > 48 || d2 > 48 || d3 > 48 || girth > 60) {
            status = 0;
            transaction_rejected++;
        } else {
            status = 1;
            transaction_accepted++;
        }

        // Display Results
        if (package_weight == -1) {
            std::cout << std::endl;
        } else {
            std::cout << "Transaction: " << transaction_counter << std::endl;
            std::cout << "Status: " << status << std::endl; 
            std::cout << "Weight: " << shipping_weight << std::endl;
            std::cout << "Cost: "   << shipping_cost   << std::endl;
        }
    } while (package_weight != -1);

    // Display EndPrgm Results
    std::cout << "\nNumber of accepted packaged: " << transaction_accepted;
    std::cout << "\nNumber of rejected packages: " << transaction_rejected;
    std::cout << std::endl;

    return 0;
}
