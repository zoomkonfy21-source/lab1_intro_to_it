ружественные функции. Перегрузка операторов 
Решение квадратного уравнения вида , для любых коэффициентов (модификация примера 17).
#include <iostream>
#include <cmath>
using namespace std;
class comp {
double x,y;
public:
comp (double i=0, double j=0) { x = i; y = j; }
void setx(double i){x=i;}
void sety(double j){y=j;}
friend ostream &operator<<(ostream &stream,comp ob);
friend void f(double a, double b, double c, double d, comp &z1, comp &z2);
};
ostream &operator<<(ostream &stream,comp ob)
{
   if (ob.y>0) stream<<ob.x<<"+"<<ob.y<<"i";
   else if (ob.y<0) stream<<ob.x<<ob.y<<"i";
   else stream<<ob.x;
   return stream;
}
void f(double a, double b, double c, double d, comp &z1, comp &z2)
{
if(d<0)
{z1.x=-b/(2*a);
z2.x=-b/(2*a);
z1.y=sqrt(-d)/(2*a);
z2.y=-sqrt(-d)/(2*a);
}
else
{z1.x=(-b+sqrt(d))/(2*a);
z2.x=(-b-sqrt(d))/(2*a);
z1.y=0;
z2.y=0;
}
}
int main ()
{comp z1(0,0), z2(0,0);
double a,b,c;
cout<<"input a,b,c";
cin>>a>>b>>c;
double d=b*b-4*a*c;
f(a,b,c,d,z1,z2);
cout <<"z1=" << z1<<"\n";
cout << "z2=" << z2<<"\n";
return 0;
}
