#include<iostream>
using namespace std;
int global = 5;
void sum(int a) 
{
  a = a+global;
 cout<<global;
}
int main()
{ 
  global = 9;
  sum(10);
  cout<<global;
  return 0;
}
