#include<stdio.h>
/*
     Author : Adrian C. Manatad
       Date : April 10, 2022
     Reason : for fun
*/
int main() {

    int len, sum, step=0,sum2=0, counter=0, total=0,key, i , j, mode[25], max=0, temp;
    int data[70] = {78,68,65,60,60,74,67,
                    71,69,60,60,74,76,68,
                    70,72,67,67,71,65,76,
                    56,62,77,90,61,75,67,
                    69,80,60,69,52,67,65,
                    68,71,74,65,60,60,69,
                    60,78,68,67,75,61,73,
                    61,50,59,62,57,58,79,
                    60,73,48,63,67,69,60,              
                    58,63,72,55,64,77,51
                   };
    float mean, median;


    len = sizeof(data) / sizeof(*data); //find char the len

    printf("Unsorted Data:\n");
    for(i=0; i<len; i++) { //to display unsorted array
              
        
        sum2+=data[i];
        step+=1;
        printf("%d ", data[i]);
        if(step==7) {      
           printf("= %d\n",sum2);
           sum2=0;
           step=0;   
        }
    }

    //Use this code to make it sorted
   for (i = 1; i < len; i++) { //Insertion Sort
        key = data[i];
          j = i - 1;
            while (key < data[j] && j >= 0) {
              data[j + 1] = data[j];
              --j;
            }
        data[j + 1] = key;
    }

    printf("\n\nSorted Data:\n");
    for(i=0; i<len; i++) { //to display the sorted array
       total+=data[i];
        sum2+=data[i];
        step+=1;
        printf("%d ", data[i]);
        if(step==7) {      
           printf("= %d\n",sum2);
           sum2=0;
           step=0;   
        }
              
    }

    mean = (float) total / len; // to find mean
    printf("\n\n   Mean = %.2f = %d / %d",mean,total,len); //display mean

//to find median
    if (len%2==1) {   //odd
        median=( (data[(len-1)/2]) );
        printf("\n Median = %.1f\n",median);
    } else if(len%2==0) { //even
        median=( (data[(len-1)/2] + data[(len-1)/2+1] ) / 2.0);
        printf("\n Median = %.2f = %d + %d / 2\n" , median, data[(len-1)/2], data[(len-1)/2+1]);
    }

//to find mode
    for(i=0; i<len; i++) {
        key=data[i];
        temp=0;

         for(j=0; j<len; j++) {
           if(key==data[j]) temp++;
         }
            if(temp>=max) {
                 if(temp>max) {
                    counter=0;
                    mode[counter]=key;
                 } else if(temp==max && mode[counter] != data[i]) {
                    counter++;
                    mode[counter]=key;
                 }
                    max=temp;
             }
     }

//to display mode
         if(max!=1) {
            for(i=0; i<=counter; i++) printf("   Mode = %d [%d]\n" ,mode[i],max);
         } else if(max==1) {
             printf("   Mode = none\n\n");
         }

 return 0;
}
