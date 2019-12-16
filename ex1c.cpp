#include <iostream>
using namespace std;
int main(void)
{int x, y;
int a, b, c;
x = 3;
y = 2;
a = 5;
b = 10;
c = (x+y) * (a - b);
--x *= (y*c);
cout<<x;
return 0;}
