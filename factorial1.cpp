#include <iostream>  
using namespace std;  
int main()  
{  
   int i,n,fact=1;    
  cout<<"Enter the Number: ";    
 cin>>n;    
  for(i=1;i<=n;i++){    
      fact=fact*i;    
  }    
  cout<<"Factorial of " <<n<<" is: "<<fact<<endl;  
  return 0;  
}  
