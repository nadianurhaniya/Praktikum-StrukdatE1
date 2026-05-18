/* Program   : tstack.c */
/* Deskripsi : file BODY modul stack karakter */
/* NIM/Nama  : 24060124120019/Nadia Azura Nurhaniya */
/* Tanggal   : 26 September 2025 */
/***********************************/

#include <stdio.h>
#include "tstack.h"
#include "boolean.h"
#include <string.h>

/*procedure createStack( output T: Tstack)
	{I.S.: -}
	{F.S.: T terdefinisi, semua nilai elemen T.wadah = '#' }
	{Proses: menginisialisasi T} */
void createStack (Tstack *T){
    /*Kamus Lokal*/
    int i;

    /*Algoritma*/
    (*T).top = 0;
    for (i = 1; i <= 10; i++)
    {
        (*T).wadah[i] = '#';
    }
}

/*function isEmptyStack( T: Tstack) -> boolean
	{mengembalikan True jika T kosong } */
boolean isEmptyStack (Tstack T){
    /*Kamus Lokal*/

    /*Algortima*/
    return T.top == 0;
}

/*function isFullStack( T: Tstack) -> boolean
	{mengembalikan True jika T penuh } */
boolean isFullStack (Tstack T){
    /*Kamus Lokal*/

    /*Algoritma*/
    return T.top == 10;
}

/*procedure push ( input/output T:Tstack, input E: character )
	{I.S.: T,E terdefinisi}
	{F.S.: infotop tetap, atau berisi nilai E }
	{Proses: mengisi elemen top baru, bila belum penuh }*/
void push (Tstack *T, char E){
    /*Kamus Lokal*/
     /*Kamus Lokal*/

    /*Algoritma*/
    if (!isFullStack(*T))
    {
        (*T).wadah[(*T).top+1] = E;
        (*T).top++;
    }
}

/*procedure pop ( input/output T:Tstack, output X: character )
	{I.S.: T terdefinisi}
	{F.S.: X= infotop stack lama, atau '#' }
	{Proses: mengambil elemen top, bila belum kosong }*/
void pop (Tstack *T, char *X){
    /*Kamus Lokal*/

    /*Algoritma*/
    if (!isEmptyStack(*T))
    {
        *X = (*T).wadah[(*T).top];
        (*T).wadah[(*T).top] = '#';
        (*T).top--;
    }
    else{
        *X = '#';
    }
}

/*procedure printStack ( input T:Tstack )
	{I.S.: T terdefinisi}
	{F.S.: -}
	{Proses: menampilkan kondisi wadah T ke layar} 
	{setiap elemen dipisah tanda titik koma } */
void printStack (Tstack T){
    /*Kamus Lokal*/
    int i;

    /*Algoritma*/
    for (i = 10; i >= 1; i--)
    {
        printf("%c; ", T.wadah[i]);
    }
    printf("\n");
}

/*procedure viewStack ( input T:Tstack )
	{I.S.: T terdefinisi}
	{F.S.: -}
	{Proses: menampilkan elemen tak kosong T ke layar}  
	{setiap elemen dipisah tanda titik koma } */
void viewStack (Tstack T){
    /*Kamus lokal*/
    int i;

    /*Algortima*/
    for (i = T.top; i >= 1; i--)
    {
        printf("%c ", T.wadah[i]);
        if (i > 1) {
            printf("; ");
        }
    }
    printf("\n");
}

/* boolean isPalindrom(kata:String) 
   {mengembalikan true jika kata merupakan palindrom, false jika tidak},
   {asumsi panjang kata maksimum adalah 30 karakter} */

boolean isPalindrom(char kata[20]){
    /*kamus lokal*/
    int i, len;
    Tstack S;
    char temp;

    /*algoritma*/
    createStack(&S);
    i = 0;
    len = strlen(kata);

    for (i = 0; i <= len / 2; i++)
    {
        push(&S, kata[i]);
    }

    i = len;
    while (isEmptyStack(S))
    {
        pop(&S, &temp);
        if (kata[i] != temp)
        {
            return false;
        }
    }

    return true;
}

/*procedure pushN ( input/output T:Tstack, input N: integer )
	{I.S.: T,N terdefinisi}
	{F.S.: infotop tetap, atau top=N }
	{Proses: mengisi elemen top baru N kali dari keyboard, bila belum penuh }*/
void pushN (Tstack *T, int N){
    /*Kamus Lokal*/
    int i;
    char e;

    /*Algoritma*/
    for (i = 1; i <= N; i++){
        if (!isFullStack(*T))
        {
            printf("Masukkan karakter ke-[%d]: ", i);
            scanf(" %c", &e);
            push(T, e);
        }
    }
}

/* kerjakan latihan aplikasi stack di file mbrowser.c */


/* include tstack+boolean */
