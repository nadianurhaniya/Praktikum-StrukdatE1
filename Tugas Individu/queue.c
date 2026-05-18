/* Program   : queue.c */
/* Deskripsi : file BODY */
/* NIM/Nama  : 24060124120019/Nadia Azura Nurhaniya */
/* Tanggal   : 10 Oktober 2025 */
/***********************************/

#include <stdio.h>
#include "queue.h"
#include "proses.h"
#include "boolean.h"

/*procedure createQueue ( output Q:tQueue)
{I.S.: -}
{F.S.: Q terdefinisi, kosong}
{Proses: mengisi elemen dengan ID: '-' BurstTime: 0, head=tail=0 }*/ 
void createQueue(tqueue *Q) {
    // Kamus Lokal
    int i;

    // Algoritma
    for (i = 1; i <= 5; i++) {
        SetID(&(*Q).wadah[i], '-'); 
        SetBurstTime(&(*Q).wadah[i], 0);    
    }
    (*Q).head = 0;
    (*Q).tail = 0;
}

/*function infoHead(Q:tQueue)-> Proses 
{mengembalikan nilai elemen terdepan antrian Q} */
Proses infoHead(tqueue Q) {
    // Kamus Lokal

    // Algoritma
    Proses kosong;
    MakeProses(&kosong, '-', 0);

    if (Q.head != 0 && Q.tail != 0)
        return Q.wadah[Q.head];
    else {
        printf("Queue kosong, tidak ada elemen head.\n");
        return kosong;
    }
}

/*function infoTail(Q:tQueue)-> Proses 
{mengembalikan nilai elemen terakhir antrian Q} */
Proses infoTail(tqueue Q) {
    // Kamus Lokal
    
    // Algoritma
    Proses kosong;
    MakeProses(&kosong, '-', 0);
    
    if (Q.head != 0 && Q.tail != 0)
        return Q.wadah[Q.tail];
    else {
        printf("Queue kosong, tidak ada elemen tail.\n");
        return kosong;
    }
}

/*procedure printQueue(input Q:tQueue)
{I.S.: Q terdefinisi}
{F.S.: -}
{proses: mencetak semua elemen wadah ke layar}*/
void printQueue(tqueue *Q) {
    // Kamus Lokal
    int i;

    // Algoritma
    if (!isEmptyQueue(*Q)) {
        for (i = 1; i <= 5; i++) {
            printf("ID: %c | BT: %d", GetID((*Q).wadah[i]), GetBurstTime((*Q).wadah[i]));
            if (i < 5) {
                printf("\n");
            }
        }
    }
}
/*procedure viewQueue(input Q:tQueue)
{I.S.: Q terdefinisi}
{F.S.: -}
{proses: mencetak elemen tak kosong ke layar}*/
void viewQueue(tqueue *Q) {
    // Kamus Lokal
    int i;

	// Algoritma
	if (!isEmptyQueue(*Q)) {
        for (i = head(*Q); i <= tail(*Q); i++) {
            printf("ID: %c | BT: %d", GetID((*Q).wadah[i]), GetBurstTime((*Q).wadah[i]));
            if (i < tail(*Q)) {
                printf("\n");
            }
        }
    }
}


/*function isEmptyQueue(Q:tQueue) -> boolean
{mengembalikan true jika Q kosong}*/
boolean isEmptyQueue(tqueue Q){
    return head(Q) == 0 && tail(Q) == 0;
}
 
/*function isFullQueue(Q:tQueue) -> boolean
{mengembalikan true jika Q penuh}*/
boolean isFullQueue(tqueue Q){
    /*Kamus lokal*/

    /*Algoritma*/
    return tail(Q) == 5;
}

/*function isOneElement(Q:tQueue) -> boolean
{mengembalikan True jika hanya ada 1 elemen }*/
boolean isOneElement(tqueue Q) {
    // Kamus Lokal

    // Algoritma
    if (head(Q) == 1 && tail(Q) == 1){
        return true;
    } else {
        return false;
    }
}

/*procedure enqueue( input/output Q:tQueue, input P: Proses )
{I.S.: Q dan P terdefinisi}
{F.S.: elemen wadah Q bertambah 1, bila belum penuh}
{proses: menambah elemen wadah Q } */
void enqueue(tqueue *Q, Proses P) {
    // Kamus Lokal

    // Algoritma
    if (isFullQueue(*Q)){
        printf("Queue Penuh");
    } else {
        if (isEmptyQueue(*Q)){
            head(*Q) = 1;
        }
        tail(*Q) = tail(*Q) + 1;
        (*Q).wadah[tail(*Q)] = P;
    }
}

/*procedure deQueue( input/output Q:tQueue, output E: Proses )
{I.S.: }
{F.S.: E = infohead(Q) atau E = (ID: '-' BurstTime: 0) bila Q kosong, elemen wadah Q berkurang 1 }
{proses: mengurangi elemen wadah Q, semua elemen di belakang head digeser maju }
{bila awalnya 1 elemen, maka Head dan Tail menjadi 0 } */
void dequeue(tqueue *Q, Proses *E) {
    // Kamus Lokal
    int iMin, i, minBurst;

    // Algoritma
    if (isEmptyQueue(*Q)) {
        printf("Queue kosong, tidak bisa dequeue.\n");
        MakeProses(E, '-', 0);
        return;
    }

    if (isOneElement(*Q)) {
        *E = infoHead(*Q);
        (*Q).head = 0;
        (*Q).tail = 0;
        return;
    }

    minBurst = GetBurstTime((*Q).wadah[(*Q).head]);
    iMin = (*Q).head;

    for (i = (*Q).head + 1; i <= (*Q).tail; i++) {
        if (GetBurstTime((*Q).wadah[i]) < minBurst) {
            minBurst = GetBurstTime((*Q).wadah[i]);
            iMin = i;
        }
    }

    *E = (*Q).wadah[iMin];

    for (i = iMin; i < (*Q).tail; i++) {
        (*Q).wadah[i] = (*Q).wadah[i + 1];
    }
    SetID(&(*Q).wadah[(*Q).tail], '-');
    SetBurstTime(&(*Q).wadah[(*Q).tail], 0);

    (*Q).tail = (*Q).tail - 1;

    if ((*Q).tail == 0) {
        (*Q).head = 0;
    }
}










