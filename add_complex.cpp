#include<bits/stdc++.h>
using namespace std;
class Complex {
	public:
	int real, imaginary;
	
	Complex(int r = 0, int i = 0){
		real = r;
		imaginary = i;
	}

	
	Complex addComp(Complex C1, Complex C2)	{
		Complex temp;
		temp.real = C1.real + C2.real;
		temp.imaginary = C1.imaginary + C2.imaginary;
		return temp;
	}
};


int main(){
	int r1,c1,r2,c2;
	cout<<"Enter the 1st NUMBER REAL PART AND AND COMPLEX PART:"<<endl;
	cin>>r1>>c1;
	Complex C1(r1,c1);
	cout<<"Complex number 1 : "<< C1.real<<"+"<< C1.imaginary<<"i"<<endl;
	Complex C2(9, 5);
	cout<<"Complex number 2 : "<< C2.real<<"+"<< C2.imaginary<<"i"<<endl;

	Complex C3;
	// calling addComp() method
	C3 = C3.addComp(C1, C2);
	cout<<"Sum of complex number : "<< C3.real <<"+"<< C3.imaginary<<"i";
}