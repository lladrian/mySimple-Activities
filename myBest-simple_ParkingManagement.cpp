/* 
     Author : Adrian C. Manatad
       Date : March 26, 2022
 Commission : failed to pay
*/

#include <iostream>

using namespace std;

void calculateCharges(int carNum[5],float carHours[5],int carCharge[5]);

int main()
{
    int i, j;
    int carNum[5], carCharge[5];
    float carHours[5];

  for(i = 0; i<5; i++) {
     carNum[i]=i+1;//stored value
     cout << "Car " << i+1 << " Hours Parked: " << i+1 << endl;
      carHours[i] = i+1;//stored value
     
    if(carHours[i]<3) {//less than 3 hours once it goes to 3 hours then hit the additional charges
         carCharge[i] = 30; // 30 pesos minimum
     } else if(carHours[i]>=3) {
          carCharge[i] = 30;//starter value
         for(j=3; j<=carHours[i]; j++) {  //where the condition controls the iteration        
             if(carCharge[i] < 100) {//only accept if true
                carCharge[i]+=5;//then execute this
             }
         }  
     } 
         
  }
    calculateCharges(carNum, carHours, carCharge);// passing vslue
}

void calculateCharges(int carNum[5],float carHours[5],int carCharge[5]){
    int totalCharge = 0;//as starter value
    float totalHours = 0;//as starter value
    
    
   cout << endl << "Car\t" << "Hours\t" << "Charge" << endl;
   
   for(int i=0; i<5; i++) {
      cout << carNum[i] << "\t" << carHours[i] <<"\t" << carCharge[i] << "\t" << endl;  
      totalCharge+=carCharge[i];//to be store the overall charges
       totalHours+=carHours[i];//to be stored the total of hours 
   }
   cout << "Total\t" << totalHours<< "\t"<< totalCharge << "\t" << endl;
}