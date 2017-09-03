/* Thomas Schultz
 * Section: CS1050C
 * LAB:LAB5
 * Pawprint: TJS6F2
 * DATE: 2/27/17
 */

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void drinkMenu(void);
int errorCheck(int x);
int calculateRandomNumber(void);

int main(void) {

    int selection;

    drinkMenu();

    printf("Enter an option: ");
    scanf("%d", &selection);

    while(errorCheck(selection)==0) {
        printf("Not a valid option! Please enter again: ");
        scanf("%d", &selection);
    }

    srand(time(NULL));

    printf("The random number is %d\n", calculateRandomNumber());

    return 0;

}

void drinkMenu(void) {
    printf("What would you like to drink?\n1. Water: free\n2. Coke: $1.00\n3. Lemonade: $1.50\n4. Chocolate Milk: $1.75\n");

}

int errorCheck(int x) {

    if(x<=0 || x>=5) {
        return 0;
    }
    return 1;
}

int calculateRandomNumber(void) {

    return (1+rand()%25);
}
