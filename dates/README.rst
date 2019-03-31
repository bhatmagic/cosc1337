Date Class
##########
:Author: David Boyd
:Date: Spring 2018

This program stores a date through implementing a user-defined class called: **Class**.

Member Functions
=================

	- Date constructor has no parameters.  The constructor should set the month to 1 (January), and the day to 1 and the year to 2001.
	- Set member function allows a new date to be stroed in an existing Date object. The function will have 3 integer parameters - one each for the month, day and year. The purpose of these parameters is to provide the values to be stored in the member variables of the object. 
	  
	- Validation checking on the data supplied are in the parameters as follows:

    	- The month should be between 1 and 12 (inclusive).
    	- The day should be between 1 and 31 (inclusive).
    	- The year should be between 1950 and 2020 (inclusive). 

Output
=======

Three "print" member functions will be displayed in the following formats::

       3/15/2016
       March 15, 2016
       15 March 2016

Note: These are class member functions that print the date stored in a Date object.

Run Program
============

	# Clone the repository
	# Use Make to compile, run, and clean::
        make
        make clean
