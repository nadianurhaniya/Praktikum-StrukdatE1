#include "tabel.h"
#include "boolean.h"
#include <stdio.h>

/* Program   : tabel.c */
/* Deskripsi : kode program dari ADT Tabel*/
/* NIM/Nama  : 24060124120019/Nadia Azura Nurhaniya */
/* Tanggal   : 12 September 2025 */

/************************KONSTRUKTOR*************************/				 
/* procedure createTable( output T: Tabel)
	{I.S.: -}
	{F.S.: size=0, setiap elemen wadah dengan 1 karakter spasi, spasi dianggap karakter kosong}
	{Proses: menginisialisasi T} */
void createTable(Tabel *T){
	/*Kamus Lokal*/
    int i;

	/*Algoritma*/
    (*T).size = 0;
    for (i = 1; i <= 10; i++){
        (*T).wadah[i] = ' ';  
    }
}

/************************SELEKTOR*************************/
/* function getSize( T: Tabel) -> integer
	{mengembalikan banyak elemen pengisi T } */
int getSize(Tabel T){
	return T.size;
}

/*************************PREDIKAT*************************/
/* function isEmptyTable( T: Tabel) -> boolean
	{mengembalikan True jika T kosong } */
boolean isEmptyTable(Tabel T){
	return (T.size == 0);
}

/* function isFullTable( T: Tabel) -> boolean
	{mengembalikan True jika T penuh } */
boolean isFullTable(Tabel T){
	return (T.size == 10);
}

/*************************OPERASI PENCARIAN*************************/
/*  procedure searchX (input T:Tabel, input X:character, output pos:integer )
	{I.S.: T terdefinisi, x terdefinisi }
	{F.S.: pos berisi posisi ketemu di T.wadah, atau -999 jika tidak ketemu }
	{Proses: mencari elemen bernilai x dalam T.wadah} */
void searchX(Tabel T, char x, int *pos){
	/*Kamus Lokal*/
	int i;
	*pos = -999;

	/*Algoritma*/
	for (i = 1; i <= T.size; i++){
		if (T.wadah[i] == x){
			*pos = i;
			return;
		}
	}
}

/* function countX (T:Tabel, x:character) -> integer
	{mengembalikan banyaknya elemen bernilai X dalam T.wadah} */
int countX(Tabel T, char x){
	/*Kamus Lokal*/
	int i;
	int count = 0;

	/*Algoritma*/
	for (i = 1; i <= T.size; i++){
		if (T.wadah[i] == x){
			count++;
		}
	}
    return count;
}

/* function countVocal(T: Tabel) -> integer
	{mengembalikan banyak elemen T yang berupa karakter huruf vocal } */
int countVocal(Tabel T){
	/*Kamus Lokal*/
	int i, count = 0;

	/*Algoritma*/
    for (i = 1; i <= T.size; i++){
        if (T.wadah[i] == 'A' || T.wadah[i] == 'a' ||
			T.wadah[i] == 'I' || T.wadah[i] == 'i' ||
			T.wadah[i] == 'U' || T.wadah[i] == 'u' ||
			T.wadah[i] == 'E' || T.wadah[i] == 'e' ||
    		T.wadah[i] == 'O' || T.wadah[i] == 'o'){
     		count++;
		}
	}
    return count;
}

/*************************MUTATOR*************************/
/* procedure addXTable (input/output T:Tabel, input x: character)
	{I.S.: T terdefinisi, x terdefinisi }
	{F.S.: isi T.wadah bertambah 1 elemen jika belum penuh}
	{Proses: mengisi elemen T.wadah dengan nilai x}*/
void addXTable(Tabel *T, char x){
	 if (!isFullTable(*T)){
        (*T).size++;
        (*T).wadah[(*T).size] = x;
    }
}

/* procedure addUniqueXTable (input/output T:Tabel, input x: character)
	{I.S.: T terdefinisi, x terdefinisi }
	{F.S.: isi T.wadah bertambah 1 elemen jika x unik dan tabel belum penuh}
	{Proses: mengisi elemen T.wadah dengan nilai unik x}*/
void addUniqueXTable(Tabel *T, char x){
	/*Kamus Lokal*/
	int pos;

	/*Algoritma*/
	if (!isFullTable(*T))
	{
		searchX(*T, x, &pos);
		if (pos == -999)
		{
			(*T).size++;
			(*T).wadah[T->size] = x;
		}
	}
}

/* procedure delXTable (input/output T:Tabel, input x:character)
	{I.S.: T terdefinisi, x terdefinisi}
	{F.S.: isi T.wadah berkurang 1 elemen jika belum kosong}
	{Proses: menghapus 1 elemen bernilai x, geser semua elemen sisa}*/
void delXTable(Tabel *T, char x){
	/*Kamus Lokal*/
	int pos, i;

	/*Algoritma*/
    searchX(*T, x, &pos);
    if (pos != -999){
        for (i = pos; i < (*T).size; i++){
            (*T).wadah[i] = (*T).wadah[i + 1];
        }
        (*T).wadah[(*T).size] = ' ';
        (*T).size--;
    }
}

/* procedure delTable (input/output T:Tabel, input idx:integer)
	{I.S.: T terdefinisi, idx antara 1...getSize(T)}
	{F.S.: isi T.wadah berkurang 1 elemen jika belum kosong}
	{Proses: menghapus 1 elemen pada posisi idx, geser semua elemen sisa}*/
void delTable(Tabel *T, int idx){
	/*Kamus Lokal*/
	int i;

	/*Algoritma*/
    if (idx >= 1 && idx <= (*T).size){
        for (i = idx; i < (*T).size; i++){
            (*T).wadah[i] = (*T).wadah[i + 1];
        }
        (*T).wadah[(*T).size] = ' ';
        (*T).size--;
    }
}

/* procedure delAllXTable (input/output T:Tabel, input x:character)
	{I.S.: T terdefinisi}
	{F.S.: isi T.wadah berkurang semua elemen bernilai X jika belum kosong}
	{Proses: menghapus semua elemen bernilai X, geser elemen sisa}*/
void delAllXTable(Tabel *T, char x){
	/*Kamus Lokal*/
	int i = 1;

	/*Algoritma*/
    while (i <= (*T).size){
        if ((*T).wadah[i] == x){
            delTable(T, i);
        } else {
            i++;
        }
    }
}

/*************************OPERASI BACA/TULIS*************************/
/* procedure printTable (input T:Tabel)
	{I.S.: T terdefinisi}
	{F.S.: -}
	{Proses: menampilkan semua elemen T ke layar} */
void printTable(Tabel T){
    /*Kamus lokal*/
    int i;

    /*Algoritma*/
    printf("[");
    for (i = 1; i <= 10; i++){
        printf("%c", T.wadah[i]);
        if (i < 10){
            printf(",");
        }
    }
    printf("]\n");
}


/* procedure viewTable (input T:Tabel)
	{I.S.: T terdefinisi}
	{F.S.: -}
	{Proses: menampilkan elemen T yang terisi ke layar} */
void viewTable(Tabel T){
    /*Kamus lokal*/
    int i;

    /*Algoritma*/
    printf("[");
    for (i = 1; i <= T.size; i++){
        printf("%c", T.wadah[i]);
        if (i < T.size){
            printf(",");
        }
    }
    printf("]\n");
}


/* procedure populateTable (input/output T:Tabel, input N: integer)
	{I.S.: T terdefinisi, N terdefinisi dalam rentang 1..10}
	{F.S.: T.wadah terisi sebanyak N elemen }
	{Proses: mengisi elemen T.wadah sebanyak N kali dari keyboard}
	{Syarat: angka-angka masukan keyboard > 0 }*/
void populateTable(Tabel *T, int N){
	/*Kamus Lokal*/
	int i;
    char c;

	/*Algoritma*/
    createTable(T);
    for (i = 1; i <= N; i++){
        printf("Masukkan karakter ke-%d (A-Z): ", i);
        scanf(" %c", &c);
        addXTable(T, c);
    }
}

/*************************OPERASI STATISTIK*************************/
/*function Modus (T:Tabel ) -> integer 
	{mengembalikan elemen pengisi T yang paling banyak muncul } */
	/*asumsi: bila terdapat banyak yang sama maka yang diambil yang pertama*/
int Modus(Tabel T){
	/*Kamus Lokal*/
    int i, maxCount = 0, tempCount;
    char modus = ' ';

	/*Algoritma*/
    for (i = 1; i <= T.size; i++){
        tempCount = countX(T, T.wadah[i]);
        if (tempCount > maxCount){
            maxCount = tempCount;
            modus = T.wadah[i];
        }
    }
    return modus;
}

/*************************OPERASI RELASIONAL*************************/
/* function IsEqualTable (T1:Tabel, T2: Tabel ) -> boolean 
	{mengembalikan true jika T1 memiliki elemen dan urutan yang sama dengan T2 } */
boolean isEqualTable(Tabel T1, Tabel T2){
	/*Kamus Lokal*/
	int i;

	/*Algoritma*/
    if (T1.size != T2.size) return false;
    for (i = 1; i <= T1.size; i++){
        if (T1.wadah[i] != T2.wadah[i]) return false;
    }
    return true;
}

/*************************OPERASI LAINNYA*************************/
/* function getInverseTable(T:Tabel) -> Tabel 
	{mengembalikan tabel baru dengan isi elemen yang berkebalikan dengan tabel T } */
Tabel getInverseTable(Tabel T){
	/*Kamus Lokal*/
	Tabel inv;
    int i;

	/*Algoritma*/
    createTable(&inv);
    inv.size = T.size;
    for (i = 1; i <= T.size; i++){
        inv.wadah[i] = T.wadah[T.size - i + 1];
    }
    return inv;
}

/* procedure inverseTable(input/output T:Tabel)
	{I.S.: T terdefinisi}
	{F.S.: elemen dalam T.wadah memiliki isi berkabalikan dengan isi tabel semula}
	{Proses: membalik isi elemen pada tabel T}*/
void inverseTable(Tabel *T){
	/*Kamus Lokal*/
	int i;
    char temp;

	/*Algoritma*/
    for (i = 1; i <= (*T).size / 2; i++){
        temp = (*T).wadah[i];
        (*T).wadah[i] = (*T).wadah[T->size - i + 1];
        (*T).wadah[(*T).size - i + 1] = temp;
    }
}

/*************************OPERASI PENGURUTAN*************************/
/* procedure SortAsc ( input/output T:Tabel)
	{I.S.: T terdefinisi}
	{F.S.: elemen dalam T.wadah terurut dari huruf abjad awal ke akhir}
	{Proses: mengurutkan elemen dalam T.wadah dari huruf abjad awal ke akhir}*/
void sortAsc(Tabel *T){
	/*Kamus Lokal*/
	int i, j;
    char temp;

	/*Algoritma*/
    for (i = 1; i < (*T).size; i++){
        for (j = i + 1; j <= (*T).size; j++){
            if ((*T).wadah[i] > (*T).wadah[j]){
                temp = (*T).wadah[i];
        		(*T).wadah[i] = (*T).wadah[j];
        		(*T).wadah[j] = temp;
            }
        }
    }
}

/* procedure SortDesc ( input/output T:Tabel)
	{I.S.: T terdefinisi}
	{F.S.: elemen dalam T.wadah terurut dari huruf abjad akhir ke awal}
	{Proses: mengurutkan elemen dalam T.wadah dari huruf abjad akhir ke awal}*/
void sortDesc(Tabel *T){
	/*Kamus Lokal*/
	int i, j;
    char temp;

	/*Algoritma*/
    for (i = 1; i < (*T).size; i++){
        for (j = i + 1; j <= (*T).size; j++){
            if((*T).wadah[i] < (*T).wadah[j]){
                temp = (*T).wadah[i];
        		(*T).wadah[i] = (*T).wadah[j];
        		(*T).wadah[j] = temp;
            }
        }
    }
}

