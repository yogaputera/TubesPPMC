//***********************************************************//
// [ Source Code ]
//
// Institution : Institut Teknologi Bandung
// Name : Rafita Erli A.
// File Name : cekrule.c
// Dependency : stdio.h, string.h, lib.h, math.h, stdlib.h
//
// Description:
// mengecek apakah aturan terpenuhi oleh jadwal atau tidak
//
//
// Status:
// 1. Rafita Erli - 18317005 : Create the file
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

void cekrule(rule r[max],int jrule,praktikum lab1[max][max],praktikum lab2[max][max],praktikum lab3[max][max],praktikum lss[max][max])
{
	int i;
	int checked=0;
	char shari[10];
	//printf("%d jrule cekrule",jrule);
	//bacarule(r,namafile,jrule);
	for (i=0;i<jrule;i++)
	{
		//ganti angka jadi string nama hari
		if (r[i].hari==0)
		{
			strcpy(shari,"Senin");
			//printf("%s\n",shari);
		}
		else if (r[i].hari==1)
		{

			strcpy(shari,"Selasa");
			//printf("%s\n",shari);
		}
		else if (r[i].hari==2)
		{
			strcpy(shari,"Rabu");
			//printf("%s\n",shari);
		}
		else if (r[i].hari==3)
		{
			strcpy(shari,"Kamis");
			//printf("%s\n",shari);
		}
		else if (r[i].hari==4)
		{
			strcpy(shari,"Jumat");
			//printf("%s\n",shari);
		}
		//memastikan tidak ada jadwal pada minggu dan hari itu
		if ((lab1[r[i].mg][r[i].hari].rombongan[0]==' ')&&(lab2[r[i].mg][r[i].hari].rombongan[0]== ' ')&&(lab3[r[i].mg][r[i].hari].rombongan[0]==' ')&&(lss[r[i].mg][r[i].hari].rombongan[0]==' '))
		{
			checked++;
			//printf("%d\n",checked);
		}
		else //ada yang ada jadwalnya, tapi gatau lab yang mana.
		//pokoknya dikosongkan
		{
			printf("Pada minggu %d hari %s libur. Pilih minggu dan hari lain",r[i].mg+3,shari);
			strcpy(lab1[r[i].mg][r[i].hari].rombongan," ");
			strcpy(lab2[r[i].mg][r[i].hari].rombongan," ");
			strcpy(lab3[r[i].mg][r[i].hari].rombongan," ");
			strcpy(lss[r[i].mg][r[i].hari].rombongan," ");
			strcpy(lab1[r[i].mg][r[i].hari].kode," ");
			strcpy(lab2[r[i].mg][r[i].hari].kode," ");
			strcpy(lab3[r[i].mg][r[i].hari].kode," ");
			strcpy(lss[r[i].mg][r[i].hari].kode," ");
			strcpy(lab1[r[i].mg][r[i].hari].nama," ");
			strcpy(lab2[r[i].mg][r[i].hari].nama," ");
			strcpy(lab3[r[i].mg][r[i].hari].nama," ");
			strcpy(lss[r[i].mg][r[i].hari].nama," ");
		}
		printf("%d\n",i);
	}
//tampilan lala
	printf("%d/%d\n",checked,jrule);
	if (checked==jrule)
	{
		printf("rule check berhasil");
	}
	else
	{
		printf("rule check tidak berhasil");
	}
	return;
}

