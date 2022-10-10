/*
Name: Ali Sartaz Khan
Description: C file contains the implementation of all the methods that 
are in arrayz.h. It uses loops and variables ot perform calculations and 
operations using data from array parameter.
*/

#include "arrayz.h"
#include <math.h>
#include <stdio.h>

long sum(long values[]){
    long total = 0;
    long len = values[0];
    for (int i =1; i<=len;i++)
    {
        total += values[i];
    }
    return total;
}


long minil(long values[]){
    long min = values[1];
    long minI = 1;
    long len = values[0];

    for (int i =1; i<=len;i++)
    {
        long val = values[i];
        if (val<min)
        {
            min = val;
            minI = i; // might be i-1
        }
    }
    return minI;
}


long minid(double values[]){
    double min = values[1];
    long minI = 1;
    double len = values[0];

    for (int i =1; i<=len;i++)
    {
        double val = values[i];
        if (val<min)
        {
            min = val;
            minI = i; // might be i-1
        }
    }
    return minI;
}


long maxil(long values[]){
    long max = values[1];
    long maxI = 1;
    long len = values[0];

    for (int i =1; i<=len;i++)
    {
        if (values[i]>max)
        {
            max = values[i];
            maxI = i; // might be i-1
        }
    }
    return maxI;
}


long maxid(double values[]){
    double max = values[1];
    long maxI = 1;
    double len = values[0];

    for (int i =1; i<=len;i++)
    {
        if (values[i]>max)
        {
            max = values[i];
            maxI = i; // might be i-1
        }
    }
    return maxI;

}


void printal(long values[])
{
    long len = values[0];
    printf("length %ld array:", len);
    for (int i =1; i<=len;i++)
    {
        long val = values[i];
        if (i == len){printf(" %ld", val);}
        else{printf(" %ld,", val);}

    }
}


void printad(double values[])
{
    double len = values[0];
    printf("length %d array:", (int) len); // casting len to an integer
    
    for (int i =1; i<=len;i++)
    {
        double val = values[i];
        if (i == len){printf(" %f", val);}
        else{printf(" %f,", val);}
    }
}


double mean(long values[]){
    double len =(double) values[0];
    double total = (double) sum(values);
    double avg = total/len;
    return avg;
}


double sdev(long values[]){
    double sDeviation = 0;
    long avg = (long) mean(values);
    long len = values[0];
    long new[len+1];
    new[0] = len;

    for (int i =1; i<=len;i++) // putting data into new array
    {
        long val = values[i];
        long val2 = val - avg;
        new[i] = val2*val2;
    }

    double variance = mean(new); // finds variance
    sDeviation = sqrt(variance);


    return sDeviation;

}

