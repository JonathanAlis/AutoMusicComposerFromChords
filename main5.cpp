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
#include <math.h>
using namespace std;
void troca(int *,int *);
void Mix(int *, int);
float dur1(int PertenceAoAcorde, int rapido, float);
float dur2(int PertenceAoAcorde, int rapido, float);
float dur3(int PertenceAoAcorde, int rapido, float);
int main (void)
{	MuInit();
	MuMaterial melodia;
	MuNote nota;
	MuNote nota2;
	MuNote harmonia;
//parte pra receber os acordes do usuario ,por enquanto ainda sao strings
	char acordes[100];
	cout<<"Digite a sequencia de acordes: ";
	  cin.getline(acordes,100);
	strcat(acordes," ");
		cout<<"repetir quantas vezes? ";
	int n;
	cin >> n;
		cout<<"a quantos bpm? ";
	int bpm;
	cin >> bpm;
	
	char *acorde[4*4*4*4];
	
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

puts("Dados recebidos!");
//aqui é a matriz de chances de uma nota acontecer.
	int chances[14][12][12]=
//C
{{{15,0,30,0,15,7,0,13,0,5,0,15},//do
{25,0,30,0,15,7,0,13,0,5,0,5},//do#
{20,0,5,0,30,5,0,15,0,10,0,5},//re
{15,0,10,0,30,5,0,15,0,10,0,5},//re#
{15,0,20,0,10,15,0,20,0,5,0,5},//mi
{10,0,15,0,45,5,0,20,0,5,0,5},//fa
{10,0,5,0,10,12,0,30,0,18,0,5},//fa#
{10,0,25,0,15,12,0,15,0,18,0,5},//sol
{5,0,5,0,20,15,0,25,0,20,0,10},//sol#
{25,0,5,0,10,10,0,25,0,5,0,20},//la
{25,0,5,0,10,5,0,20,0,20,0,15},//sib
{35,0,10,0,10,5,0,20,0,15,0,5}}//si
,//C7
{{15,0,30,0,15,7,0,13,0,5,15,0},//do
{20,0,25,0,15,7,0,13,0,5,15,0},//do#
{20,0,5,0,30,5,0,15,0,10,5,0},//re
{15,0,10,0,30,5,0,15,0,10,5,0},//re#
{15,0,20,0,10,15,0,20,0,5,5,0},//mi
{10,0,15,0,45,5,0,20,0,5,5,0},//fa
{10,0,5,0,10,12,0,30,0,18,5,0},//fa#
{10,0,25,0,15,12,0,15,0,18,5,0},//sol
{5,0,5,0,20,15,0,25,0,20,10,0},//sol#
{25,0,5,0,10,10,0,25,0,5,20,0},//la
{25,0,5,0,10,5,0,20,0,20,15,0},//sib
{20,0,10,0,10,5,0,20,0,15,20,0}}//si
,//Cm
{{15,0,30,15,0,7,0,13,0,5,0,15},//do
{25,0,30,15,0,7,0,13,0,5,0,5},//do#
{20,0,5,30,0,5,0,15,0,10,0,5},//re
{15,0,10,30,0,5,0,15,0,10,0,5},//re#
{15,0,20,10,0,15,0,20,0,5,0,5},//mi
{10,0,15,45,0,5,0,20,0,5,0,5},//fa
{10,0,5,10,0,12,0,30,0,18,0,5},//fa#
{10,0,25,15,0,12,0,15,0,18,0,5},//sol
{5,0,5,20,0,15,0,25,0,20,0,10},//sol#
{25,0,0,5,10,10,0,25,0,5,0,20},//la
{25,0,0,5,10,5,0,20,0,20,0,15},//sib
{35,0,0,10,10,5,0,20,0,15,0,5}}//si
,//Dm 
{{10,0,30,0,10,15,0,10,0,15,0,10},//do
{15,0,35,0,15,15,0,5,0,10,0,5},//do#
{15,0,20,0,15,20,0,5,0,15,0,10},//re
{15,0,20,0,20,10,0,10,0,15,0,5},//re#
{5,0,35,0,5,35,0,5,0,10,0,5},//mi
{5,0,15,0,20,25,0,15,0,15,0,5},//fa
{5,0,15,0,15,30,0,15,0,15,0,5},//fa#
{5,0,15,0,5,30,0,10,0,30,0,5},//sol
{5,0,10,0,5,25,0,10,0,35,0,10},//sol#
{5,0,10,0,5,20,0,20,0,20,5,15},//la
{10,0,10,0,5,15,0,15,0,30,0,15},//sib
{20,0,15,0,5,15,0,5,0,30,0,10}}//si
,//D7
{{15,0,25,0,10,0,15,5,0,15,0,10},//do
{5,0,35,0,10,0,15,10,0,15,0,5},//do#
{20,0,10,0,15,0,20,5,0,10,0,5},//re
{20,0,15,0,15,0,15,5,0,10,0,5},//re#
{15,0,25,0,5,0,25,5,0,10,0,5},//mi
{10,0,10,0,5,0,25,15,0,25,0,5},//fa
{10,0,10,0,20,0,15,20,0,15,0,5},//fa#
{10,0,10,0,5,0,30,5,0,25,0,5},//sol
{10,0,10,0,5,0,20,5,0,35,0,5},//sol#
{20,0,10,0,5,0,20,10,0,20,0,15},//la
{20,0,10,0,5,0,20,10,0,20,0,15},//sib
{35,0,15,0,5,0,15,5,0,20,0,5}}//si
,//Em 
{{10,0,15,0,15,5,0,15,0,10,0,30},//do
{10,0,15,0,15,5,0,15,0,10,0,30},//do#
{20,0,10,0,30,5,0,15,0,5,0,15},//re
{10,0,20,0,30,5,0,15,0,5,0,15},//re#
{15,0,20,0,10,15,0,20,0,5,0,15},//mi
{5,0,15,0,45,5,0,20,0,5,0,5},//fa
{5,0,15,0,20,5,0,45,0,5,0,5},//fa#
{5,0,10,0,20,17,0,20,0,18,0,10},//sol
{5,0,5,0,20,15,0,25,0,5,0,25},//sol#
{10,0,5,0,15,15,0,25,0,5,0,25},//la
{15,0,5,0,10,5,0,15,0,15,0,35},//sib
{25,0,15,0,10,5,0,15,0,15,0,15}}//si
,//E7 
{{10,0,15,0,15,5,0,0,15,10,0,30},//do
{10,0,15,0,15,5,0,0,15,10,0,30},//do#
{20,0,10,0,30,5,0,0,15,5,0,15},//re
{10,0,20,0,30,5,0,0,15,5,0,15},//re#
{15,0,20,0,10,15,0,0,20,5,0,15},//mi
{5,0,15,0,45,5,0,0,20,5,0,5},//fa
{5,0,15,0,20,5,0,0,45,5,0,5},//fa#
{5,0,10,0,20,17,0,0,20,18,0,10},//sol
{5,0,5,0,20,15,0,0,25,5,0,25},//sol#
{10,0,5,0,15,15,0,0,25,5,0,25},//la
{15,0,5,0,10,5,0,0,15,15,0,35},//sib
{25,0,15,0,10,5,0,0,15,15,0,15}}//si
,//F
{{15,0,15,0,5,15,0,20,0,15,0,15},//do
{15,0,15,0,5,15,0,20,0,15,0,15},//do#
{20,0,15,0,15,20,0,15,0,10,0,5},//re
{20,0,15,0,15,20,0,15,0,10,0,5},//re#
{5,0,20,0,10,45,0,5,0,10,0,5},//mi
{10,0,10,0,20,25,0,20,0,10,0,5},//fa
{10,0,10,0,10,35,0,20,0,10,0,5},//fa#
{10,0,5,0,10,25,0,20,0,25,0,5},//sol
{10,0,5,0,10,25,0,20,0,25,0,5},//sol#
{20,0,5,0,5,15,0,20,0,20,0,15},//la
{20,0,5,0,5,15,0,20,0,20,0,15},//sib
{30,0,5,0,5,10,0,15,0,30,0,5}}//si
,//Fm
{{15,0,15,0,5,15,0,20,15,0,0,15},//do
{15,0,15,0,5,15,0,20,0,0,15,15},//do#
{20,0,15,0,15,20,0,15,10,0,0,5},//re
{20,0,15,0,15,20,0,15,10,0,0,5},//re#
{5,0,20,0,10,45,0,5,0,0,10,5},//mi
{10,0,10,0,20,25,0,20,10,0,0,5},//fa
{10,0,10,0,10,35,0,20,10,10,0,5},//fa#
{10,0,5,0,10,25,0,20,25,0,0,5},//sol
{10,0,5,0,10,25,0,20,25,0,0,5},//sol#
{20,0,5,0,5,15,0,20,20,0,0,15},//la
{20,0,5,0,5,15,0,20,20,0,0,15},//sib
{30,0,5,0,5,10,0,15,30,0,0,5}}//si
,//G to aqui agora
{{15,0,20,0,10,5,0,10,0,10,0,30},//do
{15,0,30,0,10,5,0,10,0,10,0,20},//do#
{15,0,15,0,20,5,0,15,0,10,0,20},//re
{10,0,30,0,10,5,0,15,0,10,0,20},//re#
{5,0,25,0,15,20,0,20,0,5,0,10},//mi
{10,0,20,0,25,5,0,25,0,5,0,10},//fa
{5,0,15,0,20,15,0,30,0,5,0,10},//fa#
{5,0,15,0,15,15,0,20,0,15,0,15},//sol
{5,0,10,10,15,0,25,0,20,0,15},//sol#
{5,0,15,0,10,15,0,25,0,5,0,25},//la
{10,0,5,0,10,5,0,20,0,15,0,35},//sib
{25,0,20,0,10,5,0,15,0,15,0,10}}//si
,//Gm
{{15,0,20,0,10,5,0,10,0,10,30,0},//do
{15,0,30,0,10,5,0,10,0,10,20,0},//do#
{15,0,15,0,20,5,0,15,0,10,20,0},//re
{10,0,30,0,10,5,0,15,0,10,20,0},//re#
{5,0,25,0,15,20,0,20,0,5,10,0},//mi
{10,0,20,0,25,5,0,25,0,5,10,0},//fa
{5,0,15,0,20,15,0,30,0,5,10,0},//fa#
{5,0,15,0,15,15,0,20,0,15,15,0},//sol
{5,0,10,10,15,0,25,0,20,15,0},//sol#
{5,0,15,0,10,15,0,25,0,5,25,0},//la
{10,0,5,0,10,5,0,20,0,15,35,0},//sib
{25,0,20,0,10,5,0,15,0,15,10,0}}//si
,//Am
{{15,0,25,0,15,10,0,5,0,20,0,10},//do
{25,0,15,0,15,10,0,5,0,20,0,10},//do#
{25,0,10,0,25,5,0,5,0,15,0,15},//re
{20,0,20,0,25,5,0,5,0,10,0,15},//re#
{15,0,20,0,10,15,0,5,0,20,0,5},//mi
{10,0,15,0,45,5,0,10,0,15,0,5},//fa
{10,0,5,0,10,22,5,20,0,23,0,5},//fa#
{15,0,5,0,15,15,0,15,0,25,0,10},//sol
{10,0,5,0,10,5,0,20,0,40,0,10},//sol#
{25,0,5,0,10,10,0,20,0,15,0,15},//la
{20,0,5,0,10,5,0,20,0,30,0,10},//sib
{35,0,15,0,10,5,0,5,0,20,0,10}}//si
,//A7
{{0,15,25,0,15,10,0,5,0,20,0,10},//do
{0,20,15,0,15,10,0,10,0,20,0,10},//do#
{0,25,10,0,25,5,0,5,0,15,0,15},//re
{0,20,20,0,25,5,0,5,0,10,0,15},//re#
{0,15,20,0,10,5,0,15,0,20,0,5},//mi
{0,10,15,0,30,5,0,25,0,15,0,5},//fa
{0,10,5,0,10,12,5,30,0,23,0,5},//fa#
{0,15,5,0,15,15,0,15,0,25,0,10},//sol
{0,10,5,0,10,5,0,30,0,30,0,10},//sol#
{0,25,5,0,10,10,0,25,0,10,0,15},//la
{0,20,5,0,10,5,0,25,0,25,0,10},//sib
{0,30,15,0,10,5,0,15,0,20,0,5}}//si
,//Bb
{{10,0,30,0,10,15,0,10,0,10,15,0},//do
{15,0,35,0,15,15,0,5,0,5,10,0},//do#
{15,0,15,0,15,20,0,5,0,10,15,0},//re
{15,0,20,0,20,10,0,10,0,5,15,0},//re#
{5,0,35,0,5,35,0,5,0,5,10,0},//mi
{5,0,15,0,20,20,0,15,0,5,15,0},//fa
{5,0,15,0,15,25,0,15,0,5,15,0},//fa#
{5,0,15,0,5,30,0,5,0,5,10,0},//sol
{5,0,10,0,5,25,0,5,0,10,35,0},//sol#
{5,0,10,0,5,20,0,20,0,15,20,0},//la
{10,0,10,0,5,15,0,15,0,15,25,0},//sib
{20,0,15,0,5,15,0,5,0,10,30,0}}}//si
;





	



int ac=0;
int cont=0;
melodia.AddVoices(2);

//identificaçao das strings de acordes como acordes em notas.
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
harmonia.SetInstr(1);
	harmonia.SetDur(1);
	harmonia.SetAmp(0.2);

switch(ac){
case 0: 
harmonia.SetPitch(48);
melodia.AddNote(1,harmonia);
harmonia.SetStart(z*4.0+1.0);
melodia.AddNote(1,harmonia);
harmonia.SetStart(z*4.0+2.0);
melodia.AddNote(1,harmonia);
harmonia.SetStart(z*4.0+3.0);
melodia.AddNote(1,harmonia);
harmonia.SetPitch(52);
melodia.AddNote(1,harmonia);
harmonia.SetStart(z*4.0+1.0);
melodia.AddNote(1,harmonia);
harmonia.SetStart(z*4.0+2.0);
melodia.AddNote(1,harmonia);
harmonia.SetStart(z*4.0+3.0);
melodia.AddNote(1,harmonia);
harmonia.SetPitch(55);
melodia.AddNote(1,harmonia);
harmonia.SetStart(z*4.0+1.0);
melodia.AddNote(1,harmonia);
harmonia.SetStart(z*4.0+2.0);
melodia.AddNote(1,harmonia);
harmonia.SetStart(z*4.0+3.0);
melodia.AddNote(1,harmonia);
break;


case 1: 
harmonia.SetPitch(48);
melodia.AddNote(1,harmonia);
harmonia.SetStart(z*4.0+1.0);
melodia.AddNote(1,harmonia);
harmonia.SetStart(z*4.0+2.0);
melodia.AddNote(1,harmonia);
harmonia.SetStart(z*4.0+3.0);
melodia.AddNote(1,harmonia);
harmonia.SetPitch(52);
melodia.AddNote(1,harmonia);
harmonia.SetStart(z*4.0+1.0);
melodia.AddNote(1,harmonia);
harmonia.SetStart(z*4.0+2.0);
melodia.AddNote(1,harmonia);
harmonia.SetStart(z*4.0+3.0);
melodia.AddNote(1,harmonia);
harmonia.SetPitch(55);
melodia.AddNote(1,harmonia);
harmonia.SetStart(z*4.0+1.0);
melodia.AddNote(1,harmonia);
harmonia.SetStart(z*4.0+2.0);
melodia.AddNote(1,harmonia);
harmonia.SetStart(z*4.0+3.0);
melodia.AddNote(1,harmonia);
harmonia.SetPitch(58);
melodia.AddNote(1,harmonia);
harmonia.SetStart(z*4.0+1.0);
melodia.AddNote(1,harmonia);
harmonia.SetStart(z*4.0+2.0);
melodia.AddNote(1,harmonia);
harmonia.SetStart(z*4.0+3.0);
melodia.AddNote(1,harmonia);
break;

case 2: 
harmonia.SetPitch(48);
melodia.AddNote(1,harmonia);
harmonia.SetStart(z*4.0+1.0);
melodia.AddNote(1,harmonia);
harmonia.SetStart(z*4.0+2.0);
melodia.AddNote(1,harmonia);
harmonia.SetStart(z*4.0+3.0);
melodia.AddNote(1,harmonia);
harmonia.SetPitch(51);
melodia.AddNote(1,harmonia);
harmonia.SetStart(z*4.0+1.0);
melodia.AddNote(1,harmonia);
harmonia.SetStart(z*4.0+2.0);
melodia.AddNote(1,harmonia);
harmonia.SetStart(z*4.0+3.0);
melodia.AddNote(1,harmonia);
harmonia.SetPitch(55);
melodia.AddNote(1,harmonia);
harmonia.SetStart(z*4.0+1.0);
melodia.AddNote(1,harmonia);
harmonia.SetStart(z*4.0+2.0);
melodia.AddNote(1,harmonia);
harmonia.SetStart(z*4.0+3.0);
melodia.AddNote(1,harmonia);
break;

case 3: 
harmonia.SetPitch(50);
melodia.AddNote(1,harmonia);
harmonia.SetStart(z*4.0+1.0);
melodia.AddNote(1,harmonia);
harmonia.SetStart(z*4.0+2.0);
melodia.AddNote(1,harmonia);
harmonia.SetStart(z*4.0+3.0);
melodia.AddNote(1,harmonia);
harmonia.SetPitch(53);
melodia.AddNote(1,harmonia);
harmonia.SetStart(z*4.0+1.0);
melodia.AddNote(1,harmonia);
harmonia.SetStart(z*4.0+2.0);
melodia.AddNote(1,harmonia);
harmonia.SetStart(z*4.0+3.0);
melodia.AddNote(1,harmonia);
harmonia.SetPitch(57);
melodia.AddNote(1,harmonia);
harmonia.SetStart(z*4.0+1.0);
melodia.AddNote(1,harmonia);
harmonia.SetStart(z*4.0+2.0);
melodia.AddNote(1,harmonia);
harmonia.SetStart(z*4.0+3.0);
melodia.AddNote(1,harmonia);
break;

case 4: 
harmonia.SetPitch(50);
melodia.AddNote(1,harmonia);
harmonia.SetStart(z*4.0+1.0);
melodia.AddNote(1,harmonia);
harmonia.SetStart(z*4.0+2.0);
melodia.AddNote(1,harmonia);
harmonia.SetStart(z*4.0+3.0);
melodia.AddNote(1,harmonia);
harmonia.SetPitch(54);
melodia.AddNote(1,harmonia);
harmonia.SetStart(z*4.0+1.0);
melodia.AddNote(1,harmonia);
harmonia.SetStart(z*4.0+2.0);
melodia.AddNote(1,harmonia);
harmonia.SetStart(z*4.0+3.0);
melodia.AddNote(1,harmonia);
harmonia.SetPitch(57);
melodia.AddNote(1,harmonia);
harmonia.SetStart(z*4.0+1.0);
melodia.AddNote(1,harmonia);
harmonia.SetStart(z*4.0+2.0);
melodia.AddNote(1,harmonia);
harmonia.SetStart(z*4.0+3.0);
melodia.AddNote(1,harmonia);
harmonia.SetPitch(60);
melodia.AddNote(1,harmonia);
harmonia.SetStart(z*4.0+1.0);
melodia.AddNote(1,harmonia);
harmonia.SetStart(z*4.0+2.0);
melodia.AddNote(1,harmonia);
harmonia.SetStart(z*4.0+3.0);
melodia.AddNote(1,harmonia);
break;

case 5: 
harmonia.SetPitch(52);
melodia.AddNote(1,harmonia);
harmonia.SetStart(z*4.0+1.0);
melodia.AddNote(1,harmonia);
harmonia.SetStart(z*4.0+2.0);
melodia.AddNote(1,harmonia);
harmonia.SetStart(z*4.0+3.0);
melodia.AddNote(1,harmonia);
harmonia.SetPitch(55);
melodia.AddNote(1,harmonia);
harmonia.SetStart(z*4.0+1.0);
melodia.AddNote(1,harmonia);
harmonia.SetStart(z*4.0+2.0);
melodia.AddNote(1,harmonia);
harmonia.SetStart(z*4.0+3.0);
melodia.AddNote(1,harmonia);
harmonia.SetPitch(59);
melodia.AddNote(1,harmonia);
harmonia.SetStart(z*4.0+1.0);
melodia.AddNote(1,harmonia);
harmonia.SetStart(z*4.0+2.0);
melodia.AddNote(1,harmonia);
harmonia.SetStart(z*4.0+3.0);
melodia.AddNote(1,harmonia);
break;

case 6: 
harmonia.SetPitch(52);
melodia.AddNote(1,harmonia);
harmonia.SetStart(z*4.0+1.0);
melodia.AddNote(1,harmonia);
harmonia.SetStart(z*4.0+2.0);
melodia.AddNote(1,harmonia);
harmonia.SetStart(z*4.0+3.0);
melodia.AddNote(1,harmonia);
harmonia.SetPitch(56);
melodia.AddNote(1,harmonia);
harmonia.SetStart(z*4.0+1.0);
melodia.AddNote(1,harmonia);
harmonia.SetStart(z*4.0+2.0);
melodia.AddNote(1,harmonia);
harmonia.SetStart(z*4.0+3.0);
melodia.AddNote(1,harmonia);
harmonia.SetPitch(59);
melodia.AddNote(1,harmonia);
harmonia.SetStart(z*4.0+1.0);
melodia.AddNote(1,harmonia);
harmonia.SetStart(z*4.0+2.0);
melodia.AddNote(1,harmonia);
harmonia.SetStart(z*4.0+3.0);
melodia.AddNote(1,harmonia);
harmonia.SetPitch(62);
melodia.AddNote(1,harmonia);
harmonia.SetStart(z*4.0+1.0);
melodia.AddNote(1,harmonia);
harmonia.SetStart(z*4.0+2.0);
melodia.AddNote(1,harmonia);
harmonia.SetStart(z*4.0+3.0);
melodia.AddNote(1,harmonia);
break;

case 7: 
harmonia.SetPitch(53);
melodia.AddNote(1,harmonia);
harmonia.SetStart(z*4.0+1.0);
melodia.AddNote(1,harmonia);
harmonia.SetStart(z*4.0+2.0);
melodia.AddNote(1,harmonia);
harmonia.SetStart(z*4.0+3.0);
melodia.AddNote(1,harmonia);
harmonia.SetPitch(57);
melodia.AddNote(1,harmonia);
harmonia.SetStart(z*4.0+1.0);
melodia.AddNote(1,harmonia);
harmonia.SetStart(z*4.0+2.0);
melodia.AddNote(1,harmonia);
harmonia.SetStart(z*4.0+3.0);
melodia.AddNote(1,harmonia);
harmonia.SetPitch(60);
melodia.AddNote(1,harmonia);
harmonia.SetStart(z*4.0+1.0);
melodia.AddNote(1,harmonia);
harmonia.SetStart(z*4.0+2.0);
melodia.AddNote(1,harmonia);
harmonia.SetStart(z*4.0+3.0);
melodia.AddNote(1,harmonia);
break;

case 8: 
harmonia.SetPitch(53);
melodia.AddNote(1,harmonia);
harmonia.SetStart(z*4.0+1.0);
melodia.AddNote(1,harmonia);
harmonia.SetStart(z*4.0+2.0);
melodia.AddNote(1,harmonia);
harmonia.SetStart(z*4.0+3.0);
melodia.AddNote(1,harmonia);
harmonia.SetPitch(56);
melodia.AddNote(1,harmonia);
harmonia.SetStart(z*4.0+1.0);
melodia.AddNote(1,harmonia);
harmonia.SetStart(z*4.0+2.0);
melodia.AddNote(1,harmonia);
harmonia.SetStart(z*4.0+3.0);
melodia.AddNote(1,harmonia);
harmonia.SetPitch(60);
melodia.AddNote(1,harmonia);
harmonia.SetStart(z*4.0+1.0);
melodia.AddNote(1,harmonia);
harmonia.SetStart(z*4.0+2.0);
melodia.AddNote(1,harmonia);
harmonia.SetStart(z*4.0+3.0);
melodia.AddNote(1,harmonia);
break;

case 9: 
harmonia.SetPitch(43);
melodia.AddNote(1,harmonia);
harmonia.SetStart(z*4.0+1.0);
melodia.AddNote(1,harmonia);
harmonia.SetStart(z*4.0+2.0);
melodia.AddNote(1,harmonia);
harmonia.SetStart(z*4.0+3.0);
melodia.AddNote(1,harmonia);
harmonia.SetPitch(47);
melodia.AddNote(1,harmonia);
harmonia.SetStart(z*4.0+1.0);
melodia.AddNote(1,harmonia);
harmonia.SetStart(z*4.0+2.0);
melodia.AddNote(1,harmonia);
harmonia.SetStart(z*4.0+3.0);
melodia.AddNote(1,harmonia);
harmonia.SetPitch(50);
melodia.AddNote(1,harmonia);
harmonia.SetStart(z*4.0+1.0);
melodia.AddNote(1,harmonia);
harmonia.SetStart(z*4.0+2.0);
melodia.AddNote(1,harmonia);
harmonia.SetStart(z*4.0+3.0);
melodia.AddNote(1,harmonia);
break;

case 10: 
harmonia.SetPitch(43);
melodia.AddNote(1,harmonia);
harmonia.SetStart(z*4.0+1.0);
melodia.AddNote(1,harmonia);
harmonia.SetStart(z*4.0+2.0);
melodia.AddNote(1,harmonia);
harmonia.SetStart(z*4.0+3.0);
melodia.AddNote(1,harmonia);
harmonia.SetPitch(46);
melodia.AddNote(1,harmonia);
harmonia.SetStart(z*4.0+1.0);
melodia.AddNote(1,harmonia);
harmonia.SetStart(z*4.0+2.0);
melodia.AddNote(1,harmonia);
harmonia.SetStart(z*4.0+3.0);
melodia.AddNote(1,harmonia);
harmonia.SetPitch(50);
melodia.AddNote(1,harmonia);
harmonia.SetStart(z*4.0+1.0);
melodia.AddNote(1,harmonia);
harmonia.SetStart(z*4.0+2.0);
melodia.AddNote(1,harmonia);
harmonia.SetStart(z*4.0+3.0);
melodia.AddNote(1,harmonia);
break;

case 11: 
harmonia.SetPitch(45);
melodia.AddNote(1,harmonia);
harmonia.SetStart(z*4.0+1.0);
melodia.AddNote(1,harmonia);
harmonia.SetStart(z*4.0+2.0);
melodia.AddNote(1,harmonia);
harmonia.SetStart(z*4.0+3.0);
melodia.AddNote(1,harmonia);
harmonia.SetPitch(48);
melodia.AddNote(1,harmonia);
harmonia.SetStart(z*4.0+1.0);
melodia.AddNote(1,harmonia);
harmonia.SetStart(z*4.0+2.0);
melodia.AddNote(1,harmonia);
harmonia.SetStart(z*4.0+3.0);
melodia.AddNote(1,harmonia);
harmonia.SetPitch(52);
melodia.AddNote(1,harmonia);
harmonia.SetStart(z*4.0+1.0);
melodia.AddNote(1,harmonia);
harmonia.SetStart(z*4.0+2.0);
melodia.AddNote(1,harmonia);
harmonia.SetStart(z*4.0+3.0);
melodia.AddNote(1,harmonia);
break;

case 12: 
harmonia.SetPitch(45);
melodia.AddNote(1,harmonia);
harmonia.SetStart(z*4.0+1.0);
melodia.AddNote(1,harmonia);
harmonia.SetStart(z*4.0+2.0);
melodia.AddNote(1,harmonia);
harmonia.SetStart(z*4.0+3.0);
melodia.AddNote(1,harmonia);
harmonia.SetPitch(49);
melodia.AddNote(1,harmonia);
harmonia.SetStart(z*4.0+1.0);
melodia.AddNote(1,harmonia);
harmonia.SetStart(z*4.0+2.0);
melodia.AddNote(1,harmonia);
harmonia.SetStart(z*4.0+3.0);
melodia.AddNote(1,harmonia);
harmonia.SetPitch(52);
melodia.AddNote(1,harmonia);
harmonia.SetStart(z*4.0+1.0);
melodia.AddNote(1,harmonia);
harmonia.SetStart(z*4.0+2.0);
melodia.AddNote(1,harmonia);
harmonia.SetStart(z*4.0+3.0);
melodia.AddNote(1,harmonia);
harmonia.SetPitch(55);
melodia.AddNote(1,harmonia);
harmonia.SetStart(z*4.0+1.0);
melodia.AddNote(1,harmonia);
harmonia.SetStart(z*4.0+2.0);
melodia.AddNote(1,harmonia);
harmonia.SetStart(z*4.0+3.0);
melodia.AddNote(1,harmonia);
break;

case 13: 
harmonia.SetPitch(46);
melodia.AddNote(1,harmonia);
harmonia.SetStart(z*4.0+1.0);
melodia.AddNote(1,harmonia);
harmonia.SetStart(z*4.0+2.0);
melodia.AddNote(1,harmonia);
harmonia.SetStart(z*4.0+3.0);
melodia.AddNote(1,harmonia);
harmonia.SetPitch(50);
melodia.AddNote(1,harmonia);
harmonia.SetStart(z*4.0+1.0);
melodia.AddNote(1,harmonia);
harmonia.SetStart(z*4.0+2.0);
melodia.AddNote(1,harmonia);
harmonia.SetStart(z*4.0+3.0);
melodia.AddNote(1,harmonia);
harmonia.SetPitch(53);
melodia.AddNote(1,harmonia);
harmonia.SetStart(z*4.0+1.0);
melodia.AddNote(1,harmonia);
harmonia.SetStart(z*4.0+2.0);
melodia.AddNote(1,harmonia);
harmonia.SetStart(z*4.0+3.0);
melodia.AddNote(1,harmonia);
break;

default: break;
	}
}
MuMaterial PrimAc=melodia.GetVoice(1).Segments(h).GetVoice(0);
PrimAc.Fit(4);
melodia.Append(1,PrimAc,0); 


//inicio mesmo.
nota.SetInstr(3);
	nota.SetDur(0.5);
	nota.SetAmp(0.7);

	int pitch=Between(0,2)*2;

	int PertenceAoAcorde=0;
	int rapido=0;
	int base=60;
int temporizador=0;
int escolha=1;
	nota.SetPitch(base+pitch);
puts("Começando!");

	while(melodia.GetVoice(0).Dur()<melodia.Dur()-1)
	{//nota1
	if(nota.Start()>(Between(1,2)+0.5)*h && nota.Start()<h*(1.5+Between(1,2)) )rapido=0;
	else rapido=0;
	nota.SetInstr(Between(3,3));
	nota.SetStart(nota.Start()+nota.Dur());
	if ((base+pitch-nota.Pitch())> 6) base-=12;
	if (nota.Pitch()-(base+pitch)>= 6) base+=12;
	if (base<50+12*rapido) base+=12;
	if (base>80+12*rapido) base-=12;
	PertenceAoAcorde=0;
	for (int i=12;i<120;i+=12)
	if(melodia.GetNotesSoundingAt(1,melodia.GetVoice(0).Dur()).Contains(0,base+pitch))
	PertenceAoAcorde=1;
	//cout<<	PertenceAoAcorde;
	temporizador++;
	if(temporizador>Between(3,8))
	escolha=Between(1,3);
	switch(escolha)
	{
	case 1:	nota.SetDur(Between(2,2)*dur1(PertenceAoAcorde,rapido, melodia.GetVoice(0).Dur()));break;
	case 2: nota.SetDur(Between(2,2)*dur2(PertenceAoAcorde,rapido, melodia.GetVoice(0).Dur()));break;
	case 3: nota.SetDur(dur3(PertenceAoAcorde,rapido, melodia.GetVoice(0).Dur()));break;	
	}
	nota.SetPitch(base+pitch);
if(melodia.GetVoice(0).Dur()>h*4 && PertenceAoAcorde) nota.SetDur(nota.Dur()*2);
	melodia.AddNote(nota);


	int urna[100];
	int m=0;
	for(int k=0;k<12;k++)
		for(int l=0;l<chances[ac][pitch][k];l++)
			{urna[m]=k;
			m++;
			if (m==100)break;}
	//misturando a urna
	Mix(urna,100);

// escolhendo um valor aleatorio na urna
	pitch=urna[Between(0,100)];

cout<<"\r"<<melodia.GetVoice(0).Dur()*100.0f/(melodia.Dur())<<"%";
	}



melodia.Show();

melodia.Fit(melodia.Dur()*60.0/bpm);
	
     melodia.SetDefaultFunctionTables();
	melodia.Score("melodia.sco");

	melodia.Orchestra("melodia.orc");
	puts("Arquivos criados!");
	system("csound melodia.orc melodia.sco -W -o teste1.wav");

 return 0;
}

float dur1(int PertenceAoAcorde, int rapido, float tempo)
{
return (1.0+PertenceAoAcorde)/((rapido+1)*(2*Between(1,2)));
}
float dur2(int PertenceAoAcorde, int rapido, float tempo)
{
return (1.0+PertenceAoAcorde)/(2*Between(1,2))-0.25f*rapido;
}
float dur3(int PertenceAoAcorde, int rapido, float tempo)
{
float tempo2=(tempo-int(tempo));
return (16.0f*(1+PertenceAoAcorde)-((int)(16*tempo2)))/16.0f;

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

