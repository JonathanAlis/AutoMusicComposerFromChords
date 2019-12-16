#include <iostream>
using namespace std;
int main(void)
{int a, b, c;
cout<<a<<" "<<b<<" "<<c<<endl;
a = 12;
cout<<a<<" "<<b<<" "<<c<<endl;
b = 13;
cout<<a<<" "<<b<<" "<<c<<endl;
c = 14;
cout<<a<<" "<<b<<" "<<c<<endl;
a = a + b;
cout<<a<<" "<<b<<" "<<c<<endl;
b = c - 7;
cout<<a<<" "<<b<<" "<<c<<endl;
c -= a++ * b;
cout<<a<<" "<<b<<" "<<c<<endl;
return 0;}
