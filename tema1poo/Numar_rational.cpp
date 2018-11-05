#include "Numar_Rational.hpp"
#include <iostream>
#include <cmath>
#include <string>

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

void Numar_rational::simplifica(){

    if(m_numarator!=0){
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
            m_numitor=m_numitor/a;
        //if both numerator and denominator are negative
        //then the whole number is positive
        if(m_numarator<0 && m_numitor<0){
            m_numarator=std::abs(m_numarator);
            m_numitor=std::abs(m_numitor);
        }
    }
}

Numar_rational::Numar_rational(int numarator=0,int numitor=1)
            :m_numarator(numarator)
            ,m_numitor(numitor)
{
    try{

        if(numitor==0)
            throw 19;
        (*this).simplifica();

    }catch(int errorCode){
        std::cout<<"Denominator can not be 0 (zero), ERROR number:"<<errorCode<<std::endl;
    }
}

Numar_rational::Numar_rational(Numar_rational& r){
    try{

        if(r.getNumitor()==0)
            throw 18;

        this->m_numarator=r.getNumarator();
        this->m_numitor=r.getNumitor();

    }catch(int errorCode){
        std::cout<<"Denominator can not be 0 (zero), ERROR number:"<<errorCode<<std::endl;
    }
}

int Numar_rational::getNumarator() const {
    return this->m_numarator;
}

void Numar_rational::setNumarator(int numarator){
    this->m_numarator=numarator;
    (*this).simplifica();
}

int Numar_rational::getNumitor() const{
    return this->m_numitor;
}

void Numar_rational::setNumitor(int numitor){
    try{

        if(numitor==0)
            throw 20;
        this->m_numitor=numitor;
        (*this).simplifica();

    }catch(int errorCode){
        std::cout<<"Denominator can not be 0 (zero), ERROR number:"<<errorCode<<std::endl;
    }
}

void Numar_rational::setFractie(int numarator,int numitor){
    try{

        if(numitor==0)
            throw 21;
        this->m_numitor=numitor;
        this->m_numarator=numarator;
        (*this).simplifica();

    }catch(int errorCode){
        std::cout<<"Denominator can not be 0 (zero), ERROR number:"<<errorCode<<std::endl;
    }
}

Numar_rational& Numar_rational::operator+=(const Numar_rational& r){
    m_numarator=m_numarator*r.m_numitor + r.m_numarator*m_numitor;
    m_numitor=m_numitor*r.m_numitor;
    (*this).simplifica();
    return *this;
}

Numar_rational& Numar_rational::operator+=(const int& d){
    m_numarator=d*m_numitor + m_numarator;
    m_numitor=m_numitor;
    (*this).simplifica();
    return *this;
}

Numar_rational& Numar_rational::operator-=(const Numar_rational& r){
    m_numarator=m_numarator*r.m_numitor - m_numitor*r.m_numarator;
    m_numitor=m_numitor*r.m_numitor;
    (*this).simplifica();
    return *this;
}

Numar_rational& Numar_rational::operator-=(const int& d){
    m_numarator=m_numarator-d*m_numitor;
    m_numitor=m_numitor;
    (*this).simplifica();
    return *this;
}

Numar_rational& Numar_rational::operator*=(const Numar_rational& r){
    m_numarator=m_numarator*r.m_numarator;
    m_numitor=m_numitor*r.m_numitor;
    (*this).simplifica();
    return *this;
}

Numar_rational& Numar_rational::operator*=(const int& d){
    m_numarator*=d;
    m_numitor=m_numitor;
    (*this).simplifica();
    return *this;
}

Numar_rational& Numar_rational::operator/=(const Numar_rational& r){
    try{

        if(r.m_numarator==0 || r.m_numitor==0)
            throw 22;

        m_numarator=m_numarator*r.m_numitor;
        m_numitor=m_numitor*r.m_numarator;
        (*this).simplifica();
        return *this;

    }catch(int errorCode){
        std::cout<<"Can not divide by 0 (zero), ERROR number:"<<errorCode<<std::endl;
    }

}

Numar_rational& Numar_rational::operator/=(const int& d){
    try{
        if(d==0)
            throw 23;
        m_numarator=m_numarator;
        m_numitor=m_numitor*d;
        (*this).simplifica();
        return *this;

    }catch(int errorCode){
        std::cout<<"Can not divide by 0 (zero),Error number:"<<errorCode<<std::endl;
    }
}

Numar_rational& Numar_rational::operator + (){
    return *this;
}

Numar_rational& Numar_rational::operator - (){
    m_numarator*=(-1);
    return *this;
}

Numar_rational operator + (Numar_rational& a,Numar_rational& b){
    Numar_rational aux(0,1);
    aux.m_numarator=a.m_numarator*b.m_numitor + b.m_numarator*a.m_numitor;
    aux.m_numitor=a.m_numitor*b.m_numitor;
    aux.simplifica();
    return aux;
}

Numar_rational operator + (int& d,Numar_rational& r){
    Numar_rational aux(0,1);
    aux.m_numarator=r.m_numarator + d*r.m_numitor;
    aux.m_numitor=r.m_numitor;
    aux.simplifica();

    return aux;
}

Numar_rational operator + (Numar_rational& r,int& a){
    Numar_rational aux(0,1);
    aux.m_numarator=r.m_numarator + r.m_numitor*a;
    aux.m_numitor=r.m_numitor;
    aux.simplifica();
    return aux;
}

Numar_rational operator - (Numar_rational& a,Numar_rational& b){
    Numar_rational aux(0,1);
    aux.m_numarator=a.m_numarator*b.m_numitor - b.m_numarator*a.m_numitor;
    aux.m_numitor=a.m_numitor*b.m_numitor;
    aux.simplifica();
    return aux;
}

Numar_rational operator - (int& d,Numar_rational& r){
    Numar_rational aux(0,1);
    aux.m_numarator=d*r.m_numitor-r.m_numarator;
    aux.m_numitor=r.m_numitor;
    aux.simplifica();
    return aux;
}

Numar_rational operator - (Numar_rational& r,int& d){
    Numar_rational aux(0,1);
    aux.m_numarator=r.m_numarator - r.m_numitor*d;
    aux.m_numitor=r.m_numitor;
    aux.simplifica();
    return aux;
}

Numar_rational operator * (Numar_rational& a,Numar_rational& b){
    Numar_rational aux(1,1);
    aux.m_numarator=a.m_numarator*b.m_numarator;
    aux.m_numitor=a.m_numitor*b.m_numitor;
    aux.simplifica();
    return aux;
}

Numar_rational operator * (int& d,Numar_rational& r){
    Numar_rational aux(1,1);
    aux.m_numarator=r.m_numarator*d;
    aux.m_numitor=r.m_numitor;
    return aux;
}

Numar_rational operator * (Numar_rational& r,int& a){
    Numar_rational aux(1,1);
    aux.m_numarator=r.m_numarator*a;
    aux.m_numitor=r.m_numitor;
    return aux;
}

Numar_rational operator / (Numar_rational& a,Numar_rational& b){

    Numar_rational aux(1,1);
    try{

        if(a.m_numitor==0 || b.m_numarator==0 || b.m_numitor==0)
            throw 24;

        aux.m_numarator=a.m_numarator*b.m_numitor;
        aux.m_numitor=a.m_numitor*b.m_numarator;
        aux.simplifica();
        return aux;

    }catch(int errorCode){
        std::cout<<"Can not divide by 0 (zero), ERROR number:"<<errorCode<<std::endl;
    }
}

Numar_rational operator / (int& d,Numar_rational& r){

    try{

        if(r.m_numitor==0)
            throw 25;

        Numar_rational aux(1,1);
        aux.m_numarator=d*r.m_numitor;
        aux.m_numitor=r.m_numarator;
        return aux;
    }catch(int errorCode){
            std::cout<<"Can not divide by 0 (zero),ERROR number:"<<errorCode<<std::endl;
    }
}

Numar_rational operator / (Numar_rational& r,int& d){
   try{
        if(d==0)
            throw 26;

        Numar_rational aux(1,1);
        aux.m_numarator=r.m_numarator;
        aux.m_numitor=r.m_numitor*d;
        return aux;

   }catch(int errorCode){
        std::cout<<"Can not divide by 0 (zero), ERROR number:"<<errorCode<<std::endl;
   }

}

Numar_rational operator ^ (Numar_rational& r,int& a){
    Numar_rational aux(1,1);

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

    aux.simplifica();
    return aux;

}

std::string Numar_rational::toString(){
    std::string number;

    if(m_numitor==1)
        number=std::to_string(m_numarator);
    else{
        if(m_numitor<0 && m_numarator<0)
            number=std::to_string(-m_numarator)+"/"+std::to_string(-m_numitor);
        else
            if(m_numitor<0 && m_numarator>0)
                number=std::to_string(-m_numarator)+"/"+std::to_string(-m_numitor);
            else{
                number=number=std::to_string(m_numarator)+"/"+std::to_string(m_numitor);
            }
    }
    if(m_numarator==0){
        number=std::to_string(0);
    }
    return number;
}

bool operator == (const Numar_rational& a,const Numar_rational& b){
    if(a.m_numarator==b.m_numarator && a.m_numitor==b.m_numitor)
        return true;
    return false;
}

bool operator == (const int& d,const Numar_rational& a){
    if(a.m_numitor==d && a.m_numitor==1)
        return true;
    return false;
}

bool operator == (const Numar_rational& a,const int& d){
    if(a.m_numarator==d && a.m_numitor==1)
        return true;
    return false;
}

bool operator != (const Numar_rational& a,const Numar_rational& b){
    if(a.m_numarator!=b.m_numarator || a.m_numitor!=b.m_numitor)
        return true;
    return false;
}

bool operator != (const int& d,const Numar_rational& a){
    if(a.m_numarator==1 && a.m_numitor==d)
        return false;
    return true;
}

bool operator != (const Numar_rational& a,const int& d){
    if(a.m_numitor==1 && a.m_numarator==d)
        return false;
    return true;
}

bool operator < (const Numar_rational& a,const Numar_rational& b){
    Numar_rational a1(0,1),b1(0,1);

    //if both have the same numerator
    if(a.m_numarator==b.m_numarator)
        return a.getNumitor()>b.getNumitor();
    //if both have the same denominator
    if(a.getNumitor()==b.getNumitor())
        return a.getNumarator()<b.getNumarator();
    //if they have different denominators
    if(a.getNumitor()!=b.getNumitor()){
        a1.setNumarator(a.getNumarator()*b.getNumitor());
        a1.setNumitor(a.getNumitor()*b.getNumitor());

        b1.setNumarator(b.getNumarator()*a.getNumitor());
        b1.setNumitor(b.getNumitor()*a.getNumitor());

        return a1.getNumarator()<b1.getNumarator();
    }
}

bool operator < (const Numar_rational& a,const int& d){
    Numar_rational aux;
    aux.setNumarator(d*a.getNumitor());
    aux.setNumitor(a.getNumitor());
    return a<aux;
}

bool operator < (const int& d,const Numar_rational& a){
    Numar_rational aux;
    aux.setNumarator(d*a.getNumitor());
    aux.setNumitor(a.getNumitor());
    return aux<a;
}

bool operator <= (const Numar_rational& a,const Numar_rational& b){
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

bool operator <= (const Numar_rational& a,const int& d){
    Numar_rational aux;
    aux.setNumarator(d*a.getNumitor());
    aux.setNumitor(a.getNumitor());
    return a<=aux;
}

bool operator <= (const int& d,const Numar_rational& a){
    Numar_rational aux;
    aux.setNumarator(d*a.getNumitor());
    aux.setNumitor(a.getNumitor());
    return aux<=a;
}


bool operator >= (const Numar_rational& a,const Numar_rational& b){
    Numar_rational a1,b1;

    //if both have the same numerator
    if(a.getNumarator()==b.getNumarator())
        return a.getNumitor()<=b.getNumitor();
    //if both have the same denominator
    if(a.getNumitor()==b.getNumitor())
        return a.getNumarator()>=b.getNumarator();
    //if they have different denominators
    if(a.getNumitor()!=b.getNumitor()){
        a1.setNumarator(a.getNumarator()*b.getNumitor());
        a1.setNumitor(a.getNumitor()*b.getNumitor());

        b1.setNumarator(b.getNumarator()*a.getNumitor());
        b1.setNumitor(b.getNumitor()*a.getNumitor());

        return a1.getNumarator()>=b1.getNumarator();
    }
}


bool operator >= (const Numar_rational& a,const int& d){
    Numar_rational aux;
    aux.setNumarator(d*a.getNumitor());
    aux.setNumitor(a.getNumitor());
    return a>=aux;
}

bool operator >= (const int& d,const Numar_rational& a){
    Numar_rational aux;
    aux.setNumarator(d*a.getNumitor());
    aux.setNumitor(a.getNumitor());
    return aux>=a;
}


bool operator > (const Numar_rational& a,const Numar_rational& b){
    Numar_rational a1,b1;

    //if both have the same numerator
    if(a.getNumarator()==b.getNumarator())
        return a.getNumitor()<b.getNumitor();
    //if both have the same denominator
    if(a.getNumitor()==b.getNumitor())
        return a.getNumarator()>b.getNumarator();
    //if they have different denominators
    if(a.getNumitor()!=b.getNumitor()){
        a1.setNumarator(a.getNumarator()*b.getNumitor());
        a1.setNumitor(a.getNumitor()*b.getNumitor());

        b1.setNumarator(b.getNumarator()*a.getNumitor());
        b1.setNumitor(b.getNumitor()*a.getNumitor());

        return a1.getNumarator()>b1.getNumarator();
    }
}


bool operator > (const Numar_rational& a,const int& d){
    Numar_rational aux;
    aux.setNumarator(d*a.getNumitor());
    aux.setNumitor(a.getNumitor());
    return a>aux;
}

bool operator > (const int& d,const Numar_rational& a){
    Numar_rational aux;
    aux.setNumarator(d*a.getNumitor());
    aux.setNumitor(a.getNumitor());
    return aux>a;
}

Numar_rational::operator int(){
    return m_numarator/m_numitor;
}


Numar_rational::operator double(){
    return (double)m_numarator/(double)m_numitor;
}

Numar_rational::operator std::string(){
    return (*this).toString();
}

std::istream& operator>>(std::istream& in,Numar_rational& r){
    in>>r.m_numarator>>r.m_numitor;
    return in;
}

std::ostream& operator<<(std::ostream& out,Numar_rational& r){
    std::string number=r.toString();
    out<<number;
    return out;
}




