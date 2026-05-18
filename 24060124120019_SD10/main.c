/* File : pohon1.c */
/* Deskripsi : ADT bintree berkait dengan representasi fisik pointer */
/* NIM & Nama : 24060124120019 - Nadia Azura Nurhaniya*/
/* Tanggal : 28 November 2025*/

#include "pohon1.h"

int main() {
     //kamus lokal
     bintree B;
     bintree A;
     //algirtma
     printf("Tree (A):\n");
     A = Tree('N',     // root
         NIL,     // left child
         NIL);    // right child
     PrintPrefix(A);

     printf("\n\nTree (B):\n");
     B =  Tree('T',
               Tree('I',
                    Tree('N',NIL,NIL),
                    Tree('F',
                         Tree('O',NIL,NIL),
                         NIL)),
               Tree('R',
                    Tree('M',
                         Tree('A',NIL,NIL),
                         Tree('T',NIL,NIL)),
                    Tree('I',
                         NIL,
                         Tree('K',
                              NIL,
                              Tree('A',NIL,NIL))))
               );
     PrintPrefix(B);


     /****** SELEKTOR *****/
     //aplikasi GetLeft dan GetRight
     printf("\n\n[Pohon B] Left child of root: %c\n", info(GetLeft(B)));
     printf("[Pohon B] Right child of root: %c\n", info(GetRight(B)));
     

     /****************** PREDIKAT ******************/
    /// aplikasi IsEmptyTree
    if (IsEmptyTree(A)) {
            printf("\nPohon A Kosong");
          } else {
            printf("\nPohon A Tidak Kosong");
          }
     
     if (IsEmptyTree(B)) {
            printf("\nPohon B Kosong");
          } else {
            printf("\nPohon B Tidak Kosong\n");
          }

     //aplikasi IsDaun
     if (IsDaun(A)) {
            printf("\nPohon A hanya memiliki satu elemen (akar)");
          } else {
            printf("\nPohon B memiliki lebih dari satu elemen\n");
          }
     
     if (IsDaun(B)) {
            printf("\nPohon B hanya memiliki satu elemen (akar)");
          } else {
            printf("\nPohon B memiliki lebih dari satu elemen\n");
          }
     
     //aplikasi IsBiner
     if (IsBiner(A)) {
            printf("\nPohon A adalah pohon biner\n");
          } else {
            printf("\nPohon A bukan pohon biner");
          }
     
     if (IsBiner(B)) {
            printf("\nPohon B adalah pohon biner\n");
          } else {
            printf("\nPohon B bukan pohon biner\n");
          }
     
     //aplikasi IsUnerLeft
     if (IsUnerLeft(B)) {
            printf("\nPohon B adalah pohon unerleft\n");
          } else {
            printf("\nPohon B bukan pohon unerleft");
          }

     //aplikasi IsUnerRight
     if (IsUnerRight(B)) {
            printf("\nPohon B adalah pohon unerright\n");
          } else {
            printf("\nPohon B bukan pohon unerright\n");
          }

     //*********PENELUSURAN************//
     //aplikasi NbElm
     printf("\nPohon A memiliki %d elemen", NbElm(A));
     printf("\nPohon B memiliki %d elemen\n", NbElm(B));

     //aplikasi NBDaun
     printf("\nPohon A memiliki %d daun", NbDaun(A));
     printf("\nPohon B memiliki %d daun\n", NbDaun(B));
 
     //aplikasi max2 dan Tinggi
     printf("\nTinggi pohon A adalah %d", Tinggi(A));
     printf("\nTinggi pohon B adalah %d\n", Tinggi(B));

     //************ PENCARIAN **************//
     //aplikasi SearchX
     if (SearchX(B, 'K')) {
          printf("\nNode K ada di pohon B");
     } else {
          printf("\nNode K tidak ada di pohon B");
     }
     
     if (SearchX(B, 'J')) {
          printf("\nNode J ada di pohon B");
     } else {
          printf("\nNode J tidak ada di pohon B");
     }

     if (SearchX(A, 'N')) {
          printf("\nNode N ada di pohon A");
     } else {
          printf("\nNode N tidak ada di pohon A");
     }

     if (SearchX(A, 'C')) {
          printf("\nNode C ada di pohon A\n");
     } else {
          printf("\nNode C tidak ada di pohon A\n");
     }
     
     /*** MANIPULASI ELEMEN bintree ***/
     //aplikasi UpdateX
     printf("\nPohon B sebelum updateX: ");
     PrintPrefix(B);
     printf("\nUpdate node 'O' menjadi 'Z' di Tree B");
     UpdateX(&B, 'O', 'Z');
     printf("\nPohon B setelah updateX: ");
     PrintPrefix(B);

     //aplikasi CountX
     printf("\n\nJumlah huruf 'A' di Tree B = %d\n", CountX(B,'A'));

     //aplikasi IsSkewLeft
     if (IsSkewLeft(B)) {
            printf("\nPohon B adalah Skew-Left\n");
          } else {
            printf("\nPohon B bukan Skew-Left\n");
          }

     //aplikasi IsSkewRight
      if (IsSkewRight(B)) {
            printf("\nPohon B adalah Skew-Right\n");
          } else {
            printf("\nPohon B bukan Skew-Right\n");
          }

     //aplikasi PrintPrefixRingkas
     printf("\nPrefix Ringkas Pohon B: ");
     PrintPrefixRingkas(B);

     //aplikasi LevelX
     printf("\n\nLevel huruf 'T' pada Pohon B = %d", LevelX(B,'T'));
     printf("\n\nLevel huruf 'K' pada Pohon B = %d", LevelX(B,'K'));

     //aplikasi countLevel
     printf("\n\nJumlah node pada level 3 = %d", CountLevel(B,3));

     //aplikasi PrintLevel
     printf("\n\nNode pada level 3: ");
     PrintLevel(B, 3);

     //aplikasi GetDaunTerkiri
     printf("\n\nDaun paling kiri di Pohon B = %c", GetDaunTerkiri(B));

     //aplikasi FrekuensiX
     printf("\n\nFrekuensi kemunculan elemen 'T' dalam Pohon B: %.2f", FrekuensiX(B, 'T'));

     //aplikasi CountVocal
     printf("\n\nJumlah huruf vokal di Pohon B = %d", CountVocal(B));

     //aplikasi PrintVocal
     printf("\n\nHuruf vokal pada Pohon B: ");
     PrintVocal(B);

     //aplikasi CountConsonant
     printf("\n\nJumlah konsonan di Pohon B = %d", CountConsonant(B));

     //aplikasi PrintConsonant
     printf("\n\nHuruf konsonan pada Pohon B: ");
     PrintConsonant(B);

     //aplikasi Modus
     printf("\n\nModus Pohon B = %c\n", Modus(B));

     return 0;
}
