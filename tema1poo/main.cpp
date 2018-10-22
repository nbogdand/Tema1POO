#include <iostream>


class Numar_rational{
private:
    int numarator;
    int numitor;
public:

    Numar_rational(int numarator=0,int numitor=1){
        this->numarator=numarator;
        this->numitor=numitor;
    }

    int getNumarator(){
        return this->numarator;
    }
    void setNumarator(int numarator){
        this->numarator=numarator;
    }

    int getNumitor(){
        return this->numitor;
    }

    void setNumitor(int numitor){
        this->numitor=numitor;
    }

    Numar_rational operator + (Numar_rational& r){
        Numar_rational nr;
        nr.numarator=this->numarator*r.numitor + r.numarator*this->numitor;
        nr.numitor=this->numitor*r.numitor;
        simplifica(nr);
        return nr;
    }

    Numar_rational operator - (Numar_rational& r){
        Numar_rational nr;
        nr.numarator=this->numarator*r.numitor + r.numarator*this->numitor;
        nr.numitor=this->numitor*r.numitor;
        simplifica(nr);
        return nr;
    }

private:
    int cmmdc(int a,int b){
        while(a!=b){
            if(a>b)
                a-=b;
            else
                b-=a;
        }
        return a;
    }

    void simplifica(Numar_rational& r){
        int cmmdcF=cmmdc(r.numarator,r.numitor);
        r.numarator=r.numarator/cmmdcF;
        r.numitor=r.numitor/cmmdcF;
    }

};


using namespace std;

int main()
{
    Numar_rational r1(2,3);
    Numar_rational r2(4,5);
    Numar_rational aux;
    aux=r1+r2;
    cout<<aux.getNumarator()<<"/"<<aux.getNumitor();
    return 0;
}
