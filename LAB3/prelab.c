/* Thomas Schultz
 * Lab: LAB3
 * Section: CS1050C
 * Pawprint: TJS6F2
 * TA: Dheeraj
 * Date: 2/13/2017
 */

#include <stdio.h>
#include <math.h>

int main(void) {

    int selection;
    int length;
    int square;
    int cube;
    int circle;

    do {
        printf("\nArea calculation\n");
        printf("(1) Square\n(2) Cube\n(3) Circle\n");

        printf("Please make a selection: ");
        scanf("%d", &selection);

        if (selection<=0 || selection>3) {
            printf("Incorrect choice\n");
        }

    }while(selection<=0 || selection>3);

    switch(selection) {

        case 1: { 
                    if (selection==1) {
                        printf("\nEnter a positive number: ");
                        scanf("%d", &length);

                        while(length <=0) {
                            printf("\nNumber can't be negative or zero.\nPlease enter a positive number: ");
                            scanf("%d", &length);
                        }
                        square=length*length;
                        printf("\nLength of the side of the square is %d", length);
                        printf("\nArea of square is %d\n", square);
                        break;

                    }
                }

        case 2: {
                    if (selection==2) {
                        printf("\nEnter a positive number: ");
                        scanf("%d", &length);

                        while(length <=0) {
                            printf("\nNumber can't be negative or zero.\nPlease enter a positve number: ");                 
                            scanf("%d", &length);
                        }
                    }

                    cube=6*length*length;
                    printf("\nLength of the side of cube is %d", length);
                    printf("\nArea of cube is %d\n", cube);
                    break;
                }

        case 3: {
                    if (selection==3) {
                        printf("\nEnter a positve number: ");
                        scanf("%d", &length);

                        while(length<=0) {
                            printf("\nNumber can't be negative or zero.\nPlease enter a positive number: ");
                            scanf("%d", &length);
                        }

                        float square=3.14159* length*length;
                        printf("\nRadius of circle is %d", length);
                        printf("\nArea of circle is %.2f\n", square);
                        break;
                    }
                }
    }

    return 0;
}


