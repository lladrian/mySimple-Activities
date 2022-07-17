/*
     Author : Adrian C. Manatad
       Date : March 28, 2022
     Reason : for fun
*/

// Program to find Maximum and
// Minimum of an array elements.
#include <iostream>

using namespace std;

int main() {
   
    int  i, j, arr[5], min, max;

    cout << "\nEnter Five Integer Numbers :\n";
    for( i=0 ; i<5 ; i++ ) {
        cout <<"arr["<< i << "] = " ;
        cin >> arr[ i ]; // loop to input array value
    }

    min = arr[0];//starter
    max = arr[0];//starter

    for( i=0 ; i<5 ; i++ ) {
        if( min > arr[ i ] )//check if true
            min = arr[ i ];//then update the min value
        if( max < arr[ i ] )//check if true
            max = arr[ i ];//then update the max value
    }

    cout << "\n Minimum value is = " << min;
    cout << "\n Maximum value is = " << max;

}
