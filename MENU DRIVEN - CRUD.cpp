#include <iostream>
#include <string>
#include <fstream>
#include <bits/stdc++.h>
#include <windows.h>
    /*. AUTHOR: Adrian C. Manatad
          DATE: July 16, 2022
        REASON: FOR COMMISSION
        CLIENT: Alma Española
    */ //100% done
    using namespace std;

    struct Student{
        int id;
        string name;
        string price;
    };

    int i, ssn, step=0, zone=0, record=-1, num1=1,num2=0, found=0, counts=0;
    char choice,name[100], price[100],u_name[100], course[100], section[100], subject[100],look[100], check[100];
    bool back=true, loop=true, flag=false, edit=false;
    string text, line;

    ifstream read;
    ofstream write;
    fstream append;

    void deleteAll_DATA(), insert_DATA(), viewAll_DATA(), view_DATA(), delete_DATA(), edit_DATA();
    bool isAlpha(string const &str), isNumeric(string const &str), writeInfo_DATA();
    int total_RECORD();
    Student input_DATA(int ssn, const int edit);

int main() {
    while(back==true) {
        record=total_RECORD(); //reset
         if (flag==true) {  //Personal Information
                cout << "\n\n\n";
                read.open("user_info.txt"); //read from file
                    while(getline(read,line)) cout << line << endl;
                read.close();
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
            cin.getline(check, 100);
                if(strlen(check) > 1) {
                    found=1;
                    cerr <<"\nCaught an ERROR!.\n"<<endl;
                } else choice = check[0];

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
                    cout << "\n\nDisplay ALL: \n";
                    viewAll_DATA();
            break;
            //Delete All Records 100%
            case 'z':
            case 'Z':
                    deleteAll_DATA();
            break;
            //Student Information 100%
            case 'p':
            case 'P':
                    system("CLS");
                    flag=writeInfo_DATA();
                    system("CLS");
            break;
            //CLEAR SCREEN FUNCTION 100%
            case 'c':
            case 'C':
                    system("CLS");
                    zone=1;
            break;
             //EXIT FUNCTION 100%
            case 'x':
            case 'X':
                     cout << "\nEXIT SUCCESFULLY.\n";
                     exit(1);
            break;
            //if out of range
            default:
                    cout << "\nTRY AGAIN! Out of range.\n\n";
            break;
        }//swith end
        zone=0;//reset
        found=0;//reset
    }//while loop ends
	return 0;
}
bool isAlpha(string const &str) {
    auto ch = str.begin();

    while(loop==true) {
            if(ch != str.end() && !isdigit(*ch))
                ch++;
            else
                loop = false;
    }
    loop = true;
    return (!str.empty() && ch==str.end()) ? true : false;
}
bool isNumeric(string const &str) {
    auto num = str.begin();

    while(loop==true) {
            if(num != str.end() && isdigit(*num))
                num++;
            else
                loop = false;
    }
    loop = true;
    return (!str.empty() && num==str.end()) ? true : false;
}
Student input_DATA(int ssn, const int edit) {
    Student s1;
    s1.id=ssn;
    cout<<"\nInsert Name: ";
    getline(cin, s1.name);
    cout<<"Input Price: ";
    getline(cin, s1.price);
    if (isAlpha(s1.name) == false) { //if false or return 0
        cerr <<"\nDigit(s) found.\n"<<endl;
        found=1;
    }
    if (isNumeric(s1.price) == false) { //if false or return 0
        cerr <<"\nCharacter(s) found.\n"<<endl;
        found=1;
    }
        if(s1.name.size() > 11 || s1.price.size() > 12 || s1.id >=10000000) {
            cerr <<"\nCaught an ERROR!.\n"<<endl;
            if(s1.name.size() > 11) cerr << "NAME_SIZE:" << s1.name.size() << endl;
            if(s1.price.size() > 12) cerr << "PRICE_DIGITS:" << s1.price.size() << endl;
            if(s1.id>=1000000) cerr << "ID_EXCEEDS:" << s1.id << endl;
            found=1;
        }
        if(edit==0 && found==0) {
            append.open("data.txt", fstream::app);
                append << " " << left << setw(6) << s1.id << " " << left << setw(11)<< s1.name << " " << right << setw(12)<< s1.price <<endl;
            append.close();
        }
  if (edit==1 && found==0) return  s1;
}
void edit_DATA() {//100%
    Student s1;
    cout<<"\nEnter user ID to EDIT: ";
    cin.getline(look,100);
    if(record>0) {
    read.open("data.txt");//read from file //original file
    write.open("temp.txt");;//read from file //original file
        while(getline(read, line)) {//find
            stringstream X(line);
            while (getline(X, text, ' ') && loop==true) { //column..holder
                step++;
                edit=false;//reset
                if(look==text && step==2) {
                    stringstream str1(text);
                    str1 >> ssn;//string to integer
                    s1 = input_DATA(ssn,1);
                    write <<" " << left << setw(6) << s1.id << " " << left << setw(11)<< s1.name << " " << right << setw(12)<< s1.price <<endl;
                    if(found==1) cout << "\nFAILED to update.\n" << endl;
                    if(found==0) cout << "\nUpdated succesfully.\n" << endl;
                    edit=true;
                    loop=false;
                    counts=1;
                }
            }
            if(edit==0) write << line << endl ;
                step=0;//reset
                loop=true;//reset
        }
    read.close();//file is closed
    }
    write.close();//file is closed
    remove("data.txt");//file is removed
    rename("temp.txt", "data.txt");// transfer success
    if(counts==0) cout << "\nEMPTY! Please try again!\n" << endl;
    viewAll_DATA();//display all
    edit==false;
    counts=0;
}
void insert_DATA() {
    cout << "\nINSERT DATA [Y/N]: ";
    cin.getline(check, 100);
    if(strlen(check) > 1) {
        found=1;
        cerr <<"\nCaught an ERROR!.\n"<<endl;
    } else
        choice = check[0];
    if(choice=='y' || choice=='Y') {
        record++;
        input_DATA(record,0);
        if (record>0 && found==0) cout << "\nInserted succesfully.\n\n" << endl;
        if(record==-1 || found==1) cout << "\nFAILED to insert.\n\n" << endl;
    }
    viewAll_DATA();
}
void delete_DATA() { //100%
    read.open("data.txt", fstream::in);//read from file //original file
    write.open("temp.txt", fstream::out);//transfer data
    cout<<"\nEnter user ID to DELETE: ";
    cin.getline(look,100);
    if(record>0) {
        while (getline(read, line)) {//find
            stringstream X(line);
            while(getline(X, text, ' ') && loop==true) { //column..holder
                step++;
                if(look!=text) if(step==2) write << line << endl ;
                if(look==text && step==2) {
                    found=1;
                    loop=false;
                }
            }
            step=0;//reset
            loop=true;//reset
        }
    }
    read.close();//file is closed
    write.close();//file is closed
    if(found==1) cout << "\nSuccesfully Deleted.\n" << endl;
    if(found==0) cout << "\nEMPTY! Please try again!" << endl;
    remove("data.txt");//file is removed
    rename("temp.txt", "data.txt");// transfer success
    viewAll_DATA();
}
void view_DATA() {//100%
    cout<<"\nEnter user ID to VIEW: ";
    cin.getline(look,100);
    read.open("data.txt");//read from file
    while(getline(read,line)) {//row
        stringstream X(line);
        stringstream str1(look);
        while(getline(X, text, ' ')) { //column
            step++;
            if(look==text && step==2) {
                stringstream str2(text);
                str1 >> num1;
                str2 >> num2;
                found = 1;
                cout << "\n|  ID  |    Name    |   Price   |" << endl;
                if(num1==num2) {
                    cout << line << endl;
                }
            }
        }
        step=0;
    }
        if(found==0) cout << "\n\nEMPTY! Please try again!\n" << endl;
    read.close();
}
int total_RECORD() { //100%
    record=-1;//reset
    read.open("data.txt");
        while(getline(read,line)) record++;
    read.close();//required to put
    if(record==-1) {
      write.open("data.txt");
            record++;
            write << "|  ID  |    Name    |   Price   |" << endl;
      write.close();
    }
    return record;
}
void viewAll_DATA() {//100%
    cout<<endl;
    read.open("data.txt");
    while(getline(read,line)) cout << line << endl;
    read.close();//required to put
    zone=1;
}
void deleteAll_DATA() { //100%
    record=-1;//reset
     cout << "\n\nDELETED SUCCESFULLY.\n" << endl;
    if(record==-1) {
        record++;
        write.open("data.txt");
            write << "|  ID  |    Name    |   Price   |" << endl;
        write.close();
    }
    zone=1;
}
bool writeInfo_DATA() { // 100%
    cout << "\n\nName: ";
    cin.getline(u_name,100);
    cout << "Course: ";
    cin.getline(course,100);
    cout << "Section: ";
    cin.getline(section,100);
    cout << "Subject: ";
    cin.getline(subject,100);
     write.open("user_info.txt");
        write << "Name: " << u_name << endl;
        write << "Course: " << course << endl;
        write << "Section: " << section << endl;
        write << "Subject: " << subject << endl;
     write.close();//required
    zone=1;
    return true;
}
