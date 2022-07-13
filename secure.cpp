#include<iostream>
#include<string>
#include "secure.h"
using namespace std;

Encdec::Encdec(int n)
{
    key=n;
}

string Encdec::encrypt(string psw)
{
    int l=psw.size();
    for(int i=0;i<l;i++)
    psw[i]+=key;
    return psw;
}

string Encdec::decrypt(string psw)
{
    int l=psw.size();
    for(int i=0;i<l;i++)
    psw[i]-=key;
    return psw;
}

