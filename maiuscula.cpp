#include <iostream>
using namespace std;

void maiusculizar(char *);
bool eMaiuscula(char);

int main(void)
{

cout<<"Digite uma string"<<endl;
char str[100];
cin.getline(str, 100);
maiusculizar(str);
cout<<str;

return 0;}

bool eMaiuscula(char ch)
{return(ch>='A' && ch<='Z');}

void maiusculizar(char *str)
{
int i=0;
	while(str[i]!='\0')
	{
	if(!eMaiuscula(str[i]))
	str[i]-=32;
	i++;
	}
}
