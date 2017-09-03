/*Thomas Schultz
 * Lab: LAB9
 * Section: CS1050C
 * TA: Dheeraj
 * Date: 4/3/17
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define MAX 50

//prototypes
int check_size(int);
void initialize_array(int *, int);
void print_array(int *, int);
float median(int *, int);
float mean(int *, int);
float standard(int *, int);
void sort(int *, int);

int main(void) {

    //variables
    int array[MAX] = {0};
    int *p=0;
    p=array;
    int num;

    printf("Enter the size of the input: ");
    scanf("%d", &num);

    while(check_size(num)==0) {//checks to see if number is 1-50
        printf("\nInvalid input enter the size of the array again: ");
        scanf("%d", &num);
    }

    initialize_array(p, num);//calls function to set array

    printf("\nInput Array\n");

    print_array(p, num);//calls function to print array

    printf("\nSorted Array\n");

    sort(p, num);//sorts array

    print_array(p,num);//prints sorted array

    printf("\nMedian of the array  is %0.2f", median(p, num));//finds middle #

    printf("\nStandard deviation is %0.2f\n", standard(p,num));//finds standard deviation

    return 0;
}

int check_size(int num) {//function that error checks input #

    if(num<=0 || num>50)
        return 0;
    else
        return 1;
}

void initialize_array(int *p, int size) {//sets array with random 5 numbers
    srand(time(NULL));
    int i=0;

    for(i=0; i<size; i++) {
        *(p+i) = (1+ rand()%5);
    }
}

void print_array(int *p, int size) {//prints out array
    int i=0;

    for(i=0; i<size; i++){
        printf("%d ", *(p+i));
    }
    printf("\n");
}

void sort(int *p, int size) {//sorts numbers from smallest to largest

    int keep = 0;
    int move = 0;

    for(move=1; move<size; move++){
        int i = 0;
        for(i=0; i<size-1; i++) {
            if(*(p+i) > *(p+i+1)) {
                keep = *(p+i);
                *(p+i) = *(p+i+1);
                *(p+i+1) = keep;
            }
        }
    }
}

float median(int *p, int size) {//finds average of numbers

    sort(p, size);
    float middle = 0;

    if(size%2==0) {
        middle += *(p+(size/2));
        middle += *(p+((size/2)-1));
        middle /= 2;
    }
    else 
        middle = *(p+(size-1)/2);

    return middle;
}

float mean(int *p, int size) {//finds average of array
    float mean=0;
    int i=0;

    for(i=0; i<size; i++) {
        mean = mean + *(p+i);
    }
    return mean/size;
}

float standard(int *p, int size) {//finds standard deviation

    float avg;
    mean(p, size);//calls mean function
    avg = mean(p, size);//sets avg to mean

    float sum=0;
    int i =0;

    for(i=0; i<size; i++) {
        float temp = (*(p+i)-avg);
        sum += pow(temp,2);
    }

    sum/=(size-1);
    float std = sqrt(sum);

    return std;
}





