/*Thomas Schultz
 * HW2
 * Section: CS1050C
 * Pawprint: TJS6F2
 * TA: Dheeraj
 * Date:
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 13

//prototypes
void display_menu();
int error_check(int);
void shuffle(int[]);
int draw_card(int[]);
int lucky_seven(int);
int high_card(int, int);
double calculate_winnings(int, int, double);

int main(void) {
    //variables
    srand(time(NULL));
    int game;
    double bet;
    int card;
    int card2;
    int win;
    int loss;
    double startfunds;
    double newfunds;

    int array [SIZE]={0};//initializing array
    int array2 [SIZE]={0};

    printf("\nWelcom to the Guilliams Casino!\n");

    do {//loops entire program until you exit 

        startfunds=100;

        do {//loop that calls error check function

            display_menu();//calls menu function

            scanf("%d", &game);

        }while(error_check(game)==0);//end of loop

        if(game==3)//exits program
            exit(0);

        printf("\nHow much do you want to bet? $");//place $$ bet
        scanf("%lf", &bet);

        switch(game) {//selects which game to be played

            case 1: {//lucky seven game 
                        printf("\nLucky Seven\n");

                        shuffle(array);//calls shuffle function

                        card = draw_card(array);//sets variable card to draw card function

                        printf("You drew %d.\n", card);//calls draw card function

                        if(lucky_seven(card)==1){ //sets parameters for game
                            win=1;
                            printf("You won $%.2lf", calculate_winnings(game, win, bet));
                        }
                        else {
                            loss = 0;
                            printf("You lost $%.2lf. Too bad.\n", calculate_winnings(game, loss, bet));
                        }

                        break;
                    }

            case 2: {//high card game
                        printf("High Card\n");

                        shuffle(array);
                        shuffle(array2);

                        card = draw_card(array);
                        card2 = draw_card(array2);

                        printf("You drew %d.The dealer drew %d.\n", card, card2);

                        if(high_card(card, card2)==1) {
                            win=1;
                            printf("You won $%.2lf\n", calculate_winnings(game, win, bet));
                        }
                        else {
                            loss=0;
                            printf("You lost $%.2lf. Too bad.\n", calculate_winnings(game, loss, bet));
                        }

                        break;

                    }
        }


    }while(game==1 || 2);//end of loop

    if(game==1 && win==1)
        newfunds = startfunds + (bet*7);
    else if(game==1 && loss==0)
        newfunds = startfunds - bet;

    printf("Your total money is $%.2lf.\n", newfunds);


    return 0;
}

void display_menu() {//display function. displays game options

    printf("\n\nWhich game do you want to play?\n");

    printf("1)Lucky Seven\n2)High Card\n3)Exit\n");
}

int error_check(int x) {//error check functions. checks to see if users input is valid

    if(x<=0 || x>=4) {
        printf("\nInvalid choice; Try again.\n");
        return 0;
    }
    else
        return 1;
}

void shuffle(int a[]) {//initializes values to array

    int i;
    int k;
    int swap;

    for(i=0; i<SIZE; i++) {//loads array with random numbers
        a[i]=1+(rand()%13);
    }

    for(i=0; i<SIZE; i++) {//shuffles array
        k = 1+(rand()%13);
        swap = a[i];
        a[i] = a[k];
        a[k] = swap;
    }
}

int draw_card(int a[]) {//function that prints out single value 

    int i;

    for(i=0; i<1; i++) {
        a[i] = a[i-1];

    }

    return a[i];
}

int lucky_seven(int x) {//lucky seven function

    if(x==7)
        return 1;
    else
        return 0;
}

int high_card(int x, int y) {//high card function

    if(x>y) 
        return 1;
    else 
        return 0;
}

double calculate_winnings(int type, int outcome, double amount) {//functions that returns $$ amount won/loss

    double total;

    if(type==1 && outcome==1) {

        total = amount * 7;
        return total;
    }
    else 
        return amount;

    if(type==2) 
        return amount;
}






