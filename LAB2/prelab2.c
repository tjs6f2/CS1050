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

    printf("Enter the first integer\n");

    scanf("%d" , &x);

    if (x<=0) {

        printf("Error, please enter a postive integer\n");

        scanf("%d" , &x);
    }

    printf("Enter the second integer\n");

    scanf("%d" , &y);

    if (y<=0) {

        printf("Error, please enter a postive integer\n");

        scanf("%d" , &y);
    }

    sum = (x + y);

    printf("Sum is equal to %d\n", sum);

    product = (x * y);

    printf("Product is equal to %d\n", product);

    return 0;
}
