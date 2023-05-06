#include <stdio.h>

int main() {
    // test case 1
    // printf("C uses escape sequences for a variety of purposes.\n");
    // printf("Some common ones are:\n");
    // printf("     to print \", use \\\" \n" );
    // printf("     to print \\, use \\\\ \n");
    // printf("     to jump to a new line, use \\n");

    //test case 2
    // float convert;
    // float foreigncurrency;
    // printf("Enter the conversion rate: ");
    // scanf("%f", &convert);
    // printf("Enter the amount to be converted (in foreign currency): ");
    // scanf("%f",&foreigncurrency);
    // float CAD = foreigncurrency * convert;
    // printf("The amount in Canadian Dollars is: %.2f",CAD);

    //test case 3

    // int number;
    // printf("Enter number to convert to base 2: "); 
    // scanf("%d",&number);
    // printf("The four digits of that number are as follows: ");
    // int lastnum = number % 2;
    // int seclastnum = (number/2)% 2;
    // int middlenum =(number/4) % 2;
    // int firstnum = (number/8)%2;

    // printf("Most significant digit: %d\n",firstnum);
    // printf("Next digit: %d\n",middlenum);
    // printf("Next digit: %d\n",seclastnum);
    // printf("Least significant digit: %d\n",lastnum);

    // testcase 4
    const double CmPerInch = 2.54;
	const double CmPerMetre = 100.00;
	const int InchesPerFoot = 12;
	const int InchesPerYard = 36;
	
	int distance;
	printf("Please provide a distance in metres: ");
	scanf("%d", &distance);
	
	double distanceInInches = distance * CmPerMetre / (CmPerInch);
    
    // yards
    float remainder = (int)distanceInInches % InchesPerYard;
    int yards = distanceInInches / InchesPerYard;
 




	// truncate fractional part to get # of inches
	int inches = distanceInInches;
	float remainder = distanceInInches - inches;
	
	// how many inches are left after extracting feet
	int feet = inches / InchesPerFoot;
    
    // how many inches are left after extracting yards
	int yards = inches / InchesPerYard;
	
	printf("%d yards, %d feet, %d inches, %.2f inches remainder\n", yards, feet, inches, remainder);

return 0;
}