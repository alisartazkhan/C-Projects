/*
Name: Ali Sartaz Khan
Description: Program makes a version of the cut command by taking in 
command line arguments and differentiating between flags and arguments
to call different methods and performs customized operations of the cut
command.
*/
#include <stdio.h> 
#include <stdbool.h> 
#include <string.h> 
#include <stdlib.h>

/*
  Method prints out the character in the column based on the
  parameter. Column in 1-based.

  sentence: input char string 
  num: int column number
  */
    
void letter(char* sentence, int num){
    printf("%c ", sentence[num-1]);}

/*
  Iterates through the sentence parameter and seperates columns based on 
  commas. It then prints out the word in the num column.

  sentence: input char string 
  num: int column number
  */
void comma(char* sentence, int num){
    int column = 1;
    for (int i = 0; sentence[i];i++)
    {
        char letter = sentence[i];
        if (letter == ','){column++;}
        else if (num == column)
        {
            printf("%c", letter);
            if ((sentence[i+1]) && (sentence[i+1] == ',')){printf(" ");}
        }
    }

    }


/*
  Iterates through the sentence parameter and seperates columns based on 
  whitespace. It then prints out the word in the num column.

  sentence: input char string 
  num: int column number
  */
void whiteSpace(char* sentence, int num){ 
    int column = 1;
    
    for (int i = 0; sentence[i];i++)
    {   
        // printf("%c", sentence[i]);
        char letter = sentence[i];
        if (letter == ' '){
            column++;
            while((sentence[i+1]) && (sentence[i+1] == ' ')) //avoid all whitespace
            {
                i++;
            }
            
            }
        else if (num == column)
        {
            printf("%c", letter);
            if ((sentence[i+1]) && (sentence[i+1] == ' ')){printf(" ");}
        }
    }
}


/*
  Using the start and end index, method iterates through the number string
  from those two indexes(inclusive) and then turns that range into a string 
  and returns it.

  numbers: Char string of numbers
  start: starting index
  end: ending index
  */
char * concatenateString(char* numbers, int start, int end){
    char* string = malloc(4);
    int j =0;
    for (int i=start; i<= end; i++)
    {
        char num = numbers[i];
        string[j] = num; // adding val to string variable
        j++;
    } 
    string[j+1] ='\0';
    return string;

}


/*
  Gets char string values of either 1 or 2 digit numbers or a range of numbers specified
  from the start and end indexes from the numbers. After finding all the integer values of
  those characters, it then calls the different functions based on the flag input.

  sentence: input char string 
  flag: delimiter for the command line argument
  numbers: Char string of numbers
  start: starting index
  end: ending index
  */
void getNumbers(char* sentence, char* flag, char* numbers, int start, int end){
    bool hasDash = false;
    for (int i=start; i<= end; i++)
    {
        char num = numbers[i];
        if (num == '-'){ // gets values in the range
            hasDash = true;
            char* initial = concatenateString(numbers, start, i-1);
            int first = atoi(initial);
            
            start = i+1;
            char* final = concatenateString(numbers, start, end);
            int last = atoi(final);
            

            for (int k = first; k<= last; k++)
            {
                
                if (strcmp(flag, "-l") == 0) {letter(sentence,k);} 
                else if (strcmp(flag, "-c") == 0){comma(sentence,k);}
                else if (strcmp(flag, "-w") == 0){whiteSpace(sentence,k);}
            }
            break;
        }
    }
    if (!hasDash) // gets value if there is no range
    {
        char* val = concatenateString(numbers, start,end);
        int num = atoi(val);
        if (strcmp(flag, "-l") == 0) {letter(sentence,num);} 
        else if (strcmp(flag, "-c") == 0){comma(sentence,num);}
        else if (strcmp(flag, "-w") == 0){whiteSpace(sentence,num);}
    }
}

/*
  Validates if the numbers char string contains only numbers and "-"s.

  numbers: char string of numbers argument
  */
bool isValidNumbers(char* numbers){
    if ((numbers[0] < '0') || (numbers[0] > '9')){return false;}
    if ((numbers[strlen(numbers)-1] < '0') || (numbers[strlen(numbers)-1] > '9'))
    {return false;}
    for (int i =0; numbers[i];i++)
    {   char num = numbers[i];
        if ((num == '-') || (num == ','))
        {continue;} 
        if ((num < '0') || (num > '9'))
        {
            return false;
        }
    }
    return true;
}


 /*
  Validates the flag parameter to check if it is of three options. If not, 
  returns false.

  flag: char string of delimiter from command line argument.
*/
bool isValidFlag(char* flag){
   
    if (strcmp(flag, "-c") == 0){return true;}
    if (strcmp(flag, "-l") == 0){return true;}
    if (strcmp(flag, "-w") == 0){return true;}
    return false;
}




int main(int argc, char * argv[]) {
    if (argc  !=3)
    {
        printf("expected 2 command line arguments.\n");
        exit(1);
    }

    char * flag = argv[1];
    
    if (!isValidFlag(flag) == 1)
    {
        printf("Invalid delimiter type.\n");
        exit(1);
    }
    char * numbers = argv[2]; 

    if (!isValidNumbers(numbers))
    {
        
        printf("Invalid selection.\n");
        exit(1);
    }
    char sentence[102];
    while (fgets(sentence, 102, stdin) != NULL){
        if (sentence[strlen(sentence)-1] == '\n'){ // getting rid of \n
            sentence[strlen(sentence)-1] = '\0'; 
        }
        int start = 0;
    
        for (int i=0; numbers[i]; i++) // seperating selection based on commas
        {
            char num = numbers[i];
            if (num == ','){
                getNumbers(sentence, flag, numbers, start, i-1);
                start = i+1;
            }
        
        }

        int end = strlen(numbers)-1;
        getNumbers(sentence, flag, numbers, start, end);
        printf("\n");
    }
        
    return 0;   

}
