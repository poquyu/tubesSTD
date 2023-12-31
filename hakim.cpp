#include "hakim.h"
#include <conio.h>

void createListHakim(listHakim &L) {
/*
I.S. -
F.S. Terbentuk list kosong 
 */
    first(L) = NULL;
    last(L) = NULL;
}

adr_hakim alokasiHakim(dataHakim x) {
/*
    Mengembalikan elemen hakim baru dengan info = x, nextHakim = NULL, dan firstTerdakwa = NULL
*/
    adr_hakim P = new elemenHakim;
    infoHakim(P) = x;
    nextHakim(P) = NULL;
    firstTerdakwa(P) = NULL;
    return P;
}

adr_terdakwa alokasiTerdakwa(dataTerdakwa x){
/*
    Mengembalikan elemen terdakwa baru dengan info = x, nextTerdakwa = NULL
*/
    adr_terdakwa P = new elemenTerdakwa;
    infoTerdakwa(P) = x;
    nextTerdakwa(P) = NULL;
    return P;
}

void insertFirstHakim(listHakim &L, adr_hakim P) {
/*
I.S. Terdapat listHakim L mungkin kosong, dan P pointer yang akan dimasukkan
F.S. P menjadi elemen pertama pada listHakim L 
*/
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
/* 
I.S Terdapat listHakim L mungkin kosong
F.S Elemen pertama pada listHakim L dihapus dan disimpan pada P
 */
    if (first(L) != NULL) {
        if (nextHakim(first(L)) == first(L)) {
            P = first(L);
            first(L) = NULL;
            last(L) = NULL;
        } else {
            P = first(L);
            first(L) = nextHakim(first(L));
            nextHakim(last(L)) = first(L);
            nextHakim(P) = NULL;
        }
    } else {
        cout << "List Kosong\n";
    }
}

void deleteLastHakim(listHakim &L, adr_hakim &P) {
/*
I.S Terdapat listHakim L mungkin kosong
F.S Elemen terakhir pada listHakim L dihapus dan disimpan pada P
*/
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
            last(L) = Q;
        }
    } else {
        cout << "List Kosong\n";
    }
}

void deleteAfterHakim(listHakim &L, adr_hakim Prec, adr_hakim &P) {
/*
I.S Terdapat listHakim L mungkin kosong
F.S Elemen setelah Prec pada listHakim L dihapus dan disimpan pada P
*/
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


void deleteAllTerdakwa(adr_hakim &P){
/*
I.S. Terdapat P yang pasti memiliki terdakwa
F.S. Semua terdakwa pada P dihapus
*/

    adr_terdakwa Q = firstTerdakwa(P);
    while(Q != NULL){
        adr_terdakwa R = Q;
        Q = nextTerdakwa(Q);
        dealokasiTerdakwa(R);
    }
    firstTerdakwa(P) = NULL;
}

void deleteHakim(listHakim &L, adr_hakim &P, string NIP){
/*
I.S. Terdapat listHakim L yang mungkin kosong, dan NIP hakim yang akan dihapus
F.S. Hakim dengan NIP yang sama dihapus dari listHakim L
*/
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
    }
}

adr_hakim searchHakim(listHakim L, string NIP){
/*
    Mengembalikan pointer ke elemen hakim dengan NIP yang sama dengan NIP yang dicari
*/

    adr_hakim P = first(L);
    if (P != NULL){
        while (nextHakim(P) != first(L) && infoHakim(P).NIP != NIP) {
            P = nextHakim(P);
        }
        if (infoHakim(P).NIP == NIP) {
            return P;
        }else{
            return NULL;
        }
    }else{
        return NULL;
    }
}
void insertTerdakwa(listHakim &L, adr_terdakwa P, string NIP){
/*
I.S. Terdapat listHakim L, P yaitu pointer terdakwa yang akan dimasukkan ke hakim yang memiliki NIP yang sesuai
F.S. Terdakwa P dimasukkan ke hakim dengan NIP yang sesuai
*/

    adr_hakim Q = searchHakim(L,NIP);
    if(firstTerdakwa(Q) == NULL){
        firstTerdakwa(Q) = P;
    }else{
        nextTerdakwa(P) = firstTerdakwa(Q);
        firstTerdakwa(Q) = P;
    }
}



adr_terdakwa searchTerdakwa(listHakim L,string NIP, string NIK){
/*
    Mengembalikan pointer ke elemen terdakwa dengan NIK yang sama dengan NIK yang dicari
*/
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
/*
I.S. Terdapat listHakim L, NIP hakim yang memiliki terdakwa, dan NIK terdakwa yang akan dihapus
F.S. Terdakwa dengan NIK yang sesuai dihapus dari hakim dengan NIP yang sesuai
*/
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

void hakimWithLeastTerdakwa(listHakim L, adr_hakim &Q, int &count){
/*
I.S. Terdapat listHakim L mungkin kosong
F.S. Q adalah hakim dengan terdakwa paling sedikit, count adalah jumlah terdakwa pada Q
*/
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
    count = min;
}


bool checkDuplicateTerdakwa(listHakim L, string NIK){
/*
    Mengembalikan true jika terdakwa dengan NIK yang sama dengan NIK yang dicari ada pada listHakim L
*/
    adr_hakim P = first(L);
    adr_terdakwa Q;
    if (P == NULL){
        return false;
    }else{
        do {
            Q = firstTerdakwa(P);
            while(Q != NULL && infoTerdakwa(Q).NIK != NIK){
                Q = nextTerdakwa(Q);
            }
            if(Q != NULL && infoTerdakwa(Q).NIK == NIK){
                return true;
            }
            P = nextHakim(P);
        } while(P != first(L));
        return false;
    }
}


void dealokasiHakim(adr_hakim &P) {
    delete P;
}
void dealokasiTerdakwa(adr_terdakwa &P) {
    delete P;
}
void backToMenu(){
    cout << "============================================================\n";
    cout << endl;
    cout << "             Masukkan apa saja untuk kembali                \n";
    cout << endl;
    cout << "============================================================\n";
    char input = getch();
}

void header(){
    cout << "============================================================\n";
    cout << "                                                            \n";
    cout << "                                                            \n";
    cout << "                    Aplikasi Pendataan                      \n";
    cout << "                    Hakim dan Terdakwa                      \n";
    cout << "                                                            \n";
    cout << "                                                            \n";
}

void mainMenu(listHakim &L){

    string input;
    do {
        system("cls");
        header();
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

        if (input == "1"){
            showListHakim(L);
        }else if (input == "2"){
            menuShowHakimWithTerdakwa(L);
        }else if (input == "3"){
            menuSearchHakim(L);
        }else if (input == "4"){
            menuSearchTerdakwa(L);
        }else if (input == "5"){
            menuDeleteHakim(L);
        }else if (input == "6"){
            menuDeleteTerdakwa(L);
        }else if (input == "7"){
            menuShowLeastTerdakwa(L);
        }else if (input == "8"){
            menuInsertHakim(L);
        }else if (input == "9"){
            menuInsertTerdakwa(L);
        }else if (input == "10"){
            testCase(L);
        }else if (input == "0"){
            break;
        }else {
            cout << "                     Input tidak valid                      \n";
            backToMenu();
        }
    } while(input != "0");
    cout << "============================================================\n";
    cout << "                      Terima Kasih\n";
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
    cout << "============================================================\n" << endl;
    cout << "                      List Hakim                           \n" << endl;
    adr_hakim P = first(L);
    if (P == NULL) {
        listKosong();
    }else {
        do {
            printHakim(P);
            P = nextHakim(P);
        } while ((P) != first(L));
        backToMenu();
    }
}
void menuShowHakimWithTerdakwa(listHakim L){
    system("cls");
    cout << "============================================================\n" << endl;
    cout << "                  Hakim Deserta Terdakwa                    \n" << endl;
    if (first(L) == NULL){
        listKosong();
    }else{
        string NIP;
        cout << "============================================================\n";
        cout << " Masukkan NIP Hakim : ";
        cin >> NIP;
        adr_hakim Q = searchHakim(L,NIP);
        if(Q != NULL){
            if (firstTerdakwa(Q) != NULL){
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
                cout << endl;
                cout << "                Hakim Tidak Memiliki Terdakwa                \n";
                cout << endl;
            }
        }else{
                cout << "                Data Hakim tidak ditemukan                 \n";
        }
        backToMenu();
    }
}

void menuSearchHakim(listHakim L){
    system("cls");
    cout << "============================================================\n" << endl;
    cout << "                       Cari Hakim                           \n" << endl;
    if (first(L) == NULL){
        listKosong();
    }else{
        string NIP;
        cout << "============================================================\n" ;
        cout << " Masukkan NIP Hakim : ";
        cin >> NIP;
        adr_hakim Q = searchHakim(L,NIP);
        if(Q != NULL){
            printHakim(Q);
        }else{
            cout << endl;
            cout << "                Data Hakim tidak ditemukan                 \n";
            cout << endl;
        }
        backToMenu();
    }
}

void menuSearchTerdakwa(listHakim L){
    system("cls");
    cout << "============================================================\n" << endl;
    cout << "                     Cari Terdakwa                          \n" << endl;
    if (first(L) == NULL){
        listKosong();
    }else{
        string NIP, NIK;
        cout << "============================================================\n";
        cout << " Masukkan NIP Hakim : ";
        cin >> NIP;
        adr_hakim P = searchHakim(L,NIP);
        if (P != NULL){
            if (firstTerdakwa(P) != NULL){
                cout << "============================================================\n";
                cout << endl;
                cout << " Masukkan NIK Terdakwa : ";
                cin >> NIK;
                adr_terdakwa Q = searchTerdakwa(L,NIP,NIK);
                if (Q != NULL){
                    printTerdakwa(Q);
                }else{
                    cout << endl;
                    cout << "                Data Terdakwa tidak ditemukan                 \n";
                    cout << endl;
                }
            }else{
                cout << endl;
                cout << "                Hakim Tidak Memiliki Terdakwa                \n";
                cout << endl;
            }
        }else{
            cout << endl;
            cout << "                Data Hakim tidak ditemukan                 \n";
            cout << endl;
        }
        backToMenu();
    }
}

void menuDeleteHakim(listHakim &L){
    system("cls");
    cout << "============================================================\n"<< endl;
    cout << "                     Hapus Hakim                         " << endl<< endl;
    if (first(L) == NULL){
        listKosong();
    }else{
        string NIP;
        cout << "============================================================\n";
        cout << " Masukkan NIP Hakim : ";
        cin >> NIP;
        adr_hakim Q = searchHakim(L,NIP);
        if (Q != NULL){
            deleteHakim(L,Q,NIP);
            cout << "============================================================\n";
            cout << endl;
            cout << "           Hakim dengan NIP " << infoHakim(Q).NIP << " telah dihapus\n";
            cout << endl;
            backToMenu();
        }else{
            cout << endl;
            cout << "                Data Hakim tidak ditemukan                 \n";
            cout << endl;
            backToMenu();
        }
    }
}

void menuDeleteTerdakwa(listHakim &L){
    system("cls");
    cout << "============================================================\n" << endl;
    cout << "                     Hapus Terdakwa                         \n" << endl;
    if (first(L) == NULL){
        listKosong();
    }else{
        string NIP, NIK;
        cout << "============================================================\n";
        cout << " Masukkan NIP Hakim : ";
        cin >> NIP;
        adr_hakim Q = searchHakim(L,NIP);
        if (Q != NULL){
            if (firstTerdakwa(Q) != NULL){
                cout << " Masukkan NIK Terdakwa : ";
                cin >> NIK;
                if (searchTerdakwa(L,NIP,NIK) != NULL){
                    adr_terdakwa P;
                    deleteTerdakwaFromHakim(L,NIP,NIK,P);
                    cout << "============================================================\n";
                    cout << endl;
                    cout << "            Terdakwa dengan NIK " << infoTerdakwa(P).NIK << " telah dihapus\n";
                    cout << endl;
                    cout << endl;
                    backToMenu();
                }else{
                    cout << endl;
                    cout << "                Data Terdakwa tidak ditemukan                 \n";
                    cout << endl;
                    backToMenu();
                }
            }else{
                cout << endl;
                cout << "                Hakim Tidak Memiliki Terdakwa                \n";
                cout << endl;
                backToMenu();
            }
        }else{
            cout << endl;
            cout << "                Data Hakim tidak ditemukan                 \n";
            cout << endl;
            backToMenu();
        }

    }
}

void menuShowLeastTerdakwa(listHakim L){
    system("cls");
    cout << "============================================================\n"<< endl;
    cout << "            Hakim dengan Terdakwa Paling Sedikit        " << endl<< endl;
    if (first(L) == NULL){
        listKosong();
    }else{
        adr_hakim Q;
        int min;
        hakimWithLeastTerdakwa(L,Q, min);
        cout << "============================================================\n";
        cout << endl;
        cout << "    Hakim dengan terdakwa paling sedikit yaitu : "<< min << endl;
        cout << endl;
        printHakim(Q);
        cout << endl;
        backToMenu();
    }
}

void menuInsertHakim(listHakim &L){
    system("cls");
    cout << "============================================================\n"<< endl;
    cout << "                     Tambah Hakim                         \n"<< endl;
    dataHakim x;
    cout << "============================================================\n";
    cin.ignore();
    cout << "   Masukkan NIP Hakim : ";
    getline(cin, x.NIP);
    adr_hakim Q = searchHakim(L,x.NIP);
    if (Q != NULL){
        cout << "============================================================\n";
        cout << endl;
        cout << "             Hakim dengan NIP " << x.NIP << " sudah ada\n";
        cout << endl;
        backToMenu();
    }else{
        cout << "   Masukkan Nama Hakim : ";
        getline(cin, x.nama);
        cout << "   Masukkan Pendidikan Hakim : ";
        getline(cin, x.pendidikan);
        cout << "   Masukkan Jabatan Hakim : ";
        getline(cin, x.jabatan);
        cout << "   Masukkan Pangkat Hakim : ";
        getline(cin, x.pangkat);
        cout << "   Masukkan Umur Hakim : ";
        cin >> x.usia;
        adr_hakim P = alokasiHakim(x);
        insertFirstHakim(L,P);
        cout << "============================================================\n";
        cout << endl;
        cout << "           Hakim dengan NIP " << infoHakim(P).NIP << " telah ditambahkan\n";
        cout << endl;
        backToMenu();
    }
}

void menuInsertTerdakwa(listHakim &L){
    system("cls");
    cout << "============================================================\n"<< endl;
    cout << "                     Tambah Terdakwa                         \n"<< endl;
    if (first(L) == NULL){
        listKosong();
    }else{
        string NIP;
        cout << "============================================================\n";
        cin.ignore();
        cout << " Masukkan NIP Hakim : ";
        getline(cin,NIP);
        adr_hakim Q = searchHakim(L,NIP);
        if (Q != NULL){
            dataTerdakwa x;
            cout << "============================================================\n";
            cout << " Masukkan NIK Terdakwa : ";
            getline(cin, x.NIK);
            if (!checkDuplicateTerdakwa(L,x.NIK) ){
                cout << " Masukkan Nama Terdakwa : ";
                getline(cin, x.nama);
                cout << " Masukkan Alamat Terdakwa : ";
                getline(cin, x.alamat);
                cout << " Masukkan Pekerjaan Terdakwa : ";
                getline(cin, x.pekerjaan);
                cout << " Masukkan Agama Terdakwa : ";
                getline(cin, x.agama);
                cout << " Masukkan Jenis Kelamin Terdakwa : ";
                getline(cin, x.jenisKelamin);
                cout << " Masukkan Tempat Tanggal Lahir Terdakwa : ";
                getline(cin, x.tempatTglLahir);
                adr_terdakwa P = alokasiTerdakwa(x);
                insertTerdakwa(L,P,NIP);
                cout << "============================================================\n";
                cout << endl;
                cout << "           Terdakwa dengan NIK " << infoTerdakwa(P).NIK << " telah ditambahkan\n";
                cout << endl;
                backToMenu();
            }else{
                cout << "============================================================\n";
                cout << endl;
                cout << "             Terdakwa dengan NIK " << x.NIK << " sudah ada\n";
                cout << endl;
                backToMenu();
            }
        }else {
            cout << "============================================================\n";
            cout << endl;
            cout << "                Data Hakim tidak ditemukan                 \n";
            cout << endl;
            backToMenu();
        }
    }
}

void listKosong(){
    cout << endl;
    cout << "                      List Kosong                           \n";
    cout << endl;
    backToMenu();
}

void testCase(listHakim &L){
    system("cls");
    dataHakim p, q, r, s, t, u;
    p.nama = "Hakim 1";
    p.NIP = "123";
    p.pendidikan = "S1";
    p.jabatan = "Hakim";
    p.pangkat = "Pengadilan Tinggi";
    p.usia = 30;

    q.nama = "Hakim 2";
    q.NIP = "456";
    q.pendidikan = "S1";
    q.jabatan = "Hakim";
    q.pangkat = "Pengadilan Tinggi";
    q.usia = 32;

    r.nama = "Hakim 3";
    r.NIP = "789";
    r.pendidikan = "S1";
    r.jabatan = "Hakim";
    r.pangkat = "Pengadilan Tinggi";
    r.usia = 56;

    s.nama = "Hakim 4";
    s.NIP = "101";
    s.pendidikan = "S1";
    s.jabatan = "Hakim";
    s.pangkat = "Pengadilan Tinggi";
    s.usia = 60;

    t.nama = "Hakim 5";
    t.NIP = "102";
    t.pendidikan = "S1";
    t.jabatan = "Hakim";
    t.pangkat = "Pengadilan Tinggi";
    t.usia = 54;

    u.nama = "Hakim 6";
    u.NIP = "103";
    u.pendidikan = "S1";
    u.jabatan = "Hakim";
    u.pangkat = "Pengadilan Tinggi";
    u.usia = 35;

    adr_hakim P = alokasiHakim(p);
    adr_hakim Q = alokasiHakim(q);
    adr_hakim R = alokasiHakim(r);
    adr_hakim S = alokasiHakim(s);
    adr_hakim T = alokasiHakim(t);
    adr_hakim U = alokasiHakim(u);

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
    a.tempatTglLahir = "Batam/12-01-2004";

    b.nama = "Terdakwa 2";
    b.alamat = "Jalan 2";
    b.NIK = "456";
    b.pekerjaan = "PNS";
    b.agama = "Islam";
    b.jenisKelamin = "Laki-laki";
    b.tempatTglLahir = "Tomohon/19-10-2004";

    c.nama = "Terdakwa 3";
    c.alamat = "Jalan 3";
    c.NIK = "789";
    c.pekerjaan = "PNS";
    c.agama = "Islam";
    c.jenisKelamin = "Laki-laki";
    c.tempatTglLahir = "Batam/27-06-2004";

    d.nama = "Terdakwa 4";
    d.alamat = "Jalan 4";
    d.NIK = "101";
    d.pekerjaan = "PNS";
    d.agama = "Islam";
    d.jenisKelamin = "Laki-laki";
    d.tempatTglLahir = "Pontianak/19-07-2004";

    e.nama = "Terdakwa 5";
    e.alamat = "Jalan 5";
    e.NIK = "102";
    e.pekerjaan = "PNS";
    e.agama = "Islam";
    e.jenisKelamin = "Laki-laki";
    e.tempatTglLahir = "Jakarta/28-12-2004";

    f.nama = "Terdakwa 6";
    f.alamat = "Jalan 6";
    f.NIK = "103";
    f.pekerjaan = "PNS";
    f.agama = "Islam";
    f.jenisKelamin = "Laki-laki";
    f.tempatTglLahir = "Surabaya/01-04-2004";

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

    cout << "============================================================\n";
    cout << endl;
    cout << "              Test Case Berhasil Dimasukkan                       \n";
    cout << endl;
    backToMenu();
}



