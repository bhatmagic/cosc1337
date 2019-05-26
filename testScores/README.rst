Test Scores
###########
:Author: David Boyd
:Date: Summer 2019
:Status: Complete

This program processes test scores for a class.

Input Data
==========

Input a test grade (integer value) for each student in the class.

Validation
----------

Tests are graded on a 100 point scale with a 5 point bonus question.  So a valid grade should be 0 through 105, inclusive.

Processing
----------

Works for any number of students.  When the program starts, it asks the user for the number of students to be processed.  The is uses the *new* operator to dynamically allocate an array of that size.  The program then:

	- Calls a function to input and validate the student grades and stores them in the array.
	- Calls a function to sort the array in ascending (increasing) order.
	- Calls a value-returning function that returns the floating-point average of the grades.
	- Calls a function that displays a neat table of student grades in sorted order.  Includes the appropriate column headings for the table and average score with appropriate label.

In general, this program uses array notation when processing arrays becuase it makes the code easier to read and understand.  However, this program implements only pointer notation in the function to calculate the average.  That is, it declares the array parameter using pointer notation instead of array notation to access the array elements.  

Sample Output
=============

The student's name will be displayed along with the grade.  A struct holds the name and grade for one student.  The name is a C++ string object.  The array will now be an array of structs.  The sample display output looks like this::

	Name			Score
	---------------------
	Jim Smith          75
	Victor Montero     81
	Christa Kim        88
	---------------------
	Average          81.3
