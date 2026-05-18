/* File : List2.h */
/* Deskripsi : ADT list berkait SIRKULAR dengan representasi fisik pointer */
/* NIM & Nama : 24060124130069 - Nadia Azura Nurhaniya*/
/* Tanggal : 14 November 2025 */

#include "stdio.h"
#include "stdlib.h"
#include "list2.h" 

/*================== PROTOTYPE =======================*/
/****************** Manajemen Memori ******************/
/* Function Alokasi(E:infotype)->address
{mengembalikan alamat elemen E} */
address Alokasi(infotype E) {
    //kamus lokal
    address P;

    //algoritma 
    P = (address) malloc(sizeof(Elm)); //casting
    if (P != NULL ) {
        info(P) = E;
        next(P) = NIL;
    } // end if (P == NULL)
    return P;
}

/* procedure Dealokasi (input/output P:address) */
/* {I.S. P terdefinisi
    F.S. P dikembalikan ke sistem
    Proses: Melakukan pengembalian address P} */
void Dealokasi(address *P) {
    // kamus lokal
    // algoritma
    if ((*P) != NIL){
        next(*P) = NIL;
        (*P) = NIL;
    } // end if ((*P) == NIL)
}

/********** PEMBUATAN LIST KOSONG ***********/
/* Procedure CreateList(output L:List2)
   {I.S.: - ; F.S.: L list kosong} 
   {proses: membuat list kosong}*/
void CreateList (List2 *L) {
    (*L).First = NIL;
}

/****************** TEST KONDISI LIST ******************/
/* function IsEmptyList(L:List2) --> boolean 
   {mengembalikan true bila list L kosong} */
boolean IsEmptyList (List2 L) {
    //kamus lokal
    //algoritma
    return (First(L) == NIL);
}

/* function IsOneElm(L:List2) --> boolean 
   {mengembalikan true bila list L hanya punya satu elemen} */
boolean IsOneElm (List2 L) {
    //kamus lokal
    //algoritma
    return (!IsEmptyList(L) && (next(First(L)) == First(L)));
}

/*********** PENELUSURAN ***********/
/*procedure PrintList(input L:List2)
{I.S. L terdefinisi; F.S. :-}
{ menampilkan info semua elemen list L} */
void PrintList(List2 L){
    // kamus lokal
    address P;
    // algoritma
    P = First(L);
    if (!IsEmptyList(L)){
        printf("\nElemen = ");
        do{
            printf("\t%c", info(P));
            P = next(P);
        } while (P != First(L)); 
    } // end if (IsEmptyList(L))
}

/*function NbElm(L:List2) --> integer
{ menghitung banyaknya elemen list L} */
int NbElm(List2 L) {
    //kamus lokal
    address P;
    int count;
    //algoritma
    count = 0;
    if (!IsEmptyList(L)) {
        P = First(L);
        do {
            count++;
            P = next(P);
        } while (P != First(L));
    } // end if (IsEmptyList(L))
    return count;
}

/******* PENAMBAHAN ELEMEN LIST ********/
/* Procedure InsertVFirst(input/output L:List2, input V:infotype )
{ I.S. List L mungkin kosong, V terdefinisi }
{ F.S. L tetap, atau bertambah elemen pertama berinfo V }
{ Proses: Insert sebuah elemen beralamat P dengan Info(P)=V sebagai elemen pertama list linier L yg mungkin kosong } */
void InsertVFirst(List2 *L, infotype V ) {
    //kamus lokal
    address P, Last;
    //algoritma
    P = Alokasi(V);
    if (P != NIL) {
        if (IsEmptyList(*L)) {
            First(*L) = P;
            next(P) = P; //sirkular
        } else {
            Last = First(*L);
            while (next(Last) != First(*L)) { //cari elemen terakhir
                Last = next(Last);
            } 
            next(P) = First(*L);
            First(*L) = P;
            next(Last) = First(*L); //menghubungkan last ke first yang baru
        }
    } // end if (P == NIL)
}

/*Procedure InsertVLast(input/output L:List2, input V:infotype )
{ I.S. List L mungkin kosong, V terdefinisi }
{ F.S. L tetap, atau bertambah elemen terakhir berinfo V, next(P)=First(L)}
{ Proses: Insert sebuah elemen beralamat P dengan Info(P)=V sebagai elemen akhir list linier L yg mungkin kosong }*/
void InsertVLast(List2 *L, infotype V ) {
    //kamus lokal
    address P;
    address Last;
    //algoritma
    P = Alokasi(V);
    if (P != NIL) {
        if (IsEmptyList(*L)) {
            First(*L) = P;
            next(P) = P; //sirkular
        } else {
            Last = First(*L);
            while (next(Last) != First(*L)) { //cari elemen terakhir
                Last = next(Last);
            } 
            next(Last) = P;
            next(P) = First(*L); //menghubungkan last ke first
        }
    } // end if (P == NIL)
}

/******* PENGHAPUSAN ELEMEN ********/
/*Procedure DeleteVFirst(input/output L:List2, output V:infotype )
{ I.S. List L terdefinisi }
{ F.S. Elemen pertama list L dihapus dan didealokasi. Nilai penghapusan disimpan dalam V. Default V='#'.
List mungkin menjadi kosong. Jika tidak kosong, elemen pertama list yang baru adalah elemen sesudah elemen pertama yang lama. } */
void DeleteVFirst(List2 *L, infotype *V) {
    //kamus lokal
    address P;
    address Last;
    // algoritma
    if (IsEmptyList(*L)){
        (*V) = '#';
    } else{
        P = First(*L);
        (*V) = info(P);

        if (IsOneElm(*L)){
            First(*L) = NIL;
        }
        else{
            // Cari elemen terakhir
            Last = First(*L);
            while (next(Last) != First(*L)) { //cari elemen terakhir
                Last = next(Last);
            }
            First(*L) = next(P);
            next(Last) = First(*L);
        }
        Dealokasi(&P);
    } // end if (IsEmptyList(*L))
}

/*Procedure DeleteVLast(input/output L:List2, output V:infotype )
{ I.S. List L terdefinisi }
{ F.S. Elemen terakhir list L dihapus dan didealokasi. Nilai penghapusan disimpan dalam V. Default V='#'.
List mungkin menjadi kosong. Jika tidak kosong, elemen terakhir list yang baru adalah elemen sebelum elemen terakhir yang lama. }*/
void DeleteVLast(List2 *L, infotype *V) {
   // kamus lokal
    address P, Prec;
   // algoritma
   if (IsEmptyList(*L)) {
       *V = '#';
   } else {
       if (IsOneElm(*L)){   // hanya 1 elemen
            (*V) = info(First(*L));
            Dealokasi(&First(*L));
            First(*L) = NIL;
        } else{     // lebih dari 1 elemen
            P = First(*L);
            Prec = NIL;
            while (next(P) != First(*L)){ //cari elemen terakhir
                Prec = P;
                P = next(P);
            }
            (*V) = info(P);
            next(Prec) = First(*L);
            Dealokasi(&P);
        }
   } // end if (IsEmptyList(*L))
}

/*Procedure DeleteX(input/output L:List2, input X:infotype)
{ I.S. List L tidak kosong }
{ F.S. Elemen bernilai X dihapus, dan didealokasi. 
List mungkin menjadi kosong. }*/
void DeleteX(List2 *L, infotype X) {
    // kamus lokal
    address P, Prec;
    // algoritma
    if (!IsEmptyList(*L)) {
        P = First(*L);
        Prec = NIL;
        do { 
            if (info(P) == X) { //ketemu
                if (P == First(*L)) { //hapus elemen pertama
                    DeleteVFirst(L, &X); //nilai X diabaikan
                    P = First(*L);
                } else { //hapus elemen selain pertama
                    next(Prec) = next(P);
                    if (P == First(*L)) { //jika yang dihapus adalah first
                        First(*L) = next(P);
                    }
                    Dealokasi(&P);
                    P = next(Prec);
                }
            } else { 
                Prec = P;
                P = next(P);
            }
        } while (P != First(*L)); //looping sampai kembali ke first
    } // end if (IsEmptyList(*L))
}

/*** PENCARIAN ***/
/*Procedure SearchX(input L:List2, input X:infotype, output A:address )
{ I.S. L, X terdefinisi }
{ F.S. A berisi alamat elemen yang nilainya X.
Mencari apakah ada elemen list dengan info(P)= X. Jika ada, mengisi A dengan address elemen tersebut. Jika tidak ada, A=Nil }*/
void SearchX(List2 L, infotype X, address *A) {
    // kamus lokal
    address P;
    boolean found;
    // algoritma
    (*A) = NIL;
    found = false;
    if (!IsEmptyList(L)) { //list tidak kosong
        P = First(L);
        do {
            if (info(P) == X) { 
                (*A) = P;
                found = true;
            }
            P = next(P);
        } while (P != First(L) && !found); //looping sampai kembali ke first atau ketemu
    } // end if (IsEmptyList(L))
}

/*** MANIPULASI ELEMEN LIST ***/
/*Procedure UpdateX(input/output L:List2, input X:infotype, input Y:infotype)
{ I.S. L, X, Y terdefinisi }
{ F.S. L tetap, atau elemen bernilai X berubah menjadi Y.
Mengganti elemen bernilai X menjadi bernilai Y}*/
void UpdateX(List2 *L, infotype X, infotype Y) {
    // kamus lokal
    address P;
    // algoritma
    if (!IsEmptyList(*L)) {
        P = First(*L);
        do {
            if (info(P) == X) {
                info(P) = Y;
            }
            P = next(P);
        } while (P != First(*L)); //looping sampai kembali ke first
    } // end if (IsEmptyList(*L))
}

/*Procedure Invers(input/output L:List2)
{ I.S. L terdefinisi }
{ F.S. urutan posisi elemen terbalik, 
misal {'A','B','C'} menjadi {'C','B','A'} }*/
void Invers(List2 *L) {
    // kamus lokal
    address Prev, Curr, Next, FirstElm;
    // algoritma
    if (!IsEmptyList(*L) && !IsOneElm(*L)) {
        FirstElm = First(*L);
        Prev = NIL;
        Curr = First(*L);
        do {
            Next = next(Curr);
            next(Curr) = Prev;
            Prev = Curr;
            Curr = Next;
        } while (Curr != FirstElm); //looping sampai kembali ke first
        next(FirstElm) = Prev;
        First(*L) = Prev;
    } // end if (IsEmptyList(*L) || IsOneElm(*L))
}

/*********** SOAL TAMBAHAN, DIKERJAKAN BILA LUANG *****************/

/*function CountX(L:List2, X:infotype) -> integer */
/*{ mengembalikan banyaknya kemunculan X dalam list L}*/
int CountX(List2 L, infotype X) {
    // kamus lokal
    address P;
    int count;
    // algoritma
    count = 0;
    if (!IsEmptyList(L)) {
        P = First(L);
        do {
            if (info(P) == X) {
                count++;
            }
            P = next(P);
        } while (P != First(L)); //looping sampai kembali ke first
    } // end if (IsEmptyList(L))
    return count;
}

/*function FrekuensiX(L:List2, X:infotype) -> real */
/*{ mengembalikan rasio kemunculan X dibandingkan ukuran list L }*/
float FrekuensiX(List2 L, infotype X){
    // kamus lokal
    int total, count;
    // algoritma
    count = CountX(L, X);
    total = NbElm(L);
    if (total > 0) {
       return (float) count / total;
    } else { 
        return 0.0;
    } // end if (total <= 0)
}

/*function CountVocal(L:List2) -> integer */
/*{ mengembalikan banyaknya kemunculan huruf vokal dalam list L}*/
int CountVocal(List2 L) {
    // kamus lokal
    address P;
    int count;
    // algoritma
    count = 0;
    if (!IsEmptyList(L)) {
        P = First(L);
        do {
            if (info(P) == 'A' || info(P) == 'I' || info(P) == 'U' || info(P) == 'E' || info(P) == 'O' ||
                info(P) == 'a' || info(P) == 'i' || info(P) == 'u' || info(P) == 'e' || info(P) == 'o') {
                count++;
            }
            P = next(P);
        } while (P != First(L)); //looping sampai kembali ke first
    } // end if (IsEmptyList(L))
    return count;
}

/*function CountNG(L:List2) -> integer */
/*{ mengembalikan banyaknya huruf N yang langsung diikuti huruf G dalam list L}*/
int CountNG(List2 L) {
    // kamus lokal
    address P;
    int count;
    // algoritma
    count = 0;
    if (!IsEmptyList(L)) {
        P = First(L);
        do {
            if (info(P) == 'N' && info(next(P)) == 'G') {
                count++;
            }
            P = next(P);
        } while (P != First(L)); //looping sampai kembali ke first
    } // end if (IsEmptyList(L))
    return count;
}

/*Procedure InsertVAfterX(input/output L:List2, input X:infotype, input V:infotype )
{ I.S. List L mungkin kosong }
{ F.S. P dialokasi, Info(P)=V }
{ Insert sebuah elemen beralamat P dengan Info(P)=V sebagai elemen dengan posisi setelah elemen bernilai X }*/
void InsertVAfterX(List2 *L, infotype X, infotype V) {
    // kamus lokal
    address P, Q;
    // algoritma
    P = Alokasi(V);
    if (P != NIL) {
        if (IsEmptyList(*L)) {
            First(*L) = P;
            next(P) = P; //sirkular
        } else { //list tidak kosong
            Q = First(*L);
            do {
                if (info(Q) == X) {
                    next(P) = next(Q);
                    next(Q) = P;
                    return; //keluar setelah menyisipkan
                }
                Q = next(Q);
            } while (Q != First(*L));
            // Jika X tidak ditemukan, sisipkan di akhir
            address Last = First(*L);
            while (next(Last) != First(*L)) {
                Last = next(Last);
            }
            next(Last) = P;
            next(P) = First(*L);
        }
    } // end if (P == NIL)
}

/*Procedure InsertVBeforeX(input/output L:List2, input X:infotype, input V:infotype )
{ I.S. List L mungkin kosong }
{ F.S. P dialokasi, Info(P)=V }
{ Insert sebuah elemen beralamat P dengan Info(P)=V sebagai elemen dengan posisi sebelum elemen bernilai X }*/
void InsertVBeforeX(List2 *L, infotype X, infotype V) {
    // kamus lokal  
    address P, Q, Prec;
    // algoritma
    P = Alokasi(V);
    if (P != NIL) {
        if (IsEmptyList(*L)) {
            First(*L) = P;
            next(P) = P; //sirkular
        } else { //list tidak kosong
            Q = First(*L);
            Prec = NIL;
            do {
                if (info(Q) == X) {
                    if (Prec == NIL) { // Insert sebelum first
                        InsertVFirst(L, V);
                    } else {
                        next(P) = Q;
                        next(Prec) = P;
                    }
                    return; //keluar setelah menyisipkan
                }
                Prec = Q;
                Q = next(Q);
            } while (Q != First(*L));
            // Jika X tidak ditemukan, sisipkan di akhir
            address Last = First(*L);
            while (next(Last) != First(*L)) {
                Last = next(Last);
            }
            next(Last) = P;
            next(P) = First(*L);
        }
    } // end if (P == NIL)
}

/*Procedure DeleteVAfterX(input/output L:List2, input X:infotype, output V:infotype )
{ I.S. List L tidak kosong }
{ F.S. Elemen setelah X dihapus, dan didealokasi. Hasil penghapusan disimpan nilainya dalam V.
List mungkin menjadi kosong. }*/
void DeleteVAfterX(List2 *L, infotype X, infotype *V) {
    // kamus lokal
    address P, Q;
    // algoritma
    if (!IsEmptyList(*L)) {
        P = First(*L);
        do {
            if (info(P) == X) {
                Q = next(P);
                if (Q == First(*L)) { // Jika yang dihapus adalah first
                    DeleteVFirst(L, V);
                } else {
                    (*V) = info(Q);
                    next(P) = next(Q);
                    Dealokasi(&Q);
                }
                return; //keluar setelah penghapusan
            }
            P = next(P);
        } while (P != First(*L));
    } // end if (IsEmptyList(*L))
}

/*Procedure DeleteVBeforeX(input/output L:List2, input X:infotype, output V:infotype )
{ I.S. List L tidak kosong }
{ F.S. Elemen sebelum X dihapus, dan didealokasi. Hasil penghapusan disimpan nilainya dalam V.
List mungkin menjadi kosong. }*/
void DeleteVBeforeX(List2 *L, infotype X, infotype *V) {
    // kamus lokal
    address P, Q, Prec;
    // algoritma
    if (!IsEmptyList(*L)) {
        P = First(*L);
        Prec = NIL;
        do {
            if (info(P) == X) {
                if (Prec == NIL) { // Jika yang dihapus adalah last
                    // Cari last
                    address Last = First(*L);
                    address BeforeLast = NIL;
                    while (next(Last) != First(*L)) { 
                        BeforeLast = Last;
                        Last = next(Last);
                    }
                    (*V) = info(Last);
                    if (BeforeLast != NIL) {
                        next(BeforeLast) = First(*L);
                    } else {
                        First(*L) = NIL; // List menjadi kosong
                    }
                    Dealokasi(&Last);
                } else if (Prec == First(*L)) { // Jika yang dihapus adalah first
                    DeleteVFirst(L, V);
                } else {
                    Q = First(*L);
                    while (next(Q) != Prec) {
                        Q = next(Q);
                    }
                    (*V) = info(Prec);
                    next(Q) = P;
                    Dealokasi(&Prec);
                }
                return; //keluar setelah penghapusan
            }
            Prec = P;
            P = next(P);
        } while (P != First(*L));
    } // end if (IsEmptyList(*L))
}

/*Procedure DeleteAllX(input/output L:List2, input X:infotype)
{ I.S. List L tidak kosong }
{ F.S. Semua elemen bernilai X dihapus, dan didealokasi. 
List mungkin menjadi kosong. }*/
void DeleteAllX(List2 *L, infotype X){
    //kamus lokal
    address P, Next, Last, Prec;
    boolean found;
    //algoritma
    if (IsEmptyList(*L)){
        return;
    }
    do{
        found = false;
        P = First(*L);
        Prec = NIL;

        // Cari elemen terakhir
        Last = First(*L);
        while (next(Last) != First(*L)){
            Last = next(Last);
        }
        do {
            if (info(P) == X){
                found = true;
                Next = next(P);

                if (IsOneElm(*L)){
                    Dealokasi(&First(*L));
                    First(*L) = NIL;
                    return;
                } else if (P == First(*L)) { 
                    First(*L) = Next;
                    next(Last) = First(*L);
                    Dealokasi(&P);
                } else{
                    next(Prec) = Next;
                    if (P == Last){
                        Last = Prec;
                    }
                    Dealokasi(&P);
                }
                break;
            }
            Prec = P;
            P = next(P);
        } while (P != First(*L)); 

    } while (found && !IsEmptyList(*L)); // end while (!found || IsEmptyList(*L))
}

/*Procedure SearchAllX(input L:List2, input X:infotype)
{ I.S. L, X terdefinisi }
{ F.S. -
Proses: menampilkan posisi-posisi kemunculan elemen X dalam list L }*/
/*misal L=['M','A','N','D','A'], SearchAllX(L,'A') menampilkan angka 2,5 */
/*misal L=['M','A','N','D','A'], SearchAllX(L,'J') menampilkan angka 0 */
void SearchAllX(List2 L, infotype X) {
    // kamus lokal
    address P;
    int position;
    boolean found;
    // algoritma
    position = 1;
    found = false;
    if (!IsEmptyList(L)) { //list tidak kosong
        P = First(L);
        printf("\nPosisi kemunculan '%c' dalam list: ", X);
        do {
            if (info(P) == X) { 
                printf("%d ", position);
                found = true;
            }
            P = next(P);
            position++;
        } while (P != First(L));
        if (!found) {
            printf("0");
        }
        printf("\n");
    } else {
        printf("0\n");
    } // end if (IsEmptyList(L))
}

/*function MaxMember(L:List2) -> integer */
/*{ mengembalikan banyaknya huruf yang paling banyak muncul di list L}*/
int MaxMember(List2 L){
    //kamus lokal
    address P;
    int max, count;
    //algoritma
    max = 0;
    if (!IsEmptyList(L)) {
        P = First(L);
        do {
            count = CountX(L, info(P));
            if (count > max) {
                max = count;
            }
            P = next(P);
        } while (P != First(L));
    } // end if (IsEmptyList(L))
    return max;
}

/*function Modus(L:List2) -> character */
/*{ mengembalikan huruf yang paling banyak muncul dalam list L}*/
char Modus(List2 L) {
    // kamus lokal
    address P, Q;
    int maxCount, currentCount;
    char modusChar;
    // algoritma
    maxCount = 0;
    modusChar = '\0'; // Inisialisasi dengan karakter null
    if (!IsEmptyList(L)) {
        P = First(L);
        do {
            currentCount = 0;
            Q = First(L);
            do {
                if (info(P) == info(Q)) {
                    currentCount++;
                }
                Q = next(Q);
            } while (Q != First(L));
            if (currentCount > maxCount) {
                maxCount = currentCount;
                modusChar = info(P);
            }
            P = next(P);
        } while (P != First(L));
    } // end if (IsEmptyList(L))
    return modusChar;
}

/*OPERASI BANYAK LIST*/
/*Procedure ConcatList(input L1:List2, input L2:List2, output L:List2)
{I.S.: L1,L2 terdefinisi ; 
 F.S.: L gabungan L1 dan L2}*/
void ConcatList(List2 L1, List2 L2, List2 *L) {
    // kamus lokal
    address P;
    // algoritma
    CreateList(L);
    if (!IsEmptyList(L1)) {
        P = First(L1);
        do {
            InsertVLast(L, info(P));
            P = next(P);
        } while (P != First(L1));
    } // end if (IsEmptyList(L1))
    if (!IsEmptyList(L2)) {
        P = First(L2);
        do {
            InsertVLast(L, info(P));
            P = next(P);
        } while (P != First(L2));
    } // end if (IsEmptyList(L2))
}

/*Procedure SplitList(input L:List2, output L1:List2, output L2:List2)
{I.S.: L terdefinisi ; 
 F.S.: L1, L2 hasil pemecahan L}*/
void SplitList(List2 L, List2 *L1, List2 *L2){
    //kamus lokal
    address P;
    int total, batas, idx;
    //algoritma
    CreateList(L1);
    CreateList(L2);
    total = NbElm(L);
    batas = (total + 1) / 2;
    P = First(L);
    idx = 1;

    if (!IsEmptyList(L)) {
        do {
            if (idx <= batas){
                InsertVLast(L1, info(P));
            } else {
                InsertVLast(L2, info(P));
            }
            idx++;
            P = next(P);
        } while (P != First(L));
    } // end if (IsEmptyList(L))
}

/*Procedure CopyList(input L1:List2, output L2:List2)
{I.S.: L1 terdefinisi;  
 F.S.: L2 menjadi salinan L1}*/
void CopyList(List2 L1, List2 *L2) {
    // kamus lokal
    address P;
    // algoritma
    CreateList(L2);
    if (!IsEmptyList(L1)) {
        P = First(L1);
        do {
            InsertVLast(L2, info(P));
            P = next(P);
        } while (P != First(L1));
    } // end if (IsEmptyList(L1))
}