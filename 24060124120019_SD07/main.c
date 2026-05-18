/* File : main.c */
/* Deskripsi : aplikasi driver ADT list berkait, representasi fisik pointer */
/* NIM & Nama : 24060124120019 - Nadia Azura Nurhaniya */
/* Tanggal : 7 November 2025 */
#include <stdio.h>
#include <stdlib.h>
#include "list1.h"
int main()
{ //kamus
  address A; 
  address B;
  address P;
  infotype X;
  char kemunculanX;
  int total;
  float Frek;
  List1 Senarai, L1, L2, L3;

  //algoritma
  //aplikasi tipe address
  A = (address) malloc ( sizeof (Elm) ); // Alokasi('G')
  A->info = 'G';   A->next = NIL;
  printf("info(A)=%c\t", A->info );
  B = (address) malloc ( sizeof (Elm) ); // Alokasi('N')
  B->info = 'N';   B->next = A;
  printf("info(B)=%c\n", B->info );
  
  //aplikasi tipe List1
  Senarai.First = B; //First(Senarai) = B;
  printf("Isi Senarai :");
  P = First(Senarai);
  while (P != NIL) {
	  printf("\t%c",info(P));
	  P = next(P);
  }

  //PrintList( Senarai )
  PrintList( Senarai );

  //aplikasi IsEmptyList
  printf("\n");
  if (IsEmptyList(Senarai)) {
    printf("List masih kosong");
  } else {
    printf("List tidak kosong");
  }

  //aplikasi NbElm
  printf("\nBanyak Elemen = %d", NbElm(Senarai));

  //aplikasi prosedur InsertVFirst
  printf("\n");
  First(Senarai) = NIL;
  printf("\nInsertVFirst");
  InsertVFirst(&Senarai, 'C');
  InsertVFirst(&Senarai, 'B');
  InsertVFirst(&Senarai, 'A');
  PrintList(Senarai);
  
  //aplikasi prosedur InsertVLast
  printf("\n");
  printf("\nInsertVLast");
  InsertVLast(&Senarai, 'D');
  InsertVLast(&Senarai, 'E');
  InsertVLast(&Senarai, 'F');
  PrintList(Senarai);

  //aplikasi DeleteVFirst 
  printf("\n");
  printf("\nDeleteVFirst");
  DeleteVFirst(&Senarai, &X);
  printf("\nElemen yang dihapus: %c", X);
  PrintList(Senarai);
  
  //aplikasi DeleteVLast
  printf("\n");
  printf("\nDeleteVLast");
  DeleteVLast(&Senarai, &X);
  printf("\nElemen yang dihapus: %c", X);
  PrintList(Senarai);

  //aplikasi SearchX
  printf("\n");
  printf("\nSearchX\n");
  SearchX(Senarai, 'B', &A);
  if (A != NIL) {
    printf("Elemen 'B' ditemukan di alamat: %p\n", A);
  } else {
    printf("Elemen 'B' tidak ditemukan\n");
  }
  SearchX(Senarai, 'Z', &A);
  if (A != NIL) {
    printf("Elemen 'Z' ditemukan di alamat: %p\n", A);
  } else {
    printf("Elemen 'Z' tidak ditemukan\n");
  }

  //aplikasi UpdateX
  printf("\n");
  printf("UpdateX");
  printf("\nSebelum UpdateX: ");
  PrintList(Senarai);
  UpdateX(&Senarai, 'B', 'Z');
  printf("\nSetelah UpdateX: ");
  PrintList(Senarai);
  
  //aplikasi Invers
  printf("\n");
  printf("\nInvers");
  Invers(&Senarai);
  printf("\nSetelah Invers: ");
  PrintList(Senarai);

  //aplikasi CountVocal
  printf("\n");
  printf("\nCountVocal");
  printf("\nBanyak huruf vocal pada list: ");
  printf("%d", CountVocal(Senarai));
 
  //aplikasi CountX
  kemunculanX = 'E';
  printf("\n");
  printf("\nCountX");
  printf("\nBanyak kemunculan %c dalam list: ", kemunculanX);
  printf("%d", CountX(Senarai, kemunculanX));

  //aplikasi FrekuensiX
  printf("\n");
  printf("\nFrekuensiX");
  total = CountX(Senarai, 'C');
  Frek = FrekuensiX(Senarai, 'C');
  printf("\nTotal 'C': %d", total);
  printf("\nFrekuensi 'C': %.2f\n", Frek);

  //aplikasi SearchAllX
  printf("\nSearchAllX");
  InsertVFirst(&Senarai, 'A');
  InsertVLast(&Senarai, 'A');
  PrintList(Senarai);
  SearchAllX(Senarai, 'A');

  //aplikasi UpdateAllX
  printf("\nUpdateAllX");
  printf("\nSebelum update semua A menjadi P :");
  PrintList(Senarai);
  UpdateAllX(&Senarai, 'A', 'P');
  printf("\nSetelah update: ");
  PrintList(Senarai);

  //aplikasi InsertVAfter
  printf("\n");
  printf("\nInsertVAfter");
  printf("\nSebelum insert 'Q' setelah 'D':");
  PrintList(Senarai);
  InsertVAfter(&Senarai, 'D', 'Q');
  printf("\nSetelah insert:");
  PrintList(Senarai);

  //aplikasi Modus dan NbModus
  printf("\n");
  printf("\nModus dan NbModus");
  PrintList(Senarai);
  printf("\nNilai Modus: %c\n", Modus(Senarai));
  printf("Banyaknya kemunculan modus: %d\n", NbModus(Senarai));

  //aplikasi ConcatList
  CreateList(&L1);
  InsertVFirst(&L1, 'T');
  InsertVFirst(&L1, 'S');
  InsertVFirst(&L1, 'R');
  printf("\nL1:");
  PrintList(L1);
  CreateList(&L2);
  InsertVLast(&L2, 'U');
  InsertVLast(&L2, 'V');
  InsertVLast(&L2, 'W');
  printf("\nL2:");
  PrintList(L2);
  printf("\n\nConcatList");
  printf("\nHasil menggabungkan L1 dan L2 menjadi L3: ");
  ConcatList(L1, L2, &L3);
  PrintList(L3);
  
  //aplikasi SplitList
  printf("\n\nSplitList");
  printf("\nMemecah list L3 menjadi L1 dan L2: \n");
  SplitList(L3, &L1, &L2);
  printf("L1 = "); 
  PrintList(L1);
  printf("\nL2 = "); 
  PrintList(L2);

  //aplikasi CopyList
  printf("\n\nCopyList");
  printf("\nMenyalin list L3 ke L1: ");
  CopyList(L3, &L1);
  PrintList(L1);

  return 0;
}
