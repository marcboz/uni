#include <iostream>

using namespace std;

void hello()
{
  cout<<"Hello World!"<<endl;
}

float fun2(float input1)
{
  return input1;
}

int sum(int suma, int sumb)
{
  
  int sumt;
  sumt=suma+sumb;
  return sumt;
}

int mult(int mult1, float mult2, float mult3)
{
  int multt=mult1*mult2*mult3;
  return multt;
}
int array(int arr[],int arrsize)
{
  int arrt=1;
  
  for(int counter=0;counter<arrsize;counter++)
  {
	arrt=arrt*arr[counter];
  }
  
  return arrt;
}
int main()
{
  float input1,mult2,mult3;
  int suma, sumb,mult1,arrsize;
  int arr[5];
  hello();
  cin>>input1;
  cout<<fun2(input1)<<endl;
  cout<<"Podaj liczby do dodania"<<endl;
  cin>>suma;
  cin>>sumb;
  cout<<"Wynik dodawania: "<<sum(suma,sumb)<<endl;
  cout<<"Mnozenie trzech elementow: "<<endl;
  cin>>mult1;cin>>mult2;cin>>mult3;
  cout<<mult(mult1,mult2,mult3)<<endl;
  cout<<"Wprowadz elementy tablicy: "<<endl;
  for(int counter=0;counter<5;counter++)
  {
	  cin>>arr[counter];
  }
  cout<<"Iloczyn elementow tablicy: "<<array(arr,5)<<endl;
  
  return 0;
}
  
