/* File : list1.c */
/* Deskripsi : realisasi body ADT list berkait representasi fisik pointer */
/* NIM & Nama : 24060124120019 & Nadia Azura Nurhaniya*/
/* Tanggal : 7 November 2025 */
#include <stdio.h>
#include <stdlib.h>
#include "list1.h"

/**************** OPERATOR ALOKASI ****************/
/********* manajemen memori ********/
/* Function Alokasi(E:infotype)->address
{mengembalikan alamat elemen E bila berhasil, Nil bila gagal} */
address Alokasi(infotype E) {
	//kamus lokal
	address P;
	//algoritma
	P = (address) malloc(sizeof(Elm));
	if (P != NIL) { //ruang memori tersedia
		info(P) = E;
		next(P) = NIL;
	} // end if (P == NIL)
	return P;
}

/* procedure Dealokasi (input/output P:address) */ 
/* {I.S. P terdefinisi 
    F.S. P dikembalikan ke NIL  
	Proses: Melakukan pengosongan address P} */
void Dealokasi (address P) {
	//kamus lokal
	
	//algoritma
	if ( P != NIL ) {
		next(P) = NIL;
	} // end if (P == NIL)
	P = NIL;
}
/*********** OPERATORS ***********/
/********** PEMBUATAN LIST KOSONG ***********/
/* Procedure CreateList(output L:List1)
   {I.S.: - ; F.S.: L list kosong} 
   {proses: membuat list kosong}*/
void CreateList (List1 *L) {
	//kamus lokal
	//algoritma
	First(*L) = NIL;
}

/****************** TEST LIST KOSONG ******************/
/* function IsEmptyList(L:List1) --> boolean 
   {mengembalikan true bila list L kosong} */
boolean IsEmptyList (List1 L) {
	//kamus lokal
	//algoritma
	return First(L) == NIL; 
}

/**************** PENELUSURAN ****************/
/*procedure PrintList(input L:List1)
{I.S. L terdefinisi; F.S. :-}
{ menampilkan info semua elemen list L} */
void PrintList(List1 L) {
	//kamus lokal 
	address P;
	//algoritma
	P = First(L);
	if (P != NIL) {
		printf("\nElemen = ");
		do {
			printf("\t%c", info(P));
			P = next(P);
		} while( P != NIL );
	}
}

/*function NbElm(L:List1) --> integer
{ menghitung banyaknya elemen list L} */
int NbElm(List1 L) {
	//kamus lokal
	address P;
	int count; //counter
	//algoritma
	count = 0;
	P = First(L);
	while (P != NIL) {  // selama elemen belum habis (belum mencapai akhir list)
		count++;
		P = next(P);    // geser ke elemen berikutnya
	} // end while (P == NIL)
	return count;
}

/******* PENAMBAHAN ELEMEN LIST ********/
/* Procedure InsertVFirst(input/output L:List1, input V:infotype )
{ I.S. L mungkin kosong, V terdefinisi }
{ F.S. L tetap, atau bertambah elemen pertama berinfo V }
{ Proses: Insert sebuah elemen beralamat P dengan Info(P)=V sebagai elemen pertama list linier L yg mungkin kosong } */
void InsertVFirst(List1 *L, infotype V ) {
	//kamus lokal
	address P;
	//algoritma
	P = Alokasi (V);
	if (P != NIL) { // jika alokasi berhasil
		if (First(*L) == NIL) { // list masih kosong
			First(*L) = P;
		} // end if (First(*L) != NIL)
		else { // list tidak kosong
			next(P) = First(*L);
			First(*L) = P;
		}
 	} // end if (P == NIL)
}

/*Procedure InsertVLast(input/output L:List1, input V:infotype )
{ I.S. L mungkin kosong, V terdefinisi }
{ F.S. L tetap, atau bertambah elemen terakhir berinfo V}
{ Proses: Insert sebuah elemen beralamat P dengan Info(P)=V sebagai elemen akhir list linier L yg mungkin kosong }*/
void InsertVLast(List1 *L, infotype V ) {
	// kamus lokal
    address P;
	address A;
    // algoritma
    P = Alokasi(V); 
    if (P != NIL) {  // jika alokasi berhasil 
        if (IsEmptyList(*L)) { // jika list kosong
            First(*L) = P;
        } // end if (!IsEmptyList(*L))
        else {  // list tidak kosong
            A = First(*L);
            while (next(A) != NIL) {  
                A = next(A);  
            } // end while (next(A) == NIL)
            next(A) = P; 
		}
	} // end if (P == NIL)
}

/******* PENGHAPUSAN ELEMEN ********/
/*Procedure DeleteVFirst(input/output L:List1, output V:infotype )
{ I.S. L terdefinisi,  }
{ F.S. L tetap, atau berkurang elemen pertamanya.
Proses: Elemen pertama list L dihapus, dan didealokasi. Hasil penghapusan disimpan nilainya dalam V. default nilai V='#'.
List mungkin menjadi kosong. Jika tidak kosong, elemen pertama yang baru adalah elemen sesudah elemen pertama yang lama. } */
void DeleteVFirst(List1 *L, infotype *V){
	// kamus lokal
	address P;
	// algoritma
	if (!IsEmptyList(*L)) {   // jika list tidak kosong
        P = First(*L);              
        *V = info(P);               
        First(*L) = next(P);        
        Dealokasi(P);               
    } // end if (IsEmptyList(*L))
    else {  // jika list kosong
        *V = '#';                   
    }
}

/*Procedure DeleteVLast(input/output L:List1, output V:infotype )
{ I.S. L terdefinisi }
{ F.S. L tetap atau berkurang elemen terakhirnya.
Proses: Elemen terakhir list L dihapus, dan didealokasi. Hasil penghapusan disimpan nilainya dalam V. default nilai V='#'.
List mungkin menjadi kosong. Jika tidak kosong, elemen terakhir yang baru adalah elemen sebelum elemen terakhir yang lama. }*/
void DeleteVLast(List1 *L, infotype *V){
	// kamus lokal
	address P;
	address A;
    // algoritma
    if (!IsEmptyList(*L)) {    // jika list tidak kosong     
        P = First(*L);
        A = NIL;
        while (next(P) != NIL) {   // cari hingga node terakhir
            A = P;
            P = next(P);
        } // end while (next(P) == NIL)
        *V = info(P);       
		if (A == NIL) {   // jika hanya ada satu elemen            
            First(*L) = NIL;
        } // end if (A != NIL)
        else {         // jika lebih dari satu elemen
            next(A) = NIL;          
        }
        Dealokasi(P);                  
    } // end if (IsEmptyList(*L))
    else {       // jika kosong, tidak ada yang dihapus
        *V = '#';                       
    }
}

/*** PENCARIAN ***/
/*Procedure SearchX(input L:List1, input X:infotype, output A:address )
{ I.S. L, X terdefinisi }
{ F.S. A berisi alamat elemen yang nilainya X.
Proses: Mencari apakah ada elemen list dengan info(P)= X. Jika ada, mengisi A dengan address elemen tersebut. Jika tidak ada, A=Nil }*/
void SearchX(List1 L, infotype X, address *A) {
	//kamus lokal
	address P;
	//algoritma
	P = First(L);
	(*A) = NIL;
	while (P != NIL) {  // selama masih ada elemen (belum akhir list)
		if (info(P) == X) {  // jika nilai X ketemu
			(*A) = P;
			P = NIL;
		} // end if (info(P) != X)
		else {  // jika X belum ketemu 
			P = next(P);
		}
	} // end while (P == NIL)
}

/*** MANIPULASI ELEMEN LIST ***/
/*Procedure UpdateX(input/output L:List1, input X:infotype, input Y:infotype)
{ I.S. L, X, Y terdefinisi }
{ F.S. L tetap, atau elemen bernilai X berubah menjadi Y.
Proses: Mengganti elemen bernilai X menjadi Y}*/
void UpdateX(List1 *L, infotype X, infotype Y) {
	//kamus lokal
	address P;
	//algoritma
	P = First(*L);
	while (P != NIL) {
		if (info(P) == X) { // jika nilai X ditemukan
			info(P) = Y;    // diganti dengan Y
		} // end if (info(P) != X)
		P = next(P);     // lanjut elemen berikutnya
	} // end while (P == NIL)
}

/*Procedure Invers(input/output L:List1)
{ I.S. L terdefinisi }
{ F.S. urutan posisi elemen terbalik, misal {'i','t','u'} menjadi {'u','t','i'} }*/
void Invers(List1 *L) {
	//kamus lokal
	address P;
	address Prec;   //menyimpan elemen sebelumnya
	address Temp;   //menyimpan elemen berikutnya untuk sementara
	//algoritma
	if (!IsEmptyList(*L) && next(First(*L)) != NIL) {
		P = First(*L);
		Prec = NIL;

		while (P != NIL) {    // selama belum mencapai akhir list
			Temp = next(P);
			next(P) = Prec;
			Prec = P;
			P = Temp;
		} // end while (P == NIL)
		First(*L) = Prec;     // ubah head list ke elemen terakhir (yang jadi pertama)
	} // end if (IsEmptyList(*L) || next(First(*L)) == NIL)
}

/*********** SOAL TAMBAHAN, DIKERJAKAN BILA LUANG *****************/
/*function CountVocal(L:List1, X:infotype) -> integer */
/*{ mengembalikan banyaknya kemunculan huruf vokal dalam list L}*/
int CountVocal(List1 L){
	//kamus lokal
	address P;
	int count; //counter
	//algoritma
	count = 0;
	P = First(L);
	while (P != NIL) {
		if (
			info(P) == 'a' || info(P) == 'A' ||
			info(P) == 'i' || info(P) == 'I' ||
			info(P) == 'u' || info(P) == 'U' ||
			info(P) == 'e' || info(P) == 'E' ||
			info(P) == 'o' || info(P) == 'O')
			count++;
		// end if (info(P) != vokal)
		P = next(P);
	} // end while (P == NIL)
	return count;
}

/*function CountX(L:List1, X:infotype) -> integer */
/*{ mengembalikan banyaknya kemunculan X dalam list L}*/
int CountX(List1 L, infotype X) {
	//kamus lokal
	address P;
	int count;  //counter
	//algoritma
	count = 0;
	P = First(L);
	while (P != NIL) {
		if (info(P) == X)   // jika elemen sama dengan X
			count++;
		// end if (info(P) != X)
		P = next(P);
	} // end while (P == NIL)
	return count;
}

/*function FrekuensiX(L:List1, X:infotype) -> real */
/*{ mengembalikan rasio kemunculan X dibandingkan ukuran list L }*/
float FrekuensiX(List1 L, infotype X) {
	//kamus lokal
	address P;
	int Frek;
	int total;  //counter (banyak kemunculan X)
	//algoritma
	Frek = 0;
	total = 0;
	P = First(L);
	while (P != NIL) {
		total++;
		if (info(P) == X)
			Frek++;
		// end if (info(P) != X)
		P = next(P);
	} // end while (P == NIL)
	if (total == 0)        // jika list kosong
		return 0.0;
	else                  // jika list tidak kosong
		return (float)Frek / (float)total;  
}

/*Procedure SearchAllX(input L:List1, input X:infotype)
{ I.S. L, X terdefinisi }
{ F.S. -
Proses: menampilkan posisi-posisi (1,2,3,...nbElm(L)) kemunculan elemen X dalam list L }*/
void SearchAllX(List1 L, infotype X) {
	//kamus lokal
	address P;
	int position;
	//algoritma
	P = First(L);
	position = 1;
	printf("\nPosisi kemunculan elemen %c : ", X);
	while (P != NIL) {
		if (info(P) == X) {       // jika elemen X ditemukan
			printf("%d ", position);
		} // end if (info(P) != X)
		P = next(P);
		position++;
	} // end while (P == NIL)
	printf("\n");
}

/*Procedure UpdateAllX(input/output L:List1, input X:infotype, input Y:infotype)
{ I.S. L, X, Y terdefinisi }
{ F.S. L tetap, atau semua elemen bernilai X berubah menjadi Y. 
Proses : mengganti semua elemen bernilai X menjadi Y}*/
void UpdateAllX(List1 *L, infotype X, infotype Y) {
	//kamus lokal
	address P;
	//algoritma
	P = First(*L);
	while (P != NIL) {
		if (info(P) == X) {     // jika elemen sama dengan X
			info(P) = Y;
		} // end if (info(P) != X)
		P = next(P);
	} // end while (P == NIL)
}

/* Procedure InsertVAfter(input/output L:List1, input V:infotype, input VA:infotype )
{ I.S. List L mungkin kosong, V, S terdefinisi }
{ F.S. L tetap, atau bertambah 1 elemen (VA) pada posisi setelah elemen berinfo V}
{ Proses: Insert sebuah elemen beralamat P dengan Info(P)=VA sebagai elemen setelah elemen V list linier L yg mungkin kosong } */
void InsertVAfter(List1 *L, infotype V, infotype VA ) {
	//kamus lokal
	address P;
	address temp;
	boolean found;
	//algoritma
	temp = Alokasi(VA);
	found = false;
	P = First(*L);
	while (P != NIL && !found) {  // selama belum akhir list dan belum ditemukan V
		if (info(P) == V) {       // jika elemen dengan info = V ditemukan
			next(temp) = next(P);

			next(P) = temp;
			found = true;
		} // end if (info(P) != V)
		P = next(P);
	} // end while (P == NIL || found)
}

/*function Modus(L:List1) -> infotype */
/*{ mengembalikan huruf yang paling banyak muncul dalam list L}*/
infotype Modus(List1 L) {
	//kamus lokal
	infotype A;
	int counter;
	address P;
	//algoritma
	A = '#';
	counter = 0;
	P = First(L);
	while (P != NIL ) {     // selama belum akhir list
		if (CountX(L, info(P)) > counter){
			counter = CountX(L, info(P));    // simpan nilai frekuensi baru
			A = info(P);
		} // end if (CountX(L, info(P)) <= counter)
		P = next(P);
	} // end while (P == NIL)
	return A;
}

/*function NbModus(L:List1) -> integer */
/*{ mengembalikan banyaknya huruf yang paling banyak muncul di list L}*/
int NbModus(List1 L) {
	//kamus lokal
	address P;
	infotype A;
	int counter;
	//algoritma
	A = '#';
	counter = 0;
	P = First(L);
	while (P != NIL) {      // selama belum akhir list
		if (CountX(L, info(P)) > counter) {
			counter = CountX(L, info(P));
			A = info(P);
		} // end if (CountX(L, info(P)) <= counter)
		P = next(P);
	} // end while (P == NIL)
	return counter;
}

/*OPERASI BANYAK LIST*/
/*Procedure ConcatList(input L1:List1, input L2:List1, output L:List1)
{I.S.: L1,L2 terdefinisi ; 
 F.S.: L gabungan L1 dan L2}*/
void ConcatList(List1 L1, List1 L2, List1 *L) {
	//kamus lokal
    address P;
    //algoritma
    CreateList(L);

    // salin semua elemen dari L1 ke L
    P = First(L1);
    while (P != NIL) {
        InsertVLast(L, info(P));
        P = next(P);
    }

    // lanjut salin semua elemen dari L2 ke L
    P = First(L2);
    while (P != NIL) {
        InsertVLast(L, info(P));
        P = next(P);
    }
}

/*Procedure SplitList(input L:List1, output L1:List1, output L2:List1)
{I.S.: L terdefinisi ; 
 F.S.: L1, L2 hasil pemecahan L}*/
void SplitList(List1 L, List1 *L1, List1 *L2) {
	// kamus lokal
	address P;
    int i, n, batas;
    // algoritma
    CreateList(L1);
    CreateList(L2);

    n = NbElm(L);
    if (n == 0) return;     // jika list kosong, tidak perlu dibagi

    batas = n / 2;
    if (n % 2 != 0) {      // jika jumlah elemen ganjil
        batas = batas + 1;
    } // end if (n % 2 == 0)

    P = First(L);
    for (i = 1; i <= n; i++) {     // menelusuri seluruh elemen
        if (i <= batas) {
            InsertVLast(L1, info(P));
        } else {
            InsertVLast(L2, info(P));
        }
        P = next(P);
    }
}

/*Procedure CopyList(input L1:List1, output L2:List1)
{I.S.: L1 terdefinisi;  
 F.S.: L2 menjadi salinan L1}*/
void CopyList(List1 L1, List1 *L2) {
	//kamus lokal
	address P;
	//algoritma
	P = First(L1);
	CreateList(L2);
	while (P != NIL) {       // selama masih ada elemen di L1
		InsertVLast(L2, info(P));  // salin ke L2
		P = next(P);
	} // end while (P == NIL)
}



