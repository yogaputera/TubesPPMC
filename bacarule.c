//***********************************************************//
// [ Source Code ]
//
// Institution : Institut Teknologi Bandung
// Name : Rafita Erli A.
// File Name : bacarule.c
// Dependency : stdio.h, string.h, lib.h, stdlib.h, math.h
//
// Description:
// membaca hari-hari yang tidak diperkenankan punya jadwal praktikum
//
//
// Status:
// 1. Rafita Erli A. - 18317005 : Create the file
// 2. Yoga Putera - 13217080 : Debug
// 3. Michaella Yosephine - 18317004 : Debug
// 4. Lulu Firdaus - 18317001 : Debug
//***********************************************************//

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#define max 100
#include "lib.h"

//ada struct rule isinya int mg dan int hari

void bacarule (rule r[max],char namafile[40],int *jrule)
{

	char S[max];
	char *token;
	FILE *fp;
	fp =  fopen(namafile,"r");
	int i=0;
	while (!feof(fp))
	{
		fgets(S,max,fp);
		token= strtok(S," ");
		r[i].mg = (atoi(token))-3;
		token=strtok(NULL," ");
		//ngilangin enter \n
		char *newline = strchr(token, '\n');
		if(newline) *newline = 0;
		if (!strcmp(token,"Senin"))
		{
			r[i].hari=0;
		}
		else if (!strcmp(token,"Selasa"))
		{
			r[i].hari=1;
		}
		else if (!strcmp(token,"Rabu"))
		{
			r[i].hari=2;
		}
		else if (!strcmp(token,"Kamis"))
		{
			r[i].hari=3;
		}
		else if (!strcmp(token,"Jumat"))
		{
			r[i].hari=4;
		}
		i++;
		*jrule=i;
	}
	//printf("%d jrule bacarule\n",*jrule);
	close(fp);
}

