#include "child.h"

void createList(List_pelanggar &L) {
    first(L) = NULL;
    last(L) = NULL;
}

adr_pelanggar alokasiPelanggar(int no_tilang, string nama, string kendaraan, string no_kendaraan) {
    adr_pelanggar P = new elmlist_pelanggar;
    info(P).no_tilang = no_tilang;
    info(P).nama = nama;
    info(P).kendaraan = kendaraan;
    info(P).no_kendaraan = no_kendaraan;
    next(P) = NULL;
    prev(P) = NULL;
    return P;
}

void insertFirst(List_pelanggar &L, adr_pelanggar P) {
    if(first(L) == NULL) {
        last(L) = P;
        first(L) = P;
    } else {
        next(P) = first(L);
        prev(first(L)) = P;
        first(L) = P;
    }
}

void printInfo(List_pelanggar L) {
    adr_pelanggar P = first(L);
    while(P !=NULL) {
        cout<<"\t Nomor Tilang : "<<info(P).no_tilang<<endl;
        cout<<"\t Pelanggar : "<<info(P).nama<<endl;
        cout<<"\t Kendaraan : "<<info(P).kendaraan<<endl;
        cout<<"\t No. Kendaraan : "<<info(P).no_kendaraan<<endl<<endl;
        P = next(P);
    }
}

adr_pelanggar searchNomor(List_pelanggar L, string x) {
    adr_pelanggar P = first(L);
    while(P != NULL) {
        if(info(P).no_kendaraan == x) {
            return P;
        }
        P = next(P);
    }
    return NULL;
}
/* Nama : Muhammad Afif Raihan ; NIM : 1301184220 */

void insertAfter(List_pelanggar &L, adr_pelanggar Prec, adr_pelanggar P) {
    prev(next(Prec)) = P;
    next(P) = next(Prec);
    prev(P) = Prec;
    next(Prec) = P;
}

void insertLast(List_pelanggar &L, adr_pelanggar P)
{
    adr_pelanggar Q = first(L);
    if(Q==NULL)
    {
        first(L) = P;
    }else
    {
        while (next(Q)!=NULL)
        {
            Q = next(Q);
        }
        next(Q) = P;
    }
};
void deleteFirst(List_pelanggar &L, adr_pelanggar P)
{
    if(first(L) != NULL){
        P = first(L);
        first(L) = next(P);
        next(P) = NULL;
    }
};

void deleteLast(List_pelanggar &L, adr_pelanggar &P){
    adr_pelanggar Q = first(L);
    while(next(Q) != P){
        Q = next(Q);
    }
    next(Q) = NULL;
    delete(P);
}


void deleteAfter(List_pelanggar &L, adr_pelanggar Prec, adr_pelanggar &P){
    next(P) = next(Prec);
    next(Prec) = P;
}

void dealokasiPelanggar(adr_pelanggar &P){
    delete P;
}
/* Nama : Rayhan Rahmanda ; NIM : 1301184233 */
