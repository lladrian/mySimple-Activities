/* 
     Author : Adrian C. Manatad
       Date : February 25, 2022
     Reason : for commission
*/
#include<stdio.h>
#include<conio.h>

int main()
{
  int combination[5], i, j, k;

  int counterHL[5];
  int takenB[5][1];
  int takenI[5][1];
  int takenN[5][1];
  int takenG[5][1];
  int takenO[5][1];
  char opt;

   int arr[5][5] = {{1,17,37,51,67},
                   {2,18,36,50,69},
                   {3,19,35,49,68},
                   {12,16,32,47,75},
                   {10,21,38,48,74}
                  };



do {

    int counterLX=0, counterRX=0;
    int counterBV=0, counterIV=0, counterNV=0, counterGV=0, counterOV=0;

    system("cls");

  for(i=0;i<5;i++) {
        counterHL[i]=0;
     for(j=0;j<5;j++) {
        if(i==0) takenB[j][i] = 0;
        if(i==1) takenI[j][i] = 0;
        if(i==2) takenN[j][i] = 0;
        if(i==3) takenG[j][i] = 0;
        if(i==4) takenO[j][i] = 0;
    }
  }

/*
  printf("Please insert number first.\n");

 // begin to stored numbers for bingo cards
  for(i=0; i<=4; i++) { //control the number of rows
     for(j=0; j<=4; j++) { //control the number of columns
         printf("arr[%d][%d]: ",i,j);
         scanf("%d",&arr[i][j]);
     }
  }
  //inserting value ends
*/


   for(i=0; i<=4; i++) { //control the number of rows
        if(i==0) {
            for(k=0;k<=30;k++) printf("-");

            printf("\n|  B  |  I  |  N  |  G  |  O  |\n");
        }
           for(k=0;k<=30;k++) printf("-");

            printf("\n");

     for(j=0; j<=4; j++) { //control the number of columns
         if (arr[i][j] < 10) {
            printf("|  %d  ",arr[i][j]);
             if(j==4) {
                printf("|");
             }
         } else {
            printf("|  %d ",arr[i][j]);
             if(j==4) {
                printf("|");
             }
         }


     }
       if(i==4) {
         printf("\n");
            for(k=0;k<=30;k++) printf("-");
       }
     printf("\n");
  }

   printf("\nPicked 5 lucky number combination. \n\n");

   for(i=0; i<=4; i++) {
       printf("Lucky Number: ");
       scanf("%d",&combination[i]);
   }

   printf("\n");

   //Rules of the game
   for(i=0; i<5; i++) {
        for(j=0; j<5; j++) {

            if(i==0) {
                  if(arr[0][0]==combination[j] && takenB[0][0] != 1) {
                        counterLX++;
                        counterBV++;
                        counterHL[i]++;
                        takenB[0][0] = 1;
                        printf("Checked: %d\n", combination[j]);
                  } else if(arr[0][1]==combination[j] && takenI[0][1] != 1) {
                        counterIV++;
                        counterHL[i]++;
                        takenB[0][1] = 1;
                        printf("Checked: %d\n", combination[j]);
                  } else if(arr[0][2]==combination[j] && takenN[0][2] != 1) {
                        counterNV++;
                        counterHL[i]++;
                        takenB[0][2] = 1;
                        printf("Checked: %d\n", combination[j]);
                  } else if(arr[0][3]==combination[j] && takenG[0][3] != 1) {
                        counterGV++;
                        counterHL[i]++;
                        takenB[0][3] = 1;
                        printf("Checked: %d\n", combination[j]);
                  } else if(arr[0][4]==combination[j] && takenO[0][4] != 1) {
                        counterRX++;
                        counterOV++;
                        counterHL[i]++;
                        takenO[0][4] = 1;
                        printf("Checked: %d\n", combination[j]);
                  }
            } else if(i==1){
                   if(arr[1][0]==combination[j] && takenB[1][0] != 1) {
                        counterBV++;
                         counterHL[i]++;
                        takenB[1][0] = 1;
                        printf("Checked: %d\n", combination[j]);
                  } else if(arr[1][1]==combination[j] && takenI[1][1] != 1) {
                        counterLX++;
                        counterIV++;
                        counterHL[i]++;
                        takenI[1][1] = 1;
                        printf("Checked: %d\n", combination[j]);
                  } else if(arr[1][2]==combination[j] && takenN[1][2] != 1) {
                        counterNV++;
                       counterHL[i]++;
                        takenN[1][2] = 1;
                        printf("Checked: %d\n", combination[j]);
                  } else if(arr[1][3]==combination[j] && takenG[1][3] != 1) {
                        counterRX++;
                        counterGV++;
                         counterHL[i]++;
                        takenG[1][3] = 1;
                        printf("Checked: %d\n", combination[j]);
                  } else if(arr[1][4]==combination[j] && takenO[1][4] != 1) {
                        counterOV++;
                         counterHL[i]++;
                       takenO[1][4] = 1;
                        printf("Checked: %d\n", combination[j]);
                  }
            }  else if(i==2){
                   if(arr[2][0]==combination[j] && takenB[2][0] != 1) {
                        counterBV++;
                         counterHL[i]++;
                       takenB[2][0] = 1;
                        printf("Checked: %d\n", combination[j]);
                  } else if(arr[2][1]==combination[j] && takenI[2][1] != 1) {
                        counterIV++;
                        counterHL[i]++;
                          takenI[2][1] = 1;
                        printf("Checked: %d\n", combination[j]);
                  } else if(arr[2][2]==combination[j] && takenN[2][2] != 1) {
                        counterLX++;
                        counterRX++;
                        counterNV++;
                        counterHL[i]++;
                         takenN[2][2] = 1;
                        printf("Checked: %d\n", combination[j]);
                  } else if(arr[2][3]==combination[j] && takenG[2][3] != 1) {
                        counterGV++;
                         counterHL[i]++;
                         takenG[2][3] = 1;
                        printf("Checked: %d\n", combination[j]);
                  } else if(arr[2][4]==combination[j] && takenO[2][4] != 1) {
                        counterOV++;
                        counterHL[i]++;
                        takenO[2][4] = 1;
                        printf("Checked: %d\n", combination[j]);
                  }
            } else if(i==3){
                   if(arr[3][0]==combination[j] && takenB[3][0] != 1) {
                        counterBV++;
                        counterHL[i]++;
                        takenB[3][0] = 1;
                        printf("Checked: %d\n", combination[j]);
                  } else if(arr[3][1]==combination[j] && takenI[3][1] != 1) {
                        counterRX++;
                        counterIV++;
                        counterHL[i]++;
                        takenI[3][1] = 1;
                        printf("Checked: %d\n", combination[j]);
                  } else if(arr[3][2]==combination[j] && takenN[3][2] != 1) {
                        counterNV++;
                        counterHL[i]++;
                        takenN[3][2] = 1;
                        printf("Checked: %d\n", combination[j]);
                  } else if(arr[3][3]==combination[j] && takenG[3][3] != 1) {
                        counterLX++;
                        counterGV++;
                        counterHL[i]++;
                        takenG[3][3] = 1;
                        printf("Checked: %d\n", combination[j]);
                  } else if(arr[3][4]==combination[j] && takenO[3][4] != 1) {
                        counterOV++;
                        counterHL[i]++;
                        takenO[3][4] = 1;
                        printf("Checked: %d\n", combination[j]);
                  }
            } else if(i==4){
                  if(arr[4][0]==combination[j] && takenB[4][0] != 1) {
                        counterRX++;
                        counterBV++;
                        counterHL[i]++;
                        takenB[4][0] = 1;
                        printf("Checked: %d\n", combination[j]);
                  } else if(arr[4][1]==combination[j] && takenI[4][1] != 1) {
                        counterIV++;
                        counterHL[i]++;
                        takenI[4][1] = 1;
                        printf("Checked: %d\n", combination[j]);
                  } else if(arr[4][2]==combination[j] && takenN[4][2] != 1) {
                        counterNV++;
                        counterHL[i]++;
                        takenN[4][2] = 1;
                        printf("Checked: %d\n", combination[j]);
                  } else if(arr[4][3]==combination[j] && takenG[4][3] != 1) {
                        counterGV++;
                        counterHL[i]++;
                        takenG[4][3] = 1;
                        printf("Checked: %d\n", combination[j]);
                  } else if(arr[4][4]==combination[j] && takenO[4][4] != 1) {
                        counterLX++;
                        counterOV++;
                        counterHL[i]++;
                        takenO[4][4] = 1;
                        printf("Checked: %d\n", combination[j]);
                  }
            }

       }
   }

      printf("\n   Counter \\ = %d",counterLX);
      printf("\n   Counter / = %d",counterRX);
      for(i=0;i<5;i++) printf("\n Counter HL%d = %d",i,counterHL[i]);
      printf("\n Counter BVL = %d",counterBV);
      printf("\n Counter IVL = %d",counterIV);
      printf("\n Counter NVL = %d",counterNV);
      printf("\n Counter GVL = %d",counterGV);
      printf("\n Counter OVL = %d",counterOV);

    //rules for winning
     if(counterRX == 5 || counterLX == 5 || counterBV==5 || counterIV==5 || counterNV==5 || counterGV==5 || counterOV==5 || counterHL[0] == 5 || counterHL[1] == 5 || counterHL[2] == 5 || counterHL[3] == 5 || counterHL[4] == 5 ){
        printf("\n\nYou won! Bingo\n");
     } else {
        printf("\n\nTry again!\n");
     }
     printf("SELECT OPTION? (N/Y): ");
     scanf("%s",&opt);

} while(opt=='y' || opt=='Y');

   return 0;
}
