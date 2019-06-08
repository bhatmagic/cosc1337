// Copyright 2019 David Boyd
#include <iostream>

int main(void) {
    int min = 1,
        max = 100;
    
    for (int i=min; i<max+1; ++i) {
        if (i%3==0 && i%5==0)
            std::cout << "FizzBuzz\n";
        else if (i%3==0)
            std::cout << "Fizz\n";
        else if (i%5==0)
            std::cout << "Buzz\n";
        else 
            std::cout << i << std::endl;
    }

    return 0;
}
