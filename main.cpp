#include <iostream>
#include <fstream>
#include <cstdlib>
#include <stdlib.h>
#include <windows.h>
using namespace std;

class login{

public:
    string password,username,n_user,log_user,log_pass;


    bool log(){


        cout<<"Enter Your Username"<<endl;
     cin>>username;
     cout<<"Enter Your Password"<<endl;
     cin>>password;

    n_user=username;
    n_user+=".txt";

     ifstream log_info(n_user.c_str());
     getline(log_info,log_user);
     getline(log_info,log_pass);

     if(log_user == username && log_pass == password){

        return true;
     }else{
     return false;
     }
    }
};







class reg{
    public:


string password,username,user_n;

void regi(){
    int r_bal=0;

     cout<<"Enter Your Username"<<endl;
     cin>>username;
     cout<<"Enter Your Password"<<endl;
     cin>>password;

     user_n=username;
     user_n+=".txt";

     ofstream reg;
     reg.open(user_n.c_str()); //converting the string to a character array
     reg<<username<<endl<<password<<endl<<r_bal;
     reg.close();
}
};


class Transactions{

private:
    double balance=0;


public:
    void setBalance(double bal);
    double getBalance();
    double Deposit(double amount);
    double Withdraw(double amount);

};

void Transactions :: setBalance(double bal){
    balance = bal;
}

double Transactions :: Deposit(double amount){
    balance += amount;
    return balance;
}

double Transactions :: Withdraw(double amount){
    balance -= amount;
    return balance;
}

double Transactions :: getBalance(){

    system("cls");
    cout <<endl<<endl<< "Your account balance is:$" << balance <<endl;;
}



class accOpera{
public:
    void acc_operation(string getName){
string setUser;
setUser=getName;

Transactions txn1;
    int trns;
    double bal=0;
    string sBal;

    ifstream Acc_File1;
    Acc_File1.open(setUser.c_str(),ios::in | ios::app);
    while(Acc_File1){
        Acc_File1>>sBal;
        bal = atof(sBal.c_str());
        //converting double to a string then converting the string to a character array

    }



    txn1.setBalance(bal);


    cout << "\n\n\n\t\t\t\tWelcome to ABC ATM machine\n\nPlease select the transaction you want to perform\n" << endl;
    cout << "1.Deposit Money\n2.Withdraw money\n3.Check Balance\n4.EXIT" << endl;
    cin >> trns;

    switch (trns)
    {
        case (1):
            double Dep_Amum
            cout << "Please Enter the amount you want to deposit" << endl;
            cin >> Dep_Amu;
            bal = txn1.Deposit(Dep_Amu);
            txn1.getBalance();
0
        break;


        case (2):
            double With_Amu;
            cout << "Please Enter the amount you want to withdraw" << endl;
            cin >> With_Amu;
            bal = txn1.Withdraw(With_Amu);
            txn1.getBalance();

        break;
        case (3):
            txn1.getBalance();

        break;
        case (4):
            exit(0);

        default:
            cout << "Invalid entry" << endl;

    }


    ofstream Acc_File;
    Acc_File.open(setUser.c_str(),ios::out | ios::app); //converting the string to a character array
    Acc_File << bal << endl;
    Acc_File.close();

acc_operation(setUser);

    }


};

 void ani(){

cout<<endl<<endl<<endl<<endl<<endl<<endl<<"\t\t\t\t\tLoading";
	for(int i=0; i<3; i++)
	{
	       for(int i=0; i<2; i++)
	       {
			Sleep(200);
			cout<<".";
		}
	 }
}




int main()
{
    int choice;
    bool log_bool;
    reg regObj;
    login logObj;
    accOpera accObj;

    cout<<endl<<"\t\t\t\t\tHi! Welcome to Mr. Zamar’s ATM Machine!"<<endl<<endl<<endl;
    cout<<"Please select an option from the menu below:"<<endl<<endl<<endl;
    cout<<"1 -> Login"<<endl;
    cout<<"2 -> Create New Account"<<endl;
    cout<<"3 -> Quit"<<endl;



    cin>>choice;
    switch(choice){


case 1:

    log_bool =  logObj.log();

          if(log_bool){
                system("cls");
                ani();
                system("cls");
            cout<<endl<<endl<<"\t\t\t\t\t******** LOGIN SUCCESFUL! ********"<<endl<<endl<<endl<<endl;

            accObj.acc_operation(logObj.n_user);


          }else{
            system("cls");
            cout<<endl<<endl<<"\t\t\t\t\t******** LOGIN FAILED! ********"<<endl<<endl<<endl<<endl;
            cout<<"\t\t\t\t\tyou dont have a account please create a account"<<endl<<endl<<endl<<endl;
            main();
          }
break;

case 2:

    regObj.regi();
    system("cls");
    ani(); //call for the loading animation
    system("cls");
    cout<<endl<<endl<<endl<<"\t\t\t\t\Thank You! Your account has been created!"<<endl<<endl<<endl<<endl;
    main();
break;



case 3:

    exit(0);

break;

default:
    cout<<"Enter Valid Choice"<<endl;
    main();

    }

}
