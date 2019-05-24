// Copyright 2019 David Boyd
#include <iostream>
#include <iomanip>
#include "main.h"

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
