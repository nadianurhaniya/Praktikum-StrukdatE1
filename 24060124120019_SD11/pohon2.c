/* File : pohon2.c */
/* Deskripsi : ADT bintree berkait dengan representasi fisik pointer */
/* pohon2 melengkapi operator ADT bintree yang ada dalam pohon1 */
/* NIM & Nama : 24060124120019 - Nadia Azura Nurhaniya */
/* Tanggal : 5 Desember 2025*/

// #include "stdio.h"
// #include "stdlib.h"
#include "pohon2.h"

/*PENELUSURAN*/
/* procedure PrintTreeInden (input P : BinTree, input H : integer)
{ I.S. P terdefinisi, h adalah jarak indentasi subpohon }
{ F.S. Semua simpul P ditulis dengan indentasi berjenjang,mirip file explorer} */
void PrintTreeInden(bintree P, int H ) {
    //kamus lokal
    int i;

    //algoritma
    if (P != NIL){
        for(i = 0; i < H; i++){
            printf("\t");
        }
        printf("%c",info(P));
        printf("\n");
        PrintTreeInden(left(P), H + 1);
        PrintTreeInden(right(P), H + 1);
    }
}

/* procedure PrintLevel(input P:bintree, input N:integer)
{I.S. L terdefinisi; F.S. :-}
{ menampilkan info semua elemen bintree P pada generasi/level N} */
void PrintLevel2(bintree P, int N) {
    //kamus lokal

    //algoritma
    if (IsEmptyTree(P)) {
        printf("Kosong");
    } else {
        if (N == 1){
            printf("%c ", info(P));
        } else {
            PrintLevel2(left(P),  N - 1);
            PrintLevel2(right(P), N - 1);
        }
    }
}

/*** MANIPULASI ELEMEN bintree ***/
/*Procedure UpdateAllX(input/output P:bintree, input X:infotype, input Y:infotype)
{ I.S. L, X, Y terdefinisi }
{ F.S. L tetap, atau elemen bernilai X berubah menjadi Y. Mengganti semua elemen bernilai X menjadi Y}*/
void UpdateAllX(bintree *P, infotype X, infotype Y) {
    //kamus lokal

    //algoritma
    if ((*P) != NIL) {
        if (info(*P) == X) {
            info(*P) = Y;
        } //endif (info(P) != X)
        UpdateAllX(&left(*P), X, Y);
        UpdateAllX(&right(*P), X, Y);
    } 
}

/******* PENAMBAHAN ELEMEN bintree ********/
/*procedure AddDaunTerkiri (input/output P : BinTree, input X : infotype)
{ I.S. P boleh kosong }
{ F.S. P bertambah simpulnya, dengan X sebagai simpul daun terkiri }*/
void AddDaunTerkiri(bintree P, infotype X) {
    //kamus lokal

    //algoritma
    if (IsEmptyTree(P)) {
        P = Tree(X, NIL, NIL);
    } else {
        if (IsUnerRight(P) || IsDaun(P)) {
            left(P) = Tree(X, NIL, NIL);
        } else {
            AddDaunTerkiri(left(P), X);
        }

    }
}

/*procedure AddDaun (input/Output P : BinTree, input X, Y : infotype, input Kiri : boolean)
{ I.S. P tidak kosong, X adalah salah satu daun Pohon Biner P }
{ F.S. P bertambah simpulnya, dengan Y sebagai anak kiri X (jika Kiri), atau sebagai anak Kanan X (jika not Kiri) }*/
void AddDaun(bintree P, infotype X, infotype Y, boolean Kiri) {
    //kamus lokal

    //algoritma
    if (P != NIL) {
        if (akar(P) == X) {
            if (Kiri) {
                left(P) = Tree(Y, NIL, NIL);
            } else {
                right(P) = Tree(Y, NIL, NIL);
            }
        } else {
            if (!IsDaun(P)) {
                if (SearchX(left(P), X)) {
                    AddDaun(left(P), X, Y, Kiri);
                } else {
                    AddDaun(right(P), X, Y, Kiri);
                }
            }
        }
    }
}

/*procedure InsertX (input/output P : BinTree, input X : infotype)
{ Menghasilkan sebuah pohon P dengan tambahan simpul X. Belum ada simpul P yang bernilai X. }*/
void InsertX(bintree *P, infotype X) {
    //kamus lokal

    //algorutna
    if (IsEmptyTree(*P)) {
        (*P) = Tree(X, NIL, NIL);
    } else {
        if (X < akar(*P)) {
            InsertX(&left(*P), X);
        } else {
            InsertX(&right(*P), X);
        }
    }
}

/******* PENGHAPUSAN ELEMEN ********/
/*procedure DelDaunTerkiri (input/output P : BinTree, output X : infotype)
{ I.S. P tidak kosong }
{ F.S. P dihapus daun terkirinya, dan didealokasi, dengan X adalah info yang
semula disimpan pada daun terkiri yang dihapus }*/
void DelDaunTerkiri(bintree *P, infotype X) {
    //kamus lokal

    //algoritma
    if (IsDaun(*P)){
        X = info(*P);
        *P = NIL;
    }else{
        if(left(*P) != NIL){
            DelDaunTerkiri(&left(*P),X);
        }else{
            DelDaunTerkiri(&right(*P),X);
        }
    }

}

/*procedure DelDaun (input/output P : BinTree, input X : infotype)
{ I.S. P tidak kosong, X adalah salah satu daun }
{ F.S. X dihapus dari P }*/
void DelDaun(bintree *P, infotype X) {
    //kamus lokal

    //algoritma
    if (*P != NIL) {
        if (IsDaun(*P) && info(*P) == X) { 
            DealokasiTree(P);
            *P = NIL;
        } else {
            DelDaun(&left(*P),X);
            DelDaun(&right(*P),X);
        }
    }
}

/*procedure DeleteX (input/output P : BinTree, input X : infotype)
{ Menghapus simpul bernilai X bila ada dari P, HATI-HATI! }*/
void DeleteX(bintree *P, infotype X) {
    //kamus lokal

    //algoritma
    if(*P != NIL){
        if(info(*P) == X){
            if(!IsDaun(*P)){
                if (IsUnerLeft(*P)){
                    *P = left(*P);
                }else{
                    *P = right(*P);
                }
            }else{
                DealokasiTree(P);
                *P = NIL;
            }
        }else{
            DeleteX(&left(*P),X);
            DeleteX(&right(*P),X);
        }
    }
}

/*********** SOAL TAMBAHAN, DIKERJAKAN BILA LUANG *****************/
/*KONSTRUKTOR*/
/*function BuildBalanceTree (n : integer) -> BinTree
{ Menghasilkan balanced tree dengan n node, nilai setiap node dibaca dari keyboard }*/
bintree BuildBalanceTree(int n) {
    //kamus lokal
    char X;

    //algoritma
    if (n == 0) {
        return NIL;
    } else {
        printf("Masukkan input : ");
        scanf(" %c", &X);
        return Tree(X,BuildBalanceTree(n/2),BuildBalanceTree(n - 1 - n/2));
    }
}

/*PREDIKAT*/
/*function IsBalanceTree (P : BinTree) -> boolean
{ Menghasilkan true jika P seimbang, banyak node kiri ~= kanan }*/
boolean IsBalanceTree(bintree P) {
    //kamus lokal
    int selisih;

    //algoritma
    if (P == NIL) {
        return true;
    } else {
        if (IsDaun(P)) {
            return true;
        } else {
            selisih = (NbElm(left(P)) - NbElm(right(P))) * (NbElm(left(P)) - NbElm(right(P)));
            return (selisih <= 1 && IsBalanceTree(left(P)) && IsBalanceTree(right(P)));
        }
    }
}

/* function maxTree(P:bintree)->character
{mengembalikan huruf "maksimal" dari elemen P, A<B<C<..<Z }*/
int maxTree(bintree P) {
    //kamus lokal
    char max;
    char modus;
    //algoritma
    max = '#';
    if(IsEmptyTree(P)){
        return '#';
    }
    else{
        max = info(P);
        if(max <= maxTree(left(P))){
            max = maxTree(left(P));
        }

        if(max <= maxTree(right(P))){
            max = maxTree(right(P));
        }

        return max;
    }
}

/* function minTree(P:bintree)->character
{mengembalikan huruf "minimal" dari elemen P, A<B<C<..<Z }*/
int minTree(bintree P) {
    //kamus lokal
    char min;
    char modus;
    //algoritma
    min = '_';
    if(IsEmptyTree(P)){
        return '_';
    }
    else{
        min = info(P);
        if(min >= minTree(left(P))){
            min = minTree(left(P));
        }

        if(min >= minTree(right(P))){
            min = minTree(right(P));
        }

        return min;
    }
}

/*{ Operator KHUSUS Binary Search Tree, node kiri selalu lebih kecil daripada node kanan }

/*function BSearch (P : BinTree, X : infotype) → boolean
{ Mengirimkan true jika ada node dari pohon binary search P yang bernilai X }*/
boolean BSearch(bintree P, infotype X) {
    //kamus lokal

    //algoritma
    if(P == NIL){
        return false;
    }else{
        if(info(P) == X){
            return true;
        }else if(info(P) > X){
            return BSearch(left(P),X);
        }else{
            return BSearch(right(P),X);
        }
    }
}

/*function InsSearch (P : BinTree, X : infotype) → BinTree
{ Menghasilkan sebuah pohon Binary Search Tree P dengan tambahan simpul X. Belum ada simpul P yang bernilai X. }*/
bintree InsSearch(bintree P, infotype X) {
    //kamus lokal

    //algoritma
    if(P == NIL){
        return Tree(X,NIL,NIL);
    }else{
        if(info(P) > X){
            left(P) = InsSearch(left(P),X);
        }else{
            right(P) = InsSearch(right(P),X);
        }
        return P;
    }

}

/*procedure DelBtree (input/output P : BinTree, input X : infotype)
{ I.S. Pohon binary search P tidak kosong }
{ F.S. Nilai X yang dihapus pasti ada }
{ Sebuah node dg nilai X dihapus }*/
void DelBtree(bintree *P, infotype X) {
    //kamus lokal

    //algoritma
    if(*P != NIL){
        if(info(*P) == X){
            if(!IsDaun(*P)){
                if (IsUnerLeft(*P)){
                    *P = left(*P);
                }else{
                    *P = right(*P);
                }
            }else{
                DealokasiTree(P);
                *P = NIL;
            }
        }else{
            if(info(*P) > X){
                DelBtree(&left(*P),X);
            }else{
                DelBtree(&right(*P),X);
            }
        }
    }

}





