/* File : main3.c */
/* Deskripsi : aplikasi driver ADT list berkait Ganda, representasi fisik pointer */
/* NIM & Nama : 24060124120019 - Nadia Azura Nurhaniya */
/* Tanggal : 21 November 2025 */

#include "stdio.h"
#include "list3.h"

int main() {
    //kamus
    List3 Senarai, L, L1, L2, L3, L4, L5;
    infotype V;
    address P;

    //algoritma
    CreateList(&Senarai);

    //aplikasi InsertVFirst dan InsertVLast
    InsertVFirst(&Senarai, 'P');
    InsertVFirst(&Senarai, 'I');
    InsertVFirst(&Senarai, 'D');
    InsertVFirst(&Senarai, 'N');
    InsertVFirst(&Senarai, 'U');
    printf("Isi list setelah InsertVFirst:");
    PrintList(Senarai);

    InsertVLast(&Senarai, 'J');
    InsertVLast(&Senarai, 'A');
    InsertVLast(&Senarai, 'Y');
    InsertVLast(&Senarai, 'A');
    printf("\n\nIsi list setelah InsertVLast:");
    PrintList(Senarai);

    //aplikasi NbElm
    printf("\n\nBanyaknya elemen dalam list: %d\n", NbElm(Senarai));

    //aplikasi DeleteVFirst 
    DeleteVFirst(&Senarai, &V);
    printf("\nIsi list setelah DeleteVFirst (menghapus '%c'):", V);
    PrintList(Senarai);

    //aplikasi DeleteVLast
    DeleteVLast(&Senarai, &V);
    printf("\n\nIsi list setelah DeleteVLast (menghapus '%c'):", V);
    PrintList(Senarai);

    //aplikasi DeleteX
    DeleteX(&Senarai, 'A');
    printf("\n\nIsi list setelah DeleteX (menghapus elemen 'A'):");
    PrintList(Senarai);

    //aplikasi SearchX
    SearchX(Senarai, 'Y', &P);
    if (P != NIL) {
        printf("\n\nElemen 'Y' ditemukan di alamat: %p", P);
    } else {
        printf("\n\nElemen 'Y' tidak ditemukan.");
    }

    SearchX(Senarai, 'Z', &P);
    if (P != NIL) {
        printf("\nElemen 'Z' ditemukan di alamat: %p", P);
    } else {
        printf("\nElemen 'Z' tidak ditemukan.");
    }

    //aplikasi updateX
    CreateList(&L);
    InsertVFirst(&L, 'A');
    InsertVLast(&L, 'B');
    InsertVLast(&L, 'C');
    InsertVLast(&L, 'H');
    printf("\n\nIsi list L sebelum UpdateX:");
    PrintList(L);
    UpdateX(&L, 'C', 'A');
    printf("\nIsi list setelah UpdateX (mengganti 'C' menjadi 'A'):");
    PrintList(L);

    //aplikasi Invers
    CreateList(&L1);
    InsertVFirst(&L1, 'K');
    InsertVLast(&L1, 'A');
    InsertVLast(&L1, 'S');
    InsertVLast(&L1, 'U');
    InsertVLast(&L1, 'R');
    printf("\n\nIsi list sebelum Invers:");
    PrintList(L1);
    printf("\nIsi list setelah Invers:");
    Invers(&L1);
    PrintList(L1);

    //aplikasi InsertVAfterX
    InsertVAfterX(&Senarai, 'Y', 'A');
    printf("\n\nIsi list setelah InsertVAfterX (menyisipkan 'A' setelah 'Y'):");
    PrintList(Senarai);
    InsertVAfterX(&Senarai, 'J', 'A');
    printf("\nIsi list setelah InsertVAfterX (menyisipkan 'A' setelah 'J'):");
    PrintList(Senarai);

    //aplikasi insertVBeforeX
    InsertVBeforeX(&Senarai, 'N', 'U');
    printf("\n\nIsi list setelah InsertVBeforeX (menyisipkan 'U' sebelum 'N'):");
    PrintList(Senarai);

    //aplikasi DeleteVAfterX
    DeleteVAfterX(&Senarai, 'P', &V);
    printf("\n\nIsi list setelah DeleteVAfterX (menghapus elemen setelah 'P' yaitu '%c'):", V);
    PrintList(Senarai);

    //aplikasi DeleteVBeforeX
    DeleteVBeforeX(&Senarai, 'I', &V);
    printf("\n\nIsi list setelah DeleteVBeforeX (menghapus elemen sebelum 'I' yaitu '%c'):", V);
    PrintList(Senarai);

    //aplikasi CountX
    InsertVAfterX(&Senarai, 'N', 'D');
    InsertVAfterX(&Senarai, 'P', 'J');
    printf("\n\nIsi list untuk CountX:");
    PrintList(Senarai);
    printf("\nBanyaknya kemunculan elemen 'A' dalam list: %d", CountX(Senarai, 'A'));
    printf("\nBanyaknya kemunculan elemen 'J' dalam list: %d", CountX(Senarai, 'J'));

    //aplikasi FrekuensiX
    printf("\n\nFrekuensi kemunculan elemen 'A' dalam list: %.2f", FrekuensiX(Senarai, 'A'));
    printf("\nFrekuensi kemunculan elemen 'I' dalam list: %.2f", FrekuensiX(Senarai, 'I'));

    //aplikasi MaxMember
    printf("\n\nBanyaknya huruf yang paling banyak muncul dalam list: %d\n", MaxMember(Senarai));

    //aplikasi Modus
    printf("\nHuruf yang paling banyak muncul dalam list: '%c'", Modus(Senarai));

    //aplikasi CountVocal
    CreateList(&L3);
    InsertVFirst(&L3, 'A');
    InsertVLast(&L3, 'P');
    InsertVLast(&L3, 'A');
    InsertVLast(&L3, 'I');
    InsertVLast(&L3, 'N');
    InsertVLast(&L3, 'I');
    printf("\n\nIsi list L3 untuk CountVocal:");
    PrintList(L3);
    printf("\nBanyaknya huruf vokal dalam list L3: %d\n", CountVocal(L3));

    //aplikasi CountNG
    PrintList(L3);
    printf("\nBanyaknya huruf N yang langsung diikuti huruf G dalam list L3: %d", CountNG(L3));
    CreateList(&L4);
    InsertVFirst(&L4, 'J');
    InsertVLast(&L4, 'U');
    InsertVLast(&L4, 'R');
    InsertVLast(&L4, 'A');      
    InsertVLast(&L4, 'N');
    InsertVLast(&L4, 'G');
    printf("\n\nIsi list L4 untuk CountNG:");
    PrintList(L4);
    printf("\nBanyaknya huruf N yang langsung diikuti huruf G dalam list L4: %d\n", CountNG(L4));

    //aplikasi SearchAllX
    printf("\nIsi list Senarai untuk SearchAllX:");
    PrintList(Senarai);
    SearchAllX(Senarai, 'A');
    SearchAllX(Senarai, 'Z');

    //aplikasi DeleteAllX
    printf("\n\nIsi list sebelum DeleteAllX (menghapus semua elemen 'A'):");
    PrintList(Senarai);
    DeleteAllX(&Senarai, 'A');
    printf("\nIsi list setelah DeleteAllX:");
    PrintList(Senarai);

    //apliasi ConcatList
    printf("\n\nIsi list L1 untuk ConcatList:");
    PrintList(L1);
    printf("\nIsi list L4 untuk ConcatList:");
    PrintList(L4);
    ConcatList(L1, L4, &L5);
    printf("\nIsi list L5 hasil ConcatList L1 dan L4:");
    PrintList(L5);

    //aplikasi SplitList
    InsertVAfterX(&Senarai, 'J', 'A');
    InsertVAfterX(&Senarai, 'Y', 'A');
    InsertVAfterX(&Senarai, 'A', 'A');
    printf("\n\nIsi list Senarai untuk SplitList:");
    PrintList(Senarai);
    SplitList(Senarai, &L1, &L2);
    printf("\nIsi list L1 hasil SplitList dari Senarai:");
    PrintList(L1);
    printf("\nIsi list L2 hasil SplitList dari Senarai:");
    PrintList(L2);
    
    //aplikasi CopyList
    CopyList(L1, &L2);
    printf("\n\nIsi list L2 hasil CopyList dari L1:");
    PrintList(L2);


    
    return 0;
}