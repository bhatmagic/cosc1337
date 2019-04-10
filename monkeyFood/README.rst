Monkey Food
############
:Author: David Boyd
:Date: Spring 2018
:Status: COMPLETE

A local zoo wants to keep track of how many pounds of food each of its three monkeys eats each day during a typical week. This program that stores this information in a two-dimensional 3 x 7 arrray, where each row represents a different monkey and each column represents a different day of the week. This program first has the user input the data for each monkey from the keyboard. The number of pounds of food eaten by one monkey in one day is a floating-point value.

Input
######
Does not accept negative numbers.

Program creates a report that includes the following information:

	- A nicely-formatted table with a row for each monkey and a column for each day of the week showing the amount of food eaten by that monkey on that day. Be sure to include row and column labels. Format all the food amounts so that they print with the same number of decimal places. This makes the decimal points line up nicely. Note: A separate function prints this table.
	- The average amount of food eaten per day by the whole group of monkeys. This is the total food eaten by all monkeys during the week divided by seven. Note: A separate value-returning function calculates this average.
	- The least amount of food eaten on any day during the week by any one monkey. Note: A separate value-returning function finds the smallest amount of food.
	- The greatest amount of food eaten on any day during the week by any one monkey. Note: A separate value-returning function finds the largest amount of food.

The screen dialog display::

	Enter pounds of food eaten by monkey 1 on Sun: 2.9
	Enter pounds of food eaten by monkey 1 on Mon: 3.3
	Enter pounds of food eaten by monkey 1 on Tue: 2.1
	Enter pounds of food eaten by monkey 1 on Wed: 3.7
	Enter pounds of food eaten by monkey 1 on Thu: 2.2
	Enter pounds of food eaten by monkey 1 on Fri: 3.5
	Enter pounds of food eaten by monkey 1 on Sat: 3.4

	Enter pounds of food eaten by monkey 2 on Sun: 4.4
	...

Output
#######
User report will display::

	Pounds of Food Eaten by Monkey and Day of Week
	
	Monkey   Sun   Mon   Tue   Wed   Thu   Fri   Sat
	     1   2.9   3.3   2.1   3.7   2.2   3.5   3.4
	     2   4.4   4.8   4.1   3.2   5.1   2.9   2.6
	     3   1.5   2.1   3.5   2.7   2.0   1.7   2.9
	
	The average food eaten per day by all monkeys     :   9.2 pounds
	The least amount of food eaten by any monkey      :   1.5 pounds
	The largest amount of food eaten per by any monkey:   5.1 pounds

**Modularity** This program is a modular program. The main function does not contain any loops. It calls one function to input the food amounts. It calls a separate function to print the table of food eaten. And it calls a separate value-returning function to find each of the following: average food eaten, least food eaten, and most food eaten (a total of 5 functions in addition to main()).
