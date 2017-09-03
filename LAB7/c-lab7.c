/*Thomas Schultz
 * Lab: LAB7
 * Section: CS1050C
 * Pawprint: TJS6F2
 * TA: Dheeraj
 * Date: 3/13/17
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 100

//prototypes
int check_error(int);
void set_2Darray(int[MAX][MAX], int);
void print_2Darray(int [MAX][MAX], int);
int findZeros(int [][MAX], int);
int findEvenOdd(int [][MAX], int);
void printTranspose(int[][MAX], int);
void loadDiagonal(int[][MAX], int, int[MAX]);
void print1DArray(int [], int);

int main(void) {
    //variables & initialize array
    srand(time(NULL));
    int array[MAX][MAX] = {};
    int array2[MAX]= {0};
    int num;

    printf("\nEnter the size of the 2-D array: ");
    scanf("%d", &num);

    while(check_error(num)==0){//call to check error function
        printf("Please enter a value between 1-20 only: ");
        scanf("%d", &num);
    }

    printf("\nTHE FIRST 2-D Array: \n");

    set_2Darray(array, num);//calls to function to intitialize array

    print_2Darray(array, num);//calls to function to print array

    printf("The number of zeros in the 2-D Array: %d\n", findZeros(array, num));//calls to function to find zeros

    printf("The number of Even numbers: %d\n", findEvenOdd(array, num));

    int even = findEvenOdd(array, num);//assigns function to variable

    int odd = (num*num) - even;//finds odd numbers in array

    printf("The number of Odd numbers: %d\n", odd);//prints odd numbers in array

    loadDiagonal(array, num, array2);//calls to initializes array

    printf("The primary diagonal elements in the 2-D array, loaded into a 1-D array are: ");

    print1DArray(array2, num);//calls to print diagonal array

    printf("The transpose of the 2-D Array is\n");

    printTranspose(array, num);//calls to print transpose array

    return 0;
}

int check_error(int x){//check error function

    if(x<=0 || x>=21)//only takes in numbers from 1-20
        return 0;
    else
        return 1;

}

void set_2Darray(int a[MAX][MAX], int size) {//initializes values to function

    int i;
    int j;

    for(i=0; i<size; i++) {
        for(j=0; j<size; j++) {

            a[i][j]=rand()%10;
        }
    }
}

void print_2Darray(int a[MAX][MAX], int size) {//prints 2d array

    int i;
    int j;

    for(i=0; i<size; i++) {
        for(j=0; j<size; j++) {
            printf("%3d ", a[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int findZeros(int a[][MAX], int size) {//function that finds zeros

    int i;
    int j;
    int counter;

    counter = 0;

    for(i=0; i<size; i++) {
        for(j=0; j<size; j++) {
            if(a[i][j]==0)//if ==0 then it its 0
                counter++;//bump counter
        }
    }

    return counter;
}

int findEvenOdd(int a[][MAX], int size) {//function counts even numbers

    int i;
    int j;
    int counter;

    counter = 0;

    for(i=0; i<size; i++) {
        for(j=0; j<size; j++) {
            if(a[i][j]%2==0)
                counter++;
        }
    }

    return counter;
}

void printTranspose(int a[][MAX], int size) {//function that switches columns and rows in array

    int i;
    int j;

    for(i=0; i<size; i++) {
        for(j=0; j<size; j++) {
            printf("%3d ", a[j][i]);
        }
        printf("\n");
    }
}

void loadDiagonal(int a[][MAX], int size, int dia[]) {//intitializes array

    int i;
    int j;
    int k = 0;

    for(i=0; i<size; i++) {
        for(j=0; j<size; j++){
            if(i==j) {
                dia[k]=a[i][j];
                k++;
            }
        }
    }
}

void print1DArray(int a[], int size) {//prints out diaognal array

    int i;

    for(i=0; i<size; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}
