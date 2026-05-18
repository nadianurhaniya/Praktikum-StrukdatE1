/* Program   : mprosesSJF.c */
/* Deskripsi : program untuk mensimulasikan penjadwalan proses pada CPU menggunakan algoritma 
                penjadwalan Shortest Job First (SJF) */
/* NIM/Nama  : 24060124120019 / Nadia Azura Nurhaniya */
/* Tanggal   : 10 Oktober 2025 */
/***********************************/

#include <stdio.h>
#include "queue.h"
#include "proses.h"
#include "boolean.h"

int main() {
    // Kamus
    tqueue Q;
    Proses P1, P2, P3, P4, P5;
    Proses E;
    int clock_time = 0;
    int i;
    int digit[5] = {2, 0, 0, 1, 9};
    int BT[5];

    // Algoritma

    // 1. Menghitung Burst Time berdasarkan NIM
    for (i = 0; i < 5; i++) {
        if (i == 0)
            BT[i] = (digit[i] == 0) ? 3 : digit[i];
        else
            BT[i] = (digit[i] == 0) ? (BT[i - 1] + 3) : digit[i];
    }

    // 2. Membuat 5 proses berdasarkan hasil Burst Time
    MakeProses(&P1, '1', BT[0]);
    MakeProses(&P2, '2', BT[1]);
    MakeProses(&P3, '3', BT[2]);
    MakeProses(&P4, '4', BT[3]);
    MakeProses(&P5, '5', BT[4]);

    // 3. Inisialisasi Queue
    createQueue(&Q);

    // 4. Menambahkan semua proses ke dalam Queue
    enqueue(&Q, P1);
    enqueue(&Q, P2);
    enqueue(&Q, P3);
    enqueue(&Q, P4);
    enqueue(&Q, P5);

    // 5. Menampilkan antrean awal proses
    printf("Antrean proses awal:\n");
    printQueue(&Q);
    printf("\n");

    // 6. Simulasi penjadwalan CPU dengan algoritma SJF
    printf("\nHasil penjadwalan CPU (SJF):\n");
    printf("ID | Start -> Finish | Burst Time\n");

    while (!isEmptyQueue(Q)) {
        dequeue(&Q, &E);
        printf("Proses %c | %d -> %d | BT = %d\n",
               GetID(E),
               clock_time,
               clock_time + GetBurstTime(E),
               GetBurstTime(E));
        clock_time += GetBurstTime(E);
    }

    // 7. Menampilkan total waktu eksekusi
    printf("\nTotal waktu eksekusi seluruh proses: %d\n", clock_time);
    printf("Program selesai.\n");

    return 0;
}
