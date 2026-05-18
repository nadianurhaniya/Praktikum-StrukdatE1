/* File : list3.c */
/* Deskripsi : ADT list berkait Ganda dengan representasi fisik pointer */
/* NIM & Nama : 24060124130069 - Nadia Azura Nurhaniya*/
/* Tanggal : 21 November 2025 */

#include "stdio.h"
#include "stdlib.h"
#include "list3.h" 

/*OPERATOR ALOKASI*/
/****************** Manajemen Memori ******************/
/* Function Alokasi(E:infotype)->address
{mengembalikan alamat elemen E bila berhasil, Nil bila gagal} */
address Alokasi(infotype E) //representasi fisik fungsi
{	//kamus lokal
	address P;
	//algoritma
	P = (address)malloc(sizeof(Elm));
	if (P != NIL) {
		info(P) = E;
		next(P) = NIL;
		prev(P) = NIL;
	}
	return P;
} 
 
/* procedure Dealokasi (input/output P:address) */ 
/* {I.S. P terdefinisi 
    F.S. P dikembalikan ke sistem  
	Proses: Melakukan pengembalian address P} */
void Dealokasi (address *P) {
	//kamus lokal
    
    // algoritma
    if ((*P) != NIL){
        next(*P) = NIL;
        (*P) = NIL;
    } // end if ((*P) == NIL)	
}

/* PROTOTYPE */
/********** PEMBUATAN LIST KOSONG ***********/
/* Procedure CreateList(output L:List3)
   {I.S.: - ; F.S.: L list kosong} 
   {proses: membuat list kosong}*/
void CreateList (List3 *L){
	First(*L) = NIL;
}

/****************** TEST LIST KOSONG ******************/
/* function IsEmptyList(L:List3) --> boolean 
   {mengembalikan true bila list L kosong} */
boolean IsEmptyList (List3 L){
	return First(L) == NIL; 
}

/*PENELUSURAN*/
/*procedure PrintList(input L:List3)
{I.S. L terdefinisi; F.S. :-}
{ menampilkan semua elemen list L} */
void PrintList(List3 L) {
	//kamus lokal
	address P;
	//algoritma
	P = First(L);
	if (P != NIL){
		printf("\nElemen:");
		do {
			printf("\t%c", info(P));
			P = next(P);
		} while (P != NIL);
	}
}

/*function NbElm(L:List3) --> integer
{ menghitung banyaknya elemen list L} */
int NbElm(List3 L) {
	//kamus lokal
	address P;
	int count;  //counter
	//algoritma
	count = 0;
	P = First(L);
	while (P != NIL) {
		count++;
		P = next(P);
	} // end while (P == NIL)
	return count;
}

/******* PENAMBAHAN ELEMEN LIST ********/
/* Procedure InsertVFirst(input/output L:List3, input V:infotype )
{ I.S. List L mungkin kosong, V terdefinisi }
{ F.S. L tetap, atau bertambah elemen pertama berinfo V }
{ Insert sebuah elemen beralamat P dengan Info(P)=V sebagai elemen pertama list linier L yg mungkin kosong } */
void InsertVFirst(List3 *L, infotype V ) {
	// kamus lokal
	address P;
	// algoritma
	P = Alokasi(V);
	if (IsEmptyList(*L)) { // list masih kosong
		First(*L) = P;
	} // end if (First(*L) != NIL)
	else { // list tidak kosong
		prev(First(*L)) = P;
		next(P) = First(*L);
		First(*L) = P;
	}
}

/*Procedure InsertVLast(input/output L:List3, input V:infotype )
{ I.S. List L mungkin kosong, V terdefinisi }
{ F.S. L tetap, atau bertambah elemen terakhir berinfo V}
{ Insert sebuah elemen beralamat P dengan Info(P)=V sebagai elemen akhir list linier L yg mungkin kosong }*/
void InsertVLast(List3 *L, infotype V ) {
	//kamus lokal
	address P;
	address Last; 
	//algoritma
	P = Alokasi(V);
	if (P != NIL) {
		if (First(*L) == NIL) { // jika list kosong
			First(*L) = P;
		} // end if (First(*L) != NIL)
		else { // list tidak kosong
			Last = First(*L);
			while (next(Last) != NIL) {
				Last = next(Last);
			} // end while (next(Last) == NIL)
			next(Last) = P;
			prev(P) = Last;
		}
	}
}

/******* PENGHAPUSAN ELEMEN ********/
/*Procedure DeleteVFirst(input/output L:List3, output V:infotype )
{ I.S. List L tidak kosong }
{ F.S. Elemen pertama list L dihapus, dan didealokasi. Hasil penghapusan disimpan nilainya dalam V. Default V='#'.
List mungkin menjadi kosong. Jika tidak kosong, elemen pertama list yang baru adalah elemen sesudah elemen pertama yang lama. } */
void DeleteVFirst(List3 *L, infotype *V) {
	//kamus lokal
	address P;
	//algoritma
	if (IsEmptyList(*L)) {
		printf ("\nList kosong, tidak dapat menghapus Elemen\n");
	} else {
		P = First(*L);
		*V = info(P);
		if (next(P) == NIL) { // hanya ada satu elemen
			First(*L) = NIL;
		} else { // lebih dari satu elemen
			First(*L) = next(P);
			prev(First(*L)) = NIL;
		} Dealokasi(&P);
	}
}

/*Procedure DeleteVLast(input/output L:List3, output V:infotype )
{ I.S. List L terdefinisi }
{ F.S. Elemen terakhir list L dihapus, dan didealokasi. Hasil penghapusan disimpan nilainya dalam V. Default V='#'.
List mungkin menjadi kosong. Jika tidak kosong, elemen terakhir list yang baru adalah elemen sebelum elemen terakhir yang lama. }*/
void DeleteVLast(List3 *L, infotype *V) {
    //kamus lokal
    address P;
    //algoritma
    if (!IsEmptyList(*L)) {
        P = First(*L);
        if (next(P) == NIL) { // 1 element
            *V = info(P);
            CreateList(L);
        } else { // 1 < element
            while (next(P) != NIL) {
                P = next(P);
            } // P sampai di elemen dengan next nya NIL (elemen terakhir)
            next(prev(P)) = NIL; // set next dari elemen P-1 dengan NIL
            *V = info(P);
            Dealokasi(&P);
        }
    } else { // list kosong
        printf("\n[List Kosong!!!]");
        *V = '#';
    }
}

/*Procedure DeleteX(input/output L:List3, input X:infotype)
{ I.S. List L terdefinisi }
{ F.S. List mungkin menjadi kosong, atau berkurang 1 elemen. }
{ Proses: Elemen bernilai X dihapus, dan didealokasi. }*/
void DeleteX(List3 *L, infotype X) {
	//kamus lokal
	address P;
	//algoritma
	if (!IsEmptyList(*L)) {
		P = First(*L);
		while (P != NIL && info(P) != X) {
			P = next(P);
		} // end while (P == NIL || info(P) == X)
		if (info(P) == X) { // ketemu elemen X
			if (P == First(*L)) { // elemen pertama
				First(*L) = next(P);
				if (First(*L) != NIL) { // jika masih ada elemen setelahnya
					prev(First(*L)) = NIL;
				}
			} else { // elemen tengah/akhir
				next(prev(P)) = next(P);
				if (next(P) != NIL) { // jika bukan elemen terakhir
					prev(next(P)) = prev(P);
				}
			} Dealokasi(&P);
		}
	}
}

/*** PENCARIAN ***/
/*Procedure SearchX(input L:List3, input X:infotype, output A:address )
{ I.S. L, X terdefinisi }
{ F.S. A berisi alamat elemen yang nilainya X. }
{ Proses : Mencari apakah ada elemen list dengan info(P)= X. Jika ada, mengisi A dengan address elemen tersebut. Jika tidak ada, A=Nil }*/
void SearchX(List3 L, infotype X, address *A) {
	//kamus lokal
	address p;
	boolean ketemu; 
	//algoritma
	*A = NIL;
	ketemu = false;
	p = First(L);
	while (p != NIL && !ketemu) {
		if (info(p) == X) { // ketemu elemen X
			*A = p;
			ketemu = true;
		}else { // belum ketemu
			p = next(p);
		}
	} // end while (p == NIL || ketemu)
}

/*** MANIPULASI ELEMEN LIST ***/
/*Procedure UpdateX(input/output L:List3, input X:infotype, input Y:infotype)
{ I.S. L, X, Y terdefinisi }
{ F.S. L tetap, atau elemen bernilai X berubah menjadi Y.}
{ Proses : Mengganti elemen bernilai X menjadi bernilai Y}*/
void UpdateX(List3 *L, infotype X, infotype Y){
	//kamus lokal
	address p;
	boolean found;
	//algoritma
	p = First(*L);
	found = false;
	while(p != NIL && !found){
		if (info(p) == X){ // ketemu elemen X
			found = true;
			info(p) = Y;
		}else{ // belum ketemu
			p = next(p);
		}
	} // end while (p == NIL || found)
}

/*Procedure Invers(input/output L:List3)
{ I.S. L terdefinisi }
{ F.S. urutan posisi elemen terbalik, misal {3,5,6} menjadi {6,5,3} }*/
void Invers(List3 *L){
    //kamus lokal
    address P;
    infotype V;
	List3 temp; //list sementara
    //algoritma
    CreateList(&temp);
    while (First(*L) != NIL){ //pindah semua elemen dari L ke temp secara terbalik
        DeleteVFirst(L, &V); //hapus elemen dari L
        InsertVFirst(&temp, V); //masukkan ke temp di awal
    } // end while (First(*L) == NIL)
    P = First(temp); // pindah kembali ke L
    while (P != NIL){ // insert semua elemen dari temp ke L
        InsertVLast(L, info(P)); 
        P = next(P);
    } // end while (P == NIL)
}

/*********** SOAL TAMBAHAN, DIKERJAKAN BILA LUANG *****************/
/*Procedure InsertVAfterX(input/output L:List3, input X:infotype, input V:infotype )
{ I.S. List L mungkin kosong }
{ F.S. P dialokasi, Info(P)=V }
{ Insert sebuah elemen beralamat P dengan Info(P)=V sebagai elemen dengan posisi setelah elemen bernilai X }*/
void InsertVAfterX(List3 *L, infotype X, infotype V){
	//kamus lokal
	address P; // elemen baru
	address Q; // penjelajah
	//algoritma
	if (!IsEmptyList(*L)) {
		Q = First(*L);
		while (Q != NIL && info(Q) != X) {
			Q = next(Q);
		} // end while (Q == NIL || info(Q) == X)
		if (info(Q) == X) { // ketemu elemen X
			P = Alokasi(V);
			if (next(Q) != NIL) { // insert di tengah
				next(P) = next(Q);
				prev(next(Q)) = P;
			} prev(P) = Q; 
			next(Q) = P;
		} // end if (info(Q) == X
	}
}

/*Procedure InsertVBeforeX(input/output L:List3, input X:infotype, input V:infotype )
{ I.S. List L mungkin kosong }
{ F.S. P dialokasi, Info(P)=V }
{ Insert sebuah elemen beralamat P dengan Info(P)=V sebagai elemen dengan posisi sebelum elemen bernilai X }*/
void InsertVBeforeX(List3 *L, infotype X, infotype V) {
	//kamus lokal
	address P; // elemen baru
	address Q; // penjelajah
	//algoritma
	if (!IsEmptyList(*L)) {
		Q = First(*L);
		while (next(Q) != NIL && info(Q) != X) {
			Q = next(Q);
		} // end while (Q == NIL || info(Q) == X)
		if (info(Q) == X) { // ketemu elemen X
			P = Alokasi(V);
			if (Q != First(*L)) { // insert di tengah/akhir
				next(prev(Q)) = P;
			} else { // insert di awal
				First(*L) = P;
			} prev(P) = prev(Q);
			next(P) = Q;
			prev(Q) = P;
		} // end if (info(Q) == X
	}
}

/*Procedure DeleteVAfterX(input/output L:List3, input X:infotype, output V:infotype )
{ I.S. List L tidak kosong }
{ F.S. Elemen setelah X dihapus, dan didealokasi. Hasil penghapusan disimpan nilainya dalam V.
List mungkin menjadi kosong. }*/
void DeleteVAfterX(List3 *L, infotype X, infotype *V) {
	//kamus lokal
	address P, Q;
	//algoritma
	if (!IsEmptyList(*L)) {
		P = First(*L);
		while (P != NIL && info(P) != X) {
			P = next(P);
		} // end while (P == NIL || info(P) == X)
		if (info(P) == X && next(P) != NIL) { // ketemu elemen X dan ada elemen setelahnya
			Q = next(P);
			*V = info(Q);
			next(P) = next(Q);
			if (next(Q) != NIL) { // jika Q bukan elemen terakhir
				prev(next(Q)) = P;
			} 
			Dealokasi(&Q); 
		} // end if (info(P) == X
	}
}

/*Procedure DeleteVBeforeX(input/output L:List3, input X:infotype, output V:infotype )
{ I.S. List L tidak kosong }
{ F.S. Elemen sebelum X dihapus, dan didealokasi. Hasil penghapusan disimpan nilainya dalam V.
List mungkin menjadi kosong. }*/
void DeleteVBeforeX(List3 *L, infotype X, infotype *V) {
	//kamus lokal
	address P, Q, Prec;
	//algoritma
	if (!IsEmptyList(*L)) { // list tidak kosong
		P = First(*L);
		Prec = NIL;
		while (P != NIL && info(P) != X) {
			Prec = P;
			P = next(P);
		} // end while (P == NIL || info(P) == X)
		if (info(P) == X) { // ketemu elemen X
			if (Prec == NIL) { // Jika yang dihapus adalah first
				printf("\nTidak ada elemen sebelum elemen pertama.\n");
			} else { // ada elemen sebelum X
				if (Prec == First(*L)) { // Jika yang dihapus adalah first
					DeleteVFirst(L, V);
				} else { // elemen tengah/akhir
					Q = First(*L);
					while (next(Q) != Prec) {
						Q = next(Q);
					}
					*V = info(Prec);
					next(Q) = P;
					prev(P) = Q;
					Dealokasi(&Prec);
				} 
			} // end if (Prec == NIL)
		} // end if (info(P) == X)
	}
}

/*function CountX(L:List3, X:infotype) -> integer */
/*{ mengembalikan banyaknya kemunculan X dalam list L}*/
int CountX(List3 L, infotype X) {
	//kamus lokal
	address P;
	int count; //counter
	//algoritma
	count = 0;
	P = First(L);
	while (P != NIL) {
		if (info(P) == X) {
			count++;
		} //
		P = next(P);
	} // end while (P == NIL)
	return count;
}

/*function FrekuensiX(L:List3, X:infotype) -> real */
/*{ mengembalikan rasio kemunculan X dibandingkan ukuran list L }*/
float FrekuensiX(List3 L, infotype X) {
	// kamus lokal
	int total; // total elemen
	int count; // counter kemunculan X
	// algoritma
	count = CountX(L, X);
	total = NbElm(L);
	if (total > 0) { 
	   return (float) count / total;
	} else {
	    return 0.0;
	} // end if (total <= 0)
}

/*function MaxMember(L:List3) -> integer */
/*{ mengembalikan banyaknya huruf yang paling banyak muncul di list L}*/
int MaxMember(List3 L) {
	//kamus lokal
	address P; // penjelajah
	int max; // counter maksimum
	int count; // counter sementara
	//algoritma
	max = 0;
	P = First(L);
	while (P != NIL) {
		count = CountX(L, info(P));
		if (count > max) {
			max = count;
		}
		P = next(P);
	} // end while (P == NIL)
	return max;
}

/*function Modus(L:List3) -> character */
/*{ mengembalikan huruf yang paling banyak muncul dalam list L}*/
char Modus(List3 L) {
	//kamus lokal
	address P, Q;
	int maxCount; // counter maksimum
	int currentCount; // counter sementara
	char modus; // hasil modus
	// algoritma
	maxCount = 0;
	modus = '\0'; // Inisialisasi dengan karakter null
	P = First(L);
	while (P != NIL) {
		currentCount = 0;
		Q = First(L);
		while (Q != NIL) {
			if (info(P) == info(Q)) {
				currentCount++;
			}
			Q = next(Q);
		} // end while (Q == NIL)
		if (currentCount > maxCount) {
			maxCount = currentCount;
			modus = info(P);
		}
		P = next(P);
	} // end while (P == NIL)
	return modus;
}

/*function CountVocal(L:List3) -> integer */
/*{ mengembalikan banyaknya kemunculan huruf vokal dalam list L}*/
int CountVocal(List3 L) {
	//kamus lokal
	address P;
	int count; //counter
	//algoritma
	count = 0;
	P = First(L);
	while (P != NIL) {
		if (info(P) == 'A' || info(P) == 'a' ||
			info(P) == 'I' || info(P) == 'i' ||
			info(P) == 'U' || info(P) == 'u' ||
			info(P) == 'E' || info(P) == 'e' ||
			info(P) == 'O' || info(P) == 'o') {
			count++;
		} // end if (info(P) != huruf vokal)
		P = next(P);
	} // end while (P == NIL)
	return count;
}

/*function CountNG(L:List3) -> integer */
/*{ mengembalikan banyaknya huruf N yang langsung diikuti huruf G dalam list L}*/
int CountNG(List3 L) {
	//kamus lokal
	address P;
	int count; //counter
	//algoritma
	count = 0;
	P = First(L);
	while (P != NIL && next(P) != NIL) {
		if (info(P) == 'N' && info(next(P)) == 'G') {
			count++;
		} // end if (info(P) != 'N' || info(next(P)) != 'G')
		P = next(P);
	} // end while (P == NIL || next(P) == NIL)
	return count;
}

/*Procedure SearchAllX(input L:List3, input X:infotype)
{ I.S. L, X terdefinisi }
{ F.S. - }
{ Proses: menampilkan posisi-posisi kemunculan elemen X dalam list L }*/
/*misal L=['M','A','N','D','A'], SearchAllX(L,'A') menampilkan angka 2,5 */
/*misal L=['M','A','N','D','A'], SearchAllX(L,'J') menampilkan angka 0 */
void SearchAllX(List3 L, infotype X) {
	//kamus lokal
	address P; // penjelajah
	int posisi; // counter posisi
	boolean found; // penanda ketemu
	//algoritma
	posisi = 1;
	found = false;
	P = First(L);
	printf("\nPosisi kemunculan elemen '%c': ", X);
	while (P != NIL) {
		if (info(P) == X) {
			printf("%d ", posisi);
			found = true;
		} // end if (info(P) != X)
		P = next(P);
		posisi++;
	} // end while (P == NIL)
	if (!found) { // tidak ada kemunculan elemen X
		printf("0");
	}
}

/*Procedure DeleteAllX(input/output L:List3, input X:infotype)
{ I.S. List L tidak kosong }
{ F.S. List mungkin menjadi kosong. }
{ Proses: Semua elemen bernilai X dihapus, dan didealokasi. }*/
void DeleteAllX(List3 *L, infotype X) {
	//kamus lokal
	address P, Q; 
	//algoritma
	if (!IsEmptyList(*L)) {
		P = First(*L);
		while (P != NIL) {
			if (info(P) == X) { // ketemu elemen X
				Q = P;
				if (P == First(*L)) { // elemen pertama
					First(*L) = next(P);
					if (First(*L) != NIL) { // ada elemen setelahnya
						prev(First(*L)) = NIL;
					} 
					P = First(*L);
				} else { // elemen tengah/akhir
					next(prev(P)) = next(P);
					if (next(P) != NIL) { // jika bukan elemen terakhir
						prev(next(P)) = prev(P);
					} 
					P = next(P);
				} Dealokasi(&Q);
			} else { // belum ketemu
				P = next(P);
			} // end if (info(P) == X)
		} // end while (P == NIL)
	}
}

/*OPERASI BANYAK LIST*/
/*Procedure ConcatList(input L1:List3, input L2:List3, output L:List3)
{I.S.: L1,L2 terdefinisi ; 
 F.S.: L gabungan L1 dan L2}*/
void ConcatList(List3 L1, List3 L2, List3 *L) {
	//kamus lokal
	address P; 
	infotype V;
	//algoritma
	CreateList(L);
	P = First(L1);
	while (P != NIL) { 
		V = info(P);
		InsertVLast(L, V);
		P = next(P);
	} // end while (P == NIL)
	P = First(L2);
	while (P != NIL) {
		V = info(P);
		InsertVLast(L, V);
		P = next(P);
	} // end while (P == NIL)
}

/*Procedure SplitList(input L:List3, output L1:List3, output L2:List3)
{I.S.: L terdefinisi ; 
 F.S.: L1, L2 hasil pemecahan L}*/
void SplitList(List3 L, List3 *L1, List3 *L2) {
	//kamus lokal
	address P; // penjelajah
	int total; // total elemen
	int batas; // batas pemisahan
	int idx; // counter indeks
	//algoritma
	CreateList(L1);
	CreateList(L2);
	total = NbElm(L);
	batas = (total + 1) / 2;
	P = First(L);
	idx = 1;

	if (!IsEmptyList(L)) { // list tidak kosong
		while (P != NIL) {
			if (idx <= batas) { // masuk ke L1
				InsertVLast(L1, info(P));
			} else { // masuk ke L2
				InsertVLast(L2, info(P));
			} 
			idx++;
			P = next(P);
		} // end while (P == NIL)
	} // end if (IsEmptyList(L))
}

/*Procedure CopyList(input L1:List3, output L2:List3)
{I.S.: L1 terdefinisi;  
 F.S.: L2 menjadi salinan L1}*/
void CopyList(List3 L1, List3 *L2) {
	//kamus lokal
	address P;
	infotype V;
	//algoritma
	CreateList(L2);
	P = First(L1);
	while (P != NIL) { 
		V = info(P);
		InsertVLast(L2, V);
		P = next(P);
	} // end while (P == NIL)
}
