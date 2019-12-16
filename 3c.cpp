#include <iostream>
using namespace std;

int media(int n1, int n2)
	{return (n1+n2)/2;}

int menu(int n)
	{cout<<"Eu acho que se numero é "<<n<< endl;
	cout<<"Digite 1 se eu acertei!\n";
	cout<<"Digite 2 se o numero que voce pensou é menor que "<<n<<endl;
	cout<<"Digite 3 se o numero que voce pensou é maior que "<<n<<endl;
	cout<<"Nao vale mentir, viu?!"<<endl;
	int opcao;
	cin>>opcao;
	return opcao;
 }
 
int main (void)
{	int max=100, min=0, chute;
	bool sair=false;
     cout << "Pense num numero de 0 a 100.\n";
	 getchar();

		do{     
		chute=media(max,min);
		switch(menu(chute))
		{
			case 1:cout<<"Acertei!!!"<<endl; sair =true; break;
			case 2:max=chute; break;
			case 3:min=chute; break;
			default:cout<<"Assim nao da pra saber né, amigo, escolha 1 ou 2 ou 3."<<endl;
		}	
		}while(!sair);
 return 0;
}
