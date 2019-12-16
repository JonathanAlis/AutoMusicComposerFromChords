	    /*
	    Jonathan Alis - 06/87391
	    trabalho de composição algoritma.
	    
	    Funcionamento:
	    pede uma sequencia de acordes, digitados mesmo, separados por espaço. Os acordes aceitos são C, Cm...
	    pede quantas vezes repetir, 0 vezes da erro.
	    E pede a quantos batimentos por minuto.
	    A partir daí cria uma harmonia 4/4 na voz 1 com as informações obtidas.
	    A partir dessa harmonia e de uma nota inicial, vai criando na voz 0 a melodia nota por nota segundo uma aleatoriamente segundo uma matriz de pesos, que depende da nota anterior e do acorde atual na harmonia.
	    A duração dessas notas segua 4 funções, todas eleas dependem se a nota pertencem ao acorde e de uma outra variavel, a que foi chamada de rapido, que indica se a musica esta no estado rapido. essas funçoes tem pessos diferentes de ocorrer, e sao escolhidas aleatoriamente.
	    Esse estado rapido acontece por volta de 1/2 ate 3/4 da duracao total, nao exatamente esses valores, mas valores aleatorios perto deles.
	    nesse estado as notas tendem a ser mais rapidas e o limite de alcance em altura delas aumentam.
	    por ultimo é acrescentada a nota final, ela é a nota com menor distancia de altura pra alguma nota do acorde, ela dura o compasso todo.
	    aí então ela é exportada como melodia.sco e aberta no csound com junto com a orquestra orq.orc, ja criada.
	    
	    compila assim:
	    g++ main10.cpp MuMaterial.cpp MuUtil.cpp MuNote.cpp MuVoice.cpp MuParamBlock.cpp MuError.cpp -o compor
	    
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
	    float dur4(int PertenceAoAcorde, int rapido, float tempo);
	    float dur5(int PertenceAoAcorde, int rapido, float tempo);
	    int main (void)
	    {	MuInit();
		MuMaterial melodia;
		MuNote nota;
		MuNote harmonia;
		//parte pra receber os acordes do usuario
	    
		char acordes[100];
		cout<<"Digite a sequencia de acordes: ";
		cin.getline(acordes,100);
		strcat(acordes," ");
		cout<<"repetir quantas vezes? ";
		int n;
		cin >> n;
		cout<<"quantos tempos por compasso? ";
		int tempo;
		cin >> tempo;
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
		  {25,0,20,0,25,7,0,13,0,5,0,5},//do#
		  {20,0,5,0,30,5,0,15,0,10,0,5},//re
		  {15,0,10,0,30,5,0,15,0,10,0,5},//re#
		  {15,0,20,0,10,15,0,20,0,5,0,5},//mi
		  {20,0,15,0,35,5,0,20,0,5,0,5},//fa
		  {10,0,5,0,10,12,0,30,0,18,0,5},//fa#
		  {10,0,25,0,15,12,0,15,0,18,0,5},//sol
		  {5,0,5,0,20,15,0,25,0,20,0,10},//sol#
		  {15,0,5,0,20,10,0,25,0,5,0,20},//la
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
		     {20,0,15,0,10,5,0,0,20,15,0,15}}//si
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
	    
		//identificaçao das strings de acordes como acordes em notas e preenchimento da harmonia.
		for(int z=0;z<=h;z++)
		{
			    cout<<100*z/h<<"%"<<endl;
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
		    harmonia.SetStart(z*tempo);
		    harmonia.SetInstr(1);
		    harmonia.SetDur(1);
		    harmonia.SetAmp(0.5);
	    
		    switch(ac){
		    case 0:
			harmonia.SetAmp(0.7);
			harmonia.SetPitch(48);
			melodia.AddNote(1,harmonia);
			harmonia.SetAmp(0.3);
			for(int i=1;i<=tempo-1;i++)
			{harmonia.SetStart(z*tempo+i);
			    melodia.AddNote(1,harmonia);}
			harmonia.SetPitch(52);
			for(int i=1;i<=tempo-1;i++)
			{harmonia.SetStart(z*tempo+i);
			    melodia.AddNote(1,harmonia);}
			harmonia.SetPitch(55);
			for(int i=1;i<=tempo-1;i++)
			{harmonia.SetStart(z*tempo+i);
			    melodia.AddNote(1,harmonia);}
			break;
	    
	    
	    case 1: 
		harmonia.SetAmp(0.7);
		harmonia.SetPitch(48);
		melodia.AddNote(1,harmonia);
		harmonia.SetAmp(0.3);
		for(int i=1;i<=tempo-1;i++)
		{harmonia.SetStart(z*tempo+i);
		    melodia.AddNote(1,harmonia);}
		harmonia.SetPitch(52);
		for(int i=1;i<=tempo-1;i++)
		{harmonia.SetStart(z*tempo+i);
		    melodia.AddNote(1,harmonia);}
		harmonia.SetPitch(55);
		for(int i=1;i<=tempo-1;i++)
		{harmonia.SetStart(z*tempo+i);
		    melodia.AddNote(1,harmonia);}
		harmonia.SetPitch(58);
		for(int i=1;i<=tempo-1;i++)
		{harmonia.SetStart(z*tempo+i);
		    melodia.AddNote(1,harmonia);}
		break;
	    
	    case 2: 
		harmonia.SetAmp(0.7);
		harmonia.SetPitch(48);
		melodia.AddNote(1,harmonia);
		harmonia.SetAmp(0.3);
		for(int i=1;i<=tempo-1;i++)
		{harmonia.SetStart(z*tempo+i);
		    melodia.AddNote(1,harmonia);}
		harmonia.SetPitch(51);
		for(int i=1;i<=tempo-1;i++)
		{harmonia.SetStart(z*tempo+i);
		    melodia.AddNote(1,harmonia);}
		harmonia.SetPitch(55);
		for(int i=1;i<=tempo-1;i++)
		{harmonia.SetStart(z*tempo+i);
		    melodia.AddNote(1,harmonia);}
		break;
	    
	    case 3: 
		harmonia.SetAmp(0.7);
		harmonia.SetPitch(50);
		melodia.AddNote(1,harmonia);
		harmonia.SetAmp(0.3);
		for(int i=1;i<=tempo-1;i++)
		{harmonia.SetStart(z*tempo+i);
		    melodia.AddNote(1,harmonia);}
		harmonia.SetPitch(53);
		for(int i=1;i<=tempo-1;i++)
		{harmonia.SetStart(z*tempo+i);
		    melodia.AddNote(1,harmonia);}
		harmonia.SetPitch(57);
		for(int i=1;i<=tempo-1;i++)
		{harmonia.SetStart(z*tempo+i);
		    melodia.AddNote(1,harmonia);}
		break;
	    
	    case 4: 
		harmonia.SetAmp(0.7);
		harmonia.SetPitch(50);
		melodia.AddNote(1,harmonia);
		harmonia.SetAmp(0.3);
		for(int i=1;i<=tempo-1;i++)
		{harmonia.SetStart(z*tempo+i);
		    melodia.AddNote(1,harmonia);}
		harmonia.SetPitch(54);
		for(int i=1;i<=tempo-1;i++)
		{harmonia.SetStart(z*tempo+i);
		    melodia.AddNote(1,harmonia);}
		harmonia.SetPitch(57);
		for(int i=1;i<=tempo-1;i++)
		{harmonia.SetStart(z*tempo+i);
		    melodia.AddNote(1,harmonia);}
		harmonia.SetPitch(60);
		for(int i=1;i<=tempo-1;i++)
		{harmonia.SetStart(z*tempo+i);
		    melodia.AddNote(1,harmonia);}
		break;
	    
	    case 5: 
		harmonia.SetAmp(0.7);
		harmonia.SetPitch(52);
		melodia.AddNote(1,harmonia);
		harmonia.SetAmp(0.3);
		for(int i=1;i<=tempo-1;i++)
		{harmonia.SetStart(z*tempo+i);
		    melodia.AddNote(1,harmonia);}
		harmonia.SetPitch(55);
		for(int i=1;i<=tempo-1;i++)
		{harmonia.SetStart(z*tempo+i);
		    melodia.AddNote(1,harmonia);}
		harmonia.SetPitch(59);
		for(int i=1;i<=tempo-1;i++)
		{harmonia.SetStart(z*tempo+i);
		    melodia.AddNote(1,harmonia);}
		break;
	    
	    case 6: 
		harmonia.SetAmp(0.7);
		harmonia.SetPitch(52);
		melodia.AddNote(1,harmonia);
		harmonia.SetAmp(0.3);
		for(int i=1;i<=tempo-1;i++)
		{harmonia.SetStart(z*tempo+i);
		    melodia.AddNote(1,harmonia);}
		harmonia.SetPitch(56);
		for(int i=1;i<=tempo-1;i++)
		{harmonia.SetStart(z*tempo+i);
		    melodia.AddNote(1,harmonia);}
		harmonia.SetPitch(59);
		for(int i=1;i<=tempo-1;i++)
		{harmonia.SetStart(z*tempo+i);
		    melodia.AddNote(1,harmonia);}
		harmonia.SetPitch(62);
		for(int i=1;i<=tempo-1;i++)
		{harmonia.SetStart(z*tempo+i);
		    melodia.AddNote(1,harmonia);}
		break;
	    
	    case 7: 
		harmonia.SetAmp(0.7);
		harmonia.SetPitch(53);
		melodia.AddNote(1,harmonia);
		harmonia.SetAmp(0.3);
		for(int i=1;i<=tempo-1;i++)
		{harmonia.SetStart(z*tempo+i);
		    melodia.AddNote(1,harmonia);}
		harmonia.SetPitch(57);
		for(int i=1;i<=tempo-1;i++)
		{harmonia.SetStart(z*tempo+i);
		    melodia.AddNote(1,harmonia);}
		harmonia.SetPitch(60);
		for(int i=1;i<=tempo-1;i++)
		{harmonia.SetStart(z*tempo+i);
		    melodia.AddNote(1,harmonia);}
		break;
	    
	    case 8: 
		harmonia.SetAmp(0.7);
		harmonia.SetPitch(53);
		melodia.AddNote(1,harmonia);
		harmonia.SetAmp(0.3);
		for(int i=1;i<=tempo-1;i++)
		{harmonia.SetStart(z*tempo+i);
		    melodia.AddNote(1,harmonia);}
		harmonia.SetPitch(56);
		for(int i=1;i<=tempo-1;i++)
		{harmonia.SetStart(z*tempo+i);
		    melodia.AddNote(1,harmonia);}
		harmonia.SetPitch(60);
		for(int i=1;i<=tempo-1;i++)
		{harmonia.SetStart(z*tempo+i);
		    melodia.AddNote(1,harmonia);}
		break;
	    
	    case 9: 
		harmonia.SetAmp(0.7);
		harmonia.SetPitch(43);
		melodia.AddNote(1,harmonia);
		harmonia.SetAmp(0.3);
		for(int i=1;i<=tempo-1;i++)
		{harmonia.SetStart(z*tempo+i);
		    melodia.AddNote(1,harmonia);}
		harmonia.SetPitch(47);
		for(int i=1;i<=tempo-1;i++)
		{harmonia.SetStart(z*tempo+i);
		    melodia.AddNote(1,harmonia);}
		harmonia.SetPitch(50);
		for(int i=1;i<=tempo-1;i++)
		{harmonia.SetStart(z*tempo+i);
		    melodia.AddNote(1,harmonia);}
		break;
	    
	    case 10: 
		harmonia.SetAmp(0.7);
		harmonia.SetPitch(43);
		melodia.AddNote(1,harmonia);
		harmonia.SetAmp(0.3);
		for(int i=1;i<=tempo-1;i++)
		{harmonia.SetStart(z*tempo+i);
		    melodia.AddNote(1,harmonia);}
		harmonia.SetPitch(46);
		for(int i=1;i<=tempo-1;i++)
		{harmonia.SetStart(z*tempo+i);
		    melodia.AddNote(1,harmonia);}
		harmonia.SetPitch(50);
		for(int i=1;i<=tempo-1;i++)
		{harmonia.SetStart(z*tempo+i);
		    melodia.AddNote(1,harmonia);}
		break;
	    
	    case 11: 
		harmonia.SetAmp(0.7);
		harmonia.SetPitch(45);
		melodia.AddNote(1,harmonia);
		harmonia.SetAmp(0.3);
		for(int i=1;i<=tempo-1;i++)
		{harmonia.SetStart(z*tempo+i);
		    melodia.AddNote(1,harmonia);}
		harmonia.SetPitch(48);
		for(int i=1;i<=tempo-1;i++)
		{harmonia.SetStart(z*tempo+i);
		    melodia.AddNote(1,harmonia);}
		harmonia.SetPitch(52);
		for(int i=1;i<=tempo-1;i++)
		{harmonia.SetStart(z*tempo+i);
		    melodia.AddNote(1,harmonia);}
		break;
	    
	    case 12: 
		harmonia.SetAmp(0.7);
		harmonia.SetPitch(45);
		melodia.AddNote(1,harmonia);
		harmonia.SetAmp(0.3);
		for(int i=1;i<=tempo-1;i++)
		{harmonia.SetStart(z*tempo+i);
		    melodia.AddNote(1,harmonia);}
		harmonia.SetPitch(49);
		for(int i=1;i<=tempo-1;i++)
		{harmonia.SetStart(z*tempo+i);
		    melodia.AddNote(1,harmonia);}
		harmonia.SetPitch(52);
		for(int i=1;i<=tempo-1;i++)
		{harmonia.SetStart(z*tempo+i);
		    melodia.AddNote(1,harmonia);}
		harmonia.SetPitch(55);
		for(int i=1;i<=tempo-1;i++)
		{harmonia.SetStart(z*tempo+i);
		    melodia.AddNote(1,harmonia);}
		break;
	    
	    case 13: 
		harmonia.SetAmp(0.7);
		harmonia.SetPitch(46);
		melodia.AddNote(1,harmonia);
		harmonia.SetAmp(0.3);
		for(int i=1;i<=tempo-1;i++)
		{harmonia.SetStart(z*tempo+i);
		    melodia.AddNote(1,harmonia);}
		harmonia.SetPitch(50);
		for(int i=1;i<=tempo-1;i++)
		{harmonia.SetStart(z*tempo+i);
		    melodia.AddNote(1,harmonia);}
		harmonia.SetPitch(53);
		for(int i=1;i<=tempo-1;i++)
		{harmonia.SetStart(z*tempo+i);
		    melodia.AddNote(1,harmonia);}
	    
		break;
	    
	    default: break;
	    }
	    cout<<"check 1"<<endl;
		    //inicio da criação da melodia
		    nota.SetInstr(4);
		    nota.SetDur(0.5);
		    nota.SetAmp(0.7);
	    
		    int pitch=Between(0,1)*2;
	    
		    int PertenceAoAcorde=0;
		    int rapido=0;
		    int base=60;
		    int temporizador=0;
		    int escolha=1;
		    nota.SetPitch(base+pitch);
	    cout<<"check 2"<<endl;
		    if(z!=h)
			while(melodia.GetVoice(0).Dur()<tempo*(z+1))
			{//escolha de quando será o estado rapido.
			switch((int)(11*melodia.GetVoice(0).Dur()/(tempo*h*1.0)))
			{
			case 0:
			case 1:
			case 2:rapido=0; break;
			case 3:
			case 4:rapido=1; break;
			case 5:rapido=0; break;
			case 6:
			case 7:rapido=1; break;
			case 8:rapido=2; break;
			case 9:rapido=1; break;
			case 10:rapido=0; break;
			}
			cout<<"check 3"<<endl;
			//a proxima nota começará quando a última terminar, ou seja, na duração total atual.
			nota.SetStart(melodia.GetVoice(0).Dur());
			//controle para nao dar muitos saltos de altura que garante uma boa extensão.
			if ((base+pitch)-nota.Pitch()> 6) base-=12;
			if (nota.Pitch()-(base+pitch)>= 6) base+=12;
			//controla a extensão de altura
			if (base<30+12*rapido) base+=12;
			if (base>70+12*rapido) base-=12;
			PertenceAoAcorde=0;
			//verifica se pertence ao acorde
			for (int i=12;i<120;i+=12)
			    if(melodia.GetNotesSoundingAt(1,melodia.GetVoice(0).Dur()).Contains(0,i+pitch))
				PertenceAoAcorde=1;
			//conta quantas notas na mesma função de duração
			temporizador++;
			if(temporizador>Between(3,8)+rapido*3)
			{escolha=Between(1,8);
			    temporizador=0;}
			//escolhe a função de duração.
			//a primeira tem peso 3, a segunda tem peso 1, a terceira peso 2 e a ultima peso 2.
			cout<<"check 4"<<endl;
			switch(escolha)
			{
			case 1:
			case 2:
			case 3: nota.SetDur(4*dur1(PertenceAoAcorde,rapido, melodia.GetVoice(0).Dur()));break;
			case 4: nota.SetDur(Between(2,4)*dur2(PertenceAoAcorde,rapido, melodia.GetVoice(0).Dur()));break;
			case 5:
			case 6: nota.SetDur(dur3(PertenceAoAcorde,rapido, melodia.GetVoice(0).Dur()));break;
			case 7:
			case 8:	nota.SetDur(2*dur4(PertenceAoAcorde,rapido, melodia.GetVoice(0).Dur()));break;
			case 9: nota.SetDur(dur5(PertenceAoAcorde,rapido, melodia.GetVoice(0).Dur()));break;
			    
			}
			cout<<"check 5"<<endl;
			//note que pitch tem um valor entre 0 e 11, o valor de base que diz qual a oitava.
			nota.SetPitch(base+pitch);
			//impede que uma nota invada outro compasso, z eh o contador de compassos.
			if(melodia.GetVoice(0).Dur()+nota.Dur()>tempo*(z+1))
			    nota.SetDur(tempo*(z+1)-melodia.GetVoice(0).Dur());
			//acrescenta a nota!!!
			melodia.AddNote(nota);
	    
			//criação da urna
			cout<<"check 6"<<endl;
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
	    
			    cout<<"check 7"<<endl;
		    }
		    else{//final
			int minimo=12;
	    
			nota.SetDur(tempo);
			nota.SetStart(tempo*h);
			MuMaterial PrimAc=melodia.GetNotesSoundingAt(1,1.1);
			//procura qual deve ser o pitch da ultima nota.
			PrimAc.Transpose(-36);
			for(int i=0;i<=6;i++)
			{
			    PrimAc.Transpose(12);
			    for(int j=0;j<PrimAc.NumberOfNotes();j++)	
				if(abs(melodia.GetNote(0,melodia.NumberOfNotes(0)-1).Pitch()-PrimAc.GetNote(j).Pitch())<minimo)
				{
				minimo=abs(melodia.GetNote(0,melodia.NumberOfNotes(0)-1).Pitch()-PrimAc.GetNote(j).Pitch());
				nota.SetPitch(PrimAc.GetNote(j).Pitch());
			    }
			    cout<<"check 7"<<endl;
			}
			melodia.AddNote(nota);
		    }
		    cout<<"check 8"<<endl;
		}
		//coloca a melodia no tamanho que condiza com o bmp fornecido
		melodia.Fit(melodia.Dur()*60.0/bpm);
	    
		//cria os arquivos de saída.
		melodia.SetDefaultFunctionTables();
		melodia.Score("melodia.sco");
		puts("Arquivos criados!");
		system("csound melodia.orc melodia.sco -W -o teste1.wav");
	    
		return 0;
	    }
	    //funções de duraçao da nota
	    float dur1(int PertenceAoAcorde, int rapido, float tempo)
	    {
		return (1.0+PertenceAoAcorde)/((rapido+1)*4);
	    }
	    float dur2(int PertenceAoAcorde, int rapido, float tempo)
	    {
		return (1.0+PertenceAoAcorde)/((1+rapido)*2*Between(1,2));
	    }
	    float dur3(int PertenceAoAcorde, int rapido, float tempo)
	    {
		float tempo2=(tempo-int(tempo));
		return (16.0f*(1+PertenceAoAcorde)-((int)(16*tempo2)))/(16.0f*(1+rapido)*(1+rapido));
	    }
	    float dur4(int PertenceAoAcorde, int rapido, float tempo)
	    {
		return (1.0+PertenceAoAcorde)/((rapido+1)*3);
	    }
	    float dur5(int PertenceAoAcorde, int rapido, float tempo)
	    {
		return (1.0+PertenceAoAcorde)/(Between(2*(rapido+1),4));
	    }
	    //funções auxiliares à urna
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
	    
	    
    
