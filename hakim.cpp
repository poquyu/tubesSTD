#include "hakim.h"

void createListHakim(listHakim &L) {
    first(L) = NULL;
    last(L) = NULL;
}

adr_hakim alokasiHakim(dataHakim x) {
    adr_hakim P = new elemenHakim;
    info(P).nama = x.nama;
    info(P).NIP = x.NIP;
    info(P).pendidikan = x.pendidikan;
    info(P).jabatan = x.jabatan;
    info(P).pangkat = x.pangkat;    
    info(P).usia = x.usia;
    nextHakim(P) = NULL;
    firstTerdakwa(P) = NULL;
    return P;
}

adr_terdakwa alokasiTerdakwa(dataTerdakwa x){
    adr_terdakwa P = new elemenTerdakwa;
    info(P).nama = x.nama;
    info(P).alamat = x.alamat;
    info(P).NIK = x.NIK;
    info(P).pekerjaan = x.pekerjaan;
    info(P).agama = x.agama;
    info(P).jenisKelamin = x.jenisKelamin;
    info(P).tempatTglLahir = x.tempatTglLahir;
    nextTerdakwa(P) = NULL;
    return P;
}

void insertFirstHakim(listHakim &L, adr_hakim P) {
    if (first(L) == NULL) {
        first(L) = P;
        nextHakim(P) = P; 
    } else {
        adr_hakim Q = first(L);
        while (nextHakim(Q) != first(L)){
            Q = nextHakim(Q);
        }
        nextHakim(P) = first(L);
        first(L) = P;
        nextHakim(Q) = P; 
    }
}

void showListHakim(listHakim L) {
    adr_hakim P = first(L);
    do {
        cout << "Nama: " << info(P).nama << endl;
        cout << "NIP: " << info(P).NIP << endl;
        cout << "Pendidikan: " << info(P).pendidikan << endl;
        cout << "Jabatan: " << info(P).jabatan << endl;
        cout << "Pangkat: " << info(P).pangkat << endl;
        cout << "Usia: " << info(P).usia << endl;
        cout << endl;
        P = nextHakim(P);
    } while (P != first(L));
}

void deleteHakim(listHakim &L, adr_hakim &P, string nip){
    adr_hakim Q = first(L);
    if (info(Q).NIP == nip) {
        P = Q;
        first(L) = nextHakim(Q);
        nextHakim(last(L)) = first(L);
        nextHakim(P) = NULL;
    } else {
        while (nextHakim(Q) != first(L) && info(nextHakim(Q)).NIP != nip) {
            Q = nextHakim(Q);
        }
        if (info(nextHakim(Q)).NIP == nip) {
            P = nextHakim(Q);
            nextHakim(Q) = nextHakim(P);
            nextHakim(P) = NULL;
        }
    }
}

adr_hakim searchHakim(listHakim L, string nip) {
    adr_hakim Q = first(L);
    while (nextHakim(Q) != first(L) && info(Q).NIP != nip) {
        Q = nextHakim(Q);
    }
    if (info(Q).NIP == nip) {
        return Q;
    }else{
        return NULL;
    }
}

void insertTerdakwa(listHakim &L, adr_terdakwa P, string nip){
    adr_hakim Q = searchHakim(L,nip);
    if(firstTerdakwa(Q) == NULL){
        firstTerdakwa(Q) = P; 
    }else{
        nextTerdakwa(P) = firstTerdakwa(Q);
        firstTerdakwa(Q) = P;
    }
}

void showHakimWithTerdakwa(listHakim LH){
    
}

































adr_terdakwa cariDataTerdakwa(listHakim LH,string NIP, string NIK){
    adr_hakim P = searchHakim(LH,NIP);
    adr_terdakwa Q = firstTerdakwa(P);
    while (nextTerdakwa(Q) != NULL && info(Q).NIK != NIK) {
        Q = nextTerdakwa(Q);
    }
    if (info(Q).NIK == NIK) {
        return Q;
    }else{
        cout << "Data terdakwa tidak ditemukan" << endl;
    }
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

void menu(){
    cout << "=============================================\n";
    cout << "|                                           |\n";
    cout << "|                                           |\n";
    cout << "|                                           |\n";
    cout << "|                                           |\n";
    cout << "|                                           |\n";
    cout << "|                                           |\n";
    cout << "|                                           |\n";
    cout << "|                                           |\n";
    cout << "|                                           |\n";
    cout << "|                                           |\n";
    cout << "|                                           |\n";
    cout << "|                                           |\n";
    cout << "|                                           |\n";
    cout << "=============================================\n";
    int input;
    do{
        
        cin >> input;
        cout << endl;

    }while();
}
