Checkbook Balancing Revisited
##############################
:Author: David Boyd
:Date: Spring 2018

This program is a modified version of the Checkbook Balancing program.

Modifications
==============

	- You should enter the transaction type and amount on a single line. If there is a problem with the command (invalid transaction type or invalid amount), then an error message will be displayed and you will have to re-enter the whole command. 
    - Add additional service charges as described below.

Program Input
---------------

+----------------------+----------------------------------------------+
|  Transaction Command | Meaning                                      |
+======================+==============================================+
| C **amount**         | Process a checkout for **amount** dollars.   |
+----------------------+----------------------------------------------+
| D **amont**          | Process a deposit for **amount** dollars.    |
+----------------------+----------------------------------------------+
| E                    | Perform end-ofmonth processing & end program.|
+----------------------+----------------------------------------------+

Service Charges
----------------


	- There is a $0.35 service charge for each check written.
	- If the account balance falls below $1000.00 at any time during the month, there is a $10.00 service charge (low balance charge) for the month. If the balance stays at $1000 or more during the entire monthly statement period (program execution), there is no low balance charge for the month. Otherwise, there is a single $10.00 low balance charge for the month.
	- If processing a check results in a negative balance, there is a $30.00 service charge (insufficient funds charge). This $30.00 fee is charged for each check that results in a negative balance.
	- Note: Service charges will not be deducted from the account balance until the end of the month.

Program Output
---------------

For each transaction: 

	- the transaction type and the amount (if any)
	- the resulting account balance
	- the type and amount of any new service charges resulting from the transaction
	- the total service charges accrued so far

