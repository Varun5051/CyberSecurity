#include <iostream>
#include <algorithm>
#include <iterator>
#include <string>
#include <vector>
#include <cstring>
#include <fstream>
#include<stdio.h>
using namespace std;
int p = 167, q =151;
int n = p * q;
int modulo (int a, int b)
{
return a >= 0 ? a % b : ( b - abs ( a%b ) ) % b;
}
void encode(string s)
{
vector<int>l;
for(int i = 0; i < strlen(s.c_str()); i++)
{
l.push_back((int)s[i]);
}
copy(l.begin(), l.end(), ostream_iterator<int>(cout, ""));
}
void decode(vector<int> s)
{
vector<char>l;
for(int i = 0; i < s.size(); i++)
{
l.push_back(char(s[i]));
}
copy(l.begin(), l.end(), ostream_iterator<char>(cout, ""));
}
int encrypt(int m, int p, int q)
{
int c = (m * m)%n;
return c;
}
int mod(int k, int b, int m)
{
int i=0;
int a=1;
vector<int> t;
while(k>0)
{
t.push_back(k%2);
k=(k-t[i])/2;
i++;
}
for(int j=0; j<i; j++)
{
if(t[j]==1)
{
a=(a*b)%m;
b=(b*b)%m;
}
else
{
b=(b*b)%m;
}
}
return a;
}
vector<int> eea(int a, int b)
{
if (b>a)
{
int temp=a;
a=b;
b=temp;
}
int x=0;
int y=1;
int lastx=1;
int lasty=0;
while (b!=0)
{
int q= a/b;
int temp1= a%b;
a=b;
b=temp1;
int temp2 = x;
x=lastx-q*x;
lastx = temp2;
int temp3 = y;
y = lasty-q*y;
lasty=temp3;
}
vector<int>arr(3);
arr[0] = lastx;
arr[1] = lasty;
arr[2] = 1;
return arr;
}
int decrypt(int c, int p, int q)
{
int mp = mod((p+1)/4, c, p);
int mq = mod((q+1)/4, c, q);
vector<int> arr = eea(p, q);
int pp = arr[0]*p*mq;
int qq = arr[1]*q*mp;
double r = modulo((pp+qq), n);
if( r < 128)
return r;
int negative_r = n - r;
if (negative_r < 128) return negative_r;
int s = modulo((pp-qq), n);
if( s < 128)
return s;
int negative_s = n - s;
if( negative_s < 128)
return negative_s;
}
/*
string console()
{
 string x;
 getline(cin,x);
 return x;
}*/
int main()
{
cout<<"\n\t\t\t\t\t\t\tFILE ENCRYPTION AND DECRYPTION USING RABIN CRYPTOSYSTEM\n\n";
cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------------------";
string test;
int uu=1;
do
{
int n;
cout<<"\n";
cout<<"\n\t\tMenu\n";
cout<<"*************************************\n";
cout<<"PRESS 1 ----------->Encrypt from file\n";
cout<<"PRESS 2 ----------->Decrypt from file\n";
cout<<"PRESS 3 ----------->Read from console\n";
cout<<"PRESS 4 ----------->Exit\n"<<endl;
cout<<"Enter your choice: ";
cin>>n;
uu=n;
switch(n)
{
case 1:
 {
 ifstream inFile;
 inFile.open("example.txt");
 while(!inFile.eof())
 {
 getline(inFile,test);
 cout<<"\nFile data is"<<"="<<test;
 int len = strlen(test.c_str());
vector<int>l;
for(int i = 0; i <= len; i++)
{
l.push_back(encrypt(test[i], p, q));
}
cout << "\nEncryption: ";
copy(l.begin(), l.end(), ostream_iterator<int>(cout, ""));
}
inFile.close();
}
 break;
case 2:
 {
 ifstream inFile;
 inFile.open("example.txt");
 while(!inFile.eof())
 {
 getline(inFile,test);
 cout<<"\nFile data is"<<"="<<test;
 cout<<"\n";
 int len = strlen(test.c_str());
vector<int>l;
for(int i = 0; i < len; i++)
{
l.push_back(encrypt(test[i], p, q));
}
cout << "\nEncryption: ";
copy(l.begin(), l.end(), ostream_iterator<int>(cout, ""));
vector<int>d;
for(int i = 0; i < len; i++)
{
d.push_back(decrypt(l[i], p, q));
}
cout << "\nDecoded message: ";
decode(d);
cout << endl;
}
inFile.close();
 }
 break;
case 3:
 {
 cout<<"Enter the data:";
 cin>>test;
 cout<<"\nMessage is"<<"="<<test;
 cout<<"\n";
 int len = strlen(test.c_str());
vector<int>l;
for(int i = 0; i <= len; i++)
{
l.push_back(encrypt(test[i], p, q));
}
cout << "Encryption: ";
copy(l.begin(), l.end(), ostream_iterator<int>(cout, ""));
vector<int>d;
for(int i = 0; i < len; i++)
{
d.push_back(decrypt(l[i], p, q));
}
cout << "\nDecoded message: ";
decode(d);
cout << endl;
}
 break;
case 4:
 exit(0);
default:
 break;
}
}
while(uu!=4);
return 0;
}
