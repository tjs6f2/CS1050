/* Thomas Schultz
 * Section: CS1050C
 * LAB:LAB5
 * Pawprint: TJS6F2
 * DATE: 2/27/17
 */

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

//prototype functions
void drinkMenu(void);
void displayMenu(void);
void displayReceipt(void);
int errorCheck(int x);
int calculateRandomDiscount(void);
float calculateTax(float y);

int main(void) {

    int selection;//variables
    int choice;
    float total;
    float total2;
    float subtotal;
    float tax;
    float grandtotal;
    float dis;

    drinkMenu();//call to drink menu function

    printf("\nEnter an option: ");
    scanf("%d", &selection);

    while(errorCheck(selection)==0) {//call to error checker
        printf("Not a valid option! Please enter again: ");
        scanf("%d", &selection);
    }

    switch(selection) {

        case 1: {//water price
                    if(selection==1)
                        total= 0;
                    break;
                }

        case 2: {//coke price
                    if(selection==2)
                        total=1;
                    break;
                }

        case 3: {//lemonade price
                    if(selection==3)
                        total=1.5;
                    break;
                }

        case 4: {//milk price
                    if(selection==4)
                        total=1.75;
                    break;
                }
    }

    displayMenu();//call to meal menu function

    printf("\nEnter an option: ");
    scanf("%d", &choice);

    while(errorCheck(choice)==0) {//call to error checker
        printf("Not a valid option! Please enter again: ");
        scanf("%d", &choice);
    }

    switch(choice) {

        case 1: {//cheeseburger price
                    if(choice==1)
                        total2=4.50;
                    break;
                }

        case 2: {//hotdog price
                    if(choice==2)
                        total2=3;
                    break;
                }

        case 3: {//strips price
                    if(choice==3)
                        total2=5;
                    break;
                }

        case 4: {//combo price
                    if(choice==4)
                        total2=7.20;
                    break;
                }
    }


    printf("\nThank you for your order! It will be made shortly!\n");

    subtotal= total + total2;//formula for subtotal

    printf("Subtotal: $%.2f\n", subtotal);//prints subtotal

    tax = calculateTax(subtotal);//storing tax function

    printf("Taxes: $%.2f\n", tax);//call to tax function  

    srand(time(NULL));

    printf("You get a random discount of %d%% on this meal\n", calculateRandomDiscount());//call to discount function

    dis=calculateRandomDiscount();//storing discount function

    dis/=100;

    grandtotal = subtotal -(subtotal*dis) + tax;//formula for grandtotal

    printf("Total: $%.2f\n", grandtotal);

    printf("Your receipt number is: #");

    displayReceipt();//call to receipt function

    printf("\n");

    return 0;
}

void drinkMenu(void) {//drink menu function
    printf("What would you like to drink?\n1. Water: free\n2. Coke: $1.00\n3. Lemonade: $1.50\n4. Chocolate Milk: $1.75\n");

}

void displayMenu(void) {//meal menu function
    printf("\n1. Cheeseburger: $4.50\n2. Hotdog: $3.00\n3. Chicken Strips: $5.00\n4. Fries and Burge Combo: $7.20\n");
}

int errorCheck(int x) {//error check function

    if(x<=0 || x>=5) {
        return 0;
    }
    return 1;
}

float calculateTax(float y) {//tax function

    float base= .5;
    float rate;

    if(y<=4) {
        rate = y * .1 + base;
    }
    else {
        rate  = y *.25 + base;
    }

    return rate;
}

int calculateRandomDiscount(void) {//discount function

    return (1+rand()%25);
}

void displayReceipt(void) {

    int x;

    for(x=0; x<8; x++) {
        printf("%d", rand()%10);
    }
}





