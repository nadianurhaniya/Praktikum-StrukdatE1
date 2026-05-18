/* File : main2.c */
/* Deskripsi : Program uji ADT bintree pointer */
/* NIM & Nama : 24060124120019 - Nadia Azura Nurhaniya */
/* Tanggal : 5 Desember 2025 */

#include <stdio.h>
#include <stdlib.h>
#include "pohon2.h"

int main() {
    bintree B;
    char X;

    B = Tree('T',
            Tree('I',
                Tree('N', NIL, NIL),
                Tree('F',
                    Tree('O', NIL, NIL),
                    NIL)),
            Tree('R',
                Tree('M',
                    Tree('A', NIL, NIL),
                    Tree('T', NIL, NIL)),
                Tree('I',
                    NIL,
                    Tree('K',
                        NIL,
                        Tree('A', NIL, NIL)))));
    
    printf("=== TREE B ===\n");
    PrintTreeInden(B, 0);
    printf("\n");

    //aplikasi PrintLevel
    printf("Level 1 : ");
    PrintLevel(B, 1);
    printf("\n");

    printf("Level 2 : ");
    PrintLevel(B, 2);
    printf("\n");

    printf("Level 3 : ");
    PrintLevel(B, 3);
    printf("\n\n");
    
    //aplikasi UpdateAllX
    printf("UpdateAllX: semua 'I' -> 'U'\n");
    UpdateAllX(&B, 'I', 'U');
    PrintTreeInden(B, 0);
    printf("\n");

    //aplikasi AddDaunTerkiri
    printf("AddDaunTerkiri: tambah node 'Q'\n");
    AddDaunTerkiri(B, 'Q');
    PrintTreeInden(B, 0);
    printf("\n");

    //apkikasi AddDaun
    printf("AddDaun: tambahkan anak kiri 'Q' dengan nilai 'C'\n");
    AddDaun(B, 'Q', 'C', true);
    PrintTreeInden(B, 0);
    printf("\n");

    //aplikasi InsertX
    printf("InsertX: sisipkan huruf 'V'\n");
    InsertX(&B, 'V');
    PrintTreeInden(B, 0);
    printf("\n");

    //aplikasi DelDaunTerkiri
    printf("DelDaunTerkiri:\n");
    DelDaunTerkiri(&B, X);
    printf("Daun terkiri yang dihapus: %c\n", X);
    PrintTreeInden(B, 0);
    printf("\n");

    //aplikasi DelDaun
    printf("DelDaun: hapus daun 'O'\n");
    DelDaun(&B, 'O');
    PrintTreeInden(B, 0);
    printf("\n");

    //aplikasi DeleteX
    printf("DeleteX: hapus simpul bernilai 'F'\n");
    DeleteX(&B, 'F');
    PrintTreeInden(B, 0);
    printf("\n");
    
    //aplikasi BuildBalanceTree
    printf("BuildBalanceTree(5): masukkan 5 huruf\n");
    bintree BT = BuildBalanceTree(5);

    printf("Pohon BT seimbang hasil input:\n");
    PrintTreeInden(BT, 0);
    printf("\n");
    
    //aplikasi IsBalanceTree
    if (IsBalanceTree(B)) {
            printf("\nPohon B Balance");
          } else {
            printf("\nPohon B Tidak Balance");
          }

    if (IsBalanceTree(BT)) {
            printf("\nPohon BT Balance\n");
          } else {
            printf("\nPohon BT Tidak Balance\n");
          }

    //aplikasi maxTree dan minTree
    printf("\nNilai maksimum di pohon B: %c\n", maxTree(B));
    printf("Nilai minimum di pohon B: %c\n\n", minTree(B));

    //aplikasi InsSearch
    bintree BST = NIL;

    printf("\nMembangun BST menggunakan InsSearch:\n");
    BST = InsSearch(BST, 'N');
    BST = InsSearch(BST, 'U');
    BST = InsSearch(BST, 'R');
    BST = InsSearch(BST, 'H');
    BST = InsSearch(BST, 'A');
    BST = InsSearch(BST, 'N');
    BST = InsSearch(BST, 'I');
    BST = InsSearch(BST, 'Y');
    BST = InsSearch(BST, 'A');

    PrintTreeInden(BST, 0);
    printf("\n");

    //aplikasi BSearch
    printf("BSearch(BST, 'N') = %d\n", BSearch(BST, 'N'));
    printf("BSearch(BST, 'A') = %d\n\n", BSearch(BT, 'A'));

    //aplikasi DelBtree
    printf("Menghapus node 'H' dari BST: \n");
    DelBtree(&BST, 'H');
    PrintTreeInden(BST, 0);
    printf("\n");

    printf("Menghapus node 'T' dari BST:\n");
    DelBtree(&BST, 'T');
    PrintTreeInden(BST, 0);
    printf("\n");

    printf("Menghapus node 'N' (ROOT) dari BST:\n");
    DelBtree(&BST, 'N');
    PrintTreeInden(BST, 0);
    printf("\n");


    return 0;
}