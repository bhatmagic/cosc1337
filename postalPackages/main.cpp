// Copyright 2019 David Boyd
#include <iostream>
#include <iomanip>

//===============
//=== Structs ===
//===============
struct Package {
    double cost = 0.0,
           dim1 = 0.0,
           dim2 = 0.0,
           dim3 = 0.0,
           girth = 0.0,
           great_dim = 0.0,
           ship_cost;
    int wt = 0.0,
        ship_wt;
    bool status = 0;
};

struct Transaction {
    int count = 0,
        accept = 0,
        reject = 0;
};

//======================
//=== Fns Prototypes ===
//======================
void calcPkgData(Package *, Transaction *);
void display_menu();
void display_pkgResults(Package *, Transaction *);
void display_transResults(Transaction *);
void get_ship_charge(Package *p);
void format_money();
void getPkgData();
void run(Package *, Transaction *);

//========================
//=== Global Variables ===
//========================
const int DISP_WIDTH = 10;
const int SIZE = 15;
const int SHIPPING_WT[SIZE] = 
    {  1,  2,  3,  5,  7,
      10, 13, 16, 20, 25,
      30, 35, 40, 45, 50  };
const double SHIPPING_COST[SIZE] =  
    {  1.50,  2.10,  4.00,  6.75,  9.90, 
      14.95, 19.40, 24.20, 27.20, 31.90, 
      38.50, 43.50, 44.80, 47.40, 55.20  };

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

//============================
//=== Function Definitions ===
//============================
//--- Calculate Package Data ---------------------------------------------------
void calcPkgData(Package *p, Transaction *t) {
    t->count++;
    
    // find greatest dimension
    if (p->dim1 > p->dim2) { p->great_dim = p->dim1;
    } else { p->great_dim = p->dim2; }
    if (p->dim3 > p->great_dim) p->great_dim= p->dim3;

    // calculate girth
    p->girth = 2*(p->dim1+p->dim2+p->dim3-p->great_dim);

    // process status: check dim>3ft || girth>5th
    if (p->dim1 > 48 || p->dim2 > 48 || p->dim3 > 48 || p->girth > 60) {
        p->status = 0;
        t->reject++;
    } else if ( p->status == 1 ) {
        t->accept++;
    }
    
    // get shipping weight
    get_ship_charge(p); 
    
}

//--- Display Menu -------------------------------------------------------------
void display_menu() {
    std::cout << std::endl;
    std::cout << "For each transaction, enter package "
              << "weight and 3 dimensions.\n"
              << "Enter -1 to quit.\n" << std:: endl;
}

//--- Display Package Results  -------------------------------------------------
void display_pkgResults(Package *p, Transaction *t) {
    int width = 10;
    std::cout << std::right;
    std::cout << "Transaction: " << std::setw(width) << t->count  << std::endl;
    std::cout << "Status     : ";
        (p->status == 1)? 
            (std::cout << std::setw(width) << "Accepted"):
            (std::cout << std::setw(width) << "Rejected");
            std::cout << std::endl;
    std::cout << "Weight     : " << std::setw(width) << p->wt     << std::endl; 
    std::cout << "Cost       : "; 
        (p->status == 0)? 
            (std::cout << std::setw(width) << "-"):
            (std::cout << std::setw(width) << p->ship_cost);
            std::cout << std::endl;
    std::cout << std::endl;
}

//--- Display Transaction Results  ---------------------------------------------
void display_transResults(Transaction *t) {
    std::cout << "\nNumber of accepted packaged: " << t->accept;
    std::cout << "\nNumber of rejected packages: " << t->reject;
    std::cout << std::endl;
}

//--- Format Money Numbers -----------------------------------------------------
void format_money(){
    std::cout << std::fixed << std::showpoint << std::setprecision(2);
}

//--- Get Shipping Charge ------------------------------------------------------
void get_ship_charge(Package *p) {
    for (int i=0; i<SIZE; ++i) {
        if (p->wt <= SHIPPING_WT[i]) {
            p->ship_wt = SHIPPING_WT[i];
            p->ship_cost = SHIPPING_COST[i];
            break;
        }
    }
}

//--- Get Package Data ---------------------------------------------------------
void getPkgData(Package *p) { 
    do { 
        std::cout << "Enter package weight and 3 dimension: ";
        std::cin  >> p->wt;
        if (p->wt == -1) break; 
        std::cin  >> p->dim1;
        std::cin  >> p->dim2;
        std::cin  >> p->dim3;
        (p->wt > 50 || p->wt <= 0)?(p->status = 0):(p->status = 1);
        if (p->wt <= 0 || p->dim1 <= 0 || p->dim2 <= 0 || p->dim3 <= 0) {
            std::cout << "\nError - package weight and dimensions"
                      << " must be larger than 0" << std::endl
                      << "Please re-enter transaction\n" << std::endl;
        }
    } while (p->wt <= 0 ||  p->dim1 <= 0 || p->dim2 <= 0 || p->dim3 <= 0);
    
}

//--- Run Program --------------------------------------------------------------
void run(Package *pkg, Transaction *trans) {
    do {
        // Get User Data
        getPkgData(pkg);

        // Calculate Data
        calcPkgData(pkg, trans);

        // Display Results
        std::cout << std::endl;
        if (pkg->wt != -1) {
            display_pkgResults(pkg, trans);
        }
        std::cout << std::endl;
    } while (pkg->wt != -1);
}
