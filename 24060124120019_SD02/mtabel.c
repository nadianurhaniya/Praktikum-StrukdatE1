#include <stdio.h>
#include "tabel.h"

/* Program   : mtabel.c */
/* Deskripsi : file driver ADT Tabel Integer */
/* NIM/Nama  : 24060124120019 / Nadia Azura Nurhaniya */
/* Tanggal   : 12 September 2025 */

int main(){
    /*Kamus Lokal*/
    Tabel T1, T2, T3;
    int pos;
    char x;

    /* Algoritma*/
    printf("=====================================\n");
    printf("       PROGRAM UJI ADT TABEL         \n");
    printf("=====================================\n");

    /*1. createTable*/
    printf("\n[1] createTable\n");
    createTable(&T1);
    printf("Isi T1 setelah createTable: ");
    printTable(T1);

    /*2. addXTable*/
    printf("\n[2] addXTable\n");
    addXTable(&T1, 'A');
    addXTable(&T1, 'B');
    addXTable(&T1, 'C');
    printf("Isi T1 setelah AddXTable(A,B,C): ");
    viewTable(T1);

    /*3. delXTable*/
    printf("\n[3] delXTable\n");
    delXTable(&T1, 'B');
    printf("Isi T1 setelah DelXTable(B): ");
    viewTable(T1);

    /* 4. Populate Table */
    printf("\n[4] populateTable\n");
    populateTable(&T1, 5);
    printf("Isi T1 setelah populate 5 elemen: ");
    viewTable(T1);

    /* 5. addUniqueXTable */
    printf("\n[5] addUniqueXTable\n");  
    addUniqueXTable(&T1, 'Q');   
    printf("Isi T1 setelah AddUniqueXTable(Q): ");
    viewTable(T1);

    /*6. searchX*/
    printf("\n[6] searchX\n");
    searchX(T1, 'Q', &pos);
    if (pos != -999)
        printf("Huruf Q ditemukan di posisi ke-%d\n", pos);
    else
        printf("Huruf Q tidak ditemukan dalam T1\n");

    /*7. countX & countVocal*/
    printf("\n[7] countX dan countVocal\n");
    printf("Jumlah huruf 'A' = %d\n", countX(T1, 'A'));
    printf("Jumlah huruf vokal = %d\n", countVocal(T1));

    /*8. delTable*/
    printf("\n[8] delTable\n");
    delTable(&T1, 2);
    printf("Isi T1 setelah hapus elemen indeks ke-2: ");
    viewTable(T1);

    /*9. delAllXTable*/
    printf("\n[9] delAllXTable\n");
    delAllXTable(&T1, 'A');
    printf("Isi T1 setelah hapus semua huruf 'A': ");
    viewTable(T1);

    /*10. Modus*/
    printf("\n[10] Modus\n");
    printf("Modus dari T1 = %c\n", Modus(T1));

    /*11. inverseTable*/
    printf("\n[11] inverseTable\n");
    T2 = getInverseTable(T1);
    printf("Isi T2 (hasil getInverseTable dari T1): ");
    viewTable(T2);

    inverseTable(&T1);
    printf("Isi T1 setelah inverseTable: ");
    viewTable(T1);

    /*12. sortAsc & sortDesc*/
    printf("\n[12] sortAsc dan sortDesc\n");
    sortAsc(&T1);
    printf("Isi T1 setelah sortAsc: ");
    viewTable(T1);

    sortDesc(&T1);
    printf("Isi T1 setelah sortDesc: ");
    viewTable(T1);

    /*13. IsEqualTable*/
    printf("\n[13] IsEqualTable\n");
    createTable(&T3);
    addXTable(&T3, 'X');
    addXTable(&T3, 'Y');
    printf("Isi T3: ");
    viewTable(T3);
    printf("Apakah T1 = T3 ? %s\n", isEqualTable(T1, T3) ? "Ya" : "Tidak");

    printf("\n=====================================\n");
    printf("     UJI ADT TABEL SELESAI           \n");
    printf("=====================================\n");

    return 0;
}
