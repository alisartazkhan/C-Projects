# Encryption Program

This is a C program that reads standard input, where the first input is a keyword and the rest of the lines are lines that need to be encrypted. It then puts the encrypted text as output.

## How to Use

1. Clone the repository to your local machine.
2. Compile the program using a C compiler.
3. Open the command prompt and navigate to the directory where the program is stored.
4. Enter the following command to run the program:
(Replace "program" with the name of the compiled program and "input.txt" with the name of the file containing the input text.)
5. The program will encrypt the input text and display the output on the console.

## How it Works

The program uses the `encrypt()` function to encrypt each line of the input file. The function accepts three parameters: `sentence` (a string containing characters that need to be encrypted), `key` (a string key that's used to encrypt all the sentences), and `j` (an integer variable used to keep track of the key offset). The function returns the integer value of `j`, which helps maintain the offset of the key parameter for all lines in the file.

The `encrypt()` function uses nested for loops and several variables to encrypt characters from the `sentence` parameter. It also uses the `alphabets` variable to get the alphabets in the English language.

The `main()` function reads in the keyword and the first sentence from standard input and calls the `encrypt()` function to encrypt the sentence. It then reads in the rest of the sentences from standard input, encrypts them using the `encrypt()` function, and displays the encrypted output on the console.

## Author

This program was written by Ali Sartaz Khan.
