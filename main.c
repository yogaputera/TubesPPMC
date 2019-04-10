//***********************************************************//
// [ Source Code ]
//
// Institution : Institut Teknologi Bandung
// Name : Rafita Erli
// File Name : utama1.c
// Dependency : stdio.h, string.h, lib.h, math.h,
//#include Tampilkan.c, CheckAsistenManual.c,
//"assignasisten.c", "FileExternal.c",
//"bacarule.c", "cekrule.c", "InputJadwalManual.c"
//
// Description:
// program utama
//
//
// Status:
// 1. Rafita Erli - 18317005 : Create the file
// 2. Yoga Putera - 13217080 : debug
// 3. Michaella Yosephine - 18317004 : debug
// 4. Lulu Firdaus - 18317001 : debug
//***********************************************************//

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#define max 100

#include "lib.h"
#include "Tampilkan.c"
#include "CheckAsistenManual.c"
#include "assignasisten.c"
#include "FileExternal.c"
#include "bacarule.c"
#include "cekrule.c"
#include "InputJadwalManual.c"

//masukin include lain

//masukin variabel global
int pmenu;//var penampung pilihan menu
int pmode;//var penampung pilihan mode
char nproyek[max];//var penampung nama proyek

//masukan header fungsi
void menu();
void mode();




int main()
{
    int i,j;
    int jrule;
    rule r[max];
    char namafile[40];
    char ch;
    praktikum lab1[13][6], lab2[13][6], lab3[13][6], lss[13][6];
	int pmenu;//var penampung pilihan menu
	int pmode;//var penampung pilihan mode
	char nproyek[max];//var penampung nama proyek
	char nasisten[max];//var penampung nama proyek
	menu();
	scanf ("%d",&pmenu);
	while(pmenu!=3)
	{
		if (pmenu==1)
		{
			printf("===== Membuat Proyek Baru=====\n");
			printf("masukan nama proyek: ");
            ch = getchar();
			scanf("%[^\n]%*c", nproyek);
			printf("masukan nama file asisten: ");
			ch = getchar();
			scanf("%[^\n]%*c", nasisten);
			printf("\n");
			mode();
			scanf("%d",&pmode);
			printf("\n");
		    for (i=0;i<12;i++)
			{
				for(j=0;j<5;j++)
				{
					strcpy(lab1[i][j].kode," ");
					strcpy(lab1[i][j].rombongan," ");
					strcpy(lab1[i][j].nama," ");
					strcpy(lab2[i][j].kode," ");
					strcpy(lab2[i][j].rombongan," ");
					strcpy(lab2[i][j].nama," ");
					strcpy(lab3[i][j].kode," ");
					strcpy(lab3[i][j].rombongan," ");
					strcpy(lab3[i][j].nama," ");
					strcpy(lss[i][j].kode," ");
					strcpy(lss[i][j].rombongan," ");
					strcpy(lss[i][j].nama," ");
				}
			}
			while (pmode!=8)
			{
				switch(pmode)
				{
					case 1:
						TampilkanSchedule(lab1,lab2,lab3,lss);
						mode();
						scanf("%d",&pmode);
						printf("\n");
						break;
					case 2:
						inputSchedule(&lab1,&lab2,&lab3,&lss);
						mode();
						scanf("%d",&pmode);
						printf("\n");
						break;
					case 3:
						TampilkanAsisten(lab1,lab2,lab3,lss);
						mode();
						scanf("%d",&pmode);
						printf("\n");
						break;
					case 4:
						AssignAsisten(lab1,lab2,lab3,lss);
						mode();
						scanf("%d",&pmode);
						printf("\n");
						break;
					case 5:
						printf("fungsi tidak tersedia:v");
						mode();
						scanf("%d",&pmode);
						printf("\n");
						break;
					case 6:
						printf("fungsi tidak tersedia:v");
						mode();
						scanf("%d",&pmode);
						printf("\n");
						break;
					case 7:
						printf("[DRC]\n");
						printf("masukan file DRC (dalam format .txt): \n");
						scanf("%s",&namafile);
						printf("%s\n",namafile);
						//scanf("%[^\n]%*c", namafile);
						bacarule(r,namafile,jrule);
						printf("%d %d\n",r[0].mg,r[0].hari);
						printf("%d %d\n",r[1].mg,r[1].hari);
						printf("%d %d\n",r[2].mg,r[2].hari);
						cekrule(r,jrule,lab1,lab2,lab3,lss);
						printf("lili %s\n",namafile);
						printf("\n");
						mode();
						scanf("%d",&pmode);
						printf("\n");
						break;
					case 8:
						SaveFileJadwal(nproyek,lab1,lab2,lab3,lss);
						SaveFileAsisten(nasisten,lab1,lab2,lab3,lss);
						printf("\n");
						menu();
						scanf ("%d",&pmenu);
					default :
						printf("Invalid grade\n" );
						break;
				}
			}
			if (pmode==8)
			{
				SaveFileJadwal(nproyek,lab1,lab2,lab3,lss);
				SaveFileAsisten(nasisten,lab1,lab2,lab3,lss);
				printf("\n");
				menu();
				scanf ("%d",&pmenu);
			}
		}
		else if (pmenu==2)
		{
			//memuat proyek dari berka
			printf("===== memuat proyek dari berkas=====\n");
			printf("masukan nama proyek: ");
			ch = getchar();
			scanf("%[^\n]%*c", nproyek);
			printf("Barusan file proyek = %s", nproyek);
			printf("masukan nama file asisten: ");
			ch = getchar();
			scanf("%[^\n]%*c", nasisten);
			printf("Barusan file asisten = %s", nasisten);
			for (i=0;i<12;i++)
			{
				for(j=0;j<5;j++)
				{
					strcpy(lab1[i][j].kode," ");
					strcpy(lab1[i][j].rombongan," ");
					strcpy(lab1[i][j].nama," ");
					strcpy(lab2[i][j].kode," ");
					strcpy(lab2[i][j].rombongan," ");
					strcpy(lab2[i][j].nama," ");
					strcpy(lab3[i][j].kode," ");
					strcpy(lab3[i][j].rombongan," ");
					strcpy(lab3[i][j].nama," ");
					strcpy(lss[i][j].kode," ");
					strcpy(lss[i][j].rombongan," ");
					strcpy(lss[i][j].nama," ");
				}
			}
			LoadFileJadwal(nproyek,&lab1,&lab2,&lab3,&lss);
			LoadFileAsisten(nasisten,&lab1,&lab2,&lab3,&lss);
			printf("\n");
			mode();
			scanf("%d",&pmode);
			printf("\n");
		    for (i=0;i<12;i++)
			{
				for(j=0;j<5;j++)
				{
					strcpy(lab1[i][j].kode," ");
					strcpy(lab1[i][j].rombongan," ");
					strcpy(lab1[i][j].nama," ");
					strcpy(lab2[i][j].kode," ");
					strcpy(lab2[i][j].rombongan," ");
					strcpy(lab2[i][j].nama," ");
					strcpy(lab3[i][j].kode," ");
					strcpy(lab3[i][j].rombongan," ");
					strcpy(lab3[i][j].nama," ");
					strcpy(lss[i][j].kode," ");
					strcpy(lss[i][j].rombongan," ");
					strcpy(lss[i][j].nama," ");
				}
			}
			while (pmode!=8)
			{
				switch(pmode)
				{
					case 1:
						TampilkanSchedule(lab1,lab2,lab3,lss);
						mode();
						scanf("%d",&pmode);
						printf("\n");
						break;
					case 2:
						inputSchedule(&lab1,&lab2,&lab3,&lss);
						mode();
						scanf("%d",&pmode);
						printf("\n");
						break;
					case 3:
						TampilkanAsisten(lab1,lab2,lab3,lss);
						mode();
						scanf("%d",&pmode);
						printf("\n");
						break;
					case 4:
						AssignAsisten(lab1,lab2,lab3,lss);
						mode();
						scanf("%d",&pmode);
						printf("\n");
						break;
					case 5:
						printf("fungsi tidak tersedia:v");
						mode();
						scanf("%d",&pmode);
						printf("\n");
						break;
					case 6:
						printf("fungsi tidak tersedia:v");
						mode();
						scanf("%d",&pmode);
						printf("\n");
						break;
					case 7:
						printf("[DRC]\n");
						printf("masukan file DRC (dalam format .txt): ");
						scanf("%[^\n]%*c", namafile);
						bacarule(r,namafile,jrule);
						cekrule(r,jrule,lab1,lab2,lab3,lss);
						printf("\n");
						mode();
						scanf("%d",&pmode);
						printf("\n");
						break;
					case 8:
						SaveFileJadwal(nproyek,lab1,lab2,lab3,lss);
						SaveFileAsisten(nasisten,lab1,lab2,lab3,lss);
						printf("\n");
						menu();
						scanf ("%d",&pmenu);
					default :
						printf("Invalid grade\n" );
				}
			}
			if (pmode==8)
			{
				SaveFileJadwal(nproyek,lab1,lab2,lab3,lss);
				SaveFileAsisten(nasisten,lab1,lab2,lab3,lss);
				printf("\n");
				menu();
				scanf ("%d",&pmenu);
			}
		}
		else if (pmode)
		{
			printf("bye");
			return 0;
		}
	}
}

//implementasi fungsi
void menu()
{
	printf("Menu :\n");
	printf("\t1. buat proyek baru\n");
	printf("\t2. muat proyek dari berkas\n");
	printf("\t3. keluar\n");
	printf("masukan: ");
}

void mode()
{
	printf("[Menu Utama]\n");
	printf("pilih mode\n");
	printf("\t1. tampilkan schedule\n");
	printf("\t2. schedule manual\n");
	printf("\t3. tampilkan status Assigment Asisten\n");
	printf("\t4. assign asisten manual\n");
	printf("\t5. schedule otomatis\n");
	printf("\t6. assign otomatis\n");
	printf("\t7. rule checker\n");
	printf("\t8. simpan proyek dan keluar\nPilih mode: ");

}
