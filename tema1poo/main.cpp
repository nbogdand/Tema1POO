#include <fstream>
#include "Numar_rational.hpp"
using namespace std;

ifstream fin ("file.txt");
ofstream fout("file2.txt");

int main()
{
    Numar_rational r1,r2,aux;
    double d;
    int a;
    fin>>r1>>a;
    r1*=a;
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
    std::string s = (std::string) r1;
    fout<<s;

    return 0;
}
