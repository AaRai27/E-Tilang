#include <windows.h>
#include <conio.h>
#include <cstdlib>
#include <stdlib.h>
#include <ctime>
#include "parent.h"
#include "child.h"

int main()
{
    List_pol LP;
    List_pelanggar M;
    adr_pol P;
    adr_pelanggar Q,prec;
    adr_pelanggar C;
    createList(LP);
    infotype_pol x;
    infotype_pelanggar y;
    string nama,kendaraan,no_kendaraan,kasus,denda;
    int no_tilang,notil,no_kasus;
    int choice;
    time_t now = time(0);

    P = alokasiPolisi(1); insertFirst(LP,P);
    P = alokasiPolisi(2); insertLast(LP,P);
    P = alokasiPolisi(3); insertLast(LP,P);
    P = alokasiPolisi(4); insertLast(LP,P);
    P = alokasiPolisi(5); insertLast(LP,P);
    P = alokasiPolisi(6); insertLast(LP,P);
    P = alokasiPolisi(7); insertLast(LP,P);
    P = alokasiPolisi(9); insertLast(LP,P);
    P = alokasiPolisi(10); insertLast(LP,P);
    P = alokasiPolisi(11); insertLast(LP,P);
    P = alokasiPolisi(12); insertLast(LP,P);
    do {
        cout << "\t" << ctime(&now);
        cout << "+===================E-Tilang====================+" << endl;
        cout << "+\t                                  \t+" <<endl;
        cout << "+\t1. Input Data Tilang              \t+" <<endl;
        cout << "+\t2. Hapus Data Tilang              \t+" <<endl;
        cout << "+\t3. Daftar Tilang                  \t+" <<endl;
        cout << "+\t4. Lihat Data Tilang              \t+" <<endl;
        cout << "+\t5. Jumlah Kendaraan yang di Tilang \t+" <<endl;
        cout << "+\t6. Jumlah Pelanggaran             \t+" <<endl;
        cout << "+\t0. EXIT                           \t+" <<endl;
        cout << "+\t                                  \t+" <<endl;
        cout << "+==================TUBES 2019===================+" << endl;
        cout<<"Pilihan : ";
        cin>>choice;
        cout<<endl;
        switch(choice) {
        case 1:
            cout<<"Bulan Tilang (1-12) : "; cin>>x;
            //P = alokasiPolisi(x); insertFirst(LP,P);
            no_tilang = rand() % 10000 + 100;
            cout<<"Nomor Tilang : "<<no_tilang<<" [HARAP DIINGAT BAIK-BAIK]"<<endl;
            cout<<"Pelanggar : "; cin>>nama;
            cout<<"Kendaraan : "; cin>>kendaraan;
            cout<<"No. Kendaraan : "; cin>>no_kendaraan;
            cout <<"Kasus Pelanggaran : "<<endl;
                cout << "\t1. Tidak Pakai Helm " <<endl;
                cout << "\t2. Menerobos lampu merah   " <<endl;
                cout << "\t3. Surat-Surat Tidak Lengkap " <<endl;
                cout << "\t4. Melanggar Rambu Lalu Lintas  " <<endl;
                cout << "\t5. Penumpang Berlebih \t" <<endl;
                cout << "\t6. Bagian Kendaraan Tidak Lengkap " <<endl;
                cout << "\t7. Melawan Arus Lalu Lintas  " <<endl;
                cout << "\t0. Pelanggaran Lainya"<<endl;
                cout << "Masukkan Kasus Pelanggaran : ";
                cin >> no_kasus;
                switch(no_kasus){
                case 1:
                    kasus = "Tidak Pakai Helm";
                    denda = "300.000";
                    break;
                case 2:
                    kasus = "Menerobos lampu merah";
                    denda = "500.000";
                    break;
                case 3:
                    kasus = "Surat-Surat Tidak Lengkap";
                    denda = "1.000.000";
                    break;
                case 4:
                    kasus = "Melanggar Rambu Lalu Lintas";
                    denda = "700.000";
                    break;
                case 5:
                    kasus = "Penumpang Berlebih";
                    denda = "500.000";
                    break;
                case 6:
                    kasus = "Bagian Kendaraan Tidak Lengkap";
                    denda = "1.000.000";
                    break;
                case 7:
                    kasus = "Melawan Arus Lalu Lintas";
                    denda = "400.000";
                    break;
                default :
                    cout << "Masukan Kasus : ";
                    cin >> kasus;
                    cout << "Denda : Rp.";
                    cin >>denda;
                }
            P = searchPol(LP,x);
            C = alokasiPelanggar(no_tilang,nama,kendaraan,no_kendaraan,kasus,denda);
            insertFirst(pelanggar(P),C);
            system("CLS");
            break;
        case 2:
            cout<<"Menghapus Data Pada Bulan : "; cin>>x;
            P = searchPol(LP,x);
            cout<<"Masukkan Nomor Tilang yang ingin di Hapus : "; cin >> y.no_tilang;
            Q = searchNomor(pelanggar(P),y);
            cout << "Kasus Dengan Nomor Tilang "<<info(Q).no_tilang<<" Sudah Tuntas "<<endl;
            deleteIni(pelanggar(P),prec,Q);
            dealokasiPelanggar(Q);
            getche();
            system("CLS");
            break;
        case 3:
            printInfo(LP);
            getche();
            system("CLS");
            break;
        case 4:
            cout<<"Masukkan Bulan Anda Tertilang : "; cin>>x;
            cout << "Bulan ";
            intToBulan(LP,x);
            P = searchPol(LP,x);
            cout<<"Masukkan Nomor Tilang Anda : "; cin>>y.no_tilang;
            Q = searchNomor(pelanggar(P),y);
            cout<<"\t Nama Pelanggar : " <<info(Q).nama<<endl;
            cout<<"\t Jenis Kendaraan : " <<info(Q).kendaraan<<endl;
            cout<<"\t Nomor Kendaraan : "<< info(Q).no_kendaraan<<endl;
            cout<<"\t Kasus Pelanggaran : "<< info(Q).kasus<<endl;
            cout<<"\t Denda Yang Harus Dibayarkan : Rp."<< info(Q).denda<<endl;
            getche();
            system("CLS");
            break;
        case 5:
            cout << "Masukkan Bulan : "; cin >> x;
            P = searchPol(LP,x);
            cout << "RODA EMPAT : " <<jumlahmobil(pelanggar(P))<<endl;
            cout << "RODA DUA : " <<jumlahmotor(pelanggar(P))<<endl;
            getche();
            system("CLS");
            break;
        case 6:
            cout << "Banyak Pelanggaran Pada Tahun ini Adalah : ";
            cout << jumlahPelanggaran(LP) << " Kasus Pelanggaran"<<endl<<endl;
            printInfo(LP);
            getche();
            system("CLS");
            break;
        case 0:
            cout<<"EXIT..."<<endl;
            exit(1);
            break;
        }
    } while(true);
    /* Nama : Rayhan Rahmanda ; NIM : 1301184233 */
    //----------------------------------------
    return 0;
}
