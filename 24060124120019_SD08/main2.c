/* File : main.c */
/* Deskripsi : aplikasi driver ADT list berkait SIRKULAR, representasi fisik pointer */
/* NIM & Nama : 24060124120019 - Nadia Azura Nurhaniya */
/* Tanggal : 14 November 2025 */

#include <stdio.h>
#include <stdlib.h>
#include "list2.h"

int main() {
    //kamus lokal
    List2 L, L1, L2, L3, L4;
    infotype V;
    address A;
    char X;

    //algoritma
    //aplikasi CreateList dan IsEmptyList
    CreateList(&L);
    if (IsEmptyList(L)) {
        printf("List kosong\n");
    } else {
        printf("List tidak kosong\n");
    }

    //aplikasi InsertVFirst dan PrintList
    InsertVFirst(&L, 'C');
    InsertVFirst(&L, 'B');
    InsertVFirst(&L, 'A');
    printf("\nIsi List setelah InsertVFirst: ");
    PrintList(L);

    //aplikasi InsertVLast
    printf("\n");
    InsertVLast(&L, 'D');
    InsertVLast(&L, 'E');
    printf("\nIsi List setelah InsertVLast:");
    PrintList(L);

    //aplikasi NbElm
    printf("\n");
    printf("\nBanyak elemen dalam List: %d\n", NbElm(L));

    //aplikasi DeleteVFirst
    DeleteVFirst(&L, &V);
    printf("\nElemen yang dihapus dengan DeleteVFirst: %c\n", V);
    printf("Isi List setelah DeleteVFirst:");
    PrintList(L);

    //aplikasi DeleteVLast
    printf("\n");
    DeleteVLast(&L, &V);
    printf("\nElemen yang dihapus dengan DeleteVLast: %c\n", V);
    printf("Isi List setelah DeleteVLast:");
    PrintList(L);

    //aplikasi DeleteX
    printf("\n");
    DeleteX(&L, 'C');
    printf("\nIsi List setelah DeleteX('C'):");
    PrintList(L);

    //aplikasi SearchX
    printf("\n");
    SearchX(L, 'B', &A);
    if (A != NIL) {
        printf("\nElemen 'B' ditemukan di alamat: %p\n", (void*)A);
    } else {
        printf("\nElemen 'B' tidak ditemukan dalam List\n");
    }

    SearchX(L, 'X', &A);
    if (A != NIL) {
        printf("\nElemen 'X' ditemukan di alamat: %p\n", (void*)A);
    } else {
        printf("\nElemen 'X' tidak ditemukan dalam List\n");
    }

    //aplikasi UpdateX
    printf("\nMengupdate elemen 'B' menjadi 'Z'\n");
    printf("Isi List sebelum UpdateX:");
    PrintList(L);
    UpdateX(&L, 'B', 'Z');
    printf("\nIsi List setelah UpdateX:");
    PrintList(L);

    //aplikasi Invers
    printf("\n");
    printf("\nIsi List sebelum Invers:");
    PrintList(L);
    Invers(&L);
    printf("\nIsi List setelah Invers:");
    PrintList(L);

    //aplikasi CountX
    printf("\n");
    InsertVFirst(&L, 'A');
    InsertVFirst(&L, 'A');
    InsertVLast(&L, 'A');
    PrintList(L);
    X = 'A';
    printf("\nJumlah kemunculan '%c' dalam List: %d", 'A', CountX(L, 'A'));

    //aplikasi FrekuensiX
    printf("\n");
    PrintList(L);
    X = 'A';
    printf("\nFrekuensi kemunculan '%c' dalam List: %.2f", 'A', FrekuensiX(L, 'A'));
    
    //aplikasi CountVocal
    printf("\n");
    InsertVLast(&L, 'I');
    InsertVLast(&L, 'U');
    PrintList(L);
    printf("\nJumlah huruf vokal dalam List: %d", CountVocal(L));

    //aplikasi CountNG
    printf("\n");
    InsertVLast(&L, 'N');
    InsertVLast(&L, 'G');
    PrintList(L);
    printf("\nJumlah kemunculan 'N' yang diikuti 'G' dalam List: %d", CountNG(L));

    //aplikasi InsertVAfterX
    printf("\n");
    X = 'Z';
    printf("\nIsi List sebelum InsertVAfterX '%c','Y':", X);
    PrintList(L);
    InsertVAfterX(&L, X, 'Y');
    printf("\nIsi List setelah InsertVAfterX '%c','Y':", X);
    PrintList(L);

    //aplikasi InsertVBeforeX
    printf("\n");
    X = 'Y';
    printf("\nIsi List sebelum InsertVBeforeX '%c','W':", X);
    PrintList(L);
    InsertVBeforeX(&L, X, 'W');
    printf("\nIsi List setelah InsertVBeforeX '%c','W':", X);
    PrintList(L);

    //aplikasi DeleteVAfterX
    printf("\n");
    X = 'W';
    printf("\nIsi List sebelum DeleteVAfterX '%c':", X);
    PrintList(L);
    DeleteVAfterX(&L, X, &V);
    printf("\nElemen yang dihapus dengan DeleteVAfterX setelah '%c': %c", X, V);
    printf("\nIsi List setelah DeleteVAfterX '%c':", X);
    PrintList(L);

    //aplikasi DeleteVBeforeX
    printf("\n");
    X = 'D';
    printf("\nIsi List sebelum DeleteVBeforeX '%c':", X);
    PrintList(L);
    DeleteVBeforeX(&L, X, &V);
    printf("\nElemen yang dihapus dengan DeleteVBeforeX sebelum '%c': %c", X, V);
    printf("\nIsi List setelah DeleteVBeforeX '%c':", X);
    PrintList(L);

    //aplikasi DeleteAllX
    printf("\n");
    X = 'A';
    printf("\nIsi List sebelum DeleteAllX '%c':", X);
    PrintList(L);
    DeleteAllX(&L, X);
    printf("\nIsi List setelah DeleteAllX '%c':", X);
    PrintList(L);

    //aplikasi SearchAllX
    printf("\n");
    X = 'A';
    InsertVFirst(&L, 'A');
    InsertVLast(&L, 'A');
    printf("\nIsi List untuk SearchAllX '%c':", X);
    PrintList(L);
    SearchAllX(L, X);

    //aplikasi MaxMember
    PrintList(L);
    printf("\nMaxMember dalam List L = %d\n", MaxMember(L));;

    //aplikasi Modus
    PrintList(L);
    printf("\nModus dalam List: %c\n", Modus(L));

    //aplikasi ConcatList
    printf("\n");
    CreateList(&L2);
    InsertVLast(&L2, 'X');
    InsertVLast(&L2, 'Y');
    InsertVLast(&L2, 'Z');
    printf("Isi List pertama:");
    PrintList(L);
    printf("\nIsi List kedua:");
    PrintList(L2);
    ConcatList(L, L2, &L3);
    printf("\nIsi List setelah ConcatList:");
    PrintList(L3);

    //aplikasi SplitList
    printf("\n");
    printf("\nIsi List sebelum SplitList:");
    PrintList(L3);
    SplitList(L3, &L1, &L2);
    printf("\nIsi List pertama setelah SplitList:");
    PrintList(L1);
    printf("\nIsi List kedua setelah SplitList:");
    PrintList(L2);

    //aplikasi CopyList
    printf("\n");
    printf("\nIsi List pertama untuk CopyList:");
    PrintList(L1);
    CopyList(L1, &L4);
    printf("\nIsi List hasil CopyList dari List pertama:");
    PrintList(L4);

    return 0;
}