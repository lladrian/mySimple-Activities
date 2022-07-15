#include <iostream>
#include <fstream>
#include <bits/stdc++.h>

//#include<stdio.h>
//#include <string>
//#include <stdlib.h>
//#include <cstring>

/*a
    AUTHOR: Adrian C. Manatad
    DATE: July 15, 2022
    Reason: FOR COMMISSION
    CLIENT: Alma Española
*/

using namespace std;

void insert_DATA();
void view_DATA();
void viewAll_DATA();
void deleteAll_DATA();
void delete_DATA();
void edit_DATA();
int total_RECORD();
int writeInfo_DATA();

//Initializing
    int step=0, ssn=0, zone=0, record=-1, num1=1,num2=0, found=0, flag=0;

    bool back=true, loop=true;

    int i, id;

    char choice;
    char name[100], price[100], select[100];
    char u_name[100], course[100], section[100], subject[100];

    string text, look, line;
    fstream in_file, out_file, user_info, temp;

int main(){

         system ("CLS");

    //Menu
    while(back=true){
        record=total_RECORD(); //reset

        if (flag==1) {
                //Personal Information
                cout << "\n\n";
                user_info.open("user_info.txt",fstream::in); //read from file
                    while(getline(user_info,line)) cout << line << endl;
                user_info.close();
        }

        cout<<"\n\n   FILE HANDLING USING C++       \n" << endl;
        cout<<"*****************************"<<endl;
        cout<<"* SIMPLE MENU DRIVEN - CRUD *" << endl;
        cout<<"*****************************"<<endl;

        cout<<"* [P] Personal Information  *"<<endl;
        cout<<"* [A] Add Record            *"<<endl;
        cout<<"* [V] View Record           *"<<endl;
        cout<<"* [E] Edit Record           *"<<endl;
        cout<<"* [D] Delete Record         *"<<endl;
        cout<<"* [L] View All Record       *"<<endl;
        cout<<"* [Z] Delete All Record     *"<<endl;
        cout<<"* [C] Clear Screen          *"<<endl;
        cout<<"* [X] EXIT                  *"<<endl;
        cout<<"*****************************"<<endl;
        cout << "\nRECORD:" << record << endl;


                  cout<<"\nSELECT: ";
                  cin.getline(select,100);

                if(strlen(select) > 1) {
                  cout<<"\nCaught an ERROR!.\n"<<endl;
                  //exit(1);
                 //Code to check for numbers
                } else {
                        choice = select[0];
                }

        switch (choice){

            //Add Record 100%
            case 'a':
            case 'A':
                    insert_DATA();
            break;

            //View Record 100%
            case 'v':
            case 'V':
                    view_DATA();
            break;

            //Edit Record 100%
            case 'e':
            case 'E':
                    edit_DATA();
            break;

            //Delete Record 100%
            case 'd':
            case 'D':
                    delete_DATA();
            break;

            //View All Records 100%
            case 'l':
            case 'L':
                    viewAll_DATA();
            break;

            //Delete All Records 100%
            case 'z':
            case 'Z':
                    deleteAll_DATA();
            break;

            //EXIT FUNCTION 100%
            case 'x':
            case 'X':
                     cout << "\nEXIT SUCCESFULLY.\n";
                     exit(1);
            break;

            //CLEAR SCREEN FUNCTION 100%
            case 'c':
            case 'C':
                    system ("CLS");
                    zone=1;
            break;

            //Student Information
            case 'p':
            case 'P':
                     system ("CLS");
                     flag=writeInfo_DATA();
                     system ("CLS");
                     zone=1;
            break;

            //Exit Program if invalid input
            default:
                    cout << "\nTRY AGAIN! Out of range.\n\n";
                  //  back=false;
            break;
        }//swith end

            if(zone == 0) {
                do {
                        found=0;//reset
                    cout << "\nWant to try again? [Y/N]: ";
                    cin.getline(select,100);

                    if(strlen(select) > 1) {
                      cerr <<"\nCaught an ERROR!.\n"<<endl;
                      found=1;
                      //exit(1);
                     //Code to check for numbers
                    } else {
                            if (found==0) {
                                choice = select[0];

                                if(choice=='n' || choice=='N') {
                                         cout << "\nSYSTEM! Success!\n\n";
                                   exit(1);
                                }
                                if(!(choice=='y' || choice=='Y')) cerr << "\nERROR! Please try again.\n\n";
                            }
                    }
                } while(!(choice=='y' || choice=='Y'));
           }
                zone=0;//reset
    } //forever loop

    return 0;
}

void insert_DATA() {//100%

                  cout << "\nINSERT DATA [Y/N]: ";
                  cin.getline(select,100);

                if(strlen(select) > 1) {
                  cout<<"\nCaught an ERROR!.\n"<<endl;
                 // exit(1);
                 //Code to check for numbers
                } else {
                    choice = select[0];
                }

                    if(choice=='y' || choice=='Y') {
                            record++;
                            id=record;

                            cout<<"\nInsert Name: ";
                            cin.getline(name,100);

                            cout<<"Input Price: ";
                            cin.getline(price,100);

                            if(strlen(name) > 11 || strlen(price) > 11 || id>=10000000) {
                                    cout<<"\nCaught an ERROR!.\n"<<endl;
                                    if(strlen(name)  > 12)
                                        cerr << "NAME_SIZE:" << strlen(name) << endl;
                                    if(strlen(price) > 10)
                                        cerr << "PRICE_SIZE:" << strlen(price) << endl;
                                    if(id>=1000000)
                                        cerr << "DIGIT_SIZE:" << id << endl;
                                    found=1;
                             // exit(1);
                            }

                            in_file.open("data.txt", fstream::app);//append from file

                                if (record>=0 && found==0) {
                                        in_file << " " << left << setw(6) << id << " " << left << setw(11)<< name << " " << right << setw(11)<< price <<endl;
                                        cout << "\nInserted succesfully.\n" << endl;
                                } else if(record==-1 || found==1)
                                        cout << "\nFAILED to insert.\n" << endl;
                            in_file.close();
                 }

                in_file.open("data.txt", fstream::in);//read from file
                cout << endl;
                    while(getline(in_file,text))cout << text << endl;
                in_file.close();
                found=0;

}

void view_DATA() {//100%
             cout<<"Enter user ID to VIEW: ";
             cin >> look;

                      in_file.open("data.txt", fstream::in);//read from file
                      cout << endl;

                      while(!in_file.eof()) {//row
                            getline(in_file,line);
                            stringstream X(line);

                            // object from the class stringstream
                            stringstream str1(look);

                            while (getline(X, text, ' ')) { //column
                                step++;

                                   if(look==text && step==2) {

                                        stringstream str2(text);
                                          str1 >> num1;
                                          str2 >> num2;
                                          found = 1;//temporary

                                    cout << "|  ID  |    Name    |   Price   |" << endl;
                                          if(num1==num2) {
                                                found = 2;//temporary
                                                cout << line << endl;
                                          }
                                    }
                            }
                        step=0;
                    }

                if(found==0) cout << "EMPTY! Please try again!" << endl;
                found=0;
        in_file.close();
}

void viewAll_DATA() {//100%
                cout << "\nDisplay All: " << endl;
                in_file.open("data.txt", fstream::in);//read from file
                cout << endl;
                    while(getline(in_file,text)) cout << text << endl;
                in_file.close();
}

int total_RECORD() { //100%
            record=-1;
                in_file.open("data.txt", fstream::in);//read from file
                    while(getline(in_file,text)) record++;
                in_file.close();
                if(record==-1) {
                    in_file.open("data.txt", fstream::out);//read from file
                        record++;
                        in_file << "|  ID  |    Name    |   Price   |" << endl;
                    in_file.close();
                }
        return record;
}

void deleteAll_DATA() { //100%
            cout << "Delete All: " << endl;
                in_file.open("data.txt", fstream::out);//write from file
                        cout << endl;

                        record=-1;//reset
                             while(getline(in_file,text)){
                                    record++;
                                    if(record==0) {
                                        in_file << "|  ID  |    Name    |   Price   |" << endl;
                                    } else {
                                            in_file << '\0' << endl;
                                    }
                            }
                in_file.close();

                        cout << "DELETED SUCCESFULLY." << endl;
                        record=-1;//reset
}

void delete_DATA() { //100%
             in_file.open("data.txt", fstream::in);//read from file //original file
             temp.open("temp.txt", fstream::out);//transfer data

             cout<<"Enter user ID to DELETE: ";
             cin >> look;

                if(record>0) {
                while (getline(in_file, line)) {//find
                    stringstream X(line);

                        while (getline(X, text, ' ') && loop==true) { //column..holder
                                    step++;
                            if(look!=text) {
                                if(step==2) {
                                        temp << line << endl ;
                                }
                            }

                            if(look==text && step==2) {
                                cout << line << endl ;

                                found=1;
                                loop=false;
                            }
                        }
                            step=0;
                            loop=true;
                }
                }
            in_file.close();//file is closed
            temp.close();//file is closed

            if(found==1) {
                cout << "\nSuccesfully Deleted.\n" << endl;
            }

            if(found==0) {
                cout << "\nEMPTY! Please try again!" << endl;
            }

            remove("data.txt");//file is removed
            rename("temp.txt", "data.txt");// transfer success

            cout << endl;
            in_file.open("data.txt", fstream::in);//read from file
                    while(getline(in_file,text)) cout << text << endl;
            in_file.close();
            found=0;
}

void edit_DATA() {//100%
            in_file.open("data.txt", fstream::in);//read from file //original file
            temp.open("temp.txt", fstream::out);//transfer data

                cout<<"Enter user ID to EDIT: ";
                cin >> look;

                if(record>0) {
                    while (getline(in_file, line)) {//find
                        stringstream X(line);
                            while (getline(X, text, ' ')) { //column..holder
                                    step++;
                                if(look==text && step==2) {
                                    stringstream str1(text);
                                    found=1;
                                    str1 >> ssn;//string to integer
                                    temp << line << endl ;
                                }
                            }
                            step=0;
                     }
                }
             in_file.close();//file is closed
             temp.close();//file is closed

            if(found==1) {
                    found=0;//reset
                    in_file.open("data.txt", fstream::in);//read from file //original file
                    temp.open("temp.txt", fstream::in);//read  mode

                        while (getline(temp, line)) {
                                    temp.close();//file is closed
                                    temp.open("temp.txt", fstream::out);//write  mode
                                while (getline(in_file, text)) {
                                    if(line!=text) {
                                        temp << text << endl;
                                    }
                                }
                            loop=false;

                     }
                     temp.close();//file is closed
                     in_file.close();//file is closed

                     remove("data.txt");//file is removed
                     rename("temp.txt", "data.txt");// transfer success

                     id=ssn;

                     cout<<"New Name: ";
                     cin.getline(name,100);

                     cout<<"New Price: ";
                     cin.getline(price,100);

                      if(strlen(name)  > 11 || strlen(price) > 11 || id>=10000000) {
                                    cout<<"\nCaught an ERROR!.\n"<<endl;

                                    if(strlen(name)  > 12)
                                        cerr << "NAME_SIZE:" << strlen(name) << endl;
                                    if(strlen(price) > 10)
                                        cerr << "PRICE_SIZE:" << strlen(price) << endl;
                                    if(id>=1000000)
                                        cerr << "DIGIT_SIZE:" << id << endl;
                                    found=1;
                             // exit(1);
                      }

                     if(found==0) {
                             in_file.open("data.txt", ios::app);//to be inserted for update
                                                in_file << " " << left << setw(6) << id << " " << left << setw(11)<< name << " " << right << setw(11)<< price <<endl;
                                                cout << "\nUpdated succesfully.\n" << endl;
                             in_file.close();//file is closed
                     }

            } else {
                     cout << "\nEMPTY! Please try again!" << endl;
            }

                cout << endl;

                in_file.open("data.txt", fstream::in);//read from file
                        while(getline(in_file,text))cout << text << endl;
                in_file.close();
                found=0;//reset
}


int writeInfo_DATA() { // 100%
      //prompt the user to input the user info
        cout << "\n\nName: ";
        cin.getline(u_name,100);

        cout << "Course: ";
        cin.getline(course,100);

        cout << "Section: ";
        cin.getline(section,100);

        cout << "Subject: ";
        cin.getline(subject,100);

        remove("user_info.txt");//remove if existing

        //user info
        user_info.open("user_info.txt",fstream::out); //write from file
            user_info << "Name: " << u_name << endl;
            user_info << "Course: " << course << endl;
            user_info << "Section: " << section << endl;
            user_info << "Subject: " << subject << endl;
        user_info.close();
        return 1;
}
