# Project Description
#### This program will be a simplified version of the cut commandthat can be found on many unix systems, including lectura. The cut command can be used for extractingparticular characters / columns of data from the standard input and print them to standard output. scut will have less configuration options compared to the regular command.
#### This program expects to have *exactly* two command-line arguments. The first is a flag that specifies what mode to run the program in. You must support three options.
* -l stands for “letter” and specifies that the columns for the cut selections are on a per-character basis
* -w stands for “whitespace” and specifies that the cut selection columns will be separated by any
whitespace (spaces or tabs)
* -c stands for “comma” and specifies that the cut selection columns will be separated by commas, such
as from a CSV file
#### The second command-line argument will be the selection sequence. Basically, this will be a combination ofdigits, separated by commas and/or dashes. These sequences will specify which columns to print out in thefinal result from the cut command. A few examples:
* 1,3,5-7 : This sequence specifies that we want to extract columns 1, 3, 5, 6, and 7.
* 1-5,7,22,25-29 : This sequence specifies that we want to extract columns 1, 2, 3, 4, 5, 7, 22, 25, 26,
27, 28, and 29.
#### The program will get its input from standard in. The input may have multiple lines, so the program shouldcontinue reading input until it receives an EOF indicating that the program may stop processing input lines and may complete and then exit / return.
