/*
     Author : Adrian C. Manatad
       Date : April 10, 2022
     Reason : for fun
*/

#include<stdio.h>

int main() {

    int len,sum, counter=0, total=0,key, i , j,t , mode[25], max=0, temp;
    int data[50] = {90,87,88,82,79,78,93,94,86,84,
                    89,84,78,97,94,92,79,88,92,80,
                    87,87,88,86,85,98,81,86,86,84,  
                    91,89,92,82,83,96,80,84,78,83,  
                    98,83,95,94,81,85,85,87,91,94
                   };
            
    float mean, median;

   len = sizeof(data) / sizeof(*data);

//to display unsorted array
    printf("Unsorted Data:\n");
    for(i=0; i<len; i++)
{
    
        if(i % 10 == 0 && i!=0) {             
            printf("\n");                        
        }       
         printf("%d ", data[i]);      
    }   
    

//Use this code to make it sorted
//Insertion Sort
   for (i = 1; i < len; i++) {
        key = data[i];
          j = i - 1;   
            while (key < data[j] && j >= 0) {
              data[j + 1] = data[j];
              --j;
            }           
        data[j + 1] = key;          
    }
 
       
//to display the sorted array     
    printf("\n\nSorted Data:\n");
    for(i=0; i<len; i++)
{
  
       total+=data[i];    
       if(i % 10 == 0 && i!=0) {             
            printf("\n");              
            //printf("\nTotal: %d\n",total);
        }          
       printf("%d ", data[i]);       
           
    }   
    
// to find mean
    mean = (float) total / len;
    printf("\n\n   Mean = %.2f = %d / %d",mean,total,len);


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
        t=data[i];
        temp=0;

         for(j=0; j<len; j++) { 
           if(t==data[j]) temp++;           
         }
            if(temp>=max) {
                 if(temp>max) {
                    counter=0;
                    mode[counter]=t;
                 } else if(temp==max && mode[counter] != data[i]) {
                    counter++; 
                    mode[counter]=t;        
                 }   
                    max=temp;
             }
     }
    
//to display mode
         if(max!=1) {
            for(i=0; i<=counter; i++) {
                printf("   Mode = %d [%d]\n" ,mode[i],max);
            }        
         } else if(max==1) {
             printf("   Mode = none\n\n");
         }
        
 return 0;
}