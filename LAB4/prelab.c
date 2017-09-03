/* Thomas Schultz
 * Lab: LAB4
 * SECTION: CS1050C
 * Pawprint: TJS6F2
 * TA: Dheeraj
 */

#include <stdio.h>

//prototype functions
int checkEven(int x);

int main (void) {
    int num;//delcaring variables
    int even_steven;

    printf("Enter a positive number: ");
    scanf("%d", &num);

    while(num<=0) {
        printf("Error! Enter a positive number only: ");
        scanf("%d", &num);
    }

    even_steven= checkEven(num);//call to function

    if(even_steven==1)
        printf("%d is an even number\n", num);
    else
        printf
            ("%d is an odd number\n", num);

    return 0;
}

int checkEven(int x) {//odd or even function

    int z;
    z=2;

    if(x%z==0)           
        return 1;

    return 0;
}



