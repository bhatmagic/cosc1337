Payroll Version 1.0
####################
:Author: David Boyd
:Date: Spring 2018

This ia a mock payroll program for Armadillo Automotive Group. This program uses a struct to hold the general employee information for one employee and an array of structs to hold the employee information for all employees.

Program Input
==============

For a payroll program you would normally input the data from files, but in this first version you will input the data from the keyboard. The program input should be in 2 parts: employee master information and timesheet information.

Employee Master information
----------------------------

The employee master information consists of the following data:

	- employee ID number (integer value)
	- employee name (your program should handle names of up to 20 characters - may contain spaces)
	- pay rate per hour (floating-point value)
	- type of employee (0 for union, 1 for management) 

Note: Uses a string class for the employee name and a struct to hold the employee master information for one employee.

Timesheet Information
-----------------------

	- number of hours worked for the week (floating-point value)

Additional Information
-----------------------

This program assume that there are exactly 4 employees. The first input is the employee master information into an array of structs. Then it uses a separate loop to do the payroll processing for each employee (input the employee's hours worked and calculate their pay.

Calculations
-------------

	- Gross Pay - Union members are paid their normal pay rate for the first 40 hours worked, and 1.5 times their normal pay rate for any hours worked over 40. Management employees are paid their normal pay rate for all hours worked (they are paid for overtime hours, but they are paid at their normal hourly rate).
	- Tax - All employees pay a flat 15% income tax.
	- Net Pay is (Gross Pay - Tax).

Input Validation
-----------------

The input should be checks for reasonable values. If a value is not reasonable, the program prints an informative error message and asks the user to re-enter the value.

	- The following data should be positive numbers (greater than 0): employee id and pay rate.
	- The following data should be non-negative (0 or larger): hours worked.
	- Employee type should be 0 or 1. 

Program Output - Payroll Report
--------------------------------

This program gathers all the required input before the payroll report is printed. It will print the payroll report to an output file.  The payroll report is formatted in a tabular (row and column) format with each column clearly labeled with a column heading. The printout is one-line for each transaction that contains:

	- employee ID number
	- name
	- gross pay
	- tax
	- net pay 

The final lines of the payroll report prints the total amount of gross pay and total amount of net pay for the week (the total for all employees).
