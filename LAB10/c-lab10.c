/*Thomas Schultz
 * LAB: LAB10
 * Section: CS1050C
 * TA: Dheeraj
 * Date: 4/10/2017
 */

#include <stdio.h>
#include <stdlib.h>

//prototypes
int loadNumbers(char *, int *, int);
void printNumbers(int *, int);

int main(int argc,char *argv[]) {

    if(argc!=4) {
        printf("Incorrect number of arguments\n");
        return 0;
    }

    int size=(atoi(argv[1]));
    int *a=malloc(sizeof(int)*size);
    int *b=malloc(sizeof(int)*size);

    int load=loadNumbers(argv[2], a, size);

    if(load==0) {
        printf("UNABLE TO OPEN FILE");
        return 0;
    }

    int load2=loadNumbers(argv[3], b, size);

    if(load2==0){
        printf("UNABLE TO OPEN FILE");
        return 0;
    }

    printf("The numbers in %s are:\n", argv[2]);
    printNumbers(a, size);

    printf("The numbers in %s are:\n", argv[3]);
    printNumbers(b, size);

    return 0;
}

int loadNumbers(char *name, int *array, int size) {

    FILE *fptr;

    fptr=fopen(name, "r");

    if(fptr==NULL) {
        return 0;
    }

    int i;

    for(i=0; i<size; i++) {

        fscanf(fptr, "%d", (array +i));
    }
    fclose(fptr);

    return 1;
}

void printNumbers(int *array, int size) {

    int i;

    for(i=0; i<size; i++) {
        printf("%d ", *(array+i));
    }
}


