/* Thomas Schultz
 * Lab: LAB2 
 * Section: C
 * Pawprint: TJS6F2
 * TA: Dheeraj 
 * DATE: 1/30/17
 */

#include <stdio.h>

int main(void) {

    int x;
    int y;
    int sum;
    int product;
    float  division;

    printf("Enter the first integer\n");

    scanf("%d", &x);

    if (x<0) {

        printf("Error, please enter a positve integer\n");

        scanf("%d", &x);
    }

    printf("Enter the second integer\n");

    scanf("%d", &y);

    if (y<0) {

        printf("Error, please enter a postive integer\n");

        scanf("%d", &y);
    }

    sum = (x+ y);

    printf("Sum is equal to %d\n", sum);

    product = (x * y);

    printf("Product is equal to %d\n", product);

    division =  (float)x /  (float)y ;

    if (y==0) {
        printf("Cannot divide by zero!\n");
        printf("Enter a new number\n");
        scanf("%d",&y);
    }

    division = (float)x/ (float)y ;

    printf("Division is equal to %.2f\n", division);

    if (x>=y) {

        if(x>=y)
            printf("%d is the largest number.\n", x);
        else
            printf("%d is the largest number.\n", y);
    }


    return 0;
}
