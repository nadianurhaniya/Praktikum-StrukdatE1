/************************************/
/* Program   : maintitik.c          */
/* Deskripsi : aplikasi driver modul Titik */
/* NIM/Nama  : 24060124120019/Nadia Azura Nurhaniya */
/* Tanggal   : 5 September 2025     */
/***********************************/
#include <stdio.h>
#include "titik.h"

int main() {
    // Kamus
    Titik T1, T2, T3, P;

    // Algoritma
    printf("=== DRIVER MODUL TITIK ===\n\n");

    /* 1. Konstruktor */
    printf("1) Konstruktor\n");
    makeTitik(&T1, 4, 5); // Membuat titik T1 dengan absis = 4, ordinat = 5
    printf("T1 dibuat dengan makeTitik(4,5) -> Titik T1 = (%d,%d)\n", getAbsis(T1), getOrdinat(T1));

    makeTitik0(&T2); // Membuat titik T2 di origin (0,0)
    printf("T2 dibuat dengan makeTitik0() -> Titik T2 = (%d,%d)\n\n", getAbsis(T2), getOrdinat(T2));

    /* 2. Selektor */
    printf("2) Selektor\n");
    printf("Absis T1 = %d\n", getAbsis(T1));
    printf("Ordinat T1 = %d\n\n", getOrdinat(T1));

    /* 3. Mutator */
    printf("3) Mutator\n");
    setAbsis(&T1, 10);  // Mengubah absis T1 jadi 10
    setOrdinat(&T1, -2); // Mengubah ordinat T1 jadi -2
    printf("T1 setelah setAbsis(10) dan setOrdinat(-2) -> Titik T1 = (%d,%d)\n\n", getAbsis(T1), getOrdinat(T1));

    /* 4. Predikat */
    printf("4) Predikat\n");
    printf("Apakah T2 origin? %s\n", isOrigin(T2) ? "True" : "False");
    printf("Apakah T1 di sumbu X? %s\n", isOnSumbuX(T1) ? "True" : "False");
    printf("Apakah T1 di sumbu Y? %s\n", isOnSumbuY(T1) ? "True" : "False");
    printf("Apakah T1 sama dengan T2? %s\n\n", isEqual(T1, T2) ? "True" : "False");

    /* 5. Geser */
    printf("5) Geser\n");
    makeTitik(&T3, 1, 1); // Membuat titik T3 (1,1)
    printf("T3 awal = (%d,%d)\n", getAbsis(T3), getOrdinat(T3));
    geser(&T3, 2, -1); // Menggeser T3 sejauh (2,-1)
    printf("T3 setelah digeser (2,-1) -> Titik T3 = (%d,%d)\n\n", getAbsis(T3), getOrdinat(T3));

    /* 6. Refleksi */
    printf("6) Refleksi\n");
    makeTitik(&T3, 3, -4);
    printf("T3 sebelum refleksi = (%d,%d)\n", getAbsis(T3), getOrdinat(T3));
    refleksiX(&T3); // Refleksi terhadap sumbu X
    printf("T3 setelah refleksiX -> Titik T3 = (%d,%d)\n", getAbsis(T3), getOrdinat(T3));
    refleksiY(&T3); // Refleksi terhadap sumbu Y
    printf("T3 setelah refleksiY -> Titik T3 = (%d,%d)\n\n", getAbsis(T3), getOrdinat(T3));

    /* 7. Dilatasi terhadap (0,0) */
    printf("7) Dilatasi terhadap (0,0)\n");
    makeTitik(&T3, 2, 3);
    printf("T3 sebelum dilatasi = (%d,%d)\n", getAbsis(T3), getOrdinat(T3));
    dilatasi(&T3, 2.0); // Dilatasi dengan faktor 2 terhadap (0,0)
    printf("T3 setelah dilatasi k=2.0 -> Titik T3 = (%d,%d)\n\n", getAbsis(T3), getOrdinat(T3));

    /* 8. Dilatasi relatif terhadap titik P */
    printf("8) Dilatasi relatif\n");
    makeTitik(&T3, 5, -3);
    makeTitik(&P, 2, 2);
    printf("T3 = (%d,%d), P = (%d,%d)\n", getAbsis(T3), getOrdinat(T3), getAbsis(P), getOrdinat(P));
    dilatasiX(&T3, P, 0.5); // Dilatasi relatif terhadap P dengan faktor 0.5
    printf("T3 setelah dilatasi relatif ke P (k=0.5) -> Titik T3 = (%d,%d)\n\n", getAbsis(T3), getOrdinat(T3));

    /* 9. Kuadran */
    printf("9) Kuadran\n");
    makeTitik(&T3, -2, 4);
    printf("T3 = (%d,%d), berada di kuadran %d\n", getAbsis(T3), getOrdinat(T3), kuadran(T3));

    makeTitik(&T3, 0, 0);
    printf("T3 = (%d,%d), berada di kuadran %d (origin/sumbu)\n", getAbsis(T3), getOrdinat(T3), kuadran(T3));

    return 0;
}
