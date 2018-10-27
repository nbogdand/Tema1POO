#include <iostream>
#include "headerNumarRational.hpp"
using namespace std;

int main()
{
    Numar_rational r1,r2,aux;
    double d;
    int a;
    cin>>r1>>d;
    aux+=r1;

  //  cout<<r2;

    if(r1!=d)
        cout<<r1<<"!="<<d<<endl;
    if(r1==d)
        cout<<"egale"<<endl;
    if(r1<=d)
        cout<<"<="<<endl;
    if(r1>=d)
        cout<<">=";
    if(r1<d)
        cout<<"<"<<endl;
    if(r1>d)
        cout<<">"<<endl;

    double b= (double)r1;
    cout<<"b=="<<b<<endl;

    return 0;
}
