#include <iostream>
#include <cstdlib>
#include <time.h>
#include "MuMaterial.h"


using namespace std;
void troca(int * a,int * b)
{
int aux;
aux=*a;
*a=*b;
*b=aux;
}

void Mix(int * a, int tam)
{
int i;
for(i=0;i<tam;i++)
troca(a+i,a+Between(i,tam-1));
}

int main()
{
int a[100], i;
for(i=0;i<100;i++)
{a[i]=i;
printf("%d ", a[i]);
}printf("\n");
Mix(a,100);
for(i=0;i<100;i++)
{
printf("%d ", a[i]);
}

}


