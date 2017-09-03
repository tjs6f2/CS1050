/*Thomas Schultz
 * Lab: LAB3
 * Section: CS1050C
 * TA: Dheeraj
 * Date: 2/13/17
 */

#include <stdio.h>
#include <math.h>

int main(void) {
    //declaring variables
    int account;
    double principal;
    double rate;
    int year;
    double total_amount;
    double interest;

    do{
        printf("\nBank account type\n");

        printf("\n(1)Checking\n(2)Saving\n(3Fixed Deposit\n");//selection for accounts

        printf("Please make a selection: ");
        scanf("%d", &account);

        if(account<=0 || account>3) {
            printf("Inccorect choice, please make a choice agian\n ");
        }


    } while(account<=0 || account>3);//error checker for right account #

    switch(account) {

        case 1: {//checking account
                    if(account==1) { 
                        rate=.05;
                    }

                    break;
                }

        case 2: {//saving account
                    if(account==2) {
                        rate=.10;
                    }

                    break;
                }

        case 3: { //fixed deposit
                    if(account==3) {
                        rate=.15;
                    }
                    break;
                }
    }

    printf("\nEnter a year: ");
    scanf("%d", &year);

    while(year<=0 || year>10) {//error checker for correct year
        printf("Incorrect value, year should be between 1-10\nEnter a year: ");
        scanf("%d", &year);
    }

    printf("\nEnter the amount: ");
    scanf("%lf", &principal);

    while(principal<=0) {//error checker for correct amount
        printf("\nIncorrect value, enter the amount again\nEnter the amount: ");
        scanf("%lf", &principal);
    }

    total_amount = principal * pow(1 + rate, year);//formula for total amount

    printf("\nThe amount after %d years is $%.2lf\n", year, total_amount);

    interest = total_amount - principal;//formula for interest

    printf("Total interest earned on the amount $%.2lf with the rate %.2lf is $%.2lf\n", principal, rate, interest);

    return 0;
}






