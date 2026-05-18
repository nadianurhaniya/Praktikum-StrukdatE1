#ifndef matriks_c
#define matriks_c

/* Program   : matriks.c */
/* Deskripsi : file BODY modul matriks integer */
/* NIM/Nama  : 24060124120019/Nadia Azura Nurhaniya */
/* Tanggal   : 19 September 2025 */
/***********************************/

#include <stdio.h>
#include "matriks.h"
#include "boolean.h"
#include <stdlib.h>
#include <time.h>

/* include matriks.h & boolean.h */

/* KONSTRUKTOR */		
/* procedure initMatriks(output M: Matriks)
	{I.S.: - }
	{F.S.: Matriks M terdefinisi}
	{Proses mengisi elemen cell dengan -999, nbaris 0, nkolom 0} */
void initMatriks(Matriks *M){
    /*Kamus Lokal*/
    int i, j;

    /*Algoritma*/
    for (i = 1; i<= 10; i++){
        for (j = 1; j<= 10; j++){
            (*M).cell[i][j] = -999;
        }
    }
    (*M).nbaris = 0;
    (*M).nkolom = 0;
}

/* SELEKTOR */
/* function getNBaris(M: Matriks) -> integer
	{mengembalikan banyak baris matriks M yang terisi } */
int getNBaris(Matriks M){
    return M.nbaris;
}

/* function getNKolom(M: Matriks) -> integer
	{mengembalikan banyak kolom matriks M yang terisi } */
int getNKolom(Matriks M){
    return M.nkolom;
}

/* PREDIKAT */
/* function isEmptyMatriks(M: Matriks) -> boolean
	{mengembalikan True jika matriks M kosong } */
boolean isEmptyMatriks(Matriks M){
    return getNBaris(M) == 0 && getNKolom(M) == 0;
}

/* function isFullMatriks(M: Matriks) -> boolean
	{mengembalikan True jika matriks M penuh } */
boolean isFullMatriks(Matriks M){
    return (M.nbaris == 10 && M.nkolom == 10);
}

/* MUTATOR */
/* procedure addX (input/output M:Matriks, input X:integer, row:integer, col:integer)
	{I.S.: M terdefinisi, X terdefinisi }
	{F.S.: isi M.cell bertambah 1 elemen pada baris ke-row dan kolom ke-col jika belum penuh}
	{Proses: mengisi elemen M.cell dengan nilai X} */
void addX (Matriks *M, int X, int row, int col){
    if(row >= 1 && col >= 1 && row <= 10 && col <= 10){
        (*M).cell[row][col] = X;
        if(row > (*M).nbaris) (*M).nbaris = row;
        if(col > (*M).nkolom) (*M).nkolom = col;
    }
}

/* procedure delX (input/output M:Matriks, input X:integer )
	{I.S.: M terdefinisi, X terdefinisi}
	{F.S.: elemen M.cell berkurang 1}
	{Proses: menghapus 1 elemen bernilai X dari M.cell*/
void delX (Matriks *M, int X){
     // kamus lokal
    int i, j;
    for (i = 1; i <= (*M).nbaris; i++) {
        for (j = 1; j <= (*M).nkolom; j++) {
            if ((*M).cell[i][j] == X) {
                (*M).cell[i][j] = 0; 
                return; 
            }
        }
    }
}
/* procedure isiMatriksRandom(input/output M: Matriks, input x: integer, input y: integer)
	{I.S.: M terdefinisi}
	{F.S.: M terisi dengan bilangan random sejumlah x baris dan y kolom, nbaris=x, nkolom=y}
	{proses: mengisi matriks dengan bilangan integer random dengan jumlah baris x dan kolom y} */
void isiMatriksRandom(Matriks *M, int x, int y){
    /*Kamus Lokal*/
    int i,j;
    (*M).nbaris = x;
    (*M).nkolom = y;

    /*Algoritma*/
    for (i = 1; i<=x; i++){
        for (j = 1; j<=y; j++){
            (*M).cell[i][j] = rand() % 100;
        }
    }

}

/* procedure isiMatriksIdentitas(input/output M: Matriks, input n: integer)
	{I.S.: M terdefinisi}
	{F.S.: M terisi dengan matriks identitas berukuran n x n, nbaris=nkolom=n}
	{proses: mengisi matriks dengan matriks identitas berukuran n x n} */
void isiMatriksIdentitas(Matriks *M, int n){
    /*Kamus Lokal*/
    int i,j;

    /*Algoritma*/
    (*M).nbaris = n;
    (*M).nkolom = n;

    for (i = 1; i<=n; i++){
        for (j = 1; j<=n; j++){
            if (i == j) (*M).cell[i][j] = 1;
            else (*M).cell[i][j] = 0;
        }
    }

}

/* OPERASI BACA/TULIS */
/* procedure populateMatriks(input/output M: Matriks, input x: integer, input y: integer)
{I.S.: M terdefinisi}
{F.S.: M terisi dengan inputan dari keybord sejumlah x baris dan y kolom, nbaris=x, nkolom=y}
{proses: mengisi matriks dengan meminta inputan dari keyboard dengan jumlah baris x dan kolom y} */
void populateMatriks(Matriks *M, int x, int y){
    /*Kamus Lokal*/
    int i, j, input;

    /*Algoritma*/
    (*M).nbaris = x;
    (*M).nkolom = y;

    for(i = 1; i<=x; i++){
        for(j = 1; j<=y; j++){
            printf("Masukkan elemen [%d][%d]: ", i, j);
            scanf("%d", &input);
            (*M).cell[i][j] = input;
        }
    }
}

/* procedure printMatriks(input M:Matriks)
	{I.S.: M terdefinisi}
	{F.S.: -}
	{Proses: menampilkan semua elemen M.cell ke layar} */
void printMatriks(Matriks M){
    /* Kamus Lokal */
    int i, j;
    
    /* Algoritma */
    for (i = 1; i <= getNBaris(M); i++){
        for (j = 1; j <= getNKolom(M); j++){
            printf("%d ", M.cell[i][j]);
        }
        printf("\n");
    }
}

/* procedure viewMatriks (input M:Matriks)
	{I.S.: M terdefinisi}
	{F.S.: -}
	{Proses: menampilkan elemen M.cell yang terisi ke layar} */
void viewMatriks(Matriks M){
    /* Kamus Lokal */
    int i, j;

    /* Algoritma */
    for (i = 1; i <= getNBaris(M); i++){
        for (j = 1; j <= getNKolom(M); j++){
            if (M.cell[i][j] != -999) {   
                printf("%d ", M.cell[i][j]);
            }
        }
        printf("\n");
    }
}

/* OPERASI ARITMATIKA */
/* function addMatriks(M1,M2: Matriks) -> Matriks
{mengembalikan hasil penjumlahan matriks M1 dengan M2} */
Matriks addMatriks(Matriks M1, Matriks M2){
    /*Kamus lokal*/
    int i, j, hasil;
    Matriks MHasil;

    /*Algoritma*/
    initMatriks(&MHasil);
    if (getNBaris(M1) == getNBaris(M2) && getNKolom(M1) == getNKolom(M2))
    {
        for (i = 1; i <= getNBaris(M1); i++)
        {
            for (j = 1; j <= getNKolom(M1); j++)
            {
                hasil = M1.cell[i][j] + M2.cell[i][j];
                addX(&MHasil, hasil, i, j);
            }
        }
    }
    return MHasil;

}

/* function subMatriks(M1,M2: Matriks) -> Matriks
{mengembalikan hasil pengurangan antara matriks M1 dengan M2} */
Matriks subMatriks(Matriks M1, Matriks M2){
    /*Kamus lokal*/
    int i, j, hasil;
    Matriks MHasil;

    /*Algoritma*/
    initMatriks(&MHasil);
    if (getNBaris(M1) == getNBaris(M2) && getNKolom(M1) == getNKolom(M2))
    {
        for (i = 1; i <= getNBaris(M1); i++)
        {
            for (j = 1; j <= getNKolom(M1); j++)
            {
                hasil = M1.cell[i][j] - M2.cell[i][j];
                addX(&MHasil, hasil, i, j);
            }
        }
    }
    return MHasil;
}

/* function kaliMatriks(M1,M2: Matriks) -> Matriks
{mengembalikan hasil perkalian antara matriks M1 dengan M2} */
Matriks kaliMatriks(Matriks M1, Matriks M2){
    /*Kamus lokal*/
    int i, j, k, hasil;
    Matriks MHasil;

    /*Algoritma*/
    initMatriks(&MHasil);
    if (getNKolom(M1) == getNBaris(M2))
    {
        for (i = 1; i <= getNBaris(M1); i++)
        {
            for (j = 1; j <= getNKolom(M2); j++)
            {
                hasil = 0;
                for (k = 1; k <= getNKolom(M1); k++)
                {
                    hasil = hasil + (M1.cell[i][k] * M2.cell[k][j]);
                }
                addX(&MHasil, hasil, i, j);
            }
        }
    }
    return MHasil;
}

/* function kaliSkalarMatriks(M: Matriks, x: integer) -> Matriks
{mengembalikan perkalian antara matriks M dengan nilai skalar x} */
Matriks kaliSkalarMatriks(Matriks M1, int x){
     /*Kamus lokal*/
    int i, j;
    Matriks MHasil;

    /*Algoritma*/
    initMatriks(&MHasil);
    for (i = 1; i <= getNBaris(M1); i++)
    {
        for (j = 1; j <= getNKolom(M1); j++)
        {
            if (M1.cell[i][j] != -999)  
            {
                addX(&MHasil, M1.cell[i][j] * x, i, j);
            }
        }
    }
    return MHasil;
}

/* OPERASI LAINNYA */
/* procedure transposeMatriks(input/output M: Matriks)
	{I.S.: M terdefinisi}
	{F.S.: Matriks M sudah ditukar susunan baris dan kolomnya (Transpose)}
	{proses: mengubah susunan cell matriks, M.cell[i,j] menjadi M.cell[j,i]} */
void transposeMatriks(Matriks *M){
    *M = getTransposeMatriks(*M);
}

/* function getTransposeMatriks(M: Matriks)
	{menghasilkan sebuah matriks yang merupakan hasil transpose dari matriks M} */
Matriks getTransposeMatriks(Matriks M){
    /*Kamus lokal*/
    int i, j;
    Matriks MHasil;

    /*Algoritma*/
    initMatriks(&MHasil);
    for (i = 1; i <= getNBaris(M); i++)
    {
        for (j = 1; j <= getNKolom(M); j++)
        {
            addX(&MHasil, M.cell[i][j], j, i);
        }
    }

    return MHasil;
}


/* function addPadding(M: Matriks, input n:integer)
	{menghasilkan matriks baru dari M yang ditambahkan padding 0 sesuai dengan ukuran padding n */
Matriks addPadding(Matriks M, int n){
    /*Kamus Lokal*/
	int i,j;
	Matriks MHasil;

	/*Algoritma*/
	initMatriks(&MHasil);
	for (i = 1; i <= getNBaris(M) + 2*n; i++){
		for (j = 1; j <= getNKolom(M) + 2*n; j++){
			if (i > n && i <= getNBaris(M) + n && j > n && j <= getNKolom(M) + n){
				addX(&MHasil, M.cell[i-n][j-n], i, j);
			}else{
				addX(&MHasil, 0, i, j);
			}
		}
	}
	return MHasil;
}

/* function maxPooling(M: Matriks, input size:integer)
	{menghasilkan matriks hasil max pooling matriks M dengan pool size = size  */
Matriks maxPooling(Matriks M, int size){
    /*Kamus Lokal*/
	int i,j,x,y,maxVal;
	Matriks MHasil;

	/*Algoritma*/
	initMatriks(&MHasil);
	for (i = 1; i <= getNBaris(M); i+=size){
		for (j = 1; j <= getNKolom(M); j+=size){
			maxVal = -9999;
			for (x = i; x < i + size; x++){
				for (y = j; y < j + size; y++){
					if (x <= getNBaris(M) && y <= getNKolom(M)){
						if (M.cell[x][y] > maxVal){
							maxVal = M.cell[x][y];
						}
					}
				}
			}
			addX(&MHasil, maxVal, (i-1)/size+1, (j-1)/size+1);
		}
	}
	return MHasil;
}

/* function avgPooling(M: Matriks, input size:integer)
	{menghasilkan matriks hasil average pooling matriks M dengan pool size = size  */
Matriks avgPooling(Matriks M, int size){
    /*Kamus Lokal*/
	int i,j,x,y,sum,count;
	Matriks MHasil;

	/* Algoritma */
	initMatriks(&MHasil);
	for (i = 1; i <= getNBaris(M); i+=size){
		for (j = 1; j <= getNKolom(M); j+=size){
			sum = 0;
			count = 0;
			for (x = i; x < i + size; x++){
				for(y = j; y < j + size; y++){
					if (x <= getNBaris(M) && y <= getNKolom(M)){
						sum += M.cell[x][y];
						count++;
					}
				}
			}
			if (count>0){
				addX(&MHasil, sum/count, (i-1)/size+1, (j-1)/size+1);
			}
		}
	}
	return MHasil;
}

/* function conv(M: Matriks, K:Matriks)
	{menghasilkan matriks hasil konvolusi matriks M dengan kernel K  */
Matriks conv(Matriks M, Matriks K){
    /*Kamus lokal*/
    int i, j, k, l, m, n, rowM, colM, rowK, colK, avg, sum, row, col;
    Matriks MHasil;

    /*Algoritma*/
    initMatriks(&MHasil);
    rowM = getNBaris(M);
    colM = getNKolom(M);
    rowK = getNBaris(K);
    colK = getNKolom(K);

    if (rowM >= rowK && colM > colK){
        for (i = 1; i <= rowM - rowK + 1; i++){
            for (j = 1; j <= colM - colK + 1; j++){
                sum = 0;
                for (k = 0; k < rowK; k++){
                    for (l = 0; l < colK; l++){
                        sum += M.cell[k + i][l + j] * K.cell[k + 1][k + 1];
                    }
                } addX(&MHasil, sum, i, j);
            }
        }
    }

    return MHasil;
}

/* OPERASI PENCARIAN*/
/* procedure searchX( input M:Matriks, input X: integer, output row: integer, output col: integer )
	{I.S.: M terdefinisi, X terdefinisi }
	{F.S.: row berisi indeks baris dan col berisi indeks kolom ketemu X di M.cell, atau -999 jika tidak ketemu}
	{Proses: mencari elemen bernilai X dalam M.cell} */
void searchX(Matriks M, int X, int *row, int *col){
    /*Kamus Lokal*/
    int i,j;

    /*Algoritma*/
    for (i = 1; i<=M.nbaris; i++){
        for(j = 1; j<=M.nkolom; j++){
            if(M.cell[i][j] == X){
                *row = i;
                *col = j;
                return;
            }
        }
    }
    *row = -999;
    *col = -999;
}

/* function countX (M:Matriks, X: integer) -> integer
	{mengembalikan banyaknya elemen bernilai X dalam M.cell} */
int countX (Matriks M, int X){
    /*kamus Lokal*/
    int i,j,count=0;

    /*Algoritma*/
    for (i = 1; i<=M.nbaris; i++){
        for (j = 1; j<=M.nkolom; j++){
            if(M.cell[i][j] == X){
                count++;
            }
        }
    }
    return count;
}

#endif