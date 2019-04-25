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
    string nama,kendaraan,no_kendaraan;
    int no_tilang,notil;
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
            cout<<"Bulan Tilang : "; cin>>x;
            //P = alokasiPolisi(x); insertFirst(LP,P);
            no_tilang = rand() % 10000 + 100;
            cout<<"Nomor Tilang : "<<no_tilang<<" [HARAP DIINGAT BAIK-BAIK]"<<endl;
            cout<<"Pelanggar : "; cin>>nama;
            cout<<"Kendaraan : "; cin>>kendaraan;
            cout<<"No. Kendaraan : "; cin>>no_kendaraan;
            P = searchPol(LP,x);
            C = alokasiPelanggar(no_tilang,nama,kendaraan,no_kendaraan);
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
            getche();
            system("CLS");
            break;
        case 5:
            cout << "Masukkan Bulan : "; cin >> x;
            P = searchPol(LP,x);
            cout << "MOBIL : " <<jumlahmobil(pelanggar(P))<<endl;
            cout << "MOTOR : " <<jumlahmotor(pelanggar(P))<<endl;
            getche();
            system("CLS");
            break;
        case 6:
            cout << "Banyak Pelanggaran Pada Tahun ini Adalah : "<<endl;
            //P = searchPol(LP,x);
            cout << jumlahPelanggaran(LP);
            /*if(jumlahPelanggaran(LP)!=0)
            {
                cout<<"Jumlah Pelanggaran pada Bulan ";
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
                cout<< " Tahun 2019 yaitu "<<jumlahPelanggaran(LP)<<endl;
            }
            else
            {
                cout<<"Tidak ada Pelanggaran pada Tahun 2019"<<endl;
            }*/
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
