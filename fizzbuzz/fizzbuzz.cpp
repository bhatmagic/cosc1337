/* Copyright 2019 David Boyd
* FizzBuzz:
*      Prints          :  1-100
*      Multiples of 3  : print Fizz
*      Multiples of 5  : print Buzz
*      Multiples of 3&5: print FizzBuzz
*/
#include <iostream>

int main(void) {
    
    for (int i=1; i<101; ++i) {
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
