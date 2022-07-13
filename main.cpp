/*
    Author  @OM DUBEY
    Version @1.0.0
    Message @Please open first ermanant account in name of bank with acc_no 1.
*/

#include<bits/stdc++.h>
#include"bank.h"
using namespace std;

void loginToBank(string,int);

void loginToBank(string bankName,int setKey)
{
    cout<<"\n\t\t**************************************************\n";
    cout<<"\n\t\t\t***Welcome to the Banking World***\n";
    cout<<"\t\t\t   ----------------------------\n";
    Bank SBI(bankName,setKey);
    int choice,amt;
    string temp;
    bool login;
    do
    {
        cout << "\n\tSelect one option below ";
        cout << "\n\t1 Open an Account";
        cout << "\n\t2 Login into your Account";
        cout << "\n\t3 Show All Accounts";
        cout << "\n\t4 Quit";
        cout << "\n\nEnter your choice: ";
        cin>>choice;
        switch (choice)
        {
        case 1:
            SBI.openAccount();
            break;

        case 2:
            login=SBI.login();
            if(login) 
            cout<<"\n\tLogin Successful!\n\n\tAccount Details:\n\n"<<*SBI.acc_loggedIn<<endl;
            else cout<<"\tLogin Error! Try Again.\n";
            while(login)
            {
                cout << "\n\tSelect one option below ";
                cout << "\n\t1 Balance Enquiry";
                cout << "\n\t2 Deposit";
                cout << "\n\t3 Withdrawal";
                cout << "\n\t4 Close an Account";
                cout << "\n\t5 LogOut";
                cout << "\n\nEnter your choice: ";
                int choice;
                cin>>choice;
                switch(choice)
                {
                    case 1:
                        SBI.acc_loggedIn->balanceEnquiery();
                        break;

                    case 2:
                        cout<<"\n\tEnter Amount you want to deposit: ";
                        cin>>amt;
                        SBI.acc_loggedIn->deposit(amt);
                        break;

                    case 3:
                        cout<<"\n\tEnter Amount you want to withdraw: ";
                        cin>>amt;
                        SBI.acc_loggedIn->withdraw(amt);
                        break;

                    case 4:
                        cout<<"\n\tEnter 'YES' to confirm: ";
                        cin>>temp;
                        if(temp=="YES")
                        {
                            SBI.closeAccount(SBI.acc_loggedIn->accNum);
                            login=false;
                        }
                        break;

                    case 5:
                        SBI.acc_loggedIn->logOut(SBI);
                        login=false;
                        break;

                    default:
                        cout<<"\n\tEnter correct choice\n";
                        break;
                }
            }
            break;

        case 3:
            SBI.printAllAcc();
            break;

        case 4:
            break;
        
        default:
            cout<<"\n\tEnter correct choice\n";
            break;
        }     
    }while(choice!=4);
}

int main()
{
    // In further versions error will be handeled efficiently.
    try
    {   
        loginToBank("State Bank of India",565325);
    }
    catch(...)
    {
        cerr<<"\n\n!!!  Programme stopped suddenly.\n     This may be due to wrong input provided or some code malfunctioning.\n";
        cout<<"\nQuitting the programme...\n\n";
    }
    return 0;
}