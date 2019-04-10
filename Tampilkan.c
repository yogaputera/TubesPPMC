
//***********************************************************//
// [ Source Code ]
//
// Institution : Institut Teknologi Bandung
// Name : Michaella Yosephine
// File Name : Tampilkan.c
// Dependency : stdio.h, string.h, lib.h
//
// Description:
// menampilkan jadwal praktikum dan jadwal asisten yang sudah disimpan
//
//
// Status:
// 1. Michaella Yosephine - 18317004 : Create the file
// 2. Yoga Putera - 13217080 : debug
// 3. Rafita Erli - 18317005 : debug
// 4. Lulu Firdaus - 18317001 : debug

//***********************************************************//

#include <stdio.h>
#include <string.h>
#include "lib.h"

void checkANDprintSch(praktikum lab[13][6], int i, int j)
// fungsi untuk memeriksa apakah kode praktikum berupa sel kosong
// diasumsikan jika bukan sel kosong, rombongannya juga sudah valid
// karena pada mode 2, data rombongan diminta setelah data kode.
{
    if ((lab[i][j].kode[0] != ' ')) //jika tidak kosong, print isinya
    {
        printf("%s-%s\t| ", lab[i][j].kode, lab[i][j].rombongan);
    }
    else //jika tidak kosong, print tab saja
    {
        printf("\t\t| ");
    }
}

void printHeader()
{
    printf("|-------------------------------------------------------------------------------|\n");
    printf("|Ruang Praktikum |     LAB1\t|     LAB2\t|     LAB3\t|      LSS \t|\n");
    printf("|Minggu | Hari\t |--------------|---------------|---------------|---------------|\n");
    printf("|-------|--------|--------------|---------------|---------------|---------------|\n");
}

void TampilkanSchedule(praktikum lab1[13][6], praktikum lab2[13][6], praktikum lab3[13][6], praktikum lss[13][6])
// fungsi untuk mengoutput jadwal praktikum
{
    // Deklarasi variabel
    int i, j;
    // Print bagian atas (kepala) tabel jadwal praktikum
    printf("[Schedule Praktikum Sementara]\n");
    printHeader();
    // inisialisasi tabel hari dari Senin - Jumat
    char hari[6][10] = {"Senin", "Selasa", "Rabu", "Kamis", "Jumat"};
    // proses mengoutput
    for (i = 0; i < 12; i++) //minggu ke-i
    {
        for (j = 0; j < 5; j++) //hari ke-j
        {
            if (j == 1)
            {
                printf("| %d\t| %s | ",i+3, hari[j]); // Jika hari Selasa tidak perlu tab karena sudah pas-pasan
            }
            else
            {
                printf("| %d\t| %s\t | ",i+3, hari[j]); // Selain hari Selasa, hari lain ditambahkan tab agar rapi
            }
            // mengoutput jadwal lab1, lab2, lab3, dan lss
            checkANDprintSch(lab1,i,j);
            checkANDprintSch(lab2,i,j);
            checkANDprintSch(lab3,i,j);
            checkANDprintSch(lss,i,j);
            printf("\n");
        }
    }
    printf("|-------------------------------------------------------------------------------|\n");
}

void checkANDprintAs(praktikum lab[13][6], int i, int j)
// fungsi untuk memeriksa apakah inisial asisten berupa sel kosong
// sel kosong ditandai dengan spasi: ' '
// masing-masing praktikum memiliki 2 asisten namun mungkin asisten yang
// di-assign manual baru 1 orang, maka dibuat validasi.
// jika asisten yang di-assign baru 1, akan ditampilkan 1 asisten tersebut.
// jika tidak, akan ditampilkan keduanya.
{
    if (lab[i][j].nama[0] != ' ') // jika ada setidaknya 1 asisten
    {
        printf("     %c", lab[i][j].nama[0]); // mengeluarkan inisial asisten pertama
        if (lab[i][j].nama[1] != ' ') // jika terdapat 2 asisten
        {
            printf(",%c\t| ", lab[i][j].nama[1]); //mengeluarkan inisial asisten kedua
        }
        else
        {
            printf("\t| "); // jika hanya 1 asisten yang sudah di-assign ke praktikum tsb.
        }
    }
    else
        printf("\t\t| "); // jika sel kosong
}

void TampilkanAsisten(praktikum lab1[13][6], praktikum lab2[13][6], praktikum lab3[13][6], praktikum lss[13][6])
// fungsi untuk mengoutput jadwal praktikum
{
    // Deklarasi variabel
    int i, j;
    // Print bagian atas (kepala) tabel jadwal asisten
    printf("[Schedule Asisten Praktikum Sementara]\n");
    printHeader();
    // inisialisasi tabel hari
    char hari[6][10] = {"Senin", "Selasa", "Rabu", "Kamis", "Jumat"};
    // proses mengoutput
    for (i = 0; i < 12; i++) // minggu ke-i
    {
        for (j = 0; j < 5; j++)// hari ke-j
        {
            if (j == 1)
            {
                printf("| %d\t| %s | ",i+3, hari[j]); // Jika hari Selasa tidak perlu tab karena sudah pas-pasan
            }
            else
            {
                printf("| %d\t| %s\t | ",i+3, hari[j]); // Selain hari Selasa, hari lain ditambahkan tab agar rapi
            }
            checkANDprintAs(lab1,i,j);
            checkANDprintAs(lab2,i,j);
            checkANDprintAs(lab3,i,j);
            checkANDprintAs(lss,i,j);
            printf("\n");
        }
    }
    printf("|-------------------------------------------------------------------------------|\n");
}
