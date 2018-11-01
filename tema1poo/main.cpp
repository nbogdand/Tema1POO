#include <fstream>
#include <iostream>
#include "Numar_rational.hpp"

std::ifstream fin ("file.txt");
std::ofstream fout("file2.txt");

int main()
{
    Numar_rational r1(0,1),r2(0,1);
    int a=2;
    double d;

    fin>>r1>>r2;
   // r1*=a;


    r1+=r2;
    d=(double)r1;
  //  r2/=0;
  //  r2.setNumitor(0);
    fout<<r1;
    std::cout<<d;

/*
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
*/
 //   std::string s = (std::string) r1;
//    std::string s1 = (std::string) r1;
//    fout<<s1;

    return 0;
}
