//***********************************************************//
// [ Source Code ]
//
// Institution : Institut Teknologi Bandung
// Name : Michaella Yosephine
// File Name : CheckAsistenManual.c
// Dependency : stdio.h, string.h, lib.h
//
// Description:
// mengecek availability masing-masing asisten, berdasarkan hari
// berhalangan dan mata praktikum yang dipegang oleh asisten
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

int CheckAssistant(char initial, int hari, int minggu, praktikum lab1[13][6], praktikum lab2[13][6], praktikum lab3[13][6], praktikum lss[13][6])
{
    if (initial == 'A') //Periksa Amir
    {
        if (hari != 2) //Amir berhalangan hari Rabu, maka hari tidak boleh = 2
        {   //periksa apakah terdapat rombongan pada hari & minggu input
            if ((strcmp(lab1[minggu][hari].kode,"EL2205")==0) || (strcmp(lab2[minggu][hari].kode,"EL2205")==0) || (strcmp(lab3[minggu][hari].kode,"EL2205")==0) || (strcmp(lss[minggu][hari].kode,"EL2205")==0))
            {
                return 1;
            }
            else
            {   // jika tidak ada rombongannya pada waktu itu
                printf("Jadwal Asisten Praktikum Amir tidak sesuai (tidak ada rombongan EL2205)\n");
                return 0;
            }
        }
        else
        {   // jika harinya berhalangan
            printf("Jadwal Asisten Praktikum Amir tidak sesuai (Amir berhalangan hari Rabu)\n");
            return 0;
        }
    }
    else if (initial == 'B') //hal yang sama dilakukan untuk asisten berinisial B sampai N
    {
        if (hari != 0) //hari dimuali dari 0 (Senin) sampai 4 (Jumat)
        {
            //dilakukan perbandingan antara kode praktikum di jadwal praktikum & kode praktikum yang di-asisten-kan asisten tersebut
            if ((strcmp(lab1[minggu][hari].kode,"EL2205")==0) || (strcmp(lab2[minggu][hari].kode,"EL2205")==0) || (strcmp(lab3[minggu][hari].kode,"EL2205")==0) || (strcmp(lss[minggu][hari].kode,"EL2205")==0))
            {
                return 1;
            }
            else
            {
                printf("Jadwal Asisten Praktikum Budi tidak sesuai (tidak ada rombongan EL2205)\n");
                return 0;
            }
        }
        else
        {
            printf("Jadwal Asisten Praktikum Budi tidak sesuai (Budi berhalangan hari Senin)\n");
            return 0;
        }
    }
    else if (initial == 'C')
    {
        if ((hari != 1) && (hari != 2))
        {
            if ((strcmp(lab1[minggu][hari].kode,"EL2205")==0) || (strcmp(lab2[minggu][hari].kode,"EL2205")==0) || (strcmp(lab3[minggu][hari].kode,"EL2205")==0) || (strcmp(lss[minggu][hari].kode,"EL2205")==0))
            {
                return 1;
            }
            else
            {
                printf("Jadwal Asisten Praktikum Cici tidak sesuai (tidak ada rombongan EL2205)\n");
                return 0;
            }
        }
        else
        {
            printf("Jadwal Asisten Praktikum Cici tidak sesuai (Cici berhalangan hari Selasa & Rabu)\n");
            return 0;
        }
    }
    else if (initial == 'D')
    {
        if ((hari != 0) && (hari != 2))
        {
            if ((strcmp(lab1[minggu][hari].kode,"EL2205")==0) || (strcmp(lab2[minggu][hari].kode,"EL2205")==0) || (strcmp(lab3[minggu][hari].kode,"EL2205")==0) || (strcmp(lss[minggu][hari].kode,"EL2205")==0))
            {
                return 1;
            }
            else
            {
                printf("Jadwal Asisten Praktikum Doni tidak sesuai (tidak ada rombongan EL2205)\n");
                return 0;
            }
        }
        else
        {
            printf("Jadwal Asisten Praktikum Doni tidak sesuai (Doni berhalangan hari Senin & Rabu)\n");
            return 0;
        }
    }
    else if (initial == 'E') //hari berhalangan tidak diperiksa pada beberapa asisten tidak memiliki hari yang berhalangan
    {
        if ((strcmp(lab1[minggu][hari].kode,"EL2205")==0) || (strcmp(lab2[minggu][hari].kode,"EL2205")==0) || (strcmp(lab3[minggu][hari].kode,"EL2205")==0) || (strcmp(lss[minggu][hari].kode,"EL2205")==0) || (strcmp(lab1[minggu][hari].kode,"EL2208")==0) || (strcmp(lab2[minggu][hari].kode,"EL2208")==0) || (strcmp(lab3[minggu][hari].kode,"EL2208")==0) || (strcmp(lss[minggu][hari].kode,"EL2208")==0))
        {
                return 1;
        }
        else
        {
            printf("Jadwal Asisten Praktikum Endang tidak sesuai (tidak ada rombongan EL2205 maupun EL2208)\n");
            return 0;
        }
    }
    else if (initial == 'F')
    {
        if (hari != 1)
        {
            if ((strcmp(lab1[minggu][hari].kode,"EL2205")==0) || (strcmp(lab2[minggu][hari].kode,"EL2205")==0) || (strcmp(lab3[minggu][hari].kode,"EL2205")==0) || (strcmp(lss[minggu][hari].kode,"EL2205")==0))
            {
                return 1;
            }
            else
            {
                printf("Jadwal Asisten Praktikum Fadel tidak sesuai (tidak ada rombongan EL2205)\n");
                return 0;
            }
        }
        else
        {
            printf("Jadwal Asisten Praktikum Fadel tidak sesuai (Fadel berhalangan hari Selasa)\n");
            return 0;
        }
    }
    else if (initial == 'G')
    {
        if (hari != 3)
        {
            if ((strcmp(lab1[minggu][hari].kode,"EL2205")==0) || (strcmp(lab2[minggu][hari].kode,"EL2205")==0) || (strcmp(lab3[minggu][hari].kode,"EL2205")==0) || (strcmp(lss[minggu][hari].kode,"EL2205")==0) || (strcmp(lab1[minggu][hari].kode,"EB2200")==0) || (strcmp(lab2[minggu][hari].kode,"EB2200")==0) || (strcmp(lab3[minggu][hari].kode,"EB2200")==0) || (strcmp(lss[minggu][hari].kode,"EB2200")==0))
            {
                return 1;
            }
            else
            {
                printf("Jadwal Asisten Praktikum Gilang tidak sesuai (tidak ada rombongan EL2205 maupun EB2200)\n");
                return 0;
            }
        }
        else
        {
            printf("Jadwal Asisten Praktikum Gilang tidak sesuai (Gilang berhalangan hari Kamis)\n");
            return 0;
        }
    }
    else if (initial == 'H')
    {
        if (hari != 3)
        {
            if ((strcmp(lab1[minggu][hari].kode,"EL2208")==0) || (strcmp(lab2[minggu][hari].kode,"EL2208")==0) || (strcmp(lab3[minggu][hari].kode,"EL2208")==0) || (strcmp(lss[minggu][hari].kode,"EL2208")==0))
            {
                return 1;
            }
            else
            {
                printf("Jadwal Asisten Praktikum Hero tidak sesuai (tidak ada rombongan EL2208)\n");
                return 0;
            }
        }
        else
        {
            printf("Jadwal Asisten Praktikum Hero tidak sesuai (Hero berhalangan hari Kamis)\n");
            return 0;
        }
    }
    else if (initial == 'I')
    {
        if (hari != 2)
        {
            if ((strcmp(lab1[minggu][hari].kode,"EL2205")==0) || (strcmp(lab2[minggu][hari].kode,"EL2205")==0) || (strcmp(lab3[minggu][hari].kode,"EL2205")==0) || (strcmp(lss[minggu][hari].kode,"EL2205")==0) || (strcmp(lab1[minggu][hari].kode,"EB2200")==0) || (strcmp(lab2[minggu][hari].kode,"EB2200")==0) || (strcmp(lab3[minggu][hari].kode,"EB2200")==0) || (strcmp(lss[minggu][hari].kode,"EB2200")==0) || (strcmp(lab1[minggu][hari].kode,"EL2208")==0) || (strcmp(lab2[minggu][hari].kode,"EL2208")==0) || (strcmp(lab3[minggu][hari].kode,"EL2208")==0) || (strcmp(lss[minggu][hari].kode,"EL2208")==0))
            {
                return 1;
            }
            else
            {
                printf("Jadwal Asisten Praktikum Intan tidak sesuai (tidak ada rombongan EL2205, EL2208, maupun EB2200)\n");
                return 0;
            }
        }
        else
        {
            printf("Jadwal Asisten Praktikum Intan tidak sesuai (Intan berhalangan hari Rabu)\n");
            return 0;
        }
    }
    else if (initial == 'J')
    {
        if (hari != 4)
        {
            if ((strcmp(lab1[minggu][hari].kode,"EL2208")==0) || (strcmp(lab2[minggu][hari].kode,"EL2208")==0) || (strcmp(lab3[minggu][hari].kode,"EL2208")==0) || (strcmp(lss[minggu][hari].kode,"EL2208")==0))
            {
                return 1;
            }
            else
            {
                printf("Jadwal Asisten Praktikum Joko tidak sesuai (tidak ada rombongan EL2208)\n");
                return 0;
            }
        }
        else
        {
            printf("Jadwal Asisten Praktikum Joko tidak sesuai (Joko berhalangan hari Jumat)\n");
            return 0;
        }
    }
    else if (initial == 'K')
    {
        if (hari != 4)
        {
            if ((strcmp(lab1[minggu][hari].kode,"EL2208")==0) || (strcmp(lab2[minggu][hari].kode,"EL2208")==0) || (strcmp(lab3[minggu][hari].kode,"EL2208")==0) || (strcmp(lss[minggu][hari].kode,"EL2208")==0) || (strcmp(lab1[minggu][hari].kode,"EB2200")==0) || (strcmp(lab2[minggu][hari].kode,"EB2200")==0) || (strcmp(lab3[minggu][hari].kode,"EB2200")==0) || (strcmp(lss[minggu][hari].kode,"EB2200")==0))
            {
                return 1;
            }
            else
            {
                printf("Jadwal Asisten Praktikum Kiki tidak sesuai (tidak ada rombongan EL2208 maupun EB2200)\n");
                return 0;
            }
        }
        else
        {
            printf("Jadwal Asisten Praktikum Kiki tidak sesuai (Kiki berhalangan hari Kamis)\n");
            return 0;
        }
    }
    else if (initial == 'L')
    {
        if ((strcmp(lab1[minggu][hari].kode,"EL2208")==0) || (strcmp(lab2[minggu][hari].kode,"EL2208")==0) || (strcmp(lab3[minggu][hari].kode,"EL2208")==0) || (strcmp(lss[minggu][hari].kode,"EL2208")==0))
        {
            return 1;
        }
        else
        {
            printf("Jadwal Asisten Praktikum Luis tidak sesuai (tidak ada rombongan EL2208)\n");
            return 0;
        }
    }
    else if (initial == 'M')
    {
        if ((hari != 2) && (hari != 3))
        {
            if ((strcmp(lab1[minggu][hari].kode,"EL2208")==0) || (strcmp(lab2[minggu][hari].kode,"EL2208")==0) || (strcmp(lab3[minggu][hari].kode,"EL2208")==0) || (strcmp(lss[minggu][hari].kode,"EL2208")==0))
            {
                return 1;
            }
            else
            {
                printf("Jadwal Asisten Praktikum Mini tidak sesuai (tidak ada rombongan EL2208)\n");
                return 0;
            }
        }
        else
        {
            printf("Jadwal Asisten Praktikum Joko tidak sesuai (Mini berhalangan hari Rabu & Kamis)\n");
            return 0;
        }
    }
    else if (initial == 'N')
    {
        if (hari != 1)
        {
            if ((strcmp(lab1[minggu][hari].kode,"EL2208")==0) || (strcmp(lab2[minggu][hari].kode,"EL2208")==0) || (strcmp(lab3[minggu][hari].kode,"EL2208")==0) || (strcmp(lss[minggu][hari].kode,"EL2208")==0) || (strcmp(lab1[minggu][hari].kode,"EB2200")==0) || (strcmp(lab2[minggu][hari].kode,"EB2200")==0) || (strcmp(lab3[minggu][hari].kode,"EB2200")==0) || (strcmp(lss[minggu][hari].kode,"EB2200")==0))
            {
                return 1;
            }
            else
            {
                printf("Jadwal Asisten Praktikum Nina tidak sesuai (tidak ada rombongan EL2208 maupun EB2200)\n");
                return 0;
            }
        }
        else
        {
            printf("Jadwal Asisten Praktikum Nina tidak sesuai (Nina berhalangan hari Selasa)\n");
            return 0;
        }
    }
}
