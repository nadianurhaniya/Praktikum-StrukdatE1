/* Program   : mtqueue3.c */
/* Deskripsi : DRIVER ADT Queue representasi kontigu model III (head berputar) */
/* NIM/Nama  : 24060124120019 / Nadia Azura Nurhaniya */
/* Tanggal   : 10 Oktober 2025 */
/***********************************/

#include <stdio.h>
#include "tqueue3.h"

int main(){
    tqueue3 Q1, Q2;
    char e;

    printf("===== UJI ADT QUEUE MODEL III =====\n");

    /* --- CREATE --- */
    createQueue3(&Q1);
    printf("\nQueue Q1 setelah create:\n");
    printQueue3(Q1);

     /* --- ENQUEUE --- */
    printf("\nMenambah elemen ke Q1...\n");
    enqueue3(&Q1, 's');
    enqueue3(&Q1, 'c');
    printQueue3(Q1);

}
