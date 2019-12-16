/*
ideia:
receber os acordes do usuario.
criar um tema inicial(sei la como), na pior das hipoteses receber do usuario(tbm sei la como), que caiba nos acordes.
tocar esse tema em alguns instantes da musica(ainda to decidindo se ele tera variacoes ou nao) e preencher o resto da musica com coisas mais aleatorias, mas que caibam nos acordes dados pelo usuario e tbm dependentes dos pesos das notas anteriores(como na urna).
por volta de 3/4 da duracao total, desenvolver um climax(com notas mais rapidas e mais agudas)
e depois dele cair no tema principal, depois mais um enfeite e por ultimo terminar a musica.

*/


#include <iostream>
#include <cstdlib>
#include <time.h>
#include "MuMaterial.h"
#include <string.h>

using namespace std;
void troca(int *,int *);
void Mix(int *, int);



int main (void)
{	MuInit();
	MuMaterial melodia;
	MuNote nota;
	MuNote nota2;
	MuNote harmonia;
	char acordes[100];
	cout<<"Digite a sequencia de acordes: ";
	  cin.getline(acordes,100);
	strcat(acordes," ");
		cout<<"repetir quantas vezes? ";
	int n;
	cin >> n;

	char *acorde[4*4*4*4];
	//for (int i=0;i<4*4*4*4;i++)
	//*acorde[i]='\0';
	int h=0;
	int m=0;
	for(m=0;m<n;m++ ){

	int j=0;

	 for (int i=0; i < strlen(acordes); i++)
  {

 if(acordes[i]==' ')
	{	acorde[h+(m*n)]=(char*)malloc((i-j)*sizeof(char));
		strncpy(acorde[h+(m*n)],acordes+j,i-j);
		
		h++;
		i++;
		if(i==strlen(acordes))break;
		j=i;

	}

  }

}
cout <<h<<" ";


	int chances[14][13][13]=
//C
{{{12,0,33,0,15,10,0,20,0,5,0,5,10},//do
{12,0,33,0,15,10,0,20,0,5,0,5,10},//do#
{20,0,5,0,30,5,0,15,0,10,0,5,10},//re
{20,0,5,0,30,5,0,15,0,10,0,5,10},//re#
{15,0,20,0,10,15,0,20,0,5,0,5,10},//mi
{10,0,15,0,45,5,0,20,0,5,0,5,5},//fa
{10,0,20,0,10,12,0,15,0,18,0,5,10},//fa#
{10,0,20,0,10,12,0,15,0,18,0,5,10},//sol
{5,0,5,0,20,15,0,25,0,5,0,25,10},//sol#
{5,0,5,0,20,15,0,25,0,5,0,25,10},//la
{5,0,5,0,10,5,0,15,0,15,0,5,40},//sib
{5,0,5,0,10,5,0,15,0,15,0,5,40},//si
{10,0,5,0,5,15,0,10,0,20,0,20,15}}//do
,//C7
{{12,0,33,0,15,10,0,20,0,5,5,0,10},//do
{12,0,33,0,15,10,0,20,0,5,5,0,10},//do#
{20,0,5,0,30,5,0,15,0,10,5,0,10},//re
{20,0,5,0,30,5,0,15,0,10,5,0,10},//re#
{15,0,20,0,10,15,0,20,0,5,5,0,10},//mi
{10,0,15,0,45,5,0,20,0,5,5,0,5},//fa
{10,0,20,0,10,12,0,15,0,18,5,0,10},//fa#
{10,0,20,0,10,12,0,15,0,18,5,0,10},//sol
{5,0,5,0,20,15,0,25,0,5,25,0,10},//sol#
{5,0,5,0,20,15,0,25,0,5,25,0,10},//la
{5,0,5,0,10,5,0,15,0,15,5,0,40},//sib
{5,0,5,0,10,5,0,15,0,15,5,0,40},//si
{10,0,5,0,5,15,0,10,0,20,20,0,15}}//do
,//Cm
{{12,0,33,15,0,10,0,20,0,5,0,5,10},//do
{12,0,33,15,0,10,0,20,0,5,0,5,10},//do#
{20,0,5,30,0,5,0,15,0,10,0,5,10},//re
{20,0,5,30,0,5,0,15,0,10,0,5,10},//re#
{15,0,20,10,0,15,0,20,0,5,0,5,10},//mi
{10,0,15,35,0,5,0,30,0,5,0,5,5},//fa
{10,0,20,10,0,12,0,15,0,18,0,5,10},//fa#
{10,0,20,10,0,12,0,15,0,18,0,5,10},//sol
{5,0,5,20,0,15,0,25,0,5,0,25,10},//sol#
{5,0,5,20,0,15,0,25,0,5,0,25,10},//la
{5,0,5,10,0,5,0,15,0,15,0,5,40},//sib
{5,0,5,10,0,5,0,15,0,15,0,5,40},//si
{10,0,5,5,0,15,0,10,0,20,0,20,15}}//do
,//Dm
{{5,0,35,0,10,15,0,10,0,15,0,5,5},//do
{5,0,35,0,10,15,0,10,0,15,0,5,5},//do#
{15,0,15,0,15,20,0,10,0,15,0,5,5},//re
{15,0,15,0,15,20,0,10,0,15,0,5,5},//re#
{5,0,35,0,5,35,0,5,0,5,0,5,5},//mi
{5,0,15,0,15,15,0,15,0,25,0,5,5},//fa
{5,0,15,0,15,15,0,15,0,25,0,5,5},//fa#
{5,0,15,0,5,30,0,5,0,30,0,5,5},//sol
{5,0,15,0,5,30,0,5,0,30,0,5,5},//sol#
{5,0,10,0,5,20,0,20,0,20,0,15,5},//la
{5,0,10,0,5,20,0,20,0,20,0,15,5},//sib
{5,0,15,0,5,15,0,5,0,30,0,10,15},//si
{5,0,15,0,5,15,0,5,0,25,5,15,10}}//do
,//D7
{{15,0,25,0,10,0,15,10,0,15,0,5,5},//do
{5,0,35,0,10,0,15,10,0,15,0,5,5},//do#
{20,0,10,0,15,0,20,5,0,10,0,5,15},//re
{20,0,10,0,15,0,20,5,0,10,0,5,15},//re#
{15,0,25,0,5,0,25,5,0,10,0,5,10},//mi
{5,0,15,0,15,0,15,15,0,25,0,5,5},//fa
{5,0,15,0,15,0,15,15,0,25,0,5,5},//fa#
{5,0,15,0,5,0,30,5,0,25,0,5,10},//sol
{5,0,15,0,5,0,30,5,0,25,0,5,10},//sol#
{5,0,10,0,5,0,20,10,0,20,0,15,15},//la
{5,0,10,0,5,0,20,10,0,20,0,15,15},//sib
{5,0,15,0,5,0,15,5,0,25,0,5,25},//si
{5,0,15,0,5,0,15,5,0,20,5,15,15}}//do
,//Em
{{5,0,20,0,15,10,0,20,0,5,0,15,10},//do
{5,0,20,0,15,10,0,20,0,5,0,15,10},//do#
{10,0,15,0,30,10,0,15,0,5,0,10,5},//re
{10,0,15,0,30,10,0,15,0,5,0,10,5},//re#
{5,0,20,0,20,15,0,20,0,5,0,10,5},//mi
{5,0,10,0,35,5,0,30,0,5,0,5,5},//fa
{5,0,10,0,35,5,0,30,0,5,0,5,5},//fa#
{5,0,10,0,20,15,0,15,0,15,0,15,5},//sol
{5,0,10,0,20,15,0,15,0,15,0,15,5},//sol#
{5,0,5,0,15,10,0,25,0,10,0,25,5},//la
{5,0,5,0,15,10,0,25,0,10,0,25,5},//sib
{5,0,5,0,10,5,0,20,0,20,0,20,15},//si
{5,0,5,0,10,15,0,15,0,10,0,30,10}}//do
,//E7 to aqui.
{{5,0,20,0,15,10,0,0,20,5,0,15,10},//do
{5,0,20,0,15,10,0,0,20,5,0,15,10},//do#
{10,0,15,0,30,10,0,0,15,5,0,10,5},//re
{10,0,15,0,30,10,0,0,15,5,0,10,5},//re#
{5,0,20,0,20,15,0,0,20,5,0,10,5},//mi
{5,0,15,0,30,5,0,0,30,5,0,5,5},//fa
{5,0,15,0,30,5,0,0,30,5,0,5,5},//fa#
{5,0,10,0,20,15,0,0,15,15,0,15,5},//sol
{5,0,10,0,20,15,0,0,15,15,0,15,5},//sol#
{5,0,5,0,15,10,0,0,25,10,0,25,5},//la
{5,0,5,0,15,10,0,0,25,10,0,25,5},//sib
{5,0,5,0,10,5,0,0,20,20,0,20,15},//si
{5,0,15,0,10,15,0,0,15,10,0,20,10}}//do
,//F to aqui
{{12,0,33,0,15,10,0,20,0,5,0,5,10},//do
{12,0,33,0,15,10,0,20,0,5,0,5,10},//do#
{20,0,5,0,30,5,0,15,0,10,0,5,10},//re
{20,0,5,0,30,5,0,15,0,10,0,5,10},//re#
{15,0,20,0,10,15,0,20,0,5,0,5,10},//mi
{10,0,15,0,45,5,0,20,0,5,0,5,5},//fa
{10,0,20,0,10,12,0,15,0,18,0,5,10},//fa#
{10,0,20,0,10,12,0,15,0,18,0,5,10},//sol
{5,0,5,0,20,15,0,25,0,5,0,25,10},//sol#
{5,0,5,0,20,15,0,25,0,5,0,25,10},//la
{5,0,5,0,10,5,0,15,0,15,0,5,40},//sib
{5,0,5,0,10,5,0,15,0,15,0,5,40},//si
{10,0,5,0,5,15,0,10,0,20,0,20,15}}//do
,//Fm
{{12,0,33,0,15,10,0,20,0,5,0,5,10},//do
{12,0,33,0,15,10,0,20,0,5,0,5,10},//do#
{20,0,5,0,30,5,0,15,0,10,0,5,10},//re
{20,0,5,0,30,5,0,15,0,10,0,5,10},//re#
{15,0,20,0,10,15,0,20,0,5,0,5,10},//mi
{10,0,15,0,45,5,0,20,0,5,0,5,5},//fa
{10,0,20,0,10,12,0,15,0,18,0,5,10},//fa#
{10,0,20,0,10,12,0,15,0,18,0,5,10},//sol
{5,0,5,0,20,15,0,25,0,5,0,25,10},//sol#
{5,0,5,0,20,15,0,25,0,5,0,25,10},//la
{5,0,5,0,10,5,0,15,0,15,0,5,40},//sib
{5,0,5,0,10,5,0,15,0,15,0,5,40},//si
{10,0,5,0,5,15,0,10,0,20,0,20,15}}//do
,//G
{{12,0,33,0,15,10,0,20,0,5,0,5,10},//do
{12,0,33,0,15,10,0,20,0,5,0,5,10},//do#
{20,0,5,0,30,5,0,15,0,10,0,5,10},//re
{20,0,5,0,30,5,0,15,0,10,0,5,10},//re#
{15,0,20,0,10,15,0,20,0,5,0,5,10},//mi
{10,0,15,0,45,5,0,20,0,5,0,5,5},//fa
{10,0,20,0,10,12,0,15,0,18,0,5,10},//fa#
{10,0,20,0,10,12,0,15,0,18,0,5,10},//sol
{5,0,5,0,20,15,0,25,0,5,0,25,10},//sol#
{5,0,5,0,20,15,0,25,0,5,0,25,10},//la
{5,0,5,0,10,5,0,15,0,15,0,5,40},//sib
{5,0,5,0,10,5,0,15,0,15,0,5,40},//si
{10,0,5,0,5,15,0,10,0,20,0,20,15}}//do
,//Gm
{{12,0,33,0,15,10,0,20,0,5,0,5,10},//do
{12,0,33,0,15,10,0,20,0,5,0,5,10},//do#
{20,0,5,0,30,5,0,15,0,10,0,5,10},//re
{20,0,5,0,30,5,0,15,0,10,0,5,10},//re#
{15,0,20,0,10,15,0,20,0,5,0,5,10},//mi
{10,0,15,0,45,5,0,20,0,5,0,5,5},//fa
{10,0,20,0,10,12,0,15,0,18,0,5,10},//fa#
{10,0,20,0,10,12,0,15,0,18,0,5,10},//sol
{5,0,5,0,20,15,0,25,0,5,0,25,10},//sol#
{5,0,5,0,20,15,0,25,0,5,0,25,10},//la
{5,0,5,0,10,5,0,15,0,15,0,5,40},//sib
{5,0,5,0,10,5,0,15,0,15,0,5,40},//si
{10,0,5,0,5,15,0,10,0,20,0,20,15}}//do
,//Am
{{10,0,30,0,25,10,0,10,0,15,0,5,5},//do
{10,0,30,0,25,10,0,10,0,15,0,5,5},//do#
{20,0,10,0,30,5,0,5,0,15,0,5,10},//re
{20,0,10,0,30,5,0,5,0,15,0,5,10},//re#
{15,0,20,0,10,15,0,10,0,10,0,5,10},//mi
{10,0,10,0,30,5,0,20,0,15,0,5,5},//fa
{10,0,10,0,30,5,0,20,0,15,0,5,5},//fa#
{10,0,5,0,10,15,0,15,0,30,0,5,10},//sol
{10,0,5,0,10,15,0,15,0,30,0,5,10},//sol#
{5,0,5,0,15,10,0,20,0,20,0,15,10},//la
{5,0,5,0,15,10,0,20,0,20,0,15,10},//sib
{5,0,5,0,10,5,0,5,0,30,0,10,30},//si
{10,0,5,0,5,15,0,5,0,25,0,20,15}}//do
,//A7
{{12,0,33,0,15,10,0,20,0,5,0,5,10},//do
{12,0,33,0,15,10,0,20,0,5,0,5,10},//do#
{20,0,5,0,30,5,0,15,0,10,0,5,10},//re
{20,0,5,0,30,5,0,15,0,10,0,5,10},//re#
{15,0,20,0,10,15,0,20,0,5,0,5,10},//mi
{10,0,15,0,45,5,0,20,0,5,0,5,5},//fa
{10,0,20,0,10,12,0,15,0,18,0,5,10},//fa#
{10,0,20,0,10,12,0,15,0,18,0,5,10},//sol
{5,0,5,0,20,15,0,25,0,5,0,25,10},//sol#
{5,0,5,0,20,15,0,25,0,5,0,25,10},//la
{5,0,5,0,10,5,0,15,0,15,0,5,40},//sib
{5,0,5,0,10,5,0,15,0,15,0,5,40},//si
{10,0,5,0,5,15,0,10,0,20,0,20,15}}//do
,//Bb
{{12,0,33,0,15,10,0,20,0,5,0,5,10},//do
{12,0,33,0,15,10,0,20,0,5,0,5,10},//do#
{20,0,5,0,30,5,0,15,0,10,0,5,10},//re
{20,0,5,0,30,5,0,15,0,10,0,5,10},//re#
{15,0,20,0,10,15,0,20,0,5,0,5,10},//mi
{10,0,15,0,45,5,0,20,0,5,0,5,5},//fa
{10,0,20,0,10,12,0,15,0,18,0,5,10},//fa#
{10,0,20,0,10,12,0,15,0,18,0,5,10},//sol
{5,0,5,0,20,15,0,25,0,5,0,25,10},//sol#
{5,0,5,0,20,15,0,25,0,5,0,25,10},//la
{5,0,5,0,10,5,0,15,0,15,0,5,40},//sib
{5,0,5,0,10,5,0,15,0,15,0,5,40},//si
{10,0,5,0,5,15,0,10,0,20,0,20,15}}}//do
;





	nota.SetInstr(1);
	nota.SetDur(0.5);
	nota.SetAmp(0.7);
	
	nota2.SetInstr(1);
	nota2.SetDur(0.5);
	nota2.SetAmp(0.7);

	harmonia.SetInstr(3);
	harmonia.SetDur(4);
	harmonia.SetAmp(0.3);

	//int escala[13]={60,61,62,63,64,65,66,67,68,69,70,71,72};
	//começa com do, mi ou sol

	int bet=Between(0,2)*2;
	int bet2=Between(0,2)*2;

	int base=60;
int ac=0;
int cont=0;
melodia.AddVoices(2);
for(int z=0;z<h;z++)
{
if(strcmp(acorde[cont],"C")==0) ac=0;
if(strcmp(acorde[cont],"C7")==0) ac=1;
if(strcmp(acorde[cont],"Cm")==0) ac=2;
if(strcmp(acorde[cont],"Dm")==0) ac=3;
if(strcmp(acorde[cont],"D7")==0) ac=4;
if(strcmp(acorde[cont],"Em")==0) ac=5;
if(strcmp(acorde[cont],"E7")==0) ac=6;
if(strcmp(acorde[cont],"F")==0) ac=7;
if(strcmp(acorde[cont],"Fm")==0) ac=8;
if(strcmp(acorde[cont],"G")==0) ac=9;
if(strcmp(acorde[cont],"Gm")==0) ac=10;
if(strcmp(acorde[cont],"Am")==0) ac=11;
if(strcmp(acorde[cont],"A7")==0) ac=12;
if(strcmp(acorde[cont],"Bb")==0) ac=13;
cont++;
cont=cont%(h/n);
harmonia.SetStart(z*4.0);

switch(ac){
case 0: 
harmonia.SetPitch(48);
melodia.AddNote(1,harmonia);
harmonia.SetPitch(52);
melodia.AddNote(1,harmonia);
harmonia.SetPitch(55);
melodia.AddNote(1,harmonia);
break;


case 1: 
harmonia.SetPitch(48);
melodia.AddNote(1,harmonia);
harmonia.SetPitch(52);
melodia.AddNote(1,harmonia);
harmonia.SetPitch(55);
melodia.AddNote(1,harmonia);
harmonia.SetPitch(58);
melodia.AddNote(1,harmonia);
break;

case 2: 
harmonia.SetPitch(48);
melodia.AddNote(1,harmonia);
harmonia.SetPitch(51);
melodia.AddNote(1,harmonia);
harmonia.SetPitch(55);
melodia.AddNote(1,harmonia);
break;

case 3: 
harmonia.SetPitch(50);
melodia.AddNote(1,harmonia);
harmonia.SetPitch(53);
melodia.AddNote(1,harmonia);
harmonia.SetPitch(57);
melodia.AddNote(1,harmonia);
break;

case 4: 
harmonia.SetPitch(50);
melodia.AddNote(1,harmonia);
harmonia.SetPitch(54);
melodia.AddNote(1,harmonia);
harmonia.SetPitch(57);
melodia.AddNote(1,harmonia);
harmonia.SetPitch(60);
melodia.AddNote(1,harmonia);
break;

case 5: 
harmonia.SetPitch(52);
melodia.AddNote(1,harmonia);
harmonia.SetPitch(55);
melodia.AddNote(1,harmonia);
harmonia.SetPitch(59);
melodia.AddNote(1,harmonia);
break;

case 6: 
harmonia.SetPitch(52);
melodia.AddNote(1,harmonia);
harmonia.SetPitch(56);
melodia.AddNote(1,harmonia);
harmonia.SetPitch(59);
melodia.AddNote(1,harmonia);
harmonia.SetPitch(62);
melodia.AddNote(1,harmonia);
break;

case 7: 
harmonia.SetPitch(53);
melodia.AddNote(1,harmonia);
harmonia.SetPitch(57);
melodia.AddNote(1,harmonia);
harmonia.SetPitch(60);
melodia.AddNote(1,harmonia);
break;

case 8: 
harmonia.SetPitch(53);
melodia.AddNote(1,harmonia);
harmonia.SetPitch(56);
melodia.AddNote(1,harmonia);
harmonia.SetPitch(60);
melodia.AddNote(1,harmonia);
break;

case 9: 
harmonia.SetPitch(43);
melodia.AddNote(1,harmonia);
harmonia.SetPitch(47);
melodia.AddNote(1,harmonia);
harmonia.SetPitch(50);
melodia.AddNote(1,harmonia);
break;

case 10: 
harmonia.SetPitch(43);
melodia.AddNote(1,harmonia);
harmonia.SetPitch(46);
melodia.AddNote(1,harmonia);
harmonia.SetPitch(50);
melodia.AddNote(1,harmonia);
break;

case 11: 
harmonia.SetPitch(45);
melodia.AddNote(1,harmonia);
harmonia.SetPitch(48);
melodia.AddNote(1,harmonia);
harmonia.SetPitch(52);
melodia.AddNote(1,harmonia);
break;

case 12: 
harmonia.SetPitch(45);
melodia.AddNote(1,harmonia);
harmonia.SetPitch(49);
melodia.AddNote(1,harmonia);
harmonia.SetPitch(52);
melodia.AddNote(1,harmonia);
harmonia.SetPitch(55);
melodia.AddNote(1,harmonia);
break;

case 13: 
harmonia.SetPitch(46);
melodia.AddNote(1,harmonia);
harmonia.SetPitch(50);
melodia.AddNote(1,harmonia);
harmonia.SetPitch(53);
melodia.AddNote(1,harmonia);
break;

default: break;
}

	for(int i=0;i<8;i++)
	{nota.SetInstr(3);
	nota.SetStart(nota.Start()+nota.Dur());
	nota.SetPitch(base+bet);

	nota2.SetInstr(3);
	nota2.SetStart(nota2.Start()+nota2.Dur());
	nota2.SetPitch(base+bet2);
cout<<nota.Pitch()<<" ";
	melodia.AddNote(nota);
	//melodia.AddNote(2,nota2);

//enchendo a urna
	int urna[100];
	int m=0;
	for(int k=0;k<13;k++)
		for(int l=0;l<chances[ac][bet][k];l++)
			{urna[m]=k;
			m++;}
	//misturando a urna
	Mix(urna,100);

// escolhendo um valor aleatorio na urna
	bet=urna[Between(0,100)];
	bet2=urna[Between(0,100)];

	}
}
	
     melodia.SetDefaultFunctionTables();
	melodia.Score("melodia.sco");
	melodia.Orchestra("melodia.orc");

	system("csound melodia.orc melodia.sco");
 return 0;
}
void Mix(int * a, int tam)
{
int i;
for(i=0;i<tam;i++)
troca(a+i,a+Between(i,tam-1));
}

void troca(int * a,int * b)
{
int aux;
aux=*a;
*a=*b;
*b=aux;
}

