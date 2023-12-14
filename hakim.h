#ifndef HAKIM_H_INCLUDED
#define HAKIM_H_INCLUDED
#include <iostream>

using namespace std;

#define first(L) L.first
#define firstTerdakwa(P) P->firstTerdakwa
#define nextHakim(P) P->nextHakim
#define nextTerdakwa(P) P->nextTerdakwa
#define info(P) P->info
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
    dataHakim info;
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
    dataTerdakwa info;
    adr_terdakwa nextTerdakwa;
};
/*
struct listTerdakwa {
    adr_terdakwa first;
};
*/



void createListHakim(listHakim &L);
//void createListTerdakwa(listTerdakwa &L);
adr_hakim alokasiHakim(dataHakim x);
adr_terdakwa alokasiTerdakwa(dataTerdakwa x);
void insertFirstHakim(listHakim &L, adr_hakim P);
void showListHakim(listHakim L);
void deleteHakim(listHakim &L, adr_hakim &P, string nip);
void searchHakim(listHakim L, adr_hakim &P, string nip);
//void insertFirstTerdakwa(listTerdakwa &L, adr_terdakwa P);
void connectHakimTerdakwa(listHakim &LH, adr_hakim &PH, adr_terdakwa &PT);
void showHakimWithTerdakwa(listHakim LH);   
adr_terdakwa cariDataTerdakwa(listHakim LH,string NIP, string NIK);
void deleteTerdakwaFromHakim(listHakim &LH, string NIP, string NIK, adr_terdakwa Pterdakwa);
void hakimWithLeastTerdakwa(listHakim LH);
void menu(listHakim &LH);
void dealokasiHakim(adr_hakim &P);
void dealokasiTerdakwa(adr_terdakwa &P);


#endif // HAKIM_H_INCLUDED
