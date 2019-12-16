#include <iostream>
using namespace std;
int main(void)
{
float n1,n2,n3,n4;
int p1=1,p2=2,p3=4,p4=8;
cout<<"Digite a primeira nota: ";
cin>>n1;
cout<<"Digite a segunda nota: ";
cin>>n2;
cout<<"Digite a terceira nota: ";
cin>>n3;
cout<<"Digite a quarta nota: ";
cin>>n4;
cout<<"A media e: "<<float (n1*p1+n2*p2+n3*p3+n4*p4)/(p1+p2+p3+p4)<<endl;
return 0;}
