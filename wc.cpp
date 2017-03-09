



#include<iostream>
#include<cstdlib>
#include<iomanip> 
using namespace std;
//class definition
class fraction
{
    private:
    int n,d;
    

public:
    fraction();
    fraction(int);
    fraction(int,int);
    int gcd();
    
    int num();
    int denom();
    fraction reduce();
    double convert();
};

int fraction::gcd()
{
	int x,y;
	x = num();
	y = denom();
    while(y!=0)
    {int temp=x;
        x=y;
        y=temp%y;}
    return x;
}


//Constructor Definitions

fraction::fraction()
{n=1,d=0;}
fraction::fraction(int a)
{n=1,d=a;}
fraction::fraction(int a,int b)
{n=a,d=b;}

//Class Function Definitions
int fraction::num()
{return n;}
int fraction::denom()
{return d;}
fraction fraction::reduce()
{int x=gcd();
    fraction c(n/x, d/x);
    return c;}

double fraction::convert()
{return d*1.0/n;}

//Overloaded Operator Definitions
fraction operator-(fraction B)
{
    int x= B.gcd();
    int a=-B.num()/x;
    int b=B.denom()/x;
    fraction C(a,b);
    return C;
}

fraction operator+(fraction B)
{
    int x= B.gcd();
    int a=B.num()/x;
    int b=B.denom()/x;
    fraction C(a,b);
    return C;
}

fraction operator+(fraction A, fraction B)
{
    int a=A.denom()*B.num()+B.denom()*A.num();
    int b=A.num()*B.num();
    fraction C(a/gcd(a,b), b/gcd(a,b));
    return C;
}

fraction operator-(fraction A, fraction B)
{
    int a=A.denom()*B.num()-B.denom()*A.num();
    int b=A.num()*B.num();
    fraction C(a/gcd(a,b), b/gcd(a,b));
    return C;
}

fraction operator*(fraction A, fraction B)
{
    int a=A.denom()*B.denom();
    int b=A.num()*B.num();
    fraction C(a/gcd(a,b), b/gcd(a,b));
    return C;
}

fraction operator/(fraction A, fraction B)
{
    int a=A.denom()*B.num();
    int b=A.num()*B.denom();
    fraction C(a/gcd(a,b), b/gcd(a,b));
    return C;
}

void operator+=(fraction&A, fraction B)
{
    A=A+B;
}
void operator-=(fraction&A, fraction B)
{
    A=A-B;
}
void operator*=(fraction&A, fraction B)
{
    A=A*B;
}
void operator/=(fraction&A, fraction B)
{
    A=A/B;
}

bool operator==(fraction A, fraction B)
{
    if(A.convert()==B.convert())
        return true;
    else
        return false;
}
bool operator!=(fraction A, fraction B)
{
    if(A==B)
        return false;
    else
        return true;
}
bool operator>(fraction A, fraction B)
{
    if(A.convert()> B.convert())
        return true;
    else
        return false;
}
bool operator<(fraction A, fraction B)
{
    if(A.convert()< B.convert())
        return true;
    else
        return false;
}
bool operator>=(fraction A, fraction B)
{
    if(A<B)
        return false;
    else
        return true;
}
bool operator<=(fraction A, fraction B)
{
    if(A>B)
        return false;
    else
        return true;
}

ostream& operator<<(ostream&out, fraction B)
{
    if(B.num()==0)
        out <<"0";
    else if(B.denom()==1)
        out << B.num();
    else
        out << B.num() <<"/" << B.denom();
    return out;
}

istream& operator>>(istream&in, fraction B)
{
    int a,b;
    //char /;
    in >> a >> '/' >> b;
    fraction C(a,b);
    B=C;
    return in;
}
int main(){
	return 0;
}

