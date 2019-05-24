// Copyright 2019 David Boyd
#include "Functions.h"

//============
//=== Main ===
//============
int main(void) {
   
    // Format number display
    format_money();

    // Declare variables
    Package pkg;
    Transaction trans;

    // Run Program
    display_menu();
    run(&pkg, &trans);
    
    // Display Results
    display_transResults(&trans);

    return 0;
}
