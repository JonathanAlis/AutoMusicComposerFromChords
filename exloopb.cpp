#include <iostream>
using namespace std;
int main(void)
{
int i, pot=1;
for(i=1;i<=26;i++){
int j;
for(j=1;j<=i;j++){
cout << static_cast<char>(64+i);
}
cout <<endl;
}
return 0;}
