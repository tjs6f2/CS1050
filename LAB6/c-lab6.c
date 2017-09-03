/*Thomas Schultz
 * Lab: LAB6
 * Section: CS1050C
 * Pawprint: TJS6F2
 * Date: 3/06/17
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 50

//prototypes
int check_error(int);
void set_array(int[],int);
void print_array(int[],int);
int max(int[],int);
float average(int [], int);
int count(int[], int, int);

int main(void) {

    //variables
    int array[SIZE] = {0};
    int array2[SIZE] ={0};
    int num;
    int num2;
    srand(time(NULL));

    printf("Enter the size of the input: ");
    scanf("%d", &num);

    while(check_error(num)==1) {//calls error checker
        printf("\nInvalid input enter the size of the input again: ");
        scanf("%d", &num);
    }

    set_array(array, num);//calls initialzer function for array

    printf("\nInput Array 1\n");

    print_array(array, num);//calls print function for array

    printf("The maximum number is present at the index location %d in the array\n", max(array,num));//calls for max function

    printf("\nAverage of numbers in the first array is %.2f\n", average(array,num));//calls for average function

    set_array(array2, num);//calls intitializer

    printf("\nInput Array 2\n");

    print_array(array2, num);//calls print function for array

    printf("The maximum number is present at the index location %d in the array\n", max(array2,num));//calls for max function

    printf("\nAverage of numbers in the second array is %.2f\n", average(array2,num));//calls for average function

    printf("\nEnter a number: ");
    scanf("%d", &num2);

    printf("\nThe count of number %d in the first array is %d\n", num2, count(array,num,num2));//calls count function for first array

    printf("\nThe count of number %d in the second array is %d\n", num2, count(array2,num,num2));//calls count function for second array

    return 0;
}

int check_error(int x) {//error checker function

    if(x<=0 || x>50)
        return 1;

    return 0;
}

void set_array(int a[],int size) {//function that sets the values of the array

    int i;

    for(i=0; i<size; i++) {
        a[i]=(rand()%10);
    }
}

void print_array(int a[],int size) {//prints arrary

    int i;

    for(i=0; i<size; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int max(int a[],int size) {//max index function

    int i;
    int location;
    int max;

    max= a[0];
    location=0;

    for(i=0; i<size; i++) {
        if(a[i]>max) {
            max=a[i];
            location = i;
        }
    }

    return location;
}

float average(int a[], int size) {//function to average total of arrays

    int i;
    float average; 

    average = 0;

    for(i=0; i<size; i++) {
        average+=a[i];
    }
    average/=size;

    return average;
}

int count(int a[], int size, int num2) {//count function

    int i;
    int count =0;

    for(i=0; i<size; i++) {
        if(a[i]==num2) {
            count++;
        }
    }

    return count;    
}



