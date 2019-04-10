//***********************************************************//
// [ Source Code ]
//
// Institution : Institut Teknologi Bandung
// Name : Michaella Yosephine
// File Name : assignasisten.c
// Dependency : stdio.h, string.h, lib.h
//
// Description:
// memasukkan jadwal asisten secara manual
//
//
// Status:
// 1. Yoga Putera - 13217080 : Create the file
// 2. Michaella Yosephine - 18317004 : debug
// 3. Rafita Erli - 18317005 : debug
// 4. Lulu Firdaus - 18317001 : debug
//***********************************************************//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lib.h"

void AssignAsisten(praktikum lab1[13][6], praktikum lab2[13][6], praktikum lab3[13][6], praktikum labLSS[13][6])
//suatu prosedur yang meminta masukkan initial asisten dan dimasukkan ke array of praktikum element nama
{
    char masukan; //variabel sementara untuk menampung inisial asisten
    int mgg,hari; //variabel untuk indeks pada array
    char hr[7],ruang[5],ch; //variabel untuk menyimpan sementara inputan dari user
    printf("Isi 'q' atau 'Q' untuk kembali ke menu\n");
    int i = 0;
    while ((masukan != 'q') || (masukan != 'Q')) //keluar jika masukkan q atau Q
    {
        printf("Pilih Asisten (A-N): ");
        if (i == 0)
            ch = getchar();
        i = 1;
        scanf("%c",&masukan);//meminta masukkan inisial asisten
        if ((masukan == 'Q') || (masukan == 'q'))
        {
            return;
        }
        else
        {
            printf("Minggu: ");
            scanf("%d",&mgg); //meminta masukkan untuk indeks minggu
            printf("Hari: ");
            ch = getchar();
            gets(hr);
            //mengubah hari string ke integer agar dapat dijadikan indeks array
            if (strcmp(hr,"Senin") == 0)
                hari = 0;
            else if (strcmp(hr,"Selasa") == 0)
                hari = 1;
            else if (strcmp(hr,"Rabu") == 0)
                hari = 2;
            else if (strcmp(hr,"Kamis") == 0)
                hari = 3;
            else if (strcmp(hr,"Jumat") == 0)
                hari = 4;
            printf("Ruang: ");//meminta input ruangan
            gets(ruang);
            //memanggil fungsi check keadaan tiap asisten
            if (CheckAssistant(masukan,hari,mgg-3,lab1,lab2,lab3,labLSS)==1) //bisa dimasukkan
            {
                if (strcmp(ruang,"LAB1") == 0)
                {
                    if (lab1[mgg-3][hari].nama[0] == ' ')//belom ada asisten
                    {
                        lab1[mgg-3][hari].nama[0] = masukan;
                    }else //sudah ada 1 asisten
                    {
                        lab1[mgg-3][hari].nama[1] = masukan;
                    }
                }else if (strcmp(ruang,"LAB2") == 0)
                {
                    if (lab2[mgg-3][hari].nama[0] == ' ') //belum ada asisten
                    {
                        lab2[mgg-3][hari].nama[0] = masukan;
                    }else //sudah ada 1 asisten
                    {
                        lab2[mgg-3][hari].nama[1] = masukan;
                    }
                }else if (strcmp(ruang,"LAB3") == 0)
                {
                    if (lab3[mgg-3][hari].nama[0] == ' ')//belum ada asisten
                    {
                        lab3[mgg-3][hari].nama[0] = masukan;
                    }else //sudah ada 1 asisten
                    {
                        lab3[mgg-3][hari].nama[1] = masukan;
                    }
                }else if (strcmp(ruang,"LSS") == 0)
                {
                    if (labLSS[mgg-3][hari].nama[0] == ' ')//belum ada asisten
                    {
                        labLSS[mgg-3][hari].nama[0] = masukan;
                    }else//sudah ada 1 asisten
                    {
                        labLSS[mgg-3][hari].nama[1] = masukan;
                    }
                }
            }
        }
    }
}
