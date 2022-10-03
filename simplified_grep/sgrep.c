
/*
Name: Ali Sartaz Khan
Description: Program makes a version of the grep command by taking in 
command line arguments and differentiating between flags and arguments
to call different methods and performs customized operations of the grep
command.
*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

/*
Checks if character is upper case and returns true or false

letter: character.

*/
int isUpper(char letter)
{
    if (letter >= 97){return 0;}
    return 1;
}


/*
Takes a char string in as a parameter and compares it to the word string. Based on the boolean
parameters, it can then identifies how to compare the strings and print which desired output.

string: char string input file line
word: char string from command line arg
hasE: boolean checks if input has -e flag
hasO: boolean checks if input has -o flag
hasI: boolean checks if input has -i flag
*/
int format(char* string,  char *word, int hasE, int hasO, int hasI)
{
    if (strlen(string)< strlen(word)){
        return false;
    }
    int len = strlen(word);
    char result[26] = {'\0'};
    
    int k;
    for (int i = 0; i< strlen(string)-len+1; i++)
    {
        int isMatching = 1;
        k = i;
        int resI = 0;
        for (int j = 0; word[j]; j++) // compare substring with word argument
        {
            char actualLetter = string[k];
            char compare = word[j];
            if (hasE && compare == '.'){
                result[resI] = string[k];
                resI++;
                k++;
                continue;}   // -----

            if (hasE && compare == '#')
            {
                char nextElem = word[j+1];
                for (; string[k] != nextElem; k++) //increment string index
                {   result[resI] = string[k];
                    resI++; // incrementing result Index
                    if(!string[k+1]){isMatching = 0; break;}
                } 
                continue;
            }
            if (hasI){
                if (isUpper(actualLetter)){actualLetter+=32;} // changing them both to lower case
                if (isUpper(compare)){compare+=32;}   
            }

            if (actualLetter != compare){isMatching = 0; break;}
            result[resI] = string[k];
            resI++; //increment resultIndex
            k++; // increment string index
        }
        if (isMatching){
            if (hasO)
            {
                printf("%s\n", result);
                
            }
           else{
                printf("%s\n", string);
                break;
            }

        }
    }

    return 0;    
}


/*
Method checks if character is a char from A-Z, a-z, or 1-9.

letter: char letter from a char string.
*/
int isValidChar(char letter)
{
    if ((letter >= 'A' && letter <= 'Z') || (letter >= 'a' && letter <= 'z') || (letter >= '0' && letter <= '9')){return 1;}
    return 0;
}
    

/*
Checks if the word in the command line arg is a valid word and returns
true or false.

word: char string from command line arg
*/
int isValidWord(char* word, int hasE)
{
    if (word[0] == '#' || word[strlen(word)-1] == '#') 
    {
        return 0;
    }
    for (int i = 0; word[i]; i++)
    {
        char letter = word[i];
        if (letter == ' '){
            if (hasE){return 0;}
            else{continue;}
        }
        if (letter == '.'){continue;}
        else if (letter == '#')
        {
            if (i-1 <0){return 0;}
            if (i+1>=strlen(word)){return 0;}
            char prev = word[i-1];
            char after = word[i+1];
            if (!isValidChar(prev) || !isValidChar(after)){return 0;}
        }
        else if (!isValidChar(letter)){return 0;}
        
        
    }
    return 1;
}



int main(int argc, char * argv[]) {
    if (argc == 1)
    {
        printf("Requires more command-line arguments.\n");
        exit(1);
    }

    int hasE = 0;
    int hasO = 0;
    int hasI = 0;
    char* word;
    for (int i = 1; i< argc; i++)
    {
        
        char * flag = argv[i];
        if (strcmp(flag, "-o") == 0) {hasO = 1;} 
        else if (strcmp(flag, "-e") == 0){hasE = 1;}
        else if (strcmp(flag, "-i") == 0){hasI = 1;}
        else {word = flag;}
    }

    if (!isValidWord(word, hasE))
    {
        printf("Invalid search term.\n");
        exit(2);
    }
   
    
    char sentence[201];
    while (fgets(sentence, 102, stdin) != NULL){
        sentence[strlen(sentence)-1] = '\0'; //change this -1
        format(sentence, word, hasE, hasO, hasI);   
    }
        
    return 0;   

}
