# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <stdbool.h>
# include <string.h>

int main(){
    // goto function label --> use switch case instead
    one: ; 
    //
    char operation;
    int inpbase1;
    int inpbase2;
    int input1[32];
    int input2[32];
    int inputa;
    int inputb;

    // giving user a message if they entered bad data

    printf("Give input ($ to stop): ");
    scanf("%c %d %d %d %d",&operation,&inpbase1,&inputa,
    &inputb,&inpbase2);

    if (operation == '+' || operation == '-' || operation == '*'||
     operation == '/' || operation == '$'){
        if(operation == '$'){
            exit(0);
        }
    }
    else{
        printf("Invalid operator\t");
        goto one;
    }
    
    if (inpbase1  > 10 || inpbase1 < 2 || inpbase2  > 10 || inpbase2 < 2){
        printf("Invalid base\t");
        goto one;
    }
    
    int i =0;

    for (int testa = inputa; testa > 0;){ 
        i++;
        input1[i] = testa % 10;
        testa /= 10;
        if(inpbase1 <= input1[i] ){
            printf("Invalid digits in operand\t");
            goto one;
        }
    }

    for (int testb = inputb; testb > 0;){ 
        i++;
        input2[i] = testb % 10;
        testb /= 10;
        if(inpbase1 <= input2[i] ){
            printf("Invalid digits in operand\t");
            goto one;
        }
    }

    // converting bases based on user inputs
    int conva = 0;
    int convb = 0;
    int counter1 = 0;
    int counter2 = 0;

    for(int a = inputa; a>0;){
        conva += (a%10)*pow(inpbase1,counter1);
        a/= 10;
        counter1++;

    if (a <=0 ){
        printf("%d %c %d (base %d) = %d %c", inputa, operation, inputb, inpbase1, conva, operation);
    }
    }
    
    for(int b = inputb; b>0;){
        convb += (b%10)*pow(inpbase1,counter2);
        b /= 10;
        counter2++;

    if (b <=0 ){
        printf(" %d =",convb);
    }
    }

    int sum = 0;
    if (operation == '+'){
         sum = conva + convb;
    }
    else if (operation ==  '-' ){
        sum = conva - convb;
    }
    else if (operation ==  '*' ){
         sum = conva * convb;
    }
    else {
         sum = conva/ convb;
    }

    int sumstr= 0;
    int finalcounter = sum;
    int a =0;
    while (finalcounter > 0){
        finalcounter /= inpbase2;
        sumstr += (sum % inpbase2)*pow(10,a);
        a++;
        sum /= inpbase2;   
    }
    printf(" %d (base %d)\n",sumstr,inpbase2);


    // restarts code by forcing program to execute at label specified code
    goto one;//use switch case instead


    return(0);  
}