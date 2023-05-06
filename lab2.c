# include <stdio.h>
# include <math.h>
# include <stdlib.h>
# include <cstring>

int main (){
    //part 1
    // double x;
    // double y;
    // double h;
    // double rad;
    // double theta;

    // printf("Enter X: ");
    // scanf("%lf",&x);
    // printf("Enter Y: ");
    // scanf("%lf",&y);

    // h = sqrt(x*x + y*y);
    // rad = asin(y/h);
    // theta = rad*(180/M_PI);
    

    // printf("The Hypotenuse Length is: %.1f\n",h);
    // printf("The Angle Theta is %.1f degrees",theta);

    // float x;
    // float y;

    // printf("Enter the x-coordinate in floating point: ");
    // scanf("%f",&x);
    
    // printf("Enter the y-coordinate in floating point: ");
    // scanf("%f",&y);

    // x = int(x * 100)/100;
    // y = int(y*100)/100; 
    

    // if (x == 0 && y == 0.00  ){
    //     printf("(%.2f, %.2f) is at the origin.\n",x,y);
    // }
    // else if (x == 0){
    //     printf("(%.2f, %.2f) is on the y axis.\n",x,y);
    // }
    // else if (y == 0 ){
    //     printf("(%.2f, %.2f) is on the x axis.\n",x,y);
    // }
    // else if (x>0 && y>0){
    //     printf("(%.2f, %.2f) is in quadrant I.\n",x,y);
    // }
    // else if (x<0 && y>0){
    //     printf("(%.2f, %.2f) is in quadrant II.\n",x,y);
    // }
    // else if (x<0 && y<0){
    //     printf("(%.2f, %.2f) is in quadrant III.\n",x,y);
    // }
    // else {
    //     printf("(%.2f, %.2f) is in quadrant IV.\n",x,y);
    // }

    double userbodyweight;
    char bodyweightstr[20];

    double userheight;
    char heightstr[20];

    float weightkg;
    float heightm;
    float BMI;

    printf("Enter the body weight: ");
    scanf("%s",&bodyweightstr);
    printf("Enter the height: ");
    scanf("%s",&heightstr);

    userbodyweight = atof(bodyweightstr);
    userheight = atof(heightstr);

    if(strchr(bodyweightstr, 'l') != NULL){
        userbodyweight = userbodyweight*0.4536;
    }

    if(strchr(heightstr, 'i') != NULL){
        userheight = userheight/39.37;
    }
    else if(strchr(heightstr, 'f') != NULL){
        userheight = userheight/3.28;
    }

    BMI = userbodyweight/(userheight*userheight);
    BMI = round(BMI * 10)/10;

    printf("The Body Mass Index (BMI) is: %.1f\n",BMI);

    if (BMI < 18.5){
        printf("Category: Underweight");
    }
    else if (BMI>= 18.5 && BMI<=24.9){
        printf("Category: Healthy Weight");
    }
    else if (BMI>= 25.0 && BMI<=29.9){
        printf("Category: Overweight");
    }
    else {
        printf("Category: Obesity");
    }

    return(0);
}


    




