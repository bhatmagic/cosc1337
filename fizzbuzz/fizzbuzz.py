#!/usr/bin/env python3
# Copyright 2019 David Boyd, all rights reserved
# Program: <program name>
# Description:
#     <what the program does>
# Date: <today’s date>
# Revised:
#     <revision date>

# Declare variables
min = 1
max = 100

for i in range(min, max+1):
    if (i%3==0 and i%5 ==0):
        print('FizzBuzz')
    elif (i%3 == 0):
        print('Fizz')
    elif (i%5 ==0):
        print('Buzz')
    else:
        print(i)
