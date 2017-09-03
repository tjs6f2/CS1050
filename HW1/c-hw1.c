/* Thomas Schultz
 * HW1
 * Section: CS1050C
 * Pawprint: TJS6F2
 * TA: Dheeraj
 * Date: 2/10/17
 */

#include <stdio.h>

int main(void) {
    //declaring variables
    int again;
    int connection;
    int kWh;
    float rate;
    int fixed_rate;
    float energy_charge;
    float total_bill;
    float grand_total=0;
    int counter=0;

    do {  //loop function

        counter++;

        printf("\n1.Residential\n2.Commercial\n3.Industrial\n"); 

        printf("Choose the type of connection: ");
        scanf("%d", &connection);

        while(connection<=0 || connection>3) { //error checker
            printf("\nInvalid Choice! Please enter a valid choice: ");
            scanf("%d", &connection);
        }

        printf("\nEnter the number of units (in kWh): ");
        scanf("%d", &kWh);

        while(kWh<=0) {//error checker
            printf("\nInvalid input! Please enter a positve number: ");
            scanf("%d", &kWh);
        }

        switch(connection) {

            case 1: { //rate for Residential use
                        if(kWh>0 && kWh<=300) {
                            (rate = 7.50);
                        }
                        else if (kWh>300 && kWh<=750) {
                            (rate = 10);
                        }
                        else if (kWh>750 && kWh<=1500) {
                            (rate = 13.5);
                        }
                        else if ( kWh>1500) {
                            (rate = 15);
                        }
                        break;
                    }

            case 2: { //rate for Commercial use
                        if(kWh>0 && kWh<=300) {
                            (rate = 10.5);
                        }
                        else if (kWh>300 && kWh<=750) {
                            (rate = 14);
                        }
                        else if (kWh>750 && kWh<=1500) {
                            (rate = 17.5);
                        }
                        else if (kWh>1500) {
                            (rate = 20);
                        }
                        break;
                    }

            case 3: { //rate for Industrial use
                        if(kWh>0 && kWh<=300) {
                            (rate = 36.5);
                        }
                        else if(kWh>300 && kWh<=750) {
                            (rate = 40);
                        }
                        else if(kWh>750 && kWh<=1500) {
                            (rate = 45.5); 
                        }
                        else if(kWh>1500) {
                            (rate = 50);
                        }
                        break;
                    }
            default: {break;}   
        }

        float r= rate/100; //formulas for charges
        energy_charge=  kWh * r;

        printf("\nEnergy charge for the customer is $%.2lf\n", energy_charge); //prints out energy charge

        if (connection==1) { //fixed charge to customer- residential
            (fixed_rate=25);
        }
        else if (connection==2) { //commercial
            (fixed_rate=90);
        }
        else if (connection==3) { //industrial
            (fixed_rate=850);
        }

        total_bill = energy_charge + fixed_rate;//formula to calculate total

        printf("\nTotal bill due from this connection is $%.2lf\n", total_bill);//prints out total bill

        printf("\nDo you want to continue and calculate another bill? If yes enter 1 or else 0: ");
        scanf("%d", &again);

        while(again !=1 && again !=0) { //terminates loop
            printf("\nError, enter correct number: ");
            scanf("%d", &again);
        }

        grand_total +=total_bill;

    }while(again == 1);

    printf("\nYou calculated the bill %d times and the total amount of bills is $%.2lf\n", counter, grand_total); 

    return 0;
}

