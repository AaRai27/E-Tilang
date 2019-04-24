#include <windows.h>
#include <conio.h>
#include <cstdlib>
#include <stdlib.h>
#include "parent.h"
#include "child.h"

int main()
{
    List_pol LP;
    List_pelanggar M;
    adr_pol P;
    adr_pelanggar Q;
    adr_pelanggar C;
    createList(LP);
    infotype_pol x;
    string y;
    string nama,kendaraan,no_kendaraan;
    int no_tilang,notil;
    int choice;
    P = alokasiPolisi(1); insertFirst(LP,P);
    P = alokasiPolisi(2); insertFirst(LP,P);
    P = alokasiPolisi(3); insertFirst(LP,P);
    P = alokasiPolisi(4); insertFirst(LP,P);
    P = alokasiPolisi(5); insertFirst(LP,P);
    P = alokasiPolisi(6); insertFirst(LP,P);
    P = alokasiPolisi(7); insertFirst(LP,P);
    P = alokasiPolisi(9); insertFirst(LP,P);
    P = alokasiPolisi(10); insertFirst(LP,P);
    P = alokasiPolisi(11); insertFirst(LP,P);
    P = alokasiPolisi(12); insertFirst(LP,P);
    do {
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
            cout<<"Nomor Tilang : "<<no_tilang<<endl;
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
            cout<<"Masukkan Nomor Tilang yang ingin di Hapus : "; cin >> y;
            Q = searchNomor(pelanggar(P),y);
            cout << "Kasus Dengan Nomor Tilang "<<y<<" Sudah Tuntas "<<endl;
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
            cout<<"Masukkan Nomor Tilang Anda : "; cin>>y;
            Q = searchNomor(pelanggar(P),y);
            printInfo(pelanggar(P));
            getche();
            system("CLS");
            break;
        case 5:
            /*jumlahmobil(LP,M);
            cout << jumlahmobil(LP)<<endl;
            jumlahmotor(LP,M);
            cout << jumlahmotor(LP)<<endl;
            break;*/
        case 6:
            cout << "Cari Banyak Pelanggaaran Pada Bulan (1-12) : ";
            cin >> x;
            P = searchPol(LP,x);
            jumlahPelanggaran(LP);
            if(jumlahPelanggaran(LP)!=0)
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
            }
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
