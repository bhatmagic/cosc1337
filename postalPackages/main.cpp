// Copyright 2019 David Boyd
#include <iostream>
#include <iomanip>

//==============
//=== Stucts ===
//==============
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
void set_ship_charge(Package *p);
void format_money();
void setPkgData();
void run(Package *, Transaction *);

//========================
//=== Global Variables ===
//========================
const int SIZE = 15;
const int SHIPPING_WT[SIZE] = 
    {  1,  2,  3,  4,  5,
       7, 10, 13, 16, 20,
      25, 30, 40, 45, 50 };
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
void calcPkgData(Package *p, Transaction *t) {
    t->count++;
    if (p->dim1 > p->dim2) { p->great_dim = p->dim1; }
    else { p->great_dim = p->dim2; }
    if (p->dim3 > p->great_dim) p->great_dim= p->dim3;
    p->girth = 2*(p->dim1+p->dim2+p->dim3-p->great_dim);

    // if dim>3ft || girth>5th
    if (p->dim1 > 48 || p->dim2 > 48 || p->dim3 > 48 || p->girth > 60) {
        p->status = 0;
        t->reject++;
    } else if ( p->status == 1 ) {
        t->accept++;
    }
    
    // find shipping weight
    set_ship_charge(p); 
    
}
void set_ship_charge(Package *p) {
    for (int i=0; i<SIZE; ++i) {
        if (p->wt <= SHIPPING_WT[i]) {
            p->ship_wt = SHIPPING_WT[i];
            p->ship_cost = SHIPPING_COST[i];
            break;
        }
    }
}
void display_menu() {
    std::cout << std::endl;
    std::cout << "For each transaction, enter package "
              << "weight and 3 dimensions.\n"
              << "Enter -1 to quit.\n" << std:: endl;
}
void display_pkgResults(Package *p, Transaction *t) {
    std::cout << "Transaction: " << t->count  << std::endl;
    std::cout << "Status     : "; // << p->status << std::endl; 
    if (p->status == 1) { std::cout << "Accepted"; }
    else {std::cout << "Rejected"; }
    std::cout << std::endl;
    std::cout << "Weight     : " << p->wt     << std::endl; 
    std::cout << "Cost       : "; 
    if (p->status == 0) { std::cout << "-"; } 
    else {std::cout << p->ship_cost; }
    std::cout << std::endl;
}
void display_transResults(Transaction *t) {
    std::cout << "\nNumber of accepted packaged: " << t->accept;
    std::cout << "\nNumber of rejected packages: " << t->reject;
    std::cout << std::endl;
}
void format_money(){
    std::cout << std::fixed << std::showpoint << std::setprecision(2);
}
void setPkgData(Package *p) { 
    do { 
        std::cout << "Enter package weight and 3 dimension: ";
        std::cin  >> p->wt;
        if (p->wt == -1) break; 
        std::cin  >> p->dim1;
        std::cin  >> p->dim2;
        std::cin  >> p->dim3;
        if (p->wt > 50 || p->wt <= 0) { p->status = 0; }
        else {p->status = 1; }
        if (p->wt <= 0 || p->dim1 <= 0 || p->dim2 <= 0 || p->dim3 <= 0) {
            std::cout << "Weight and dimensions must be greater than 0.\n\n";
        }
    } while (p->wt <= 0 ||  p->dim1 <= 0 || p->dim2 <= 0 || p->dim3 <= 0);
    
}
void run(Package *pkg, Transaction *trans) {
    do {
        // Get User Data
        setPkgData(pkg);

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
