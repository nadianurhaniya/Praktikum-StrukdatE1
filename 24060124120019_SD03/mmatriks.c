/* Program   : mmatriks.c */
/* Deskripsi : driver ADT matriks integer */
/* NIM/Nama  : 24060124120019/Nadia Azura Nurhaniya */
/* Tanggal   : 19 September 2025 */
/***********************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "matriks.h"

int main(){
    Matriks M1, M2, MHasil, Minput, K;
    int row, col;

    srand(time(NULL)); 
    printf("=== PROGRAM UJI ADT MATRIKS ===\n\n");

    /* Uji init */
    printf("Inisialisasi matriks M1\n");
    initMatriks(&M1);
    printf("isEmptyMatriks(M1) = %d\n\n", isEmptyMatriks(M1));

    /* Uji isi manual (addX) */
    printf("Isi M1 dengan addX\n");
    addX(&M1, 5, 1, 1);
    addX(&M1, 3, 1, 2);
    addX(&M1, 7, 2, 1);
    addX(&M1, 9, 2, 2);
    printMatriks(M1);
    printf("\n");

    /* Uji delX */
    printf("Hapus nilai 5 dari M1\n");
    delX(&M1, 5);
    printMatriks(M1);
    printf("\n");

    /* Uji isiMatriksRandom */
    printf("Isi M2 random 3x3\n");
    isiMatriksRandom(&M2, 3, 3);
    printMatriks(M2);
    printf("\n");

    /* Uji isiMatriksIdentitas */
    printf("Matriks identitas 3x3:\n");
    isiMatriksIdentitas(&MHasil, 3);
    printMatriks(MHasil);
    printf("\n");
 
    /* Uji operasi tambah (addMatriks) */
    printf("Hasil M2 + M2:\n");
    MHasil = addMatriks(M2, M2);
    printMatriks(MHasil);
    printf("\n");

    /* Uji operasi kurang (subMatriks) */
    printf("Hasil M1 - M1:\n");
    MHasil = subMatriks(M2, M2);
    printMatriks(MHasil);
    printf("\n");

    /* Uji operasi kali (kaliMatriks) */
    printf("Hasil M2 x M2:\n");
    MHasil = kaliMatriks(M2, M2);
    printMatriks(MHasil);
    printf("\n");

    /* Uji kali skalar (kaliSkalarMatriks) */
    printf("Hasil 2 * M2:\n");
    MHasil = kaliSkalarMatriks(M2, 2);
    printMatriks(MHasil);
    printf("\n");

    /* Uji transpose (getTransposeMatriks) */
    printf("Transpose M1:\n");
    MHasil = getTransposeMatriks(M2);
    printMatriks(MHasil);
    printf("\n");

    /* Uji padding (addPadding) */
    printf("M1 dengan padding 1:\n");
    MHasil = addPadding(M1, 1);
    printMatriks(MHasil);
    printf("\n");

    /* Uji maxPooling */
    printf("Max Pooling M2 size=2:\n");
    MHasil = maxPooling(M2, 2);
    printMatriks(MHasil);
    printf("\n");

    /* Uji avgPooling */
    printf("Average Pooling M2 size=2:\n");
    MHasil = avgPooling(M2, 2);
    printMatriks(MHasil);
    printf("\n");

    /* Uji konvolusi */
    printf("Konvolusi M2 dengan kernel identitas 2x2:\n");
    isiMatriksIdentitas(&K, 2);
    MHasil = conv(M2, K);
    printMatriks(MHasil);
    printf("\n");

    /* Uji searchX */
    printf("Cari nilai 9 di M1:\n");
    searchX(M1, 9, &row, &col);
    if(row != -999){
        printf("Ketemu di baris %d kolom %d\n", row, col);
    }else{
        printf("Tidak ditemukan!\n");
    }
    printf("\n");

    /* Uji countX */
    printf("Hitung jumlah angka 9 di M1: %d\n\n", countX(M1, 9));

    /* Uji populateMatriks (input manual) */
    printf("=== Uji populateMatriks ===\n");
    populateMatriks(&Minput, 2, 2);
    printf("Isi matriks hasil input:\n");
    printMatriks(Minput);
    printf("\n");

    /* Uji viewMatriks */
    printf("=== Uji viewMatriks ===\n");
    viewMatriks(Minput);
    printf("\n");

    return 0;
}