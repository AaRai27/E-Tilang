#include "child.h"
#include "parent.h"

void createList(List_pol &L)
{
    first(L) = NULL;
};
void insertFirst(List_pol &L, adr_pol P)
{
    if (P == NULL){
        first(L) = P;
    }else{
        next(P) = first(L);
        first(L) = P;
    }
}
void insertAfter(List_pol &L, adr_pol Prec, adr_pol P){
    if (P == NULL){
        insertFirst(L,P);
    }else{
        next(P) = next(Prec);
        next(Prec) = P;
    }
}

void insertLast(List_pol &L, adr_pol P)
{
    adr_pol Q = first(L);
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
void deleteFirst(List_pol &L, adr_pol P)
{
    if(first(L) != NULL){
        P = first(L);
        first(L) = next(P);
        //deletePolisi(P);
        next(P) = NULL;
    }
};
/* Nama : Rayhan Rahmanda ; NIM : 1301184233 */

void deleteLast(List_pol &L, adr_pol &P){
    adr_pol Q = first(L);
    while(next(Q) != P){
        Q = next(Q);
    }
    next(Q) = NULL;
    dealokasiPolisi(P);
}


void deleteAfter(List_pol &L, adr_pol Prec, adr_pol &P){
    next(P) = next(Prec);
    next(Prec) = P;
}



adr_pol alokasiPolisi(infotype_pol x){
    adr_pol P;
    P = new elmlist_pol;
    info(P) = x;
    next(P) = NULL;
    createList(pelanggar(P));
    return P;
}

void dealokasiPolisi(adr_pol &P){
    delete P;
}

adr_pol searchPol(List_pol L, infotype_pol x){
    adr_pol P = first(L);
    do {
        if(info(P) == x) {
            return P;
        }
        P = next(P);
    } while(P != first(L));
    return NULL;
}

void printInfo(List_pol L){
    adr_pol P = first(L);
    while ((P != NULL)&&(info(P)<99999)){
        if (first(L) != NULL){
            cout <<endl<< "Pelanggaran Bulan :  ";
            switch(info(P)){
                case 1 :
                    cout << "Januari"<<endl;
                    break;
                case 2 :
                    cout << "Februari"<<endl;
                    break;
                case 3 :
                    cout << "Maret"<<endl;
                    break;
                case 4 :
                    cout << "April"<<endl;
                    break;
                case 5 :
                    cout << "Mei"<<endl;
                    break;
                case 6 :
                    cout << "Juni"<<endl;
                    break;
                case 7 :
                    cout << "Juli"<<endl;
                    break;
                 case 8 :
                    cout << "Agustus"<<endl;
                    break;
                 case 9 :
                    cout << "September"<<endl;
                    break;
                 case 10 :
                    cout << "Oktober"<<endl;
                    break;
                 case 11 :
                    cout << "November"<<endl;
                    break;
                 case 12 :
                    cout << "Desember"<<endl;
                    break;
                default:
                    cout << "Bulan Tidak Ada"<<endl;
            }
            printInfo(pelanggar(P));
            cout << "================================"<<endl;
            P = next(P);
        }
    }
}
/* Nama : Muhammad Afif Raihan ; NIM : 1301184220 */

int jumlahPelanggaran(List_pol L)
{
    int banyak = 0;
    adr_pol P = first(L);
    while(P!=NULL)
    {
        if(first(L)!=NULL)
        {
            banyak++;
            P = next(P);
        }
    }
    return banyak;
}
/* Nama : Rayhan Rahmanda ; NIM : 1301184233 */

/*int jumlahmobil(List_pol L)
{
    int banyak = 0;
    adr_pol P = first(L);
    adr_pelanggar
    while(P!=NULL)
    {
            if (info((pelanggar(P)))) == "mobil")
            {
                banyak ++;
            }else
            {
                Q = next(Q);
            }
        P = next(P);
    }
    return banyak;
}
int jumlahmotor(List_pol L)
{
    int banyak = 0;
    adr_pol P = first(L);
    adr_pelanggar Q = first(M);
    while(P!=NULL)
    {
        while (Q != NULL)
        {
            if (info(Q).kendaraan == "motor")
            {
                banyak ++;
            }else
            {
                Q = next(Q);
            }
        }
        P = next(P);
    }
    return banyak;
}
*/
