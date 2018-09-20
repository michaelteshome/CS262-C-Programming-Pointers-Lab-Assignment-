/*
Michael Teshome, G-Number: 01028913
CS 262, Lab Section: 212
Lab 3
*/


#include <stdio.h>
#include <stdlib.h>
void menu(char *);//parameter is identified as a pointer by reference
char select(char *);
int numericalInput(int *);
void borderOnly(char *, int  *);
void filledIn(char *, int *);

void main(){
    char decision;
    char C ; //declares char variable
    int N = 0;
    printf("This is the menu\n to test if it works. You may press any key to start\n");
    menu(&decision);
    printf("Now you can begin adding your selection\n");
    while(decision != 'Q' || decision != 'q'){
        menu(&decision);
        switch(decision){
            case 'c':
                select(&C);
                break;
            case 'C':
                select(&C);
                break;
            case 'N':
                numericalInput(&N);
                break;
            case 'n':
                numericalInput(&N);
                break;
            case '1':
                borderOnly(&C, &N);
                break;
            case '2':
                filledIn(&C, &N);
                break;
            case 'Q':
                exit(1);
                break;
            case 'q':
                exit(1);
                break;
        
        }
    }

}

void menu(char *c){
    //NOTE: *c = choice variable in main, value
    char buffer[256];

    printf("Enter/Change Character: 'C' or 'c' \n");
    printf("Enter/Change Number: 'N' or 'n' \n");
    printf("Print Rectangle Type 1 (Border Only): 1\n");
    printf("Print Rectangle Type 2 (Filled In): 2\n");
    printf("Enter/Quit Program: 'Q' or 'q' \n");
    fgets(buffer, 256, stdin);
    sscanf(buffer, "%c", &*c);
}


char select(char *c){
    char buffer[256];
    char cip;
    printf("Enter a character");
    fgets(buffer, 256, stdin);
    //sscanf(buffer, "%c", &cip);
    sscanf(buffer, "%c", &*c); //scans a value for cip
    ///printf("Value of Pass-By-Reference variable %c \n", cip);
    ///*address of choice now equals , which means when we print choice from the main it will display 
    //the value associated with *c (reference pointer).*/
    return *c;
}

int numericalInput(int *i){
    int j;
    char buffer[256];
    printf("Enter a number between 1 and 15\n");
    fgets(buffer, 256, stdin);
    sscanf(buffer, "%d", &*i);

    if(*i < 1 || *i > 15){
        numericalInput(&*i);
    }
    else{
        return *i;
    }

}

void borderOnly(char *c, int *i){
    char arry[*i][*i];
    int x = 0;
    int y = 1;
    /*for(x = 0; x < *i; x++){
        for(y = 0; y < *i; y++){
            arry[x][0] = *c;
            
            arry[0][y] = *c;
            //arry[(int)*i][y] = *c;

            

        }
    }*/
    int row, column;
    
    for(x = 0; x < *i; x ++){
        for(y = 0; y < *i; y++){
            if(y == 0 || y == *i - 1){
                arry[x][y] = *c;
            }
            else if(x == 0 || x == *i){
                arry[x][y] = *c;
            }
            else if(x == *i - 1 && y < *i ){//optional loop
                arry[x][y] = *c;//ends here
            }
            else{
                arry[x][y] = '\0';
                
            }


        }
    }
    

    for(x = 0; x < *i; x++){
        for(y = 0; y < *i; y++){
            printf("%c", arry[x][y]);
        }
        printf("\n");
    }

}

void filledIn(char *c, int *i){
    char array[*i][*i];
    int x;
    int y;
    
    for(x = 0; x < *i; x++){
       for(y = 0; y < *i; y++){
           array[x][y] = *c;
       }
     }


   for(x = 0; x < *i; x++){
       for(y = 0; y < *i; y++){
           printf("%c", array[x][y]);
       }
       printf("\n");
   }

}

