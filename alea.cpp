#include <iostream>
#include <cstdlib>
#include <time.h>
#include "MuMaterial.h"


using namespace std;

int main (void)
{	
	MuMaterial notas;
	MuNote nota;

	nota.SetInstr(1);
	nota.SetDur(0.25);
	nota.SetAmp(0.7);


	for(int i=0;i<12;i++)
	{
	  nota.SetStart(i * 0.25);
	  nota.SetPitch(Between(60,72));
	  notas.AddNote(nota);
	}

     notas.SetFunctionTables("f1 0 4096 10 1");
	notas.Score("notas.sco");

 return 0;
}

 

