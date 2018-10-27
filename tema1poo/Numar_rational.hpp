#include<iostream>
#include<string>
class Numar_rational{
public:

//    Numar_rational(int,int);
//    Numar_rational(Numar_rational& r);
    void setNumaratorNumitor(int,int);
    void setNumarator(int);
    int getNumarator();
    void setNumitor(int);
    int getNumitor();

    Numar_rational operator+=(const Numar_rational);
    Numar_rational operator+=(const int);
    Numar_rational operator-=(const Numar_rational);
    Numar_rational operator-=(const int);
    Numar_rational operator*=(const Numar_rational);
    Numar_rational operator*=(const int);
    Numar_rational operator/=(const Numar_rational);
    Numar_rational operator/=(const int);

    Numar_rational operator-();
    Numar_rational operator+();

    friend Numar_rational operator + (Numar_rational,Numar_rational);
    friend Numar_rational operator + (double,Numar_rational);
    friend Numar_rational operator + (Numar_rational,int);
    friend Numar_rational operator - (Numar_rational,Numar_rational);
    friend Numar_rational operator - (double,Numar_rational);
    friend Numar_rational operator - (Numar_rational,int);
    friend Numar_rational operator * (Numar_rational,Numar_rational);
    friend Numar_rational operator * (double,Numar_rational);
    friend Numar_rational operator * (Numar_rational,int);
    friend Numar_rational operator / (Numar_rational,Numar_rational);
    friend Numar_rational operator / (double,Numar_rational);
    friend Numar_rational operator / (Numar_rational,int);
    friend Numar_rational operator ^ (Numar_rational,int);

    std::string toString();

    friend bool operator == (Numar_rational,Numar_rational);
    friend bool operator == (int,Numar_rational);
    friend bool operator == (Numar_rational,int);
    friend bool operator != (Numar_rational,Numar_rational);
    friend bool operator != (int,Numar_rational);
    friend bool operator != (Numar_rational,int);
    friend bool operator < (Numar_rational,Numar_rational);
    friend bool operator < (int,Numar_rational);
    friend bool operator < (Numar_rational,int);
    friend bool operator <= (Numar_rational,Numar_rational);
    friend bool operator <= (int,Numar_rational);
    friend bool operator <= (Numar_rational,int);
    friend bool operator > (Numar_rational,Numar_rational);
    friend bool operator > (int,Numar_rational);
    friend bool operator > (Numar_rational,int);
    friend bool operator >= (Numar_rational,Numar_rational);
    friend bool operator >= (int,Numar_rational);
    friend bool operator >= (Numar_rational,int);

    operator int();
    operator double();
    operator std::string();

    friend std::ostream& operator << (std::ostream&,Numar_rational&);
    friend std::istream& operator >> (std::istream&,Numar_rational&);
    friend std::fstream& operator >> (std::fstream&,Numar_rational&);


private:
    int m_numarator;
    int m_numitor;
    void reducere();
};

