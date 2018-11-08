#include <fstream>
#include <iostream>
#include "Numar_rational.hpp"

std::ifstream fin ("file.txt");
std::ofstream fout("file2.txt");

/*
    Error codes:
    #18 : Numar_rational(Numar_rational&) : setting the denominator's value to zero
    #19 : Numar_rational(int,int) : setting the denominator's value to zero
    #20 : setNumitor(): setting the denominator's value to zero
    #22 : operator /=(const Numar_rational&) : division by zero
    #23 : operator /=(const int&) : division by zero
    #24 : operator /(const Numar_rational&,const Numar_rational&) : division by zero
    #25 : operator /(const Numar_rational&,const int&) : division by zero
    #26 : operator /(const int&,const Numar_rational&) : division by zero
*/

int main()
{
    Numar_rational r1(7,3),r2(-2,3);
    Numar_rational r3,r4;
    int a=2;
    double d;

    fin>>r3>>r4;
    std::cout<<" Citite din fisier:::"<<std::endl;
    std::cout<<r3<<" si "<<r4<<std::endl<<std::endl;

   // fin>>r1>>r2;
   // r1*=a;
    Numar_rational aux(0,1);
    std::cout<<r1<<"  "<<r2<<std::endl;
    aux=a*r1;
    d=(double)aux;

    std::cout<<aux<<std::endl;
  //  fout<<r1;
    std::cout<<d<<std::endl;


    if(r1==r2)
        std::cout<<r1<<"=="<<r2<<std::endl;
    if(r1!=r2)
        std::cout<<r1<<"!="<<r2<<std::endl;
    if(r1<=r2)
        std::cout<<r1<<"<="<<r2<<std::endl;
    if(r1<r2)
        std::cout<<r1<<"<"<<r2<<std::endl;
    if(r1>=r2)
        std::cout<<r1<<">="<<r2<<std::endl;
    if(r1>r2)
        std::cout<<r1<<">"<<r2<<std::endl;
    if(r1==a)
        std::cout<<r1<<"=="<<a<<std::endl;
    if(r1!=a)
        std::cout<<r1<<"!="<<a<<std::endl;
    if(r1<=a)
        std::cout<<r1<<"<="<<a<<std::endl;
    if(r1<a)
        std::cout<<r1<<"<"<<a<<std::endl;
    if(r1>=a)
        std::cout<<r1<<">="<<a<<std::endl;
    if(r1>a)
        std::cout<<r1<<">"<<a<<std::endl;

    if(a==r1)
        std::cout<<a<<"=="<<r1<<std::endl;
    if(a!=r1)
        std::cout<<a<<"!="<<r1<<std::endl;
    if(a<=r1)
        std::cout<<a<<"<="<<r1<<std::endl;
    if(a<r1)
        std::cout<<a<<"<"<<r1<<std::endl;
    if(a>=r1)
        std::cout<<a<<">="<<r1<<std::endl;
    if(a>r1)
        std::cout<<a<<">"<<r1<<std::endl;

    try{
        r1.setNumitor(0);
    }catch(const std::runtime_error ex){
        std::cout<<ex.what();
    }
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
