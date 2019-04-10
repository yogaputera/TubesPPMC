//***********************************************************//
// [ Source Code ]
//
// Institution : Institut Teknologi Bandung
// Name : Lulu Firdaus
// File Name : InputJadwalManual.c
// Dependency : stdio.h, string.h, lib.h, stdlib.h
//
// Description:
// menyimpan input jadwal praktikum manual
//
//
// Status:
// 1. Lulu Firdaus - 18317001 : Create the file
// 2. Yoga Putera - 13217080 : Menambahkan validasi input
// 3. Michaella Yosephine - 18317004 : Debugging
// 4. Rafita Erli - 18317005 : debugging
//***********************************************************//

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lib.h"

//fungsi convert hari untuk ubah input hari yang tadinya string jadi integer
int convertHari(char ihari[7])
{
	int day;
	if (strcmp(ihari,"Senin")==0)
		day=0;
	else if (strcmp(ihari,"Selasa")==0)
		day=1;
	else if (strcmp(ihari,"Rabu")==0)
		day=2;
	else if (strcmp(ihari,"Kamis")==0)
		day=3;
	else if (strcmp(ihari,"Jumat")==0)
		day=4;
	return day;
}
//akhir fungsi convertHari
void simpanArrayRuang(char ikode[7], char irombongan[3], int iminggu, int hariotw, char iruang[5], praktikum lab1[13][6], praktikum lab2[13][6], praktikum lab3[13][6], praktikum lss[13][6])
{

	int hari, minggu;
    minggu=iminggu-3;
    hari=hariotw;
	if (strcmp(iruang, "LAB1")==0)
    {
        if (lab1[minggu][hari].kode[0]==' ')
		{
			strcpy(lab1[minggu][hari].kode, ikode);
			strcpy(lab1[minggu][hari].rombongan, irombongan);
		}else
			printf("Sesi sudah terisi\n");
    }
    else if (strcmp(iruang, "LAB2")==0)
    {
        if (lab2[minggu][hari].kode[0]==' ')
        {
            strcpy(lab2[minggu][hari].kode, ikode);
            strcpy(lab2[minggu][hari].rombongan, irombongan);
        }
        else
            printf("Sesi sudah terisi\n");
	}
	else if(strcmp(iruang, "LAB3")==0)
	{
		if (lab3[minggu][hari].kode[0]==' ')
		{
			strcpy(lab3[minggu][hari].kode, ikode);
			strcpy(lab3[minggu][hari].rombongan, irombongan);
        }
        else
            printf("Sesi sudah terisi\n");
    }
    else if (strcmp(iruang, "LSS")==0)
    {
        if (lss[minggu][hari].kode[0]==' ')
        {
			strcpy(lss[minggu][hari].kode, ikode);
			strcpy(lss[minggu][hari].rombongan, irombongan);
		}
        else
            printf("Sesi sudah terisi\n");
    }
    else
        printf("Input tidak valid.");
}

//prosedur untuk membaca input jadwal manual
void inputSchedule(praktikum lab1[13][6],praktikum lab2[13][6],praktikum lab3[13][6],praktikum lss[13][6])
{
	char ikode[7];
	char irombongan[3];
	char iruang[5], iruangdua[5], iruangtiga[5];
	int iminggu,minggu;
	char ihari[7];
	int hari,hariotw;
	char ch;
	int i = 0;

	//looping untuk membaca, selama dia tidak mendapat Q atau q
	while ((ikode[0]!='q')&&(ikode[0]!='Q'))
    {
        printf("\n");
        ch = getchar();
        printf("Isi 'q' atau 'Q' untuk kembali ke menu\n");
        printf("Pilih Kode Praktikum (EL2205, EL2208, EB2200):\n");
        gets(ikode);
	//untuk EB2200, rombongannya hanya ada A atau B. kasusnya cuma 1 kategori
        if (strcmp(ikode, "EB2200")==0)
        {
            printf("Rombongan (A atau B): ");
            gets(irombongan);
            printf("Minggu ke: ");
            scanf("%d", &iminggu);
            printf("Hari: ");
            ch = getchar();
            gets(ihari);
            hariotw=convertHari(ihari);
            printf("Ruangan: ");
            gets(iruang);
            if (strcmp(iruang,"LSS")==0)
            {
                printf("Praktikum tidak dapat dilaksanakan di LSS\n");
            }
            else
            {
                if (hariotw ==1 || hariotw ==3)
                {//memasukkan nilai rombongan dan kode praktikum ke array lab[minggu][hari]
                    simpanArrayRuang(ikode, irombongan, iminggu, hariotw, iruang, lab1, lab2, lab3, lss);
                }else
                    printf("Praktikum tidak dapat dilaksanakan\n");
            }
            //akhir kasus EB2200
        }
        else if (strcmp(ikode, "EL2208")==0)
        {/* mulai kasus EL2208*/
        //ada 3 kasus, yaitu:
        //1. rombongan 1 per satu
        //2. rombongan A sekaligus (A1, A2, A3)
        //3. rombongan B sekaligus (B1, B2, B3)
            printf("Rombongan (A1, A2, A3, B1, B2, B3, atau C):");
            gets(irombongan);
            if ((strcmp(irombongan, "A1")==0)||(strcmp(irombongan, "A2")==0)||(strcmp(irombongan, "A3")==0)||
            (strcmp(irombongan, "B1")==0)||(strcmp(irombongan, "B2")==0)||(strcmp(irombongan, "B3")==0)||
            (strcmp(irombongan, "C")==0))/* kasus 1*/
            {

                    printf("Minggu ke: ");
                    scanf("%d", &iminggu);
                    printf("Hari: ");
                    ch = getchar();
                    gets(ihari);
                    hariotw=convertHari(ihari);
                    printf("Ruangan: ");
                    gets(iruang);
                    if (irombongan[0]== 'C')
                //simpan data ke array lab[minggu][hari] yang sesuai
                    {
                        simpanArrayRuang(ikode, irombongan, iminggu, hariotw, iruang, lab1, lab2, lab3, lss);
                    }else
                    {
                        if ((strcmp(lab1[iminggu-3][hariotw].kode,"EL2205")==0)|| (strcmp(lab2[iminggu-3][hariotw].kode,"EL2205")==0)||(strcmp(lab3[iminggu-3][hariotw].kode,"EL2205")==0)||(strcmp(lss[iminggu-3][hariotw].kode,"EL2205")==0))
                        {
                            printf("Terdapat Praktikum Elektronika\n");
                        }else
                        {
                            simpanArrayRuang(ikode, irombongan, iminggu, hariotw, iruang, lab1, lab2, lab3, lss);
                        }
                    }
                } /* akhir kasus 1*/
            /* kasus 2 (rombongan A seluruhnya) */
            else if (strcmp(irombongan, "A")==0)
            {
                printf("Minggu ke: ");
                scanf("%d", &iminggu);
                printf("Hari: ");
                ch = getchar();
                gets(ihari);
                hariotw=convertHari(ihari);
                /* data minggu dan hari tetap sama, yang berbeda hanya ruangan*/
                /* periksa apakah sudah terdapat Praktikum Elektronika */
                if ((strcmp(lab1[iminggu-3][hariotw].kode,"EL2205")==0)|| (strcmp(lab2[iminggu-3][hariotw].kode,"EL2205")==0)||(strcmp(lab3[iminggu-3][hariotw].kode,"EL2205")==0)||(strcmp(lss[iminggu-3][hariotw].kode,"EL2205")==0))
                {
                    printf("Terdapat Praktikum Elektronika\n");
                }
                else
                {   /* input ruangan untuk A1*/
                    printf("Ruangan 1: ");
                    gets(iruang);
                    strcpy(irombongan,"A1");
                    simpanArrayRuang(ikode, irombongan, iminggu, hariotw, iruang, lab1, lab2, lab3, lss);

                    /* input ruangan untuk A2*/
                    printf("Ruangan 2: ");
                    gets(iruang);
                    strcpy(irombongan,"A2");
                    simpanArrayRuang(ikode, irombongan, iminggu, hariotw, iruang, lab1, lab2, lab3, lss);

                    /* input ruangan untuk A3*/
                    printf("Ruangan 3: ");
                    gets(iruang);
                    strcpy(irombongan,"A3");
                    simpanArrayRuang(ikode, irombongan, iminggu, hariotw, iruang, lab1, lab2, lab3, lss);
                }
            } /* akhir kasus 2*/
        /* kasus 3 (rombongan B seluruhnya) */
        }
        else if (strcmp(irombongan, "B")==0)
        {
            printf("Minggu ke: ");
            scanf("%d", &iminggu);
            printf("Hari: ");
            ch = getchar();
            gets(ihari);
            hariotw=convertHari(ihari);
            /* data minggu dan hari tetap sama, yang berbeda hanya ruangan*/
            /* input ruangan untuk B1*/
            if ((strcmp(lab1[iminggu-3][hariotw].kode,"EL2205")==0)|| (strcmp(lab2[iminggu-3][hariotw].kode,"EL2205")==0)||(strcmp(lab3[iminggu-3][hariotw].kode,"EL2205")==0)||(strcmp(lss[iminggu-3][hariotw].kode,"EL2205")==0))
            {
                printf("Terdapat Praktikum Elektronika\n");
            }else
            {
                printf("Ruangan 1: ");
                gets(iruang);
                strcpy(irombongan,"B1");
                simpanArrayRuang(ikode, irombongan, iminggu, hariotw, iruang, lab1, lab2, lab3, lss);

                /* input ruangan untuk B2*/
                printf("Ruangan 2: ");
                gets(iruang);
                strcpy(irombongan,"B2");
                simpanArrayRuang(ikode, irombongan, iminggu, hariotw, iruang, lab1, lab2, lab3, lss);

                /* input ruangan untuk B3*/
                printf("Ruangan 3: ");
                gets(iruang);
                strcpy(irombongan,"B3");
                simpanArrayRuang(ikode, irombongan, iminggu, hariotw, iruang, lab1, lab2, lab3, lss);
            }
        } /* akhir kasus EL2208*/
        /* kasus EL2205 */
        else if (strcmp(ikode, "EL2205")==0)
        {/* mulai kasus EL2205*/
        //ada 4 kasus, yaitu:
        //1. rombongan satu per satu
        //2. rombongan A sekaligus (A1, A2)
        //3. rombongan B sekaligus (B1, B2)
        //4. rombongan B sekaligus (C1, C2)
            printf("Rombongan (A1, A2, B1, B2, C1, atau C2):");
            gets(irombongan);
            if ((strcmp(irombongan, "A1")==0)||(strcmp(irombongan, "A2")==0)||
            (strcmp(irombongan, "B1")==0)||(strcmp(irombongan, "B2")==0)||
            (strcmp(irombongan, "C1")==0)||(strcmp(irombongan, "C2")==0))/* kasus 1*/
            {
                printf("Minggu ke: ");
                scanf("%d", &iminggu);
                printf("Hari: ");
                ch = getchar();
                gets(ihari);
                hariotw=convertHari(ihari);
                printf("Ruangan: ");
                gets(iruang);
                if (strcmp(iruang,"LSS")==0)
                {
                    printf("praktikum tidak dapat dilaksanakan\n");
                }else
                {
                    if (((strcmp(lab1[iminggu-3][hariotw].kode,"EL2208")==0)&&(lab1[iminggu-3][hariotw].rombongan[0]!='C'))||((strcmp(lab2[iminggu-3][hariotw].kode,"EL2208")==0)&&(lab2[iminggu-3][hariotw].rombongan[0]!='C'))||((strcmp(lab3[iminggu-3][hariotw].kode,"EL2208")==0)&&(lab3[iminggu-3][hariotw].rombongan[0]!='C'))||((strcmp(lss[iminggu-3][hariotw].kode,"EL2208")==0)&&(lss[iminggu-3][hariotw].rombongan[0]!='C')))
                    {
                        printf("Terdapat praktikum PMC\n");
                    }else
                    {
                        //simpan data ke array lab[minggu][hari] yang sesuai
                        simpanArrayRuang(ikode, irombongan, iminggu, hariotw, iruang, lab1, lab2, lab3, lss);
                    }
                }
            } /* akhir kasus 1*/
        /* kasus 2 (rombongan A seluruhnya) */
            else if (strcmp(irombongan, "A")==0)
            {
                printf("Minggu ke: ");
                scanf("%d", &iminggu);
                printf("Hari: ");
                scanf("%s",ihari);
                hariotw=convertHari(ihari);
                /* data minggu dan hari tetap sama, yang berbeda hanya ruangan*/
                /* input ruangan untuk A1*/
                printf("Ruangan 1: ");
                scanf("%s",iruang);
                    if (strcmp(iruang,"LSS")==0)
                    {
                        printf("praktikum tidak dapat dilaksanakan\n");
                    }else
                    {
                        if (((strcmp(lab1[iminggu-3][hariotw].kode,"EL2208")==0)&&(lab1[iminggu-3][hariotw].rombongan[0]!='C'))||((strcmp(lab2[iminggu-3][hariotw].kode,"EL2208")==0)&&(lab2[iminggu-3][hariotw].rombongan[0]!='C'))||((strcmp(lab3[iminggu-3][hariotw].kode,"EL2208")==0)&&(lab3[iminggu-3][hariotw].rombongan[0]!='C'))||((strcmp(lss[iminggu-3][hariotw].kode,"EL2208")==0)&&(lss[iminggu-3][hariotw].rombongan[0]!='C')))
                        {
                            printf("Terdapat praktikum PMC\n");
                        }else
                        {
                            //simpan data ke array lab[minggu][hari] yang sesuai
                            strcpy(irombongan, "A1");
                            simpanArrayRuang(ikode, irombongan, iminggu, hariotw, iruang, lab1, lab2, lab3, lss);
                        }
                    }
                /* input ruangan untuk A2*/
                printf("Ruangan 2: ");
                scanf("%s",iruang);
                    if (strcmp(iruang,"LSS")==0)
                    {
                        printf("praktikum tidak dapat dilaksanakan\n");
                    }else
                    {
                        if (((strcmp(lab1[iminggu-3][hariotw].kode,"EL2208")==0)&&(lab1[iminggu-3][hariotw].rombongan[0]!='C'))||((strcmp(lab2[iminggu-3][hariotw].kode,"EL2208")==0)&&(lab2[iminggu-3][hariotw].rombongan[0]!='C'))||((strcmp(lab3[iminggu-3][hariotw].kode,"EL2208")==0)&&(lab3[iminggu-3][hariotw].rombongan[0]!='C'))||((strcmp(lss[iminggu-3][hariotw].kode,"EL2208")==0)&&(lss[iminggu-3][hariotw].rombongan[0]!='C')))
                        {
                            printf("Terdapat praktikum PMC\n");
                        }else
                        {
                            //simpan data ke array lab[minggu][hari] yang sesuai
                            strcpy(irombongan, "A2");
                            simpanArrayRuang(ikode, irombongan, iminggu, hariotw, iruang, lab1, lab2, lab3, lss);
                        }
                    }
            } /* akhir kasus 2*/
            /* kasus 3 (rombongan B seluruhnya) */
            else if (strcmp(irombongan, "B")==0)
            {
                printf("Minggu ke: ");
                scanf("%d", &iminggu);
                printf("Hari: ");
                scanf("%s", ihari);
                hariotw=convertHari(ihari);
                /* data minggu dan hari tetap sama, yang berbeda hanya ruangan*/
                /* input ruangan untuk B1*/
                printf("Ruangan 1: ");
                scanf("%s",iruang);
                    if (strcmp(iruang,"LSS")==0)
                    {
                        printf("praktikum tidak dapat dilaksanakan\n");
                    }else
                    {
                        if (((strcmp(lab1[iminggu-3][hariotw].kode,"EL2208")==0)&&(lab1[iminggu-3][hariotw].rombongan[0]!='C'))||((strcmp(lab2[iminggu-3][hariotw].kode,"EL2208")==0)&&(lab2[iminggu-3][hariotw].rombongan[0]!='C'))||((strcmp(lab3[iminggu-3][hariotw].kode,"EL2208")==0)&&(lab3[iminggu-3][hariotw].rombongan[0]!='C'))||((strcmp(lss[iminggu-3][hariotw].kode,"EL2208")==0)&&(lss[iminggu-3][hariotw].rombongan[0]!='C')))
                        {
                            printf("Terdapat praktikum PMC\n");
                        }else
                        {
                            //simpan data ke array lab[minggu][hari] yang sesuai
                            strcpy(irombongan, "B1");
                            simpanArrayRuang(ikode, irombongan, iminggu, hariotw, iruang, lab1, lab2, lab3, lss);
                        }
                    }
                /* input ruangan untuk B2*/
                printf("Ruangan 2: ");
                scanf("%s",iruang);
                    if (strcmp(iruang,"LSS")==0)
                    {
                        printf("praktikum tidak dapat dilaksanakan\n");
                    }else
                    {
                        if (((strcmp(lab1[iminggu-3][hariotw].kode,"EL2208")==0)&&(lab1[iminggu-3][hariotw].rombongan[0]!='C'))||((strcmp(lab2[iminggu-3][hariotw].kode,"EL2208")==0)&&(lab2[iminggu-3][hariotw].rombongan[0]!='C'))||((strcmp(lab3[iminggu-3][hariotw].kode,"EL2208")==0)&&(lab3[iminggu-3][hariotw].rombongan[0]!='C'))||((strcmp(lss[iminggu-3][hariotw].kode,"EL2208")==0)&&(lss[iminggu-3][hariotw].rombongan[0]!='C')))
                        {
                            printf("Terdapat praktikum PMC\n");
                        }else
                        {
                            //simpan data ke array lab[minggu][hari] yang sesuai
                            strcpy(irombongan,"B2");
                            simpanArrayRuang(ikode, irombongan, iminggu, hariotw, iruang, lab1, lab2, lab3, lss);
                        }
                    }
            } /* akhir kasus 3*/
            /* kasus 4 (rombongan C seluruhnya) */
            else if (strcmp(irombongan, "C")==0)
            {
                printf("Minggu ke: ");
                scanf("%d", &iminggu);
                printf("Hari: ");
                scanf("%s",ihari);
                hariotw=convertHari(ihari);
                /* data minggu dan hari tetap sama, yang berbeda hanya ruangan*/
                /* input ruangan untuk C1*/
                printf("Ruangan 1: ");
                scanf("%s",iruang);
                    if (strcmp(iruang,"LSS")==0)
                    {
                        printf("praktikum tidak dapat dilaksanakan\n");
                    }else
                    {
                        if (((strcmp(lab1[iminggu-3][hariotw].kode,"EL2208")==0)&&(lab1[iminggu-3][hariotw].rombongan[0]!='C'))||((strcmp(lab2[iminggu-3][hariotw].kode,"EL2208")==0)&&(lab2[iminggu-3][hariotw].rombongan[0]!='C'))||((strcmp(lab3[iminggu-3][hariotw].kode,"EL2208")==0)&&(lab3[iminggu-3][hariotw].rombongan[0]!='C'))||((strcmp(lss[iminggu-3][hariotw].kode,"EL2208")==0)&&(lss[iminggu-3][hariotw].rombongan[0]!='C')))
                        {
                            printf("Terdapat praktikum PMC\n");
                        }else
                        {
                            //simpan data ke array lab[minggu][hari] yang sesuai
                            strcpy(irombongan,"C1");
                            simpanArrayRuang(ikode, irombongan, iminggu, hariotw, iruang, lab1, lab2,lab3, lss);
                        }
                    }
                /* input ruangan untuk C2*/
                printf("Ruangan 2: ");
                scanf("%s",iruang);
                    if (strcmp(iruang,"LSS")==0)
                    {
                        printf("praktikum tidak dapat dilaksanakan\n");
                    }else
                    {
                        if (((strcmp(lab1[iminggu-3][hariotw].kode,"EL2208")==0)&&(lab1[iminggu-3][hariotw].rombongan[0]!='C'))||((strcmp(lab2[iminggu-3][hariotw].kode,"EL2208")==0)&&(lab2[iminggu-3][hariotw].rombongan[0]!='C'))||((strcmp(lab3[iminggu-3][hariotw].kode,"EL2208")==0)&&(lab3[iminggu-3][hariotw].rombongan[0]!='C'))||((strcmp(lss[iminggu-3][hariotw].kode,"EL2208")==0)&&(lss[iminggu-3][hariotw].rombongan[0]!='C')))
                        {
                            printf("Terdapat praktikum PMC\n");
                        }else
                        {
                            //simpan data ke array lab[minggu][hari] yang sesuai
                            strcpy(irombongan,"C2");
                            simpanArrayRuang(ikode, irombongan, iminggu, hariotw, iruang, lab1, lab2, lab3, lss);
                        }
                    }
            } /* akhir kasus 4*/
        }
        else
        {
            printf("Input mata kuliah praktikum tidak valid");
        }
             /* akhir kasus EL2205*/
    }
		//akhir looping prosedur input schedule
//masukkan fungsi untuk kembali ke menu utama
}
