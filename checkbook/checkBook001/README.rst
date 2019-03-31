Account Balancing
##################
:Author: David Boyd
:Date: Spring 2018

This program helps you balance your checkbook at the end of the month.

Instructions
=============

The user will enter the initial balance followed by a series of transactions. For each transaction, you first will have to enter a transaction type. The valid transaction types are::

    C - process a check (subtract the check amount from the current balance)
    D - process a deposit (add the deposit amount to the current balance)
    E - do end of month processing and exit the program.

For checks and deposits, you will be prompted to enter the transaction amount. 

Service Charges
----------------

	- There is a $0.35 service charge for each check written. Keep a running total of the service charges.
	- Service charges are not deducted from the account balance until the :underline: 'end of the month'.

Output
-------

After each transaction:

	- the transaction type and amount (if applicable)
	- the resulting account balance
	- the total service charges accrued so far

At the end of the month, the service charges will be deducted and the final balance will be displayed.

Input Validation
-----------------

	- If the transaction type is invalid, an informative error message will be displayed and you will have to re-enter the transaction type.
	- The transaction amount should be a positive number (larger than zero). If it is not, an informative error message will be displayed and you will have to re-enter the transaction amount. 
