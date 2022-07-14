#include<bits/stdc++.h>
#include"secure.h"
#include"bank.h"
using namespace std;

Bank::Account::Account(Bank* bank)
{
    loggedIn=false;
    this->encryption=new Encdec(bank->key);
}

//constructor for Account
Bank::Account::Account(Bank* bank,long accNum,string name,string psw)
{
    this->encryption=new Encdec(bank->key);
    this->accNum=accNum;
    this->name=name;
    this->psw=this->encryption->encrypt(psw);
    this->bal=0;
    this->loggedIn=false;
}

// get Balance of Account
void Bank::Account::balanceEnquiery()
{
    if(this->loggedIn)
    cout<<"\n\t\tCurrent Balance\t: "<<fixed<<setprecision(2)<<this->bal<<"\n";
    else
    cout<<"\n\tPlease login first\n\n";
}

// withdraw money from account
void Bank::Account::withdraw(int sum)
{
    if(this->loggedIn)
    {
        if(this->bal>=sum)
        {
            cout<<"\n\tWithdrawing the money..\n\n";
            this->bal-=sum;
        }
        else cout<<"\n\tInsufficient Amount..\n\n";
        cout<<*this;
    }
    else cout<<"\n\tWithdrawal cannot be performed\n\n";
}

// depositing money to account
void Bank::Account::deposit(int sum)
{
    if(this->loggedIn)
    {
        this->bal+=sum;
        cout<<"\n\tAmount deposited..\n\n";
        cout<<*this;
    }
    else cout<<"\n\tPlease Login first\n\n";
}

// login into account
bool Bank::Account::login(string password)
{
    if(password==this->encryption->decrypt(this->psw))
    {
        loggedIn=true;
        return true;
    }
    else
    cout<<"\n\tIncorrect Password.\n\n";
    return false;
}

// ḷogout of account
void Bank::Account::logOut(Bank& bank)
{
    this->loggedIn=false;
    bank.acc_loggedIn=nullptr;
    cout<<"\n\tLogout Successful!\n\n";
}


// Bank constructor
Bank::Bank(string bank_name,int setKey)
{
    this->BankName=bank_name;
    this->key=setKey;
    acc_loggedIn=nullptr;
    no_of_acc_opened=0;
    Account acc(this);
    ifstream fin;
    fin.open("Bank.data");
    if(!fin)
    {
        cout<<"\n\tNo previously stored data found!\n\n";
        return;
    }
    while(!fin.eof())
    {
        fin>>acc;
        no_of_acc_opened++;
        accounts.insert({acc.accNum,acc});
    }
    fin.close();
}

// Bank destructor
Bank::~Bank()
{
    this->updateStorage();
}

// first login
bool Bank::login()
{
    long acNo;
    string psw;
    cout<<"\n\t\tEnter your Account Number: ";
    cin>>acNo;
    cout<<"\t\tEnter Password           : ";
    cin>>psw;
    auto it=accounts.find(acNo);
    bool success=it->second.login(psw);
    this->acc_loggedIn=&it->second;
    return success;
}

// create bank account
void Bank::openAccount()
{
    string n,p;
    cout << "\n\t\tEnter Name   : ";
    cin.ignore();
    getline(cin,n);
    cout << "\t\tSet password : ";
    cin >> p;
    Account acc(this,++this->no_of_acc_opened,n,p);
    accounts.insert({acc.accNum,acc});
    this->updateStorage();
    cout<<"\n\tCongratulation! Account Successfully created.\n\n\tAccount Details:\n\n";
    cout<<acc;
}

// remove bank account
void Bank:: closeAccount(long accNo)
{
    auto it=accounts.find(accNo);
    cout<<it->second<<"\n\tAccount Deleted\n\n";
    accounts.erase(accNo);
    this->updateStorage();
}

// print all accounts
void Bank::printAllAcc()
{
    for(auto it:accounts)
    cout<<endl<<it.second<<endl;
}

void Bank::updateStorage()
{
    ofstream fout;
    fout.open("Bank.data",ios::trunc);
    for(auto it:accounts)
    fout<<it.second;
    fout.close();
}

// serialization of insersion operator to file
ofstream &operator<<(ofstream &fout, Bank::Account &acc)
{
    fout << acc.accNum << endl;
    fout << acc.name << endl;
    fout << acc.bal << endl;
    fout << acc.psw << endl;
    return fout;
}

// serialization of extraction operator to file
ifstream &operator>>(ifstream &fin, Bank::Account &acc)
{
    fin >> acc.accNum;
    fin.ignore();
    getline(fin,acc.name);
    fin >> acc.bal;
    fin >> acc.psw;
    return fin;
}

// serialization of insersion operator to terminal
ostream &operator<<(ostream &dout, Bank::Account &acc)
{
    dout << "\t\tAccount holder Name  :\t" << acc.name << endl;
    dout << "\t\tAccount Number       :\t" << acc.accNum << endl;
    if(acc.loggedIn)
    dout << "\t\tAccount Balance      :\t" << acc.bal << endl;
    return dout;
}