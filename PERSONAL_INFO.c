/*
    Author: Adrian C. Manatad
    Reason: FOR COMMISION
    DATE: JUNE 05, 2022
    CUSTOMER NAME: CHRISTINE LIM
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student {
   char fname[50];
   char lname[50];
   char town[50];
   int birthYear;
};

// function prototype
void displayINFO_ALPHA(struct student s[], int i);
void displayINFO_ID(struct student s[], int i);
void inputINFO(struct student s[], int i);
void sortingDATA (struct student s[], int i);
void saveFile(struct student s[], int i);
void readFile();


int main() {
    struct student s[5];
    int opt, id;
    int ans;

  inputINFO(s, 5); //  start to input 5 Persons
  sortingDATA (s, 5); // sorting the data
  saveFile(s, 5); // passing the data to  our file

do {
   sleep(2);
   system("CLS");
   printf("1. Display By Alphabetically\n");
   printf("2. Display By Number\n");
   printf("3. Read content from file.\n");
   printf("4. Exit\n");


   printf("\nSelect: ");
   scanf("%d", &opt);

   printf("\nValue: %d ", opt);

   switch (opt) {
        case 1:
               displayINFO_ALPHA(s, 5); // passing struct as an argument
               break;
        case 2:
               printf("\nEnter Person ID (1-5): ");
               scanf("%d", &id);
               displayINFO_ID(s, id); // passing struct as an argument
               break;
        case 3:
               readFile();
               break;
        case 4:
               exit(1);
               break;
       default:
               printf("\nError! Please try again!...\n\n\n\n");
               exit(1);
               break;
   }

    printf("\n\nWant to try again? (0/1): ");
    scanf("%d", &ans);

    if (!(ans==1 || ans == 0)) {
        printf("\nError! Please try again!...\n\n\n\n");
    }

} while(ans == 1);


   return 0;
}

void saveFile(struct student s[], int i) {
    FILE *fptr;
    int c;

    fptr = fopen("database.txt", "ab");

      if (fptr == NULL) {
         printf("\n\nFile does not exists. \n");
      } else {
         printf("\n\nThe file is now opened.\n") ;

        // Write the dataToBeWritten into the file

       for (c = 0; c < i; c++) {
         fprintf(fptr, "\n%s\t %s\t %s\t %d\t \n", s[c].fname, s[c].lname, s[c].town, s[c].birthYear);
       }
        // Closing the file using fclose()
        fclose(fptr);
      }
}

void readFile() {
    FILE *fptr = fopen("database.txt", "r");
    int ch = getc(fptr);

      if (fptr == NULL) {

         printf("\n\nFile does not exists. \n");

      } else {
          printf("\n\nReading the content of files.\n") ;
          // Write the dataToBeWritten into the file

          while (ch != EOF) {
            /* display contents of file on screen */
            putchar(ch);
            ch = getc(fptr);
          }

          if (feof(fptr))
             printf("\n End of file reached.");
          else
             printf("\n Something went wrong.");

        // Closing the file using fclose()
        fclose(fptr);
      }
}


void inputINFO(struct student s[], int i) {
   int c;
   printf("Personal Information\n\n");

for (c = 0; c < i; c++) {

   printf("Person %d Fname: ",c+1);
   scanf("%s", s[c].fname);

   printf("Person %d Lname: ",c+1);
   scanf("%s", s[c].lname);

   printf("Person %d Town: ",c+1);
   scanf("%s", s[c].town);

   printf("Person %d Year of Birth: ",c+1);
   scanf("%d", &s[c].birthYear);

   if(s[c].fname[0]  >= 'a' && s[c].fname[0]) {
             s[c].fname[0] = s[c].fname[0] -  32; //convert to uppercase
   }

   if(s[c].lname[0]  >= 'a' && s[c].lname[0] <= 'z') {
             s[c].lname[0] = s[c].lname[0] -  32; //convert to uppercase
   }

   if(s[c].town[0]  >= 'a' && s[c].town[0]  <= 'z') {
             s[c].town[0] = s[c].town[0] -  32; //convert to uppercase
   }

   printf("\n");
}

}

void displayINFO_ALPHA(struct student s[], int i) {
   int x;

   printf("\nDisplaying information\n");
    for(x=0; x<i; x++) {
        printf("\nlname: %s", s[x].lname);
    }

}

void sortingDATA (struct student s[], int i) {
    int x, y;
    char temp1[99];
    char temp2[99];
    char temp3[99];
     int temp4;

    for(x=0;x<i;x++){
          for(y=x+1;y<i;y++){
             if(strcmp(s[x].lname, s[y].lname)>0){
                strcpy(temp1, s[x].fname); // temp
                strcpy(temp2, s[x].lname); // temp
                strcpy(temp3, s[x].town); // temp
                temp4 =  s[x].birthYear; // temp

                strcpy(s[x].fname, s[y].fname); // swap x to y
                strcpy(s[x].lname, s[y].lname); // swap x to y
                strcpy(s[x].town, s[y].town); // swap x to y
                s[x].birthYear = s[y].birthYear; // swap x to y

                strcpy(s[y].fname, temp1); // swap y to temp1
                strcpy(s[y].lname, temp2); // swap y to temp2
                 strcpy(s[y].town, temp3); // swap y to temp3
                s[y].birthYear = temp4; // swap y to temp4
             }
          }
    }
}


void displayINFO_ID(struct student s[], int i) {
   printf("\nDisplaying information\n");

   printf("\nFname: %s", s[i-1].fname);
   printf("\nLname: %s", s[i-1].lname);
   printf("\nTown: %s", s[i-1].town);
   printf("\nYear of Birth: %d\n", s[i-1].birthYear);
}
