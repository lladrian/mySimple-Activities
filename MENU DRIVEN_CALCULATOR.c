#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/*
    Author: Adrian C. Manatad
    Reason: FOR COMMISION
    DATE: JUNE 05, 2022
    CLIENT NAME: JHONAMAE PATILUNA
*/
int main()
{
 char ans;
 int num, sum=0, result, num1, num2, i, choice;
    do{
         sleep(.8);
         system("CLS");

         printf("Enter a number: ");
         scanf("%d", &num); //accept integer number

         if(num % 2 == 0){  // odd numbers
                for(i=1; i <= num/2; i++) printf("\nIterated Sum:  %d", sum=i*(i+1));
         }
         else  if(num % 2 == 1){  // even numbers
                for(i=0; i < num; i++) printf("\nIterated Sum:  %d", sum+=i+1);
         }
          printf("\n\n");
        for(i=1; i <=34; i++) printf("*");
          printf("\n* SIMPLE MENU DRIVEN - CALCULATOR*\n");
        for(i=1; i <=34; i++) printf("*");
          printf("\n*   1 - ADDITION                *\n");
          printf("*   2 - SUBTRACTION             *\n");
          printf("*   3 - MULTIPLICATION          *\n");
          printf("*   4 - DIVISION                *\n");
          printf("*   5 - MODULOS                 *\n");
        for(i=1; i <=34; i++) printf("*");

          printf("\n\nOPERATION TO PERFORM: ");
          scanf("%d", &choice);//accept float number

         if(choice >=1 && choice <= 5) {// if the value of choice is in the range then execute this
             for(i=1; i < 34; i++) printf("*");
                        num1 = sum;
                        num2 = num;
             if (choice == 1) {
                 printf("\nYOU SELECT NUMBER %d ADDITION\n", choice);
                 result = (int) (num1 + num2);
             } else if (choice == 2) {
                 printf("\nYOU SELECT NUMBER %d SUBTRACTION\n", choice);
                 result = (int) num1 - (int) num2;
             } else if (choice == 3) {
                 printf("\nYOU SELECT NUMBER %d MULTIPLICATION\n", choice);
                 result = (int) num1 * (int) num2;
             } else if (choice == 4) {
                 printf("\nYOU SELECT NUMBER %d DIVISION\n", choice);
                 result = (int) num1 / (int) num2;
             } else if (choice == 5) {
                 printf("\nYOU SELECT NUMBER %d MODULUS\n", choice);
                 result = (int) num1 - (int) num2; // convert float num into num integer
             }
             for(i=1; i < 34; i++)  printf("*");//simplify the code and to save lines
                printf("\nTOTAL IS : %d\n", result);
     } else  // if not in range display invalid choice
            printf("\nERROR! Out of range.\n\n");

    printf("\n\nDo you want to try again? (N/Y): ");
    scanf(" %c", &ans);

    if (!(ans=='y' || ans == 'Y' || ans=='n' || ans == 'N')) printf("\nError! Please try again!...\n\n\n\n");
    if (ans == 'n' || ans == 'N')  printf("\nGoodbye and Thank you.\n");

} while(ans == 'Y' || ans == 'y');

   return 0;
}
