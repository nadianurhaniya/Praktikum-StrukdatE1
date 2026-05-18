/* Program   : mtqueue2.c */
/* Deskripsi : DRIVER ADT Queue representasi kontigu model II (head bergeser) */
/* NIM/Nama  : 24060124120019 / Nadia Azura Nurhaniya */
/* Tanggal   : 3 Oktober 2025 */
/***********************************/

#include <stdio.h>
#include "tqueue2.h"

int main() {
    tqueue2 Q1, Q2;
    char e;

    printf("===== UJI ADT QUEUE MODEL II =====\n");

    /* --- CREATE --- */
    createQueue2(&Q1);
    createQueue2(&Q2);
    printf("\nQueue Q1 setelah create:\n");
    printQueue2(Q1);

    /* --- ENQUEUE --- */
    printf("\nMenambah elemen ke Q1...\n");
    enqueue2(&Q1, 'A');
    enqueue2(&Q1, 'B');
    enqueue2(&Q1, 'C');
    printQueue2(Q1);
    printf("Isi Queue (viewQueue2): ");
    viewQueue2(Q1);

    /* --- DEQUEUE --- */
    printf("\nMengambil (dequeue) satu elemen dari Q1...\n");
    dequeue2(&Q1, &e);
    printf("Elemen yang dihapus: %c\n", e);
    printQueue2(Q1);
    printf("Isi Queue (viewQueue2): ");
    viewQueue2(Q1);

    /* --- ENQUEUE tambahan untuk menggeser HEAD --- */
    printf("\nMenambah elemen lagi sampai Tail penuh...\n");
    enqueue2(&Q1, 'D');
    enqueue2(&Q1, 'E');
    enqueue2(&Q1, 'F');
    printQueue2(Q1);
    printf("Isi Queue (viewQueue2): ");
    viewQueue2(Q1);

    /* --- TEST enqueue2N (input banyak sekaligus) --- */
    printf("\nMenambah 2 elemen baru ke Q2 dengan enqueue2N:\n");
    enqueue2N(&Q2, 2);
    printf("Isi Q2 (printQueue2):\n");
    printQueue2(Q2);
    printf("Isi Q2 (viewQueue2): ");
    viewQueue2(Q2);

    /* --- TEST isEqualQueue2 --- */
    printf("\nApakah Q1 dan Q2 Equal? ");
    if (isEqualQueue2(Q1, Q2)) {
        printf("Q1 dan Q2 Equal\n");
    } else {
        printf("Q1 dan Q2 tidak Equal\n");
    }

    /* --- DEQUEUE semua elemen --- */
    printf("\nMengosongkan Q1 dengan dequeue berturut-turut:\n");
    while (!isEmptyQueue2(Q1)) {
        dequeue2(&Q1, &e);
        printQueue2(Q1);
    }

    /* --- CEK KONDISI AKHIR --- */
    printf("\nApakah Q1 kosong sekarang? %s\n", isEmptyQueue2(Q1) ? "Ya" : "Tidak");
    printf("Apakah Q1 penuh? %s\n", isFullQueue2(Q1) ? "Ya" : "Tidak");
    printf("Apakah Q1 berisi satu elemen? %s\n", isOneElement2(Q1) ? "Ya" : "Tidak");

    return 0;
}