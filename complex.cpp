#include<iostream>
using namespace std;
class complex
{
private:
int r;
int i;
public:
complex()
{
r=0;
i=0;
}
complex(int re,int co)
{
r=re;
i=co;
}
friend ostream &operator << (ostream &output, complex &c)
{
output<<c.r<<"+"<<c.i<<"i"<<endl;
return output;
}
friend istream &operator>>(istream &input, complex &c)
{
input>>c.r>>c.i;
return input;
}
};
int main()
{
complex c1(11,10),c2(5,11);
cout<<"First no.:"<<c1<<endl;
cout<<"Second no.:"<<c2<<endl;
return 0;
}
