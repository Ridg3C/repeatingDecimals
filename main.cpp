#include <iostream>
#include <cmath>
#include <iomanip>
#include <sstream>

using namespace std;
string constantString;

string rep;
string repHelper;
string a1;
string a2;
string numeratorString;
string denominatorString;
int notDot=0;
int decimals;
int numberOfDigits=0;
float constantFloat;
float a1F;
float a2F;
float q;
float numerator;
float denominator;

int main()
{
    cout<<"Input constant: ";
    cin>>constantString;
    cout<<"Input number which will repeat: ";
    cin>>rep;
    repHelper=rep;

    for (int i=0; i<constantString.size(); i++)
    {
        if (constantString[i]!='.')
            notDot++;
        else
            break;
    }

    for (int i=0; i<constantString.size(); i++)
    {
        if (constantString[i]=='.')
        {
            decimals=constantString.size()-notDot-1;
            break;
        }
        else
            decimals=constantString.size()-notDot;
    }



    for (int i=0; i<rep.size(); i++)
    {
        numberOfDigits++;
    }

    if (constantString[0]=='-')
    {
        a1[0]='-';
        a1[1]='0';
        a1[2]='.';
        a2[0]='-';
        a2[1]='0';
        a2[2]='.';

        for (int i=3; i<decimals+3; i++)
        {
            a1[i]='0';
        }
        for (int i=decimals+3; i<decimals+3+numberOfDigits; i++)
        {
            a1[i]=rep[i-3-decimals];
        }
        for (int i=3; i<decimals+3+numberOfDigits; i++)
        {
            a2[i]='0';
        }
        for (int i=decimals+3+numberOfDigits; i<decimals+3+numberOfDigits*2; i++)
        {
            a2[i]=rep[i-3-decimals-numberOfDigits];
        }
    }
    else
    {
        a1[0]='0';
        a1[1]='.';
        a2[0]='0';
        a2[1]='.';

        for (int i=2; i<decimals+2; i++)
        {
            a1[i]='0';
        }
        for (int i=decimals+2; i<decimals+2+numberOfDigits; i++)
        {
            a1[i]=rep[i-2-decimals];
        }
        for (int i=2; i<decimals+2+numberOfDigits; i++)
        {
            a2[i]='0';
        }
        for (int i=decimals+2+numberOfDigits; i<decimals+2+numberOfDigits*2; i++)
        {
            a2[i]=rep[i-2-decimals-numberOfDigits];
        }
    }

    cout<<"Your number: "<<constantString;
    if (decimals<=0)
        cout<<".";

    cout<<rep<<rep<<rep<<"..."<<endl;

    a1F = stof(a1);
    a2F = stof(a2);
    constantFloat = stof(constantString);

    q=a2F/a1F;

    denominator=(1-q)*pow(10,numberOfDigits);
    numerator=a1F*pow(10,numberOfDigits) + constantFloat*denominator;

    if (int(numerator)!=numerator)
    {
        numerator=numerator*10;
        denominator=denominator*10;
    }

    if (numerator>=0)
        numerator+=0.5;
    else
        numerator-=0.5;


    int numeratorInt = static_cast<int>(numerator);
    int denominatorInt = static_cast<int>(denominator);


    while (numeratorInt%10==0 && denominatorInt%10==0)
    {
        numeratorInt=numeratorInt/10;
        denominatorInt=denominatorInt/10;
    }

    cout<<"In order to obtain your desired number divide these numbers: "<<endl;
    cout<<"numerator: "<<numeratorInt<<endl;
    cout<<"denominator: "<<denominatorInt<<endl;
    return 0;
}
