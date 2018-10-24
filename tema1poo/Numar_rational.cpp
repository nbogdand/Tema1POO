#include "headerNumarRational.hpp"
#include <iostream>
#include <cmath>

void Numar_rational::reducere(){
    // Saving the numerator in a and the denominator in b
    int a=std::abs(m_numarator);
    int b=std::abs(m_numitor);

    // Getting the lowest common divisor
    while(a!=b){
        if(a>b)
            a-=b;
        else
            b-=a;
    }

    // Simplify the fraction by a or b (lowest common divisor)

    m_numarator=m_numarator/a;
    m_numitor=m_numitor/b;

    //if both numerator and denominator are negative
    //then the whole number is positive
    if(m_numarator<0 && m_numitor<0){
        m_numarator=std::abs(m_numarator);
        m_numitor=std::abs(m_numitor);
    }
}
/*
Numar_rational::Numar_rational(int a=0,int b=1){
    this->m_numarator=a;
    this->m_numitor=b;

    while(a!=b){
        if(a>=b)
            a-=b;
        else
            b-=a;
    }

    if(a==b){
        this->m_numarator/=a;
        this->m_numitor/=a;
    }
}

Numar_rational::Numar_rational(Numar_rational& r){
    this->m_numarator=r.m_numarator;
    this->m_numitor=r.m_numitor;
}
*/
int Numar_rational::getNumarator(){
    return this->m_numarator;
}

void Numar_rational::setNumarator(int numarator){
    this->m_numarator=numarator;
}

int Numar_rational::getNumitor(){
    return this->m_numitor;
}

void Numar_rational::setNumitor(int numitor){
    this->m_numitor=numitor;
}

Numar_rational Numar_rational::operator+=(const Numar_rational r){
    m_numarator=m_numarator*r.m_numitor + r.m_numarator*m_numitor;
    m_numitor=m_numitor*r.m_numitor;
    return *this;
}

Numar_rational Numar_rational::operator+=(const int d){
    m_numarator=d*m_numitor + m_numarator;
    m_numitor=m_numitor;
    return *this;
}

Numar_rational Numar_rational::operator-=(const Numar_rational r){
    m_numarator=m_numarator*r.m_numitor - m_numitor*r.m_numarator;
    m_numitor=m_numitor*r.m_numitor;
    return *this;
}

Numar_rational Numar_rational::operator-=(const int d){
    m_numarator=m_numarator-d*m_numitor;
    m_numitor=m_numitor;
    return *this;
}

Numar_rational Numar_rational::operator*=(const Numar_rational r){
    m_numarator=m_numarator*r.m_numarator;
    m_numitor=m_numitor*r.m_numitor;
    return *this;
}

Numar_rational Numar_rational::operator*=(const int d){
    m_numarator*=d;
    m_numitor=m_numitor;
    return *this;
}

Numar_rational Numar_rational::operator/=(const Numar_rational r){
    m_numarator=m_numarator*r.m_numitor;
    m_numitor=m_numitor*r.m_numarator;
    return *this;
}

Numar_rational Numar_rational::operator/=(const int d){
    m_numarator=m_numarator;
    m_numitor=m_numitor*d;
    return *this;
}

Numar_rational Numar_rational::operator + (){
    return *this;
}

Numar_rational Numar_rational::operator-(){
    return (*this)*(-1);
}

Numar_rational operator + (Numar_rational a,Numar_rational b){
    Numar_rational aux;
    aux.m_numarator=a.m_numarator*b.m_numitor + b.m_numarator*a.m_numitor;
    aux.m_numitor=a.m_numitor*b.m_numitor;
    aux.reducere();
    return aux;
}

Numar_rational operator + (double d,Numar_rational r){
    Numar_rational aux;
    aux.m_numarator=r.m_numarator + d*r.m_numitor;
    aux.m_numitor=r.m_numitor;
    aux.reducere();

    return aux;
}

Numar_rational operator + (Numar_rational r,int a){
    Numar_rational aux;
    aux.m_numarator=r.m_numarator + r.m_numitor*a;
    aux.m_numitor=r.m_numitor;
    aux.reducere();
    return aux;
}

Numar_rational operator - (Numar_rational a,Numar_rational b){
    Numar_rational aux;
    aux.m_numarator=a.m_numarator*b.m_numitor - b.m_numarator*a.m_numitor;
    aux.m_numitor=a.m_numitor*b.m_numitor;
    aux.reducere();
    return aux;
}

Numar_rational operator - (double d,Numar_rational r){
    Numar_rational aux;
    aux.m_numarator=d*r.m_numitor-r.m_numarator;
    aux.m_numitor=r.m_numitor;
    aux.reducere();
    return aux;
}

Numar_rational operator - (Numar_rational r,int d){
    Numar_rational aux;
    aux.m_numarator=r.m_numarator - r.m_numitor*d;
    aux.m_numitor=r.m_numitor;
    aux.reducere();
    return aux;
}

Numar_rational operator * (Numar_rational a,Numar_rational b){
    Numar_rational aux;
    aux.m_numarator=a.m_numarator*b.m_numarator;
    aux.m_numitor=a.m_numitor*b.m_numitor;
    aux.reducere();
    return aux;
}

Numar_rational operator * (double d, Numar_rational r){
    Numar_rational aux;
    aux.m_numarator=r.m_numarator*d;
    aux.m_numitor=r.m_numitor;
    return aux;
}

Numar_rational operator * (Numar_rational r,int a){
    Numar_rational aux;
    aux.m_numarator=r.m_numarator*a;
    aux.m_numitor=r.m_numitor;
    return aux;
}

Numar_rational operator / (Numar_rational a,Numar_rational b){
    Numar_rational aux;
    aux.m_numarator=a.m_numarator*b.m_numitor;
    aux.m_numitor=a.m_numitor*b.m_numarator;
    aux.reducere();
    return aux;
}

Numar_rational operator / (double d,Numar_rational r){
    Numar_rational aux;
    aux.m_numarator=d*r.m_numitor;
    aux.m_numitor=r.m_numarator;
    return aux;
}

Numar_rational operator / (Numar_rational r,int d){
    Numar_rational aux;
    aux.m_numarator=r.m_numarator;
    aux.m_numitor=r.m_numitor*d;
    return aux;
}

Numar_rational operator ^ (Numar_rational r,int a){
    Numar_rational aux;

    if(a>0){
        aux.m_numarator=r.m_numarator;
        aux.m_numitor=r.m_numitor;
        for(int i=2;i<=a;i++){
            aux.m_numarator*=r.m_numarator;
            aux.m_numitor*=r.m_numitor;
        }
    }

    if(a<0){
        aux.m_numarator=r.m_numitor;
        aux.m_numitor=r.m_numarator;
        for(int i=2;i<=a*(-1);i++){
            aux.m_numarator*=r.m_numitor;
            aux.m_numitor*=r.m_numarator;
        }
    }

    if(a==0){
        aux.m_numarator=1;
        aux.m_numitor=1;
    }

    aux.reducere();
    return aux;

}

bool operator == (Numar_rational a,Numar_rational b){
    a.reducere();
    b.reducere();
    if(a.getNumarator()==b.getNumarator() && a.getNumitor()==b.getNumitor())
        return true;
    return false;
}

bool operator == (int d,Numar_rational a){
    a.reducere();
    if(a.getNumarator()==d && a.getNumitor()==1)
        return true;
    return false;
}

bool operator == (Numar_rational a,int d){
    a.reducere();
    if(a.getNumarator()==d && a.getNumitor()==1)
        return true;
    return false;
}

bool operator != (Numar_rational a,Numar_rational b){
    a.reducere();
    b.reducere();
    if(a.getNumarator()!=b.getNumarator() && a.getNumitor()!=b.getNumitor())
        return true;
    return false;
}

bool operator != (int d,Numar_rational a){
    a.reducere();
    if(a.getNumitor()==1 && a.getNumarator()==d)
        return false;
    return true;
}

bool operator != (Numar_rational a,int d){
    a.reducere();
    if(a.getNumitor()==1 && a.getNumarator()==d)
        return false;
    return true;
}

bool operator <= (Numar_rational a,Numar_rational b){
    a.reducere();
    b.reducere();
    Numar_rational a1,b1;

    //if both have the same numerator
    if(a.getNumarator()==b.getNumarator())
        return a.getNumitor()>=b.getNumitor();
    //if both have the same denominator
    if(a.getNumitor()==b.getNumitor())
        return a.getNumarator()<=b.getNumarator();
    //if they have different denominators
    if(a.getNumitor()!=b.getNumitor()){
        a1.setNumarator(a.getNumarator()*b.getNumitor());
        a1.setNumitor(a.getNumitor()*b.getNumitor());

        b1.setNumarator(b.getNumarator()*a.getNumitor());
        b1.setNumitor(b.getNumitor()*a.getNumitor());

        return a1.getNumarator()<=b1.getNumarator();
    }
}

std::istream& operator>>(std::istream& in,Numar_rational& r){
    in>>r.m_numarator>>r.m_numitor;
    return in;
}

std::ostream& operator<<(std::ostream& out,Numar_rational& r){
    out<<r.m_numarator<<"/"<<r.m_numitor<<" ";
    return out;
}









