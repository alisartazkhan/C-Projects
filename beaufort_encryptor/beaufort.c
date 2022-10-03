/*
Name: Ali Sartaz Khan
Description: Program reads in standard input where the first input is 
the key word and the rest of the lines are lines that need to be encrypted.
It then puts the ecrypted text as output.

*/
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>


 /*
  Function encrpyts the sentence using the key parameter. It uses nested for loops
  and uses several variables and the alphabet variable to encrypt characters from 
  the sentence parameter. Function accepts 3 parameters and returns the int value of j
  which helps maintain the offset of the key parameter for all lines in the file.

  sentence: string line in file containing characters that need to be encrypted
  key: string key that's used to encrypt all the sentences
  j: int variable used to keep track of key offset
  */
int encrypt(char sentence[], char key[], int j)
{
	
	char letter;
	char keyLetter;
    const char* alphabets = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

	for (int i=0;sentence[i];i++)
	{   
        letter = sentence[i];
        if (letter == ' '){printf(" ");} // whitespace to match formatting of the input string sentence
        else{
        if (!key[j]){j=0;} // resetting j back to 0 when it reaches end of string
        if (key[j] == ' '){i--; j++; continue;}
        keyLetter = key[j];
		j++;


         for (int k=0; alphabets[k]; k++)
        {
            char alphabet = alphabets[k];
            if (alphabet == letter)
            {
                for (int count=0; alphabets[k]; count++)
                {
                    char encryptedLetter = alphabets[count];
                    alphabet = alphabets[k];
                    if (alphabet == keyLetter)
                    {
                        printf("%c",encryptedLetter); // prints the encrypted letter
                        break;
                    }
                    k++;
                    if (!alphabets[k]){k=0;}
                    
                
                }
                break;
            
            }
            
        }
		}
	}
   
    return j;
}

int main() {
    char key[129];
    fgets(key, 128, stdin);
    key[strlen(key)-1] = '\0';
    // char newKey[strlen(key)] = removeWhitespace(key);
    char sentence[129];
    int j =0;
    fgets(sentence, 128, stdin);
    sentence[strlen(sentence)-1] = '\0';
    j = encrypt(sentence, key, j);
    while (fgets(sentence, 128, stdin) != NULL){
        printf("\n"); // newline after each line of the file is encrpypted
        sentence[strlen(sentence)-1] = '\0';
        j = encrypt(sentence, key, j); 
    }
	
    return 0;
}

