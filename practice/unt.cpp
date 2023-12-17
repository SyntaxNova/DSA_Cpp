#include<iostream>
using namespace std;

 class Complex{
	public:
	int real;
	int imag ;
	

	
	
static void multiply(Complex c1 , Complex c2){
	Complex temp;
	temp.real = c1.real * c2.real - (c1.imag*c2.imag);
	temp.imag = c1.real*c2.imag + c2.real*c1.imag ;
	
	
}


};

Complex  add(Complex c1 , Complex c2){
	Complex temp;
	temp.real = c1.real + c2.real;
	temp.imag = c1.imag + c2.imag;
	return temp;	
}

Complex  subtract(Complex c1 , Complex c2){
	Complex temp;
	temp.real = c1.real - c2.real;
	temp.imag = c1.imag - c2.imag ;
	return temp;
	
}

 

void  Display(){
	Complex c;
	
	cout<<c.real<<" + "<<c.imag<<"i";	
}


int main(){
	Complex c1;
	Complex c2;
	
	
	cout<<"Enter real part of Complex num 1 : ";
	cin>>c1.real;
	cout<<endl;
	
	cout<<"Enter imag part of Complex num 1 : ";
	cin>>c1.imag;
	cout<<endl;
	
	cout<<"Enter real part of Complex num 2 : ";
	cin>>c2.real;
	cout<<endl;
	
	cout<<"Enter imag part of Complex num 2 : ";
	cin>>c2.imag;
	cout<<endl;
	
	cout<<"Complex num 1 : ";
	cout<<c1.real<<" + "<<c1.imag<<"i";
	cout<<endl;
	cout<<"Complex num 2 : ";
	cout<<c2.real<<" + "<<c2.imag<<"i";
	cout<<endl;
	
	Complex temp;
//	temp.real = c1.real + c2.real;
//	temp.imag = c1.imag + c2.imag;
	cout<<temp.real<<" + "<<temp.imag<<"i";
	cout<<endl;
	
//	temp.real = c1.real - c2.real;
//	temp.imag = c1.imag - c2.imag ;
	cout<<temp.real<<" + "<<temp.imag<<"i";
	cout<<endl;
/*	
	temp.real = c1.real*c2.real + (c1.imag*c2.imag)*(-1);
	temp.imag = c1.real*c2.imag + c2.real*c1.imag ;
	cout<<temp.real<<" + "<<temp.imag<<"i";
	cout<<endl;
*/	
	
	temp.multiply(c1,c2);
	cout<<temp.real<<" + "<<temp.imag<<"i";
	cout<<endl;
	
	return 0;
}













