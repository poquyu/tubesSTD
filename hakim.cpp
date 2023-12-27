#include "hakim.h"

void createListHakim(listHakim &L) {
    first(L) = NULL;
    last(L) = NULL;
}

adr_hakim alokasiHakim(dataHakim x) {
    adr_hakim P = new elemenHakim;
    infoHakim(P).nama = x.nama;
    infoHakim(P).NIP = x.NIP;
    infoHakim(P).pendidikan = x.pendidikan;
    infoHakim(P).jabatan = x.jabatan;
    infoHakim(P).pangkat = x.pangkat;
    infoHakim(P).usia = x.usia;
    nextHakim(P) = NULL;
    firstTerdakwa(P) = NULL;
    return P;
}
adr_terdakwa alokasiTerdakwa(dataTerdakwa x){
    adr_terdakwa P = new elemenTerdakwa;
    infoTerdakwa(P).nama = x.nama;
    infoTerdakwa(P).alamat = x.alamat;
    infoTerdakwa(P).NIK = x.NIK;
    infoTerdakwa(P).pekerjaan = x.pekerjaan;
    infoTerdakwa(P).agama = x.agama;
    infoTerdakwa(P).jenisKelamin = x.jenisKelamin;
    infoTerdakwa(P).tempatTglLahir = x.tempatTglLahir;
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
        printHakim(P);
        P = nextHakim(P);
    } while (P != first(L));
}

void deleteHakim(listHakim &L, adr_hakim &P, string nip){
    adr_hakim Q = first(L);
    if (infoHakim(Q).NIP == nip) {
        P = Q;
        first(L) = nextHakim(Q);
        nextHakim(last(L)) = first(L);
        nextHakim(P) = NULL;
    } else {
        while (nextHakim(Q) != first(L) && infoHakim(nextHakim(Q)).NIP != nip) {
            Q = nextHakim(Q);
        }
        if (infoHakim(nextHakim(Q)).NIP == nip) {
            P = nextHakim(Q);
            nextHakim(Q) = nextHakim(P);
            nextHakim(P) = NULL;
        }
    }
}

adr_hakim searchHakim(listHakim L, string nip){
    adr_hakim Q = first(L);
    while (nextHakim(Q) != first(L) && infoHakim(Q).NIP != nip) {
        Q = nextHakim(Q);
    }
    if (infoHakim(Q).NIP == nip) {
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

void printHakim(adr_hakim Q){
    cout << "Nama : " << infoHakim(Q).nama << endl;
    cout << "NIP : " << infoHakim(Q).NIP << endl;
    cout << "Pendidikan : " << infoHakim(Q).pendidikan << endl;
    cout << "Jabatan : " << infoHakim(Q).jabatan << endl;
    cout << "Pangkat : " << infoHakim(Q).pangkat << endl;
    cout << "Umur : " << infoHakim(Q).usia << endl;
}

void printTerdakwa(adr_terdakwa Q){
    cout << "Nama : " << infoTerdakwa(Q).nama << endl;
    cout << "Alamat : " << infoTerdakwa(Q).alamat << endl;
    cout << "NIK : " << infoTerdakwa(Q).NIK << endl;
    cout << "Pekerjaan : " << infoTerdakwa(Q).pekerjaan << endl;
    cout << "Agama : " << infoTerdakwa(Q).agama << endl;
    cout << "Jenis Kelamin : " << infoTerdakwa(Q).jenisKelamin << endl;
    cout << "Tempat Tanggal Lahir : " << infoTerdakwa(Q).tempatTglLahir << endl;
}

















void showHakimWithTerdakwa(listHakim LH, string NIP){
    adr_hakim Q = searchHakim(LH,NIP);
    if(Q != NULL){   
        cout << "Data Hakim : \n"; 
        printHakim(LH,Q);
        adr_terdakwa P = firstTerdakwa(Q);
        int i = 1;
        while(P!=NULL){
            cout << "Data Terdakwa ke : " << i << endl;
            printTerdakwa(P);
            i++;
            P = nextTerdakwa(P);
        }
    }else{
        cout << "Data Hakim tidak ditemukan\n";
    }
}




































adr_terdakwa cariDataTerdakwa(listHakim LH,string NIP, string NIK){
    adr_hakim P = searchHakim(LH,NIP);
    adr_terdakwa Q = firstTerdakwa(P);
    while (nextTerdakwa(Q) != NULL && infoTerdakwa(Q).NIK != NIK) {
        Q = nextTerdakwa(Q);
    }
    if (infoTerdakwa(Q).NIK == NIK) {
        return Q;
    }else{
        cout << "Data terdakwa tidak ditemukan" << endl;
    }
}

void deleteTerdakwaFromHakim(listHakim &LH, string NIP, string NIK, adr_terdakwa &Pterdakwa){
    adr_hakim P = searchHakim(LH,NIP);
    adr_terdakwa Q = firstTerdakwa(P);
    if (infoTerdakwa(Q).NIK == NIK) {
        Pterdakwa = Q;
        firstTerdakwa(P) = nextTerdakwa(Q);
        nextTerdakwa(Pterdakwa) = NULL;
    } else {
        while (nextTerdakwa(Q) != NULL && infoTerdakwa(nextTerdakwa(Q)).NIK != NIK) {
            Q = nextTerdakwa(Q);
        }
        if (infoTerdakwa(nextTerdakwa(Q)).NIK == NIK) {
            Pterdakwa = nextTerdakwa(Q);
            nextTerdakwa(Q) = nextTerdakwa(Pterdakwa);
            nextTerdakwa(Pterdakwa) = NULL;
        }
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

void menu(listHakim &LH){
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

    }while(input != 0);
}
