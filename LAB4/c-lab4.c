/* Thomas Schultz
 * Lab: LAB4
 * SECTION: CS1050C
 * Pawprint: TJS6F2
 * TA: Dheeraj
 */

#include <stdio.h>

//prototype functions
int checkEven(int x);
int errorCheck(int y);
int checkPrime(int z);
int addDigits(int a);
void printMizzou(int b);

int main (void) {
    int num;//delcaring variables
    int numtwo;

    printf("Enter a positive number: ");
    scanf("%d", &num);

    while(errorCheck(num)==1) {//call to function--error checker
        printf("Error! Enter a positive number only: ");
        scanf("%d", &num);
    }

    if(checkEven(num)==1)//call to function--odd or even
        printf("\n%d is an even number\n", num);
    else
        printf
            ("\n%d is an odd number\n", num);

    if(checkPrime(num)==1)//call to prime function
        printf("%d is a prime number\n", num);
    else
        printf("%d is not a prime number\n", num);

    printf("The sumd of digits in %d is %d\n", num, addDigits(num));//call to addDigits function

    printf("\nEnter the second positive number: ");
    scanf("%d", &numtwo);

    while(errorCheck(numtwo)==1) {//error checker function call
        printf("Error! Enter a positive number only: ");
        scanf("%d", &numtwo);
    }

    printf("\nCalling the MIZZOU function, the output is:\n\n");

    printMizzou(numtwo);//calling printMizzou function

    return 0;
}

int errorCheck(int y) {//positive # error checker

    if(y<=0)
        return 1;

    return 0;
}


int checkEven(int x) {//odd or even function

    int z;
    z=2;

    if(x%z==0)//even or odd?         
        return 1;

    return 0;
}

int checkPrime(int z) {//prime function

    int a;

    for(a=2; a<= z/2; a++) {//prime or not prime
        if (z%a==0){
            return 0;
            break;
        }
    }  
    return 1;  
}

int addDigits(int a) {//add em up
    if(a!=0) {
        return(a%10 + addDigits(a/10));
    }
    return 0;
}

void printMizzou(int b) {//Mizzou function

    int i;

    for(i=1; i<=b; i++) {

        if(i%15==0)
            printf("MIZZOU ");     
        else if(i%3==0) 
            printf("MIZ ");       
        else if(i%5==0) 
            printf("ZOU ");
        else if((i%3!=0) && (i%5!=0))
            printf("%d ", i);
    }
    printf("\n");
}

