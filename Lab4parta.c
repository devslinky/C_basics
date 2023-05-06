#include "stdio.h"
#include "math.h"
#include "stdlib.h"

int getAscendingOrderedDigits(int number);
int getDescendingOrderedDigits(int number);

int main (){
    one: ;
    // start number
    int numin;
    printf("Enter a number (-1 to stop): ");
    scanf("%d",&numin);

    // stop command
    if (numin == -1){
        exit(0);
    }

    // checking for bad data
    if (numin < 1000){
        printf("the number is too small.");
    }
    else if(numin > 9999){
        printf("the number is too large");
    }

    printf("Number 1: %d",numin);
    int newint = numin;
    int counter = 2;
    int numdesc;
    int numasc;

// repitions 

//in case if new int is alrdy 6174
   if (newint != 6174){
    do {
        numdesc = getDescendingOrderedDigits(newint);
        numasc = getAscendingOrderedDigits(newint);
        newint = abs(numasc - numdesc); 
        printf("\nNumber %d: %d",counter,newint);
        counter++;
    } while(newint != 6174);
    printf("\nKaprekar's Constant was reached in %d iteration(s)\n",(counter-2));
   }
    else {
        printf("\nKaprekar's Constant was reached in 0 iteration(s)\n");
    }



    goto one;
    return(0);
}
    

int getAscendingOrderedDigits(int number) {
        int digits[10] = {0};
while (number > 0) {
        digits[number % 10]++;
        number /= 10;
    }
    int i = 0;
while (i < 10) {
        if (digits[i] > 0) {
        number *= 10;
        number += i;
        digits[i]--;
    } 
    else{
    i++;
    }
}
    return number;

    }

int getDescendingOrderedDigits(int number) {
    int digits[10] = {0};

    while (number > 0) {
        digits[number % 10]++;
        number /= 10;
    }
        int i = 9;
    while (i > 0) {
        if (digits[i] > 0) {
        number *= 10;
    number += i;
    digits[i]--;
    }    
    else {
    i--;
}
}
if (number<1000){
    number*= 10;
}
return number;

    }


