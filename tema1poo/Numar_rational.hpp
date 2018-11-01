#include<iostream>
#include<string>

class Numar_rational{
public:

    Numar_rational(int,int);
    Numar_rational(Numar_rational& r);
    void setNumaratorNumitor(int,int);
    void setNumarator(int);
    int getNumarator() const;
    void setNumitor(int);
    int getNumitor() const;

    Numar_rational& operator+=(const Numar_rational&);
    Numar_rational& operator+=(const int&);
    Numar_rational& operator-=(const Numar_rational&);
    Numar_rational& operator-=(const int&);
    Numar_rational& operator*=(const Numar_rational&);
    Numar_rational& operator*=(const int&);
    Numar_rational& operator/=(const Numar_rational&);
    Numar_rational& operator/=(const int&);

    Numar_rational& operator-();
    Numar_rational& operator+();

    friend Numar_rational operator + (Numar_rational&,Numar_rational&);
    friend Numar_rational operator + (int&,Numar_rational&);
    friend Numar_rational operator + (Numar_rational&,int&);
    friend Numar_rational operator - (Numar_rational&,Numar_rational&);
    friend Numar_rational operator - (int&,Numar_rational&);
    friend Numar_rational operator - (Numar_rational&,int&);
    friend Numar_rational operator * (Numar_rational&,Numar_rational&);
    friend Numar_rational operator * (int&,Numar_rational&);
    friend Numar_rational operator * (Numar_rational&,int&);
    friend Numar_rational operator / (Numar_rational&,Numar_rational&);
    friend Numar_rational operator / (int&,Numar_rational&);
    friend Numar_rational operator / (Numar_rational&,int&);
    friend Numar_rational operator ^ (Numar_rational&,int&);

    friend bool operator == (const Numar_rational&,const Numar_rational&);
    friend bool operator == (const int&,const Numar_rational&);
    friend bool operator == (const Numar_rational&,const int&);
    friend bool operator != (const Numar_rational&,const Numar_rational&);
    friend bool operator != (const int&,const Numar_rational&);
    friend bool operator != (const Numar_rational&,const int&);
    friend bool operator < (const Numar_rational&,const Numar_rational&);
    friend bool operator < (const int&,const Numar_rational&);
    friend bool operator < (const Numar_rational&,const int&);
    friend bool operator <= (const Numar_rational&,const Numar_rational&);
    friend bool operator <= (const int&,const Numar_rational&);
    friend bool operator <= (const Numar_rational&,const int&);
    friend bool operator > (const Numar_rational&,const Numar_rational&);
    friend bool operator > (const int&,const Numar_rational&);
    friend bool operator > (const Numar_rational&,const int&);
    friend bool operator >= (const Numar_rational&,const Numar_rational&);
    friend bool operator >= (const int&,const Numar_rational&);
    friend bool operator >= (const Numar_rational&,const int&);

    operator int();
    operator double();
    operator std::string();
    std::string toString();


    friend std::ostream& operator << (std::ostream&,Numar_rational&);
    friend std::istream& operator >> (std::istream&,Numar_rational&);

private:
    void simplifica();

private:
    int m_numarator;
    int m_numitor;
};

