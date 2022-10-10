/*
Name: Ali Sartaz Khan
Description: Header file instantiates methods for the arrayz.c file that
performs several operations and calculations using data from an array.
*/


/*
Returns the Sum of all the long values in the array.

values: array of long values with the first value being the length 
of the number of values
*/
long sum(long values[]);


/*
Returns the index of the minimum value in the array.

values: array of long values with the first value being the length 
of the number of values
*/
long minil(long values[]); 


/*
Returns the index of the minimum value in the array.

values: array of double values with the first value being the length 
of the number of values
*/
long minid(double values[]);


/*
Returns the index of the maximum value in the array.

values: array of long values with the first value being the length 
of the number of values
*/
long maxil(long values[]);


/*
Returns the index of the maximum value in the array.

values: array of double values with the first value being the length 
of the number of values
*/
long maxid(double values[]);

/*
Prints a string representation of all the values in the array.

values: array of long values with the first value being the length 
of the number of values
*/
void printal(long values[]); 

/*
Prints a string representation of all the values in the array.

values: array of double values with the first value being the length 
of the number of values
*/
void printad(double values[]);

/*
Returns the mean of all the values in the array.

values: array of long values with the first value being the length 
of the number of values
*/
double mean(long values[]); 


/*
Returns the standard deviation of all the values in the array.

values: array of long values with the first value being the length 
of the number of values
*/
double sdev(long values[]);
