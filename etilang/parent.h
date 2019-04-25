#ifndef PARENT_H_INCLUDED
#define PARENT_H_INCLUDED
#include <iostream>
#include "child.h"
#include "cstdlib"
using  namespace std;

#define first(L) L.first
#define next(P) P->next
#define info(P) P->info
#define pelanggar(P) P->pelanggar

typedef int infotype_pol;
typedef struct elmlist_pol *adr_pol;
struct elmlist_pol {
    infotype_pol info;
    adr_pol next;
    List_pelanggar pelanggar;
};
struct List_pol {
    adr_pol first;
};

void createList(List_pol &L);
void insertFirst(List_pol &L, adr_pol P);
void insertAfter(List_pol &L, adr_pol Prec, adr_pol P);
void insertLast(List_pol &L, adr_pol P);
void deleteFirst(List_pol &L, adr_pol P);
void deleteLast(List_pol &L, adr_pol &P);
void deleteAfter(List_pol &L, adr_pol Prec, adr_pol &P);
adr_pol alokasiPolisi(infotype_pol x);
void dealokasiPolisi(adr_pol &P);
adr_pol searchPol(List_pol L, infotype_pol x);
void printInfo(List_pol L);

/**CASE**/
int jumlahPelanggaran(List_pol L);
/* Nama : Rayhan Rahmanda ; NIM : 1301184233
   Nama : Muhammad Afif Raihan ; NIM : 1301184220*/

void intToBulan(List_pol L,int P);

#endif // PARENT_H_INCLUDED
