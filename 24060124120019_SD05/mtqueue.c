/* Program   : mtqueue.c */
/* Deskripsi : file DRIVER modul queue karakter */
/* NIM/Nama  : 24060124120019 / Nadia Azura Nurhaniya */
/* Tanggal   : 3 Oktober 2025 */
/***********************************/

#include <stdio.h>
#include "tqueue.h"

int main()
{
    tqueue Q1, Q2;
    char e = ' ';

    printf("===== UJI ADT QUEUE =====\n");

    /* --- 1. Inisialisasi Queue --- */
    printf("\nMembuat Queue Q1 dan Q2...\n");
    createQueue(&Q1);
    createQueue(&Q2);
    printQueue(Q1);
    printQueue(Q2);

    /* --- 2. Uji Enqueue --- */
    printf("\nMenambahkan elemen ke Q1...\n");
    enqueue(&Q1, 'A');
    enqueue(&Q1, 'B');
    enqueue(&Q1, 'C');
    enqueue(&Q1, 'D');
    enqueue(&Q1, 'E');
    printQueue(Q1);

    /* --- 3. Cek kondisi Queue --- */
    printf("\nCek kondisi Q1:\n");

    /*Cek isEmptyQueue*/
    if (isEmptyQueue(Q1))
        printf("- Queue kosong\n");
    else
        printf("- Queue tidak kosong\n");

    /*Cek isOneElement*/
    if (isOneElement(Q1))
        printf("- Hanya ada satu elemen\n");
    else
        printf("- Lebih dari satu elemen\n");

    /*Cek isFullQueue*/
    if (isFullQueue(Q1))
        printf("- Queue penuh\n");
    else
        printf("- Queue belum penuh\n");

    /* --- 4. Uji infoHead dan infoTail --- */
    printf("\nInfo Head Q1: %c\n", infoHead(Q1));
    printf("Info Tail Q1: %c\n", infoTail(Q1));
    printf("Size Q1 sekarang: %d\n", sizeQueue(Q1));

    /* --- 5. Uji viewQueue --- */
    printf("\nIsi Queue (tanpa '-'): ");
    viewQueue(Q1);

    /* --- 6. Uji Dequeue --- */
    printf("\nMenghapus 2 elemen dari Q1...\n");
    dequeue(&Q1, &e);
    printf("Elemen yang dihapus: %c\n", e);
    dequeue(&Q1, &e);
    printf("Elemen yang dihapus: %c\n", e);
    printQueue(Q1);
    printf("Isi Q1 sekarang: ");
    viewQueue(Q1);

    /* --- 7. Enqueue2 --- */
    printf("\n=== Uji enqueue2 (menambah ke antrian terpendek) ===\n");
    enqueue2(&Q1, &Q2, 'M');
    enqueue2(&Q1, &Q2, 'N');
    enqueue2(&Q1, &Q2, 'O');
    enqueue2(&Q1, &Q2, 'P');
    enqueue2(&Q1, &Q2, 'Q');
    enqueue2(&Q1, &Q2, 'R');

    printf("\nSetelah enqueue2 dilakukan beberapa kali:\n");
    printf("Isi Q1: ");
    viewQueue(Q1);
    printf("Size Q1: %d\n", sizeQueue(Q1));

    printf("Isi Q2: ");
    viewQueue(Q2);
    printf("Size Q2: %d\n", sizeQueue(Q2));

    /* --- 8. Dequeue2 --- */
    printf("\n=== Uji dequeue2 (hapus dari antrian terpanjang) ===\n");
    dequeue2(&Q1, &Q2, &e);
    printf("Elemen yang dihapus dari antrian terpanjang: %c\n", e);
    printf("\nIsi Q1: ");
    viewQueue(Q1);
    printf("Panjang Q1: %d\n", sizeQueue(Q1));

    printf("Isi Q2: ");
    viewQueue(Q2);
    printf("Panjang Q2: %d\n", sizeQueue(Q2));

    /* --- 9. Mengosongkan Q1 --- */
    printf("\nMengosongkan Q1...\n");
    while (!isEmptyQueue(Q1)) {
        dequeue(&Q1, &e);
        printf("Hapus: %c\n", e);
    }
    printQueue(Q1);

    printf("\n===== Selesai =====\n");

    return 0;
}
