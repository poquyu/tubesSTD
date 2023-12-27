#ifndef HAKIM_H_INCLUDED
#define HAKIM_H_INCLUDED
#include <iostream>

using namespace std;

#define first(L) L.first
#define firstTerdakwa(P) P->firstTerdakwa
#define nextHakim(P) P->nextHakim
#define nextTerdakwa(P) P->nextTerdakwa
#define infoHakim(P) P->infoHakim
#define infoTerdakwa(P) P->infoTerdakwa
#define last(L) L.last

typedef struct elemenHakim *adr_hakim;
typedef struct elemenTerdakwa *adr_terdakwa;
struct dataHakim {
    string nama;
    string NIP;
    string pendidikan;
    string jabatan;
    string pangkat;
    int usia;
};

struct elemenHakim {
    dataHakim infoHakim;
    adr_hakim nextHakim;
    adr_terdakwa firstTerdakwa;
};

struct listHakim {
    adr_hakim first;
    adr_hakim last;
};
struct dataTerdakwa {
    string nama;
    string alamat;
    string NIK;
    string pekerjaan;
    string agama;
    string jenisKelamin;
    string tempatTglLahir;
};

struct elemenTerdakwa {
    dataTerdakwa infoTerdakwa;
    adr_terdakwa nextTerdakwa;
};


void createListHakim(listHakim &L);
adr_hakim alokasiHakim(dataHakim x);
adr_terdakwa alokasiTerdakwa(dataTerdakwa x);
void insertFirstHakim(listHakim &L, adr_hakim P);
void showListHakim(listHakim L);
void deleteHakim(listHakim &L, adr_hakim &P, string nip);
adr_hakim searchHakim(listHakim L, string nip);
void insertTerdakwa(listHakim &L, adr_terdakwa P, string nip);
void showHakimWithTerdakwa(listHakim LH);   
adr_terdakwa cariDataTerdakwa(listHakim LH,string NIP, string NIK);
void deleteTerdakwaFromHakim(listHakim &LH, string NIP, string NIK, adr_terdakwa &Pterdakwa);
void hakimWithLeastTerdakwa(listHakim LH);
void menu(listHakim &LH);
void dealokasiHakim(adr_hakim &P);
void dealokasiTerdakwa(adr_terdakwa &P);
void header();

#endif // HAKIM_H_INCLUDED
