/*
    Author: Adrian C. Manatad
    Reason: FOR COMMISION
    DATE: APRIL 19, 2022
    CUSTOMER NAME: DUKE GARCIA

*/
// Store information of n products with descriptions (product name, manufacturing date, expiration date) using structures.
#include <stdio.h>


int main() {
     struct date { // structure tag
                int day;//member definition
                int month;//member definition
                int year;//member definition
        };

        struct details {// structure tag
                char productName[20]; //member definition
                struct date mfg;//member definition
                struct date exp;//member definition
        }item[50]; //one or more structure variables


        int n,i;

        printf("Enter number of items:");
        scanf("%d",&n);//prompt the user to input the number of items

        for (i=0;i<n;i++) {

                printf("Product %d name: ", i+1);
                fflush(stdin); // i use this just incase if the scanf reports an issue
                scanf ("%[^\n]%*c", item[i].productName);// ignores this without fflush(stdin) and accepts the spaces as string

                //scanf ("%[^\n]%s", item[i].productName); //accepts the spaces as string
                //gets(item[i].productName);//accepts the spaces as string
                //fgets(item[i].productName,20,stdin); //accepts the spaces as string

                printf("Manufacturing date(dd-mm-yyyy): ");
                scanf("%d-%d-%d",&item[i].mfg.day,&item[i].mfg.month,&item[i].mfg.year); //prompt the user to input manufacturing date with the given format

                printf("Expiration date(dd-mm-yyyy): ");
                scanf("%d-%d-%d",&item[i].exp.day,&item[i].exp.month,&item[i].exp.year); //prompt the user to input manufacturing date with the given format
        }

   printf("\n              ***  INVENTORY *****\n");

   for (i=0; i<60; i++) printf("-"); // fine without open and close brackets note that it only support on single statements
   printf("\n|  NO.  |  PRODUCT NAME  |   MFG. DATE   |   EXP. DATE|\n");
   for (i=0; i<60; i++) printf("-"); // fine without open and close brackets note that it only support on single statements
   printf("\n");

   for (i=0;i<n;i++) {
       printf("| %d     | %s     |  %d/%d/%d   |  %d/%d/%d  \n",i+1 , item[i].productName, item[i].mfg.day, item[i].mfg.month, item[i].mfg.year, item[i].exp.day, item[i].exp.month, item[i].exp.year);
   }

   for (i=0; i<60; i++) printf("-");
   printf("\n");

}
