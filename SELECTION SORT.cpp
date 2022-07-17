/* 
     Author : Adrian C. Manatad
       Date : March 26, 2022
     REASON : School Activity
*/

#include <stdio.h>

int main() {
  
    int  arr[7], i, min, j, temp, x;
    
    printf("Enter array values: \n");
    
    for(i=0; i<7;i++) {//iteration
        printf("arr[%d]: ", i);
        scanf("%d", &arr[i]);//prompts the user to input value
    }
    
    printf("\nStarting Point:  ");
    for(i=0; i<7;i++) {
        printf(" %d ", arr[i]);//display array values
    }
     printf("\n");
    /* selection sort */
    for(i=0; i<6;i++) {// we use 6 , because we assumed all numbers already sorted
        min = i;//for elephant
        
        /* look for min value */
       for(j=i+1;j<7;j++) {
            if(arr[min]>arr[j]) {
                 min = j;//update the min value index
            }
       } 
        
       if(i!=min) {// swap starts, only execute if the value of min has changed
           temp = arr[i];//for temporary
           arr[i] = arr[min]; //the min value to be stored at current loop
           arr[min] = temp;// then swap the value needs to be swap
       }

       printf("\n  Array Values:  "); //print array values after every iteration
        
       for(x=0; x<7;x++) {
            printf(" %d ", arr[x]);//display and look where the current value updates
       }
    }
    
    printf("\n\n Sorted Values:  ");
    
    for(i=0; i<7;i++) {
        printf(" %d ", arr[i]);//display the sorted array
    }
    printf("\n\n");
    
    return 0;
}
