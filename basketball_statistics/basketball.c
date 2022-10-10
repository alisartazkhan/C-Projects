/*
Name: Ali Sartaz Khan
Description: Program iterates through the lines of a file and 
finds data on particular players for each line. Using that data, 
it compares data of all the players mentioned in the file and prints
out several factoids about their performances at the end.
*/
#include <math.h>
#include <stdio.h>
#include "arrayz.h"
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

/*
Using the start and end index, method iterates through the number string
from those two indexes(inclusive) and then turns that range into a string,
converts into an integer and returns it.

number: Char string of numbers
start: starting index
end: ending index
*/
int concatenateString(char* number, int start, int end){
   char num[3];
   int j = 0;
   for (int i= start; i<=end;i++)
   {
        num[j] = number[i];
        j++;
   }
   num[j] = '\0';
   int res = atoi(num);
    return res;

}


/*
Iterates through a line of the file and finds the name of players and adds data to arrays for the points, 
assists, rebounds.

line: String array of characters in the line
listIndex: index of the playerNameList
playerNameList: list of all the names of the players
points: array containing all the points of a player
rebounds: array containing all rebounds of a player
assistsL array containing all assists of a player
*/
void getStatistics(char* line, int listIndex, char  playerNameList[100][51], long points[], long rebounds[], 
long assists[]){
        int statIndex = 1; //index for statistics arrays
        int bracketCount = 0;
        bool inBracket = false;
        char bracketString[9];
        int insideBracketIndex = 0;
        int elems = 0;
        for(int i=0;line[i];i++){
            char character = line[i];
            if (character == '[' && bracketCount <1){ // end of name of player
                playerNameList[listIndex][i] = '\0';
                bracketCount++;
                }
            if (bracketCount<1){playerNameList[listIndex][i] = line[i];}
            if (character == '['){
                elems ++;
                inBracket = true; 
                insideBracketIndex = 0;
                continue;
            }
            if(character == ']'){
                bracketString[insideBracketIndex] = '\0'; 
                inBracket = false;
                int start = 0;
                int values[3];
                int k = 0;
                for (int j=0; bracketString[j]; j++) // seperating string based on commas
                {
                    char num = bracketString[j];
                    if (num == ','){
                        int val = concatenateString(bracketString, start, j-1);
                        values[k] = val;
                        k++;
                        start = j+1;
                    }
                
                }
                int end = strlen(bracketString)-1;
                values[k] = concatenateString(bracketString, start, end);
                
                points[statIndex] = values[0];
                rebounds[statIndex] = values[1];
                assists[statIndex] = values[2];
                statIndex++;
                continue;}
            if (inBracket){
                bracketString[insideBracketIndex] = line[i];
                insideBracketIndex++;
            }   
        }
        points[0] = statIndex-1; // setting length as the first elem
        rebounds[0] = statIndex-1;
        assists[0] = statIndex-1;
}


/*
Print out the statistics of the data collected from the file using arrays in the 
parameter.

meanPoints: arrays containing double values of mean points of all players 
meanRebounds: arrays containing double values of mean rebounds of all players 
meanAssists: arrays containing double values of mean assists of all players 
stdevPoints: arrays containing double values of standard deviation of points of all players 
stdevRebounds: arrays containing double values of standard deviation of rebounds of all players 
stdevAssists: arrays containing double values of standard deviation of assists of all players 

*/
void printStatistics(char playerNameList[100][51], double meanPoints[], double meanRebounds[],double meanAssists[],
double stdevPoints[], double stdevRebounds[], double stdevAssists[]){

    char* mostConsistentScorer = playerNameList[minid(stdevPoints)-1];
    char* mostConsistentRebounder = playerNameList[minid(stdevRebounds)-1];
    char* mostConsistentAssister = playerNameList[minid(stdevAssists)-1];
    char* leastConsistentScorer = playerNameList[maxid(stdevPoints)-1];
    char* leastConsistentRebounder = playerNameList[maxid(stdevRebounds)-1];
    char* leastConsistentAssister = playerNameList[maxid(stdevAssists)-1];
    char* bestScorer = playerNameList[maxid(meanPoints)-1];
    char* bestRebounder = playerNameList[maxid(meanRebounds)-1];
    char* bestAssister = playerNameList[maxid(meanAssists)-1];
    char* leastScorer = playerNameList[minid(meanPoints)-1];
    char* leastRebounder = playerNameList[minid(meanRebounds)-1];
    char* leastAssister = playerNameList[minid(meanAssists)-1];

    printf("most consistent scorer: %s\n", mostConsistentScorer);
    printf("most inconsistent scorer: %s\n", leastConsistentScorer);
    printf("highest scorer: %s\n", bestScorer);
    printf("lowest scorer: %s\n",leastScorer);
    printf("most inconsistent rebounder: %s\n", leastConsistentRebounder);
    printf("most consistent rebounder: %s\n", mostConsistentRebounder);
    printf("highest rebounder: %s\n", bestRebounder);
    printf("lowest rebounder: %s\n", leastRebounder);
    printf("most inconsistent assister: %s\n", leastConsistentAssister);
    printf("most consistent assister: %s\n",mostConsistentAssister);
    printf("lowest assister: %s\n", leastAssister);
    printf("highest assister: %s\n", bestAssister);
}


int main(int argc, char *argv[]){

    if (argc > 2)
    {
        printf("expects 1 command line argument");
        return 1;
    }
    char * filePath = argv[1];
    FILE * file;
    file = fopen(filePath, "r");
    if (file == NULL) { 
        fprintf(stderr, "error opening the file.\n");
        return 1;
    }

    char line[1052];
    char playerNameList[100][51];
    int listIndex = 0; // lineNumber - 1
    double meanPoints[101];
    double meanRebounds[101];
    double meanAssists[101];
    double stdevPoints[101];
    double stdevRebounds[101];
    double stdevAssists[101];
    while(fgets(line, 1051, file) != NULL)
    {   long points[101];
        long rebounds[101];
        long assists[101];
        getStatistics(line, listIndex, playerNameList, points, rebounds, assists);
        meanPoints[listIndex+1] = mean(points);
        meanRebounds[listIndex+1] = mean(rebounds);
        meanAssists[listIndex+1] = mean(assists);
        stdevPoints[listIndex+1] = sdev(points);
        stdevRebounds[listIndex+1] = sdev(rebounds);
        stdevAssists[listIndex+1] = sdev(assists);
        listIndex++; // 1 based line numbers
    }
    meanPoints[0] = listIndex; // adding size val to arrays
    meanRebounds[0] = listIndex;
    meanAssists[0] = listIndex;
    stdevPoints[0] = listIndex;
    stdevAssists[0] = listIndex;
    stdevRebounds[0] = listIndex;
    printStatistics(playerNameList, meanPoints, meanRebounds, meanAssists, stdevPoints, 
    stdevRebounds, stdevAssists); // print statistics
    fclose(file);
    return 0;

}


