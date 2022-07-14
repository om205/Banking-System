#ifndef __BANK
#define __BANK
#include"secure.h"
using namespace std;


class Bank
{
    // Here account class is inside of bank so that no one can create object of account class except bank class.
    class Account
    {
        string name;
        string psw;
        bool loggedIn;
        double bal;
        public:
        long accNum;
        Encdec* encryption;
        Account(Bank*);
        Account(Bank*,long,string,string);
        void balanceEnquiery();
        void deposit(int);
        void withdraw(int);
        bool login(string);
        void logOut(Bank&);
        friend ofstream &operator<<(ofstream &, Account &);
        friend ifstream &operator>>(ifstream &, Account &);
        friend ostream &operator<<(ostream &, Account &);
    };
    string BankName;
    int key;
    friend ofstream &operator<<(ofstream &, Account &);
    friend ifstream &operator>>(ifstream &, Account &);
    friend ostream &operator<<(ostream &, Account &);
    long no_of_acc_opened;
    map<long,Account> accounts;
    public:
    Account* acc_loggedIn;
    Bank(string,int);
    ~Bank();
    bool login();
    void openAccount();
    void closeAccount(long);
    void printAcc(Account);
    void printAllAcc();
    void updateStorage();
};

#endif