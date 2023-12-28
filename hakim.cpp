#include "hakim.h"
#include <conio.h>

void createListHakim(listHakim &L) {
    first(L) = NULL;
    last(L) = NULL;
}

adr_hakim alokasiHakim(dataHakim x) {
    adr_hakim P = new elemenHakim;
    infoHakim(P) = x;
    nextHakim(P) = NULL;
    firstTerdakwa(P) = NULL;
    return P;
}

adr_terdakwa alokasiTerdakwa(dataTerdakwa x){
    adr_terdakwa P = new elemenTerdakwa;
    infoTerdakwa(P) = x;
    nextTerdakwa(P) = NULL;
    return P;
}

void insertFirstHakim(listHakim &L, adr_hakim P) {
    if (first(L) == NULL) {
        first(L) = P;
        nextHakim(first(L)) = first(L);
        last(L) = first(L);
    } else {
        nextHakim(P) = first(L);
        first(L) = P;
        nextHakim(last(L)) = first(L);
    }
}

void deleteFirstHakim(listHakim &L, adr_hakim &P) {
    if (first(L) != NULL) {
        if (nextHakim(first(L)) == first(L)) {
            P = first(L);
            first(L) = NULL;
        } else {
            adr_hakim Q = first(L);
            while (nextHakim(Q) != first(L)) {
                Q = nextHakim(Q);
            }
            P = first(L);
            first(L) = nextHakim(P);
            nextHakim(Q) = first(L);
            nextHakim(P) = NULL;
        }
    } else {
        cout << "List Kosong\n";
    }
}

void deleteLastHakim(listHakim &L, adr_hakim &P) {
    if (first(L) != NULL) {
        if (nextHakim(first(L)) == first(L)) {
            P = first(L);
            first(L) = NULL;
        } else {
            adr_hakim Q = first(L);
            while (nextHakim(nextHakim(Q)) != first(L)) {
                Q = nextHakim(Q);
            }
            P = nextHakim(Q);
            nextHakim(Q) = first(L);
            nextHakim(P) = NULL;
        }
    } else {
        cout << "List Kosong\n";
    }
}

void deleteAfterHakim(listHakim &L, adr_hakim Prec, adr_hakim &P) {
    if (first(L) != NULL) {
        if (nextHakim(first(L)) == first(L)) {
            P = first(L);
            first(L) = NULL;
        } else {
            P = nextHakim(Prec);
            nextHakim(Prec) = nextHakim(P);
            nextHakim(P) = NULL;
        }
    } else {
        cout << "List Kosong\n";
    }
}
    //cout << "=============================================\n";


void deleteAllTerdakwa(adr_hakim &P){
    adr_terdakwa Q = firstTerdakwa(P);
    while(Q != NULL){
        adr_terdakwa R = Q;
        Q = nextTerdakwa(Q);
        dealokasiTerdakwa(R);
    }
    firstTerdakwa(P) = NULL;
}

void deleteHakim(listHakim &L, adr_hakim &P, string NIP){
    adr_hakim Q =searchHakim(L,NIP);
    if(Q != NULL){
        if(Q == first(L)){
            deleteAllTerdakwa(Q);
            deleteFirstHakim(L,P);
        }else if(nextHakim(Q) == first(L)){
            deleteAllTerdakwa(Q);
            deleteLastHakim(L,P);
        }else{
            adr_hakim prec = first(L);
            while(nextHakim(prec) != Q){
                prec = nextHakim(prec);
            }
            deleteAllTerdakwa(Q);
            deleteAfterHakim(L,prec,P);
        }
    }else{
        cout << "Data Hakim tidak ditemukan\n";
    }
}

adr_hakim searchHakim(listHakim L, string NIP){
    adr_hakim P = first(L);
    while(nextHakim(P) != first(L) && infoHakim(P).NIP != NIP){
        P = nextHakim(P);
    }
    if(infoHakim(P).NIP == NIP){
        return P;
    }else{
        return NULL;
    }
}
void insertTerdakwa(listHakim &L, adr_terdakwa P, string NIP){
    adr_hakim Q = searchHakim(L,NIP);
    if(firstTerdakwa(Q) == NULL){
        firstTerdakwa(Q) = P;
    }else{
        nextTerdakwa(P) = firstTerdakwa(Q);
        firstTerdakwa(Q) = P;
    }
}



adr_terdakwa searchTerdakwa(listHakim L,string NIP, string NIK){
    adr_hakim P = searchHakim(L,NIP);
    adr_terdakwa Q = firstTerdakwa(P);
    if (P != NULL){
        while (nextTerdakwa(Q) != NULL && infoTerdakwa(Q).NIK != NIK) {
            Q = nextTerdakwa(Q);
        }
        if (infoTerdakwa(Q).NIK == NIK) {
            return Q;
        }else{
            return NULL;
        }
    }else{
        cout << "                Data Hakim tidak ditemukan                 \n";
        return NULL;
    }
}

void deleteTerdakwaFromHakim(listHakim &L, string NIP, string NIK, adr_terdakwa &Pterdakwa){
    adr_hakim P = searchHakim(L,NIP);
    adr_terdakwa Q = searchTerdakwa(L,NIP,NIK);
    //cari last
    adr_terdakwa R = firstTerdakwa(P);
    while (nextTerdakwa(R)!= NULL){
        R = nextTerdakwa(R);
    }
    if (firstTerdakwa(P) != NULL) {
        if(Q == firstTerdakwa(P)){
            //deleteFirst
            Pterdakwa = Q;
            firstTerdakwa(P) = nextTerdakwa(Q);
            nextTerdakwa(Pterdakwa) = NULL;
        }else if(Q == R){
            //deleteLast
            adr_terdakwa S = firstTerdakwa(P);
            while(nextTerdakwa(nextTerdakwa(S)) != NULL){
                S = nextTerdakwa(S);
            }
            Pterdakwa = Q;
            nextTerdakwa(S) = NULL;
        }else{
            //deleteAfter
            adr_terdakwa prec = firstTerdakwa(P);
            while(nextTerdakwa(prec) != Q){
                prec = nextTerdakwa(prec);
            }
            Pterdakwa = Q;
            prec = nextTerdakwa(Q);
            nextTerdakwa(Pterdakwa) == NULL;
        }
    } else {
        cout << "Hakim tidak memiliki terdakwa\n";
    }
}

void hakimWithLeastTerdakwa(listHakim L, adr_hakim &Q){
    Q = first(L);
    int min = 9999999;
    adr_hakim Pmin;
    do {
        adr_terdakwa P = firstTerdakwa(Q);
        int sum = 0;
        while(P != NULL){
            sum++;
            P = nextTerdakwa(P);
        }
        if(sum < min){
            min = sum;
            Pmin = Q;
        }
        Q = nextHakim(Q);
    } while(Q != first(L));
    Q = Pmin;
}




void dealokasiHakim(adr_hakim &P) {
    delete P;
}
void dealokasiTerdakwa(adr_terdakwa &P) {
    delete P;
}

void header(){
    cout << "=============================================\n";
    cout << "|                                           |\n";
    cout << "|            Aplikasi Pendataan             |\n";
    cout << "|            Hakim dan Terdakwa             |\n";
    cout << "|                                           |\n";
    cout << "=============================================\n";
}

void mainMenu(listHakim &L){

    int input;
    do {
        system("cls");
        cout << "============================================================\n";
        cout << "                                                            \n";
        cout << "     1. Tampilkan Seluruh Hakim                            \n";
        cout << "     2. Tampilkan Hakim dengan terdakwa                    \n";
        cout << "     3. Cari hakim                                         \n";
        cout << "     4. Cari terdakwa                                      \n";
        cout << "     5. Hapus Hakim dan terdakwanya                        \n";
        cout << "     6. Hapus terdakwa pada hakim tertentu                 \n";
        cout << "     7. Tampilkan hakim dengan terdakwa paling sedikit     \n";
        cout << "     8. Tambahkan hakim                                    \n";
        cout << "     9. Tambahkan terdakwa pada hakim tertentu             \n";
        cout << "     10. Insert Test Data                                  \n";
        cout << "                                                           \n";
        cout << "     0. Keluar                                             \n";
        cout << "                                                           \n";
        cout << "============================================================\n";
        cout << "   Pilih Menu :                                            \n";
        cin >> input;

        if (input == 1){
            showListHakim(L);
        }else if (input == 2){
            string NIP;
            cout << "============================================================\n";
            cout << " Masukkan NIP Hakim : ";
            cin >> NIP;
            menuShowHakimWithTerdakwa(L,NIP);
        }else if (input == 3){
            string NIP;
            cout << "============================================================\n";
            cout << " Masukkan NIP Hakim : ";
            cin >> NIP;
            menuSearchHakim(L, NIP);
        }else if (input == 4){
            string NIP, NIK;
            cout << "============================================================\n";
            cout << " Masukkan NIP Hakim : ";
            cin >> NIP;
            cout << " Masukkan NIK Terdakwa : ";
            cin >> NIK;
            menuSearchTerdakwa(L, NIP, NIK);
            cout << endl;
        }else if (input == 5){
            system("cls");
            string NIP;
            cout << "============================================================\n";
            cout << " Masukkan NIP Hakim : ";
            cin >> NIP;
            adr_hakim P;
            deleteHakim(L,P,NIP);
            cout << "============================================================\n";
            cout << endl;
            cout << "           Hakim dengan NIP " << infoHakim(P).NIP << " telah dihapus\n";
            cout << endl;
            cout << "============================================================\n";
            cout << endl;
            cout << "             Masukkan apa saja untuk kembali                \n";
            cout << endl;
            cout << "============================================================\n";
            char input = getch();
        }else if (input == 6){
            system("cls");
            string NIP, NIK;
            cout << "============================================================\n";
            cout << " Masukkan NIP Hakim : ";
            cin >> NIP;
            cout << " Masukkan NIK Terdakwa : ";
            cin >> NIK;
            adr_terdakwa P;
            deleteTerdakwaFromHakim(L,NIP,NIK,P);
            cout << "============================================================\n";
            cout << endl;
            cout << "            Terdakwa dengan NIK " << infoTerdakwa(P).NIK << " telah dihapus\n";
            cout << endl;
            cout << endl;
            cout << "============================================================\n";
            cout << endl;
            cout << "             Masukkan apa saja untuk kembali                \n";
            cout << endl;
            cout << "============================================================\n";
            char input = getch();
        }else if (input == 7){
            system("cls");
            adr_hakim Q;
            hakimWithLeastTerdakwa(L,Q);
            cout << "============================================================\n";
            cout << endl;
            cout << "    Hakim dengan terdakwa paling sedikit : \n";
            cout << endl;
            printHakim(Q);
            cout << endl;
            cout << "============================================================\n";
            cout << endl;
            cout << "             Masukkan apa saja untuk kembali                \n";
            cout << endl;
            cout << "============================================================\n";
            char input = getch();
        }else if (input == 8){
            menuInsertHakim(L);
        }else if (input == 9){
            string NIP;
            cout << "============================================================\n";
            cout << " Masukkan NIP Hakim : ";
            cin >> NIP;
            menuInsertTerdakwa(L,NIP);
        }else if (input == 10){
            testCase(L);
        }
    } while(input != 0);
    cout << "============================================================\n";
    cout << " Terima Kasih\n";
    cout << "============================================================\n";
}


void printHakim(adr_hakim Q){
    cout << "============================================================\n";
    cout << endl;
    cout << "    Nama       : " << infoHakim(Q).nama<< endl;
    cout << "    NIP        : " << infoHakim(Q).NIP<< endl;
    cout << "    Pendidikan : " << infoHakim(Q).pendidikan<< endl;
    cout << "    Jabatan    : " << infoHakim(Q).jabatan << endl;
    cout << "    Pangkat    : " << infoHakim(Q).pangkat<< endl;
    cout << "    Umur       : " << infoHakim(Q).usia<< endl;
    cout << endl;
}

void printTerdakwa(adr_terdakwa Q){
    cout << "============================================================\n";
    cout << endl;
    cout << "    Nama                 : " << infoTerdakwa(Q).nama << endl;
    cout << "    Alamat               : " << infoTerdakwa(Q).alamat << endl;
    cout << "    NIK                  : " << infoTerdakwa(Q).NIK << endl;
    cout << "    Pekerjaan            : " << infoTerdakwa(Q).pekerjaan << endl;
    cout << "    Agama                : " << infoTerdakwa(Q).agama << endl;
    cout << "    Jenis Kelamin        : " << infoTerdakwa(Q).jenisKelamin << endl;
    cout << "    Tempat Tanggal Lahir : " << infoTerdakwa(Q).tempatTglLahir << endl;
    cout << endl;
}


void showListHakim(listHakim L) {
    system("cls");
    adr_hakim P = first(L);
    do {
        P = nextHakim(P);
        printHakim(P);
    } while ((P) != first(L));
    cout << "============================================================\n";
    cout << endl;
    cout << "             Masukkan apa saja untuk kembali                \n";
    cout << endl;
    cout << "============================================================\n";
    char input = getch();
}
void menuShowHakimWithTerdakwa(listHakim L, string NIP){
    system("cls");
    adr_hakim Q = searchHakim(L,NIP);
    if(Q != NULL){
        cout << "    Data Hakim :  \n";
        printHakim(Q);
        adr_terdakwa P = firstTerdakwa(Q);
        int i = 1;
        while(P!=NULL){
            cout << "============================================================\n";
            cout << "   Data Terdakwa ke :     " << i << endl;
            printTerdakwa(P);
            i++;
            P = nextTerdakwa(P);
        }
    }else{
            cout << "                Data Hakim tidak ditemukan                 \n";
    }
    cout << "============================================================\n";
    cout << endl;
    cout << "             Masukkan apa saja untuk kembali                \n";
    cout << endl;
    cout << "============================================================\n";
    char input = getch();
}

void menuSearchHakim(listHakim L, string NIP){
    system("cls");
    adr_hakim Q = searchHakim(L,NIP);
    if(Q != NULL){
        printHakim(Q);
    }else{
        cout << endl;
        cout << "                Data Hakim tidak ditemukan                 \n";
        cout << endl;
    }
    cout << "============================================================\n";
    cout << endl;
    cout << "             Masukkan apa saja untuk kembali                \n";
    cout << endl;
    cout << "============================================================\n";
    char input = getch();
}

void menuSearchTerdakwa(listHakim L, string NIP, string NIK){
    system("cls");
    adr_terdakwa Q = searchTerdakwa(L,NIP,NIK);
    if(Q != NULL){
        printTerdakwa(Q);
    }else{
        cout << endl;
        cout << "             Data Terdakwa tidak ditemukan                 \n";
        cout << endl;
    }
    cout << "============================================================\n";
    cout << endl;
    cout << "             Masukkan apa saja untuk kembali                \n";
    cout << endl;
    cout << "============================================================\n";
    char input = getch();
}

void menuInsertHakim(listHakim &L){
    system("cls");
    dataHakim x;
    cout << "============================================================\n";
    cout << " Masukkan Nama Hakim : ";
    cin >> x.nama;
    cout << " Masukkan NIP Hakim : ";
    cin >> x.NIP;
    cout << " Masukkan Pendidikan Hakim : ";
    cin >> x.pendidikan;
    cout << " Masukkan Jabatan Hakim : ";
    cin >> x.jabatan;
    cout << " Masukkan Pangkat Hakim : ";
    cin >> x.pangkat;
    cout << " Masukkan Umur Hakim : ";
    cin >> x.usia;
    adr_hakim P = alokasiHakim(x);
    insertFirstHakim(L,P);
    cout << "============================================================\n";
    cout << endl;
    cout << "           Hakim dengan NIP " << infoHakim(P).NIP << " telah ditambahkan\n";
    cout << endl;
    cout << "============================================================\n";
    cout << endl;
    cout << "             Masukkan apa saja untuk kembali                \n";
    cout << endl;
    cout << "============================================================\n";
    char input = getch();
}

void menuInsertTerdakwa(listHakim &L, string NIP){
    system("cls");
    dataTerdakwa x;
    adr_hakim Q = searchHakim(L,NIP);
    if (Q != NULL){
        cout << "============================================================\n";
        cout << " Masukkan Nama Terdakwa : ";
        cin >> x.nama;
        cout << " Masukkan Alamat Terdakwa : ";
        cin >> x.alamat;
        cout << " Masukkan NIK Terdakwa : ";
        cin >> x.NIK;
        cout << " Masukkan Pekerjaan Terdakwa : ";
        cin >> x.pekerjaan;
        cout << " Masukkan Agama Terdakwa : ";
        cin >> x.agama;
        cout << " Masukkan Jenis Kelamin Terdakwa : ";
        cin >> x.jenisKelamin;
        cout << " Masukkan Tempat Tanggal Lahir Terdakwa : ";
        cin >> x.tempatTglLahir;
        adr_terdakwa P = alokasiTerdakwa(x);
        insertTerdakwa(L,P,NIP);
        cout << "============================================================\n";
        cout << endl;
        cout << "           Terdakwa dengan NIK " << infoTerdakwa(P).NIK << " telah ditambahkan\n";
        cout << endl;
        cout << "============================================================\n";
        cout << endl;
        cout << "             Masukkan apa saja untuk kembali                \n";
        cout << endl;
        cout << "============================================================\n";
        char input = getch();
    }else {
        cout << "============================================================\n";
        cout << endl;
        cout << "                Data Hakim tidak ditemukan                 \n";
        cout << endl;
        cout << "============================================================\n";
        cout << endl;
        cout << "             Masukkan apa saja untuk kembali                \n";
        cout << endl;
        cout << "============================================================\n";
        char input = getch();
    }
}

void testCase(listHakim &L){
    
    dataHakim x, y, z,p, q, r;
    x.nama = "Hakim 1";
    x.NIP = "123";
    x.pendidikan = "S1";
    x.jabatan = "Hakim";
    x.pangkat = "PengadilanTinggi";
    x.usia = 30;

    y.nama = "Hakim 2";
    y.NIP = "456";
    y.pendidikan = "S2";
    y.jabatan = "Hakim";
    y.pangkat = "Pengadilan Tinggi";
    y.usia = 40;

    z.nama = "Hakim 3";
    z.NIP = "789";
    z.pendidikan = "S3";
    z.jabatan = "Hakim";
    z.pangkat = "Pengadilan Tinggi";
    z.usia = 50;

    p.nama = "Hakim 4";
    p.NIP = "101";
    p.pendidikan = "S1";
    p.jabatan = "Hakim";
    p.pangkat = "Pengadilan Tinggi";
    p.usia = 30;

    q.nama = "Hakim 5";
    q.NIP = "102";
    q.pendidikan = "S2";
    q.jabatan = "Hakim";
    q.pangkat = "Pengadilan Tinggi";
    q.usia = 40;

    r.nama = "Hakim 6";
    r.NIP = "103";
    r.pendidikan = "S3";
    r.jabatan = "Hakim";
    r.pangkat = "Pengadilan Tinggi";
    r.usia = 50;

    adr_hakim P = alokasiHakim(x);
    adr_hakim Q = alokasiHakim(y);
    adr_hakim R = alokasiHakim(z);
    adr_hakim S = alokasiHakim(p);
    adr_hakim T = alokasiHakim(q);
    adr_hakim U = alokasiHakim(r);

    insertFirstHakim(L, P);
    insertFirstHakim(L, Q);
    insertFirstHakim(L, R); 
    insertFirstHakim(L, S);
    insertFirstHakim(L, T);
    insertFirstHakim(L, U); 

    
    dataTerdakwa a, b, c, d, e, f;
    a.nama = "Terdakwa 1";
    a.alamat = "Jalan 1";
    a.NIK = "123";
    a.pekerjaan = "PNS";
    a.agama = "Islam";
    a.jenisKelamin = "Laki-laki";

    b.nama = "Terdakwa 2";
    b.alamat = "Jalan 2";
    b.NIK = "456";
    b.pekerjaan = "PNS";
    b.agama = "Islam";
    b.jenisKelamin = "Laki-laki";

    c.nama = "Terdakwa 3";
    c.alamat = "Jalan 3";
    c.NIK = "789";
    c.pekerjaan = "PNS";
    c.agama = "Islam";
    c.jenisKelamin = "Laki-laki";

    d.nama = "Terdakwa 4";
    d.alamat = "Jalan 4";
    d.NIK = "101";
    d.pekerjaan = "PNS";
    d.agama = "Islam";
    d.jenisKelamin = "Laki-laki";

    e.nama = "Terdakwa 5";
    e.alamat = "Jalan 5";
    e.NIK = "102";
    e.pekerjaan = "PNS";
    e.agama = "Islam";
    e.jenisKelamin = "Laki-laki";
    
    f.nama = "Terdakwa 6";
    f.alamat = "Jalan 6";
    f.NIK = "103";
    f.pekerjaan = "PNS";
    f.agama = "Islam";
    f.jenisKelamin = "Laki-laki";


    adr_terdakwa A = alokasiTerdakwa(a);
    adr_terdakwa B = alokasiTerdakwa(b);
    adr_terdakwa C = alokasiTerdakwa(c);
    adr_terdakwa D = alokasiTerdakwa(d);
    adr_terdakwa E = alokasiTerdakwa(e);
    adr_terdakwa F = alokasiTerdakwa(f);


    insertTerdakwa(L, A, "123");
    insertTerdakwa(L, B, "123");
    insertTerdakwa(L, C, "456"); 
    insertTerdakwa(L, D, "789");
    insertTerdakwa(L, E, "789");
    insertTerdakwa(L, F, "789");
}


