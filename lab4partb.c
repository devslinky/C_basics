#include "stdio.h"
#include "stdlib.h"
#include "math.h"


int functioncheck(int check);

int main(){
     a: ;
    int inputed[3];
  
    // gets user input
    int input = functioncheck(input);

    if (input > 3){
       printf("The order must be between [0, 3].\n");
       goto a; 
    }
    else{
        for (int i = 0; i<= input;i++ ){
            printf("Enter coefficient of x^%d: ",i);
            scanf("%d",&inputed[i]);
        }
    }
    // generates function points 
    
   // not working????? 
    int yarr[22] = {100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100}; 


    int cases[22];
    int counter= 0;

    if (input == 0){
        for (int x = -10; x <= 9; x++) {
            cases[counter] = inputed[0]*pow(x,0);
            if (cases[counter] <= 10 && cases[counter] >= -10 ){
            yarr[counter] = cases[counter];
            }
             counter++;
        }
    }
    else if (input == 1){
         for (int x = -10; x <= 9; x++) {
            cases[counter] = inputed[0]*pow(x,0) + inputed[1]*pow(x,1);
            if (cases[counter] <= 10 && cases[counter] >= -10 ){
            yarr[counter] = cases[counter];
            
            }
            counter++;
        }
    }
    else if (input == 2){
         for (int x = -10; x <= 9; x++) {
            cases[counter] = inputed[0]*pow(x,0) + inputed[1]*pow(x,1) + inputed[2]*pow(x,2) ;
            if (cases[counter] <= 10 &&  cases[counter] >= -10 ){
            yarr[counter] = cases[counter];
            
            }
            counter++;
         }
    }
    else if (input == 3){
         for (int x = -10; x <= 9; x++) {
            cases[counter] = inputed[0]*pow(x,0) + inputed[1]*pow(x,1) + inputed[2]*pow(x,2) + inputed[3]*pow(x,3);
            if (cases[counter] <= 10 && cases[counter] >= -10 ){
            yarr[counter] = cases[counter];
            }
            counter++;
        }
      
    }
    for (int c = 0; c<= 19; c++){
        printf("%d ", yarr[c]);
    }
    printf("\n");


    // makes a 2d grid and plots the graph



    // 11 iters   --  
    for (int yaxis=10; yaxis >= -9; yaxis--){
        printf("\n");
        for (int xaxis = 0; xaxis <= 20; xaxis++){
             
            if(yarr[xaxis] == yaxis && yarr[xaxis]<100){
                printf("*");
                printf("  ");
            }
            else if (yaxis == 0 && yarr[xaxis] != yaxis ){
                printf("-");
                printf("  ");
            }
            else if (xaxis == 10 && yaxis!=0 && yarr[xaxis]!= yaxis){
                printf("|");
                printf(" ");
            }
            else{
                printf("   ");
            }
        }
    }

    // for (int yaxis=-10; yaxis <= 9; yaxis++){
    //     printf("\n");
    //     for (int xaxis = -10; xaxis <= 9; xaxis++){
    //     printf("   ");
    //     if(yaxis == 0){
    //         printf("-");
    //      }
    //     if(xaxis == 1 && yaxis!=0 ){
    //         printf(" |");
    //      }
    //     }
    // }
    return(0);
}
int functioncheck(int check) {
    printf("Enter the order of the function: ");
    scanf("%d",&check);
     if(check > 3 || check < 0){
        check += 10;
    }
    return check;
}


