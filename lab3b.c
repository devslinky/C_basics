# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <stdbool.h>
# include <string.h>

int main(){
    // print r get r
    int radius;
    printf("Enter the radius of the circle: ");
    scanf("%d", &radius);

     for(int i = -1*radius; i<= radius ; i++){
        for(int j = -1*radius; j <= radius ; j++){
            if(pow(i,2) + pow(j,2)<= pow(radius,2)){
                printf("*");
            }
            else{
                printf(".");
            }
        }
        printf("\n");
    }

    return(0);  
}