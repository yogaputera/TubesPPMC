#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char kode[7];
    char rombongan[3];
    char nama [3];
} praktikum;

int main()
{
    praktikum lab1[12][5],lab2[12][5],lab3[12][5],labLSS[12][5];
    char namafile1[100],namafile2[100];
    int i,j;
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
            strcpy(labLSS[i][j].kode," ");
            strcpy(labLSS[i][j].rombongan," ");
            strcpy(labLSS[i][j].nama," ");
        }
    }
    gets(namafile1);
    scanf("%c",&lab1[0][0].nama[0]);
    scanf("\n%c",&lab1[0][0].nama[1]);
    scanf("\n%c",&lab2[1][3].nama[0]);
    scanf("\n%c",&lab2[1][3].nama[1]);
    SaveFileAsisten(namafile1,lab1,lab2,lab3,labLSS);
    LoadFileJadwal(namafile1,&lab1,&lab2,&lab3,&labLSS);
    printf("%c,%c\n",lab1[0][0].nama[0],lab1[0][0].nama[1]);
    printf("%c,%c\n",lab2[1][3].nama[0],lab2[1][3].nama[1]);
    /*printf("%s-%s\n",lab2[0][0].kode,lab2[0][0].rombongan);
    printf("%s-%s\n",lab3[0][0].kode,lab3[0][0].rombongan);
    printf("%s-%s\n",labLSS[11][4].kode,labLSS[11][4].rombongan);
    printf("%s-%s\n",lab2[3][3].kode,lab2[3][3].rombongan);*/
    return(0);
}

void SaveFileJadwal (char namafile[],praktikum lab1[12][5],praktikum lab2[12][5],praktikum lab3[12][5],praktikum labLSS[12][5])

//sebuah fungsi untuk menyimpan element array ke sebuah file eksternal dengan file ekstension .csv
{
    int mgg,hr; //variabel iterator untuk menunjukkan minggu dan hari
    // hari senin =1 selasa = 2 rabu = 3 kamis = 4 jumat = 5
    FILE *fp;
    namafile=strcat(namafile,".csv"); // menambahkan ekstensi ke namafile
    fp = fopen(namafile,"w+"); //memanipulasi file eksternal
    fprintf(fp,"%s;%s;%s;%s;%s;%s\n","Ruang" ,"Praktikum","LAB1","LAB2","LAB3","LSS"); //memasukkan layout file eksternal
    fprintf(fp,"%s;%s\n","Minggu","Hari");
    for (mgg = 0;mgg < 12;mgg ++) //looping untuk memasukan data ke file eksternal dengan mengambil element kode dan rombongan pada tipe bentukan praktikum
    {
        for(hr=0;hr<=4;hr ++)
        { //kondisi dibagi per hari untuk menyesuaikan permisalan angka hari ke string hari
            if (hr==0)
            {
                fprintf(fp,"%d;%s;%s-%s;%s-%s;%s-%s;%s-%s\n",mgg+3,"Senin",lab1[mgg][hr].kode,lab1[mgg][hr].rombongan,lab2[mgg][hr].kode,lab2[mgg][hr].rombongan,lab3[mgg][hr].kode,lab3[mgg][hr].rombongan,labLSS[mgg][hr].kode,labLSS[mgg][hr].rombongan);
            } else if (hr == 1)
            {
                fprintf(fp,"%d;%s;%s-%s;%s-%s;%s-%s;%s-%s\n",mgg+3,"Selasa",lab1[mgg][hr].kode,lab1[mgg][hr].rombongan,lab2[mgg][hr].kode,lab2[mgg][hr].rombongan,lab3[mgg][hr].kode,lab3[mgg][hr].rombongan,labLSS[mgg][hr].kode,labLSS[mgg][hr].rombongan);
            } else if (hr == 2)
            {
                fprintf(fp,"%d;%s;%s-%s;%s-%s;%s-%s;%s-%s\n",mgg+3,"Rabu",lab1[mgg][hr].kode,lab1[mgg][hr].rombongan,lab2[mgg][hr].kode,lab2[mgg][hr].rombongan,lab3[mgg][hr].kode,lab3[mgg][hr].rombongan,labLSS[mgg][hr].kode,labLSS[mgg][hr].rombongan);
            } else if (hr == 3)
            {
                fprintf(fp,"%d;%s;%s-%s;%s-%s;%s-%s;%s-%s\n",mgg+3,"Kamis",lab1[mgg][hr].kode,lab1[mgg][hr].rombongan,lab2[mgg][hr].kode,lab2[mgg][hr].rombongan,lab3[mgg][hr].kode,lab3[mgg][hr].rombongan,labLSS[mgg][hr].kode,labLSS[mgg][hr].rombongan);
            } else //hr == 4
            {
                fprintf(fp,"%d;%s;%s-%s;%s-%s;%s-%s;%s-%s\n",mgg+3,"Jumat",lab1[mgg][hr].kode,lab1[mgg][hr].rombongan,lab2[mgg][hr].kode,lab2[mgg][hr].rombongan,lab3[mgg][hr].kode,lab3[mgg][hr].rombongan,labLSS[mgg][hr].kode,labLSS[mgg][hr].rombongan);
            }
        }
    }
    fclose(fp); //menutup file eksternal
}

void SaveFileAsisten (char namafile[],praktikum lab1[12][5],praktikum lab2[12][5],praktikum lab3[12][5],praktikum labLSS[12][5])
//sebuah fungsi untuk memasukkan element array ke file eksternal .csv
{
    int mgg,hr; //variabel untuk iterasi hari dan minggu
    FILE *fp;
    namafile=strcat(namafile,".csv"); //menambahkan ekstensi file eksternal
    fp = fopen(namafile,"w+");
    fprintf(fp,"%s;%s;%s;%s;%s\n","Ruang","Praktikum","LAB1","LAB2","LAB3","LSS");
    fprintf(fp,"%s;%s\n","Minggu","Hari");
    for (mgg = 0;mgg < 12;mgg ++)
    { //looping untuk memasukan data ke file eksternal dari array of praktikum pada element nama
        for(hr=0;hr<=4;hr ++)
        { //kondisi per hari untuk mengubah dari angka ke hari
            if (hr==0) //senin
            {
                fprintf(fp,"%d;%s;%c,%c;%c,%c;%c,%c;%c,%c\n",mgg+3,"Senin",lab1[mgg][hr].nama[0],lab1[mgg][hr].nama[1],lab2[mgg][hr].nama[0],lab2[mgg][hr].nama[1],lab3[mgg][hr].nama[0],lab3[mgg][hr].nama[1],labLSS[mgg][hr].nama[0],labLSS[mgg][hr].nama[1]);
            } else if (hr == 1) //selasa
            {
                fprintf(fp,"%d;%s;%c,%c;%c,%c;%c,%c;%c,%c\n",mgg+3,"Selasa",lab1[mgg][hr].nama[0],lab1[mgg][hr].nama[1],lab2[mgg][hr].nama[0],lab2[mgg][hr].nama[1],lab3[mgg][hr].nama[0],lab3[mgg][hr].nama[1],labLSS[mgg][hr].nama[0],labLSS[mgg][hr].nama[1]);
            } else if (hr == 2) //rabu
            {
                fprintf(fp,"%d;%s;%c,%c;%c,%c;%c,%c;%c,%c\n",mgg+3,"Rabu",lab1[mgg][hr].nama[0],lab1[mgg][hr].nama[1],lab2[mgg][hr].nama[0],lab2[mgg][hr].nama[1],lab3[mgg][hr].nama[0],lab3[mgg][hr].nama[1],labLSS[mgg][hr].nama[0],labLSS[mgg][hr].nama[1]);
            } else if (hr == 3) //kamis
            {
                fprintf(fp,"%d;%s;%c,%c;%c,%c;%c,%c;%c,%c\n",mgg+3,"Kamis",lab1[mgg][hr].nama[0],lab1[mgg][hr].nama[1],lab2[mgg][hr].nama[0],lab2[mgg][hr].nama[1],lab3[mgg][hr].nama[0],lab3[mgg][hr].nama[1],labLSS[mgg][hr].nama[0],labLSS[mgg][hr].nama[1]);
            } else // hr = 4 jumat
            {
                fprintf(fp,"%d;%s;%c,%c;%c,%c;%c,%c;%c,%c\n",mgg+3,"Jumat",lab1[mgg][hr].nama[0],lab1[mgg][hr].nama[1],lab2[mgg][hr].nama[0],lab2[mgg][hr].nama[1],lab3[mgg][hr].nama[0],lab3[mgg][hr].nama[1],labLSS[mgg][hr].nama[0],labLSS[mgg][hr].nama[1]);
            }
        }
    }
    fclose(fp); //menutup file eksternal
}

void LoadFileJadwal (char namafile[],praktikum lab1[12][5],praktikum lab2[12][5],praktikum lab3[12][5],praktikum labLSS[12][5])
// menerima masukkan nama file lalu dimasukkan ke array of praktikum
{
    FILE *fp;
    namafile=strcat(namafile,".csv"); //menambahkan ekstensi ke nama file
    fp = fopen(namafile,"r"); //membaca file eksternal
    //variabel untuk menampung data yang tidak harus dimasukkan ke array
    char temp[60];
    char temph[8];
    int tempm,mgg,hr;
    fgets(&temp,50,fp);//membaca header layout file baris 1
    fgets(&temp,50,fp);//membaca header layout file baris 2
    for (mgg=0;mgg<=11;mgg++) //looping untuk membaca data yang dibutuhkan ke array of praktikum pada elemen kode dan rombongan
    {
        for (hr=0;hr<=4;hr++)
        {
            fscanf(fp,"%d;%[^;];%[^-]-%[^;];%[^-]-%[^;];%[^-]-%[^;];%[^-]-%[^\n]\n",&tempm,&temph,&lab1[mgg][hr].kode,&lab1[mgg][hr].rombongan,&lab2[mgg][hr].kode,&lab2[mgg][hr].rombongan,&lab3[mgg][hr].kode,&lab3[mgg][hr].rombongan,&labLSS[mgg][hr].kode,&labLSS[mgg][hr].rombongan);
        }
    }
    fclose(fp);

}
void LoadFileAsisten (char namafile[],praktikum lab1[12][5],praktikum lab2[12][5],praktikum lab3[12][5],praktikum labLSS[12][5])
//menerima masukkan nama file lalu membaca file eksternal dan dimasukkan ke array of praktikum
{
    FILE *fp;
    namafile=strcat(namafile,".csv"); //menambahkan ekstensi file
    fp = fopen(namafile,"r"); //membaca file eksternal
    //variabel untuk menampung sementara layout yang tidak dimasukkan ke array
    char temp[60];
    char temph[8];
    int tempm,mgg,hr;
    //mambaca layout yang tidak dimasukkan ke array
    fgets(&temp,50,fp);
    fgets(&temp,50,fp);
    for (mgg=0;mgg<=11;mgg++) //looping untuk membaca dari file eksternal dimasukkan ke array element nama ke
    {
        for (hr=0;hr<=4;hr++)
        {
            fscanf(fp,"%d;%s;%c,%c;%c,%c;%c,%c;%c,%c\n",&tempm,&temph,&lab1[mgg][hr].nama[0],&lab1[mgg][hr].nama[1],&lab2[mgg][hr].nama[0],&lab2[mgg][hr].nama[1],&lab3[mgg][hr].nama[0],&lab3[mgg][hr].nama[1],&labLSS[mgg][hr].nama[0],&labLSS[mgg][hr].nama[1]);
        }
    }
    fclose(fp); //menutup file eksternal
}
