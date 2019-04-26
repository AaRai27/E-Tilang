#include "child.h"

void createList(List_pelanggar &L) {
    /*  Nama : Rayhan Rahmanda ;
        NIM : 1301184233 */
    first(L) = NULL;
    last(L) = NULL;
}

adr_pelanggar alokasiPelanggar(int no_tilang, string nama, string kendaraan, string no_kendaraan, string kasus,string denda) {
    /*  Nama : Rayhan Rahmanda ;
        NIM : 1301184233
        Nama : Muhammad Afif Raihan
        NIM : 1301184220*/
    adr_pelanggar P = new elmlist_pelanggar;
    info(P).no_tilang = no_tilang;
    info(P).nama = nama;
    info(P).kendaraan = kendaraan;
    info(P).no_kendaraan = no_kendaraan;
    info(P).kasus = kasus;
    info(P).denda = denda;
    next(P) = NULL;
    prev(P) = NULL;
    return P;
}

void insertFirst(List_pelanggar &L, adr_pelanggar P) {
    /*  Nama : Rayhan Rahmanda ;
        NIM : 1301184233 */
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
    /*Nama : Muhammad Afif Raihan
      NIM : 1301184220*/
    adr_pelanggar P = first(L);
    while((P !=NULL) && (info(P).no_tilang<9999)) {
        cout<<"\t Nomor Tilang : "<<info(P).no_tilang<<endl;
        cout<<"\t Pelanggar : "<<info(P).nama<<endl;
        cout<<"\t Kendaraan : "<<info(P).kendaraan<<endl;
        cout<<"\t No. Kendaraan : "<<info(P).no_kendaraan<<endl;
        cout<<"\t Kasus Pelanggaran : "<<info(P).kasus<<endl;
        cout<<"\t Denda Yang Harus Dibayarkan : Rp."<<info(P).denda<<endl<<endl;
        P = next(P);
    }
}

adr_pelanggar searchNomor(List_pelanggar L, infotype_pelanggar x) {
    /*  Nama : Rayhan Rahmanda ;
        NIM : 1301184233
        Nama : Muhammad Afif Raihan
        NIM : 1301184220*/
    adr_pelanggar P = first(L);
    while(P != NULL) {
        if(info(P).no_tilang == x.no_tilang) {
            return P;
        }else{
            P = next(P);
        }
    }
    return NULL;
}


void insertAfter(List_pelanggar &L, adr_pelanggar Prec, adr_pelanggar P) {
    /*  Nama : Rayhan Rahmanda ;
        NIM : 1301184233 */
    prev(next(Prec)) = P;
    next(P) = next(Prec);
    prev(P) = Prec;
    next(Prec) = P;
}

void insertLast(List_pelanggar &L, adr_pelanggar P)
{
    /*  Nama : Rayhan Rahmanda ;
        NIM : 1301184233 */
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
    /*  Nama : Rayhan Rahmanda ;
        NIM : 1301184233 */
    if(first(L) != NULL){
        P = first(L);
        first(L) = next(P);
        next(P) = NULL;
    }
};

void deleteLast(List_pelanggar &L, adr_pelanggar &P){
    /*  Nama : Rayhan Rahmanda ;
        NIM : 1301184233 */
    adr_pelanggar Q = first(L);
    while(next(Q) != P){
        Q = next(Q);
    }
    next(Q) = NULL;
}


void deleteAfter(List_pelanggar &L, adr_pelanggar Prec, adr_pelanggar &P){
    /*  Nama : Rayhan Rahmanda ;
        NIM : 1301184233 */
    next(P) = next(Prec);
    next(Prec) = P;
}

void dealokasiPelanggar(adr_pelanggar &P){
    /*  Nama : Rayhan Rahmanda ;
        NIM : 1301184233 */
    delete P;
}


void deleteIni(List_pelanggar &L, adr_pelanggar prec, adr_pelanggar &dihapus){
    /*Nama : Muhammad Afif Raihan
      NIM : 1301184220*/
    prec = prev(dihapus);
    if (first(L)!= last(L)){
        next(prec) = next(dihapus);;
        prev(next(dihapus)) = prec;
        next(dihapus) = NULL;
    }else{
        deleteFirst(L,dihapus);
    }
}


int jumlahmobil(List_pelanggar L)
{
    /*Nama : Muhammad Afif Raihan
      NIM : 1301184220*/
    int banyak = 0;
    adr_pelanggar Q = first(L);
    while(Q!=NULL)
    {
        if ((info(Q).kendaraan == "mobil") || (info(Q).kendaraan == "MOBIL") || (info(Q).kendaraan == "truck")
            || (info(Q).kendaraan == "TRUCK") || (info(Q).kendaraan == "bis") || (info(Q).kendaraan == "BIS"))
        {
            banyak ++;
        }
        Q = next(Q);
    }
    return banyak;
}


int jumlahmotor(List_pelanggar L)
{
    /*Nama : Muhammad Afif Raihan
      NIM : 1301184220*/
    int banyak = 0;
    adr_pelanggar Q = first(L);
    while(Q!=NULL)
    {
        if ((info(Q).kendaraan == "motor") || (info(Q).kendaraan == "MOTOR"))
        {
            banyak ++;
        }
        Q = next(Q);
    }
    return banyak;
}

int jumlahPelanggaranSebulan(List_pelanggar L){
    /*Nama : Muhammad Afif Raihan
      NIM : 1301184220*/
    int P = jumlahmobil(L);
    int Q = jumlahmotor(L);
    return P+Q;
}


