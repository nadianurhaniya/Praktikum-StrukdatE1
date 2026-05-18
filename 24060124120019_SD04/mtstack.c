/* Program   : mtstack.c */
/* Deskripsi : file DRIVER modul stack karakter */
/* NIM/Nama  : 24060124120019/Nadia Azura Nurhaniya */
/* Tanggal   : 26 September 2025 */
/***********************************/

#include <stdio.h>
#include "tstack.h"
/* include tstack+boolean */

int main() 
{	/* kamus main */
	Tstack A; // variabel A bertipe tStack
	int N;
	char e;
	char kata[30];

	/* algoritma */
	printf("-------PROGRAM UJI ADT STACK------\n");

	// createStack
	createStack(&A);
	printf("===== Uji createStack & PushN =====\n");
	printStack(A);

	// Isi Stack
	printf("Masukkan banyak elemen stack: ");
	scanf("%d", &N);
	pushN(&A, N);
	printf("View Stack : ");
	viewStack(A);
	printf("Print Stack : ");
	printStack(A);

	// push
	printf("===== Uji push =====\n");
	push(&A, '9');
	printf("Setelah Push 9 ke stack: ");
	viewStack(A);

	// pop
	printf("===== Uji pop =====\n");
	pop(&A, &e);
	printf("Karakter yang di-pop: %c\n", e);
	printf("Setelah 9 di pop: ");
	viewStack(A);

	// top
	printf("===== Uji Top =====\n");
	printf("Cek top stack: %d\n", top(A));

	// infotop
	printf("===== Uji InfoTop =====\n");
	printf("Cek infotop stack: %c\n", infotop(A));


	// isEmptyStack
	printf("===== Uji isEmptyStack =====\n");
	if (isEmptyStack(A)) {
        printf("\nA adalah stack kosong\n");
    } else {
        printf("A bukan stack kosong\n");
    }

	// isFullStack
	printf("===== Uji isFullStack =====\n");
	if (isFullStack(A)) {
        printf("\nA adalah stack penuh\n");
    } else {
        printf("A bukan stack penuh\n");
    }

	// isPalindrom
	printf("===== Uji isPalindrom =====\n");
	printf("Masukkan kata: ");
	scanf("%s", kata);
	if (isPalindrom(kata)) {
        printf("Kata termasuk palindrom\n");
    } else {
        printf("Kata bukan palindrom\n");
    }

	return 0;
}