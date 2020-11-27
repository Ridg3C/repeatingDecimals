#include <iostream>
#include <cmath>
#include <sstream>
#include <string>

using namespace std;

int main()
{
float x, r;
cout<<"Input the first part of Your number: "<<endl;
cin>>x;
cout<<"Input the repeating part of Your number: "<<endl;
cin>>r;

string s;
string t;
stringstream out;
out << x;
s=out.str();

t=s.substr(s.find(".")+1);
int l=t.length();
size_t d=s.find(".");
if (d==string::npos)
{
    l=0;
}

int cnt=0;
cnt=1+floor(log10(r));
if (cnt==1)
{
    for (int i=1; i<=cnt+1; i++)
    {
        x+=r/(pow(10,i+l));
    }
}
else
{
    x=x+(r/(pow(10,l+cnt)));

}

float hx;
float denominator;

if (cnt==1)
{
    hx=x*100;
for (int i=1; i<=cnt+1; i++)
        {
            hx+=(r/(pow(10,i+l)));
        }
    denominator=99;
}
else
{
    hx=x*pow(10,cnt);
    hx+=(r/(pow(10,l+cnt)));
    denominator=pow(10,cnt)-1;
}
float numerator=hx-x;

cout<<"In order to obtain Your desired number divide "<<numerator<<" by "<<denominator<<" if c++ messed up numbers, else divide: ."<<endl;

if (cnt>=2 || t.length()>=2)
{
    while (int(numerator)!=numerator)
{
    numerator*=10;
    denominator*=10;
}
}
cout<<numerator<<" by "<<denominator<<".";
return 0;
}
