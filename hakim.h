#ifndef HAKIM_H_INCLUDED
#define HAKIM_H_INCLUDED
#include <iostream>

using namespace std;

#define first(L) L.first
#define nextHakim(P) P->nextHakim
#define nextTerdakwa(P) P->nextTerdakwa
#define info(P) P->info
#define last(L) L.last

typedef struct elemenHakim *adr_hakim;
typedef struct elemenTerdakwa *adr_terdakwa;

struct dataHakim {
    string nama;
    string NIP;
    string jabatan;
    string pangkat;
    string alamat;
    string noTelp;
};

struct elemenHakim {
    dataHakim info;
    adr_hakim nextHakim;
    adr_terdakwa nextTerdakwa;
};

struct listHakim {
    adr_hakim first;
    adr_hakim last;
};

struct dataTerdakwa {
    string nama;
    string alamat;
    string noTelp;
    string noKTP;
    string noPaspor;
    string noNPWP;
    string pekerjaan;
    string agama;
    string jenisKelamin;
    string status;
    string kewarganegaraan;
    string tempatLahir;
    string tanggalLahir;
};

struct elemenTerdakwa {
    dataTerdakwa info;
    adr_terdakwa nextTerdakwa;
};

struct listTerdakwa {
    adr_terdakwa first;
};




#endif // HAKIM_H_INCLUDED
