//***********************************************************//
// [ Source Code ]
//
// Institution : Institut Teknologi Bandung
// Name : Michaella Yosephine
// File Name : assignasisten.c
// Dependency : stdio.h, string.h, lib.h
//
// Description:
// header library
//
//
// Status:
// 1. Michaella Yosephine - 18317004 : Create the file
// 2. Yoga Putera - 13217080 : debug
// 3. Rafita Erli - 18317005 : debug
// 4. Lulu Firdaus - 18317001 : debug
//***********************************************************//

#ifndef LIB_H
#define LIB_H
#include <stdio.h>
#include <string.h>


typedef struct {
    char kode[7];
    char rombongan[3];
    char nama[3];
    } praktikum;

typedef struct
{
	int mg;
	int hari;
}rule;

int CheckAssistant(char initial, int hari, int minggu, praktikum lab1[13][6], praktikum lab2[13][6], praktikum lab3[13][6], praktikum lss[13][6]);
void checkANDprintSch(praktikum lab[13][6], int i, int j);
void checkANDprintAs(praktikum lab[13][6], int i, int j);
void printHeader();
void TampilkanSchedule(praktikum lab1[13][6], praktikum lab2[13][6], praktikum lab3[13][6], praktikum lss[13][6]);
void checkANDprintAs(praktikum lab[13][6], int i, int j);
void TampilkanAsisten(praktikum lab1[13][6], praktikum lab2[13][6], praktikum lab3[13][6], praktikum lss[13][6]);
void AssignAsisten(praktikum lab1[13][6],praktikum lab2[13][6],praktikum lab3[13][6],praktikum labLSS[13][6]);
void SaveFileJadwal (char namafile[],praktikum lab1[13][6],praktikum lab2[13][6],praktikum lab3[13][6],praktikum labLSS[13][6]);
void SaveFileAsisten (char namafile[],praktikum lab1[13][6],praktikum lab2[13][6],praktikum lab3[13][6],praktikum labLSS[13][6]);
void LoadFileJadwal (char namafile[],praktikum lab1[13][6],praktikum lab2[13][6],praktikum lab3[13][6],praktikum labLSS[13][6]);
void LoadFileAsisten (char namafile[],praktikum lab1[13][6],praktikum lab2[13][6],praktikum lab3[13][6],praktikum labLSS[13][6]);
void menu();
void mode();
int convertHari(char ihari[7]);
void simpanArrayRuang(char ikode[7], char irombongan[3], int iminggu, int hariotw, char iruang[5], praktikum lab1[13][6], praktikum lab2[13][6], praktikum lab3[13][6], praktikum lss[13][6]);
void inputSchedule(praktikum lab1[13][6],praktikum lab2[13][6],praktikum lab3[13][6],praktikum lss[13][6]);

#endif // CHECKASISTENMANUAL_H
