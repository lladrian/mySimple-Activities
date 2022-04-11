#include<stdio.h>

int main()
{
  int combination[5], i, j, k, counter=0,counter1=0;
  int takenB00=0, taken2=0, taken3=0, taken4=0, taken5=0, taken6=0, taken7=0, taken8=0, taken9=0;
  int arr[5][5] = {{1,17,37,51,67},
               {2,18,36,50,69},
               {3,19,35,49,68},
               {12,16,32,47,75},
               {10,21,38,48,74}
              };
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
   for(i=0; i<=4; i++) {
        for(j=0; j<=4; j++) {             
        
            if(i==0) {
                  if(arr[0][0]==combination[j] && takenB_00 != 1) {
                        counter++;
                        takenB_00=1;    
                        printf("Checked: %d\n", combination[j]);                    
                  } else if(arr[0][1]==combination[j] && takenI_01 != 1) {
                        counter++;
                        takenI_01=1;    
                        printf("Checked: %d\n", combination[j]);                    
                  } else if(arr[0][2]==combination[j] && takenN_02 != 1) {
                        counter++;
                        takenN_02=1;    
                        printf("Checked: %d\n", combination[j]);                    
                  } else if(arr[0][3]==combination[j] && takenG_03 != 1) {
                        counter++;
                        takenG_03=1;    
                        printf("Checked: %d\n", combination[j]);                    
                  } else if(arr[0][4]==combination[j] && takenO_04 != 1) {
                        counter1++;
                        taken0_04=1; 
                        printf("Checked: %d\n", combination[j]);                
                  }             
            } else if(i==1){
                  if(arr[1][0]==combination[j] && takenB_10 != 1) {
                        counter++;
                        takenB_10=1;    
                        printf("Checked: %d\n", combination[j]);                    
                  } else if(arr[1][1]==combination[j] && takenI_11 != 1) {
                        counter++;
                        takenI_11=1;    
                        printf("Checked: %d\n", combination[j]);                    
                  } else if(arr[1][2]==combination[j] && takenN_12 != 1) {
                        counter++;
                        takenN_12=1;    
                        printf("Checked: %d\n", combination[j]);                    
                  } else if(arr[1][3]==combination[j] && takenG_13 != 1) {
                        counter++;
                        takenG_13=1;    
                        printf("Checked: %d\n", combination[j]);                    
                  } else if(arr[1][4]==combination[j] && takenO_14 != 1) {
                        counter1++;
                        taken0_14=1; 
                        printf("Checked: %d\n", combination[j]);                
                  }          
            }  else if(i==2){          
                  if(arr[2][0]==combination[j] && takenB_40 != 1) {
                        counter++;
                        takenB_20=1;    
                        printf("Checked: %d\n", combination[j]);                    
                  } else if(arr[2][1]==combination[j] && takenI_41 != 1) {
                        counter++;
                        takenI_21=1;    
                        printf("Checked: %d\n", combination[j]);                    
                  } else if(arr[2][2]==combination[j] && takenN_42 != 1) {
                        counter++;
                        takenN_22=1; //center   
                        printf("Checked: %d\n", combination[j]);                    
                  } else if(arr[2][3]==combination[j] && takenG_43 != 1) {
                        counter++;
                        takenG_23=1;    
                        printf("Checked: %d\n", combination[j]);                    
                  } else if(arr[2][4]==combination[j] && takenO_44 != 1) {
                        counter1++;
                        takenO_24=1; 
                        printf("Checked: %d\n", combination[j]);                
                  }                        
            } else if(i==3){
                  if(arr[3][0]==combination[j] && takenB_30 != 1) {
                        counter++;
                        takenB_30=1;    
                        printf("Checked: %d\n", combination[j]);                    
                  } else if(arr[3][1]==combination[j] && takenI_31 != 1) {
                        counter++;
                        takenI_31=1;    
                        printf("Checked: %d\n", combination[j]);                    
                  } else if(arr[3][2]==combination[j] && takenN_32 != 1) {
                        counter++;
                        takenN_32=1;    
                        printf("Checked: %d\n", combination[j]);                    
                  } else if(arr[3][3]==combination[j] && takenG_33 != 1) {
                        counter++;
                        takenG_33=1;    
                        printf("Checked: %d\n", combination[j]);                    
                  } else if(arr[3][4]==combination[j] && takenO_34 != 1) {
                        counter1++;
                        takenO_34=1; 
                        printf("Checked: %d\n", combination[j]);                
                  }          
            } else if(i==4){
                  if(arr[4][0]==combination[j] && takenB_40 != 1) {
                        counter++;
                        takenB_40=1;    
                        printf("Checked: %d\n", combination[j]);                    
                  } else if(arr[4][1]==combination[j] && takenI_41 != 1) {
                        counter++;
                        takenI_r1=1;    
                        printf("Checked: %d\n", combination[j]);                    
                  } else if(arr[4][2]==combination[j] && takenN_42 != 1) {
                        counter++;
                        takenN_42=1;    
                        printf("Checked: %d\n", combination[j]);                    
                  } else if(arr[4][3]==combination[j] && takenG_43 != 1) {
                        counter++;
                        takenG_43=1;    
                        printf("Checked: %d\n", combination[j]);                    
                  } else if(arr[4][4]==combination[j] && takenO_44 != 1) {
                        counter1++;
                        takenO_44=1; 
                        printf("Checked: %d\n", combination[j]);                
                  }     
            } 
                       
       }
   }
   
      printf("\n Counter \\ = %d",counter);
      printf("\n Counter / = %d",counter1);
   
     if(counter == 5 || counter1 == 5){
        printf("\n\nYou won! Bingo\n");
     } else {
        printf("\n\nTry again!\n");
     }


   return 0;
}