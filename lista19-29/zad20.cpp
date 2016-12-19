#include <iostream>

using namespace std;
	
int readHeight()
{
	int height;
	cout<<"Podaj wzrost: ";
	cin>>height;
	cout<<endl;
	return height;
}

int readMass()
{
	int mass;
	cout<<"Podaj wage: ";
	cin>>mass;
	cout<<endl;
	return mass;
}

float BMI(int height,int mass)
{
	float BMI,height2;
	height2=height;
	BMI=mass/((height2/100)*(height2/100));
	return BMI;
}

float BMIprint(float BMI)
{
	cout<<"Twoje BMI to: "<<BMI<<endl;
	return 0;
}

int main()
{
	BMIprint(BMI(readHeight(),readMass()));
	return 0;
}



