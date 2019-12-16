#include <iostream>
using namespace std;
int main(void)
{
      int bms = 0;
      int x ;
	 cout << "Digite um número: ";
      cin>>x;
	 int pot=1;
	 while(x>=pot)
	{
	 pot*=2;
	 bms++;
	}
      cout << x << " = ";
      for(int i = bms; i >= 0; i--)
      {
            int y = x;
            int j = i;
            while(j--)
                   y /= 2;
            if(y % 2)
                   cout << "1" ;
            else
                   cout << "0";
      }
      cout << endl;
      return 0;
}

