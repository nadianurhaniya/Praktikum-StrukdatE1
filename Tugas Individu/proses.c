/* Program   : proses.c */
/* Deskripsi : Implementasi ADT Proses */
/* NIM/Nama  : 24060124120019 / Nadia Azura Nurhaniya */
/* Tanggal   : 10 Oktober 2025 */
/***********************************/

#include <stdio.h>
#include "proses.h"

/* procedure MakeProses (input/output P:Proses, input idproses:character, input bursttime:integer) */
/* {I.S.: -} */
/* {F.S.: P terdefinisi, kosong} */
/* {Proses: mengisi elemen dengan inputan char id dan int bursttime} */ 
void MakeProses(Proses *p, char id, int burst){
    (*p).IDProses = id;
    (*p).BurstTime = burst;
}

/* procedure SetID (input/output P:Proses, input id:integer) */
/* {I.S.: P terdefinisi} */
/* {F.S.: P.IDProses = id} */
/* {proses: mengubah nilai komponen IDProses dengan id} */
void SetID(Proses *p, char id){
    (*p).IDProses = id;
}

/* procedure SetBurstTime (input/output P:Proses, input burst:integer) */
/* {I.S.: P terdefinisi} */
/* {F.S.: P.BurstTime = burst} */
/* {proses: mengubah nilai komponen BurstTime dengan burst} */
void SetBurstTime(Proses *p, int burst){
    (*p).BurstTime = burst;
}

/* function GetID (P:Proses) -> character */
/* {mengembalikan nilai komponen IDProses dari P} */
char GetID(Proses p){
    return p.IDProses;
}

/* function GetBurstTime (P:Proses) -> integer */
/* {mengembalikan nilai komponen BurstTime dari P} */
int GetBurstTime(Proses p){
    return p.BurstTime;
}

