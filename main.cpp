#include <iostream>
#include <fstream>
#include <windows.h>
#include <sstream>
using namespace std;

class Login{

    private:
    string LoginID , Password;
    
    public:
    Login():LoginID(""), Password(""){}

    void setID(string id){
        LoginID = id;
    }
    void setPw(string pw){
        Password = pw;
    }

    string getID(){
        return LoginID;
    }
    string getPw(){
        return Password;
    }
};

int registeration(Login user){
    system("cls");
    string id,pw;
    cout<<"\tEnter Login ID : ";
    cin>>id;
    user.setID(id);

    start:
    cout<<"\tEnter a Strong Password: ";
    cin>>pw;
    if(pw.length()>=8){
        user.setPw(pw);
    }else{
        cout<<"\tPassword must be at least 8 characters long.";
        goto start;
    }

    ofstream outfile("D:\cpp proj\loginer\Login", ios::app);
    if(!outfile){
        cout<<"\tError : File Cant Be Opened"<<endl;
    }else{
        outfile<<"\t"<<user.getID()<<" : "<<user.getPw()<<endl<<endl;
        cout<<"\tUser Registered Successfully"<<endl;
    }
    outfile.close();
    Sleep(3000);
};

int loginer(Login user){
    system("cls");
    string id,pw;
    cout<<"\tEnter Login ID : "<<endl;
    cin>>id;

    cout<<"\tEnter Password : "<<endl;
    cin>>pw;

    ifstream infile("D:\cpp proj\loginer\Login");
    if(!infile){
        cout<<"\tError File Cant Be Opened"<<endl;
    }
    else{
        string line;
        bool found = false;
        while(getline(infile,line)){
            stringstream ss;
            ss<<line;
            string userID,userPass;
            char delimiter;
            ss>>userID>>delimiter>>userPass;

            if(id==userID && pw==userPass){
                found=true;
                cout<<"\tPlease Wait!";
                for(int i=0; i<3; i++){
                    cout<<".";
                    Sleep(400);
                }
                system("cls");
                cout<<"\tLogin Successful"<<endl;

            }
        }
        if(!found){
            cout<<"\tError : Incorrect Credentials";
        }

    }
    infile.close();
    Sleep(5000);
}

int main(){
    Login user;


    bool exit = false;
    while(!exit){
        system("cls");
        int val;
        cout<<"\tWelcome to Registration & Login Form"<<endl;
        cout<<"\t************************************"<<endl;
        cout<<"\t1.Register."<<endl;
        cout<<"\t2.Login."<<endl;
        cout<<"\t3.Exit."<<endl;
        cout<<"\tEnter your Choice: "<<endl;
        cin>>val;

        if(val==1){
            registeration(user);
        }
        else if(val==2)
        {
            loginer(user);
        }else if(val==3){
            system("cls");
            exit = true;
            cout<<"\tGoodBye!!"<<endl;
            Sleep(3000);
        }
        
        Sleep(3000);

    }
}