#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;
int main (void)
{	srand((unsigned)time(0)); 	 
	int valor = rand() % 10 + 1;
      int input = 0;
      cout << "Digite um número de 1 a 10: ";
      cin >> input;
	if (input <1 || input >10) cout << "Eu disse de 1 a 10" << endl;
	else	if (input == valor) cout << "Parabéns, você acertou!" << endl;
	else if (input >valor) cout << "Você errou: número muito grande!" << endl;
	else if (input <valor) cout << "Você errou: número muito pequeno!" << endl;

 return 0;
}

 

