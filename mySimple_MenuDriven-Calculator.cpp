/* 
     Author : Adrian C. Manatad
       Date : March 28, 2022
     Reason : for commission
*/

#include<iostream>

using namespace std;

int main()
{

 int i, choice; 
 char repeat;
 float result, num1, num2;

    do {
    
       for(i=1; i < 34; i++) cout << "*";
       
          cout << "\n MENU DRIVEN - SIMPLE CALCULATOR\n";
   
       for(i=1; i < 34; i++) cout << "*";
   
          cout << "\n1 - ADDITION\n";
          cout << "2 - SUBTRACTION\n";
          cout << "3 - MULTIPLICATION\n";
          cout << "4 - DIVISION\n";
          cout << "5 - MODULOS\n";
     
          cout << "\nNUMBER OF CHOICE: ";
          cin >> choice; // select operation

         if(choice >=1 && choice <= 5) {// if the value of choice is in the range then execute this
             for(i=1; i < 34; i++) cout << "*";
             
                 cout << "\nINPUT THE FIRST NUMBER\t: ";
                 cin >> num1;//accept float number

                 cout << "\nINPUT THE SECOND NUMBER\t: ";
                 cin >> num2;//accept float number
 
             if (choice == 1) {
                 cout << "\nYOU SELECT NUMBER " << choice << " ADDITION\n";
                 result = (float) (num1 + num2);
             } else if (choice == 2) {
                 cout << "\nYOU SELECT NUMBER " << choice << " SUBTRACTION\n";
                 result = (float) num1 - (float) num2;
             } else if (choice == 3) {
                 cout << "\nYOU SELECT NUMBER " << choice << " MULTIPLICATION\n";
                 result = (float) num1 * (float) num2;
             } else if (choice == 4) {
                 cout << "\nYOU SELECT NUMBER " << choice << " DIVISION\n";
                 result = (float) num1 / (float) num2;
             } else if (choice == 5) {
                 cout << "\nYOU SELECT NUMBER " << choice << " MODULUS\n";
                 result = (int) num1 - (int) num2; // convert float num into num integer
             }     
   
             for(i=1; i < 34; i++) cout << "*";//simplify the code save lines
                       
                cout << "\nTHE ANSWER IS : " << result << endl << endl;
     } else { // if not in range display invalid choice
            cout << "\nERROR! Out of range.\n\n";       
     }
    
            cout << "DO YOU WANT TO TRY AGAIN? Y/N: ";
            cin >> repeat;//controls the loop once the condition not satisfied then loop ends
        
            if (!(repeat == 'y' || repeat == 'Y')) cout << "\nERROR! Please try again.";
                     
            cout << endl;// newline

  } while(repeat == 'y' || repeat == 'Y');
    
   return 0;
}
