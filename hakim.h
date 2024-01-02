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
void dealokasiHakim(adr_hakim &P);
void dealokasiTerdakwa(adr_terdakwa &P);

void insertFirstHakim(listHakim &L, adr_hakim P);
void deleteFirstHakim(listHakim &L, adr_hakim &P);
void deleteLastHakim(listHakim &L, adr_hakim &P);
void deleteAfterHakim(listHakim &L, adr_hakim Prec, adr_hakim &P);
void deleteHakim(listHakim &L, adr_hakim &P, string nip);
void deleteAllTerdakwa(adr_hakim &P);

adr_hakim searchHakim(listHakim L, string nip);
void insertTerdakwa(listHakim &L, adr_terdakwa P, string nip);
adr_terdakwa searchTerdakwa(listHakim L,string NIP, string NIK);
void deleteTerdakwaFromHakim(listHakim &L, string NIP, string NIK, adr_terdakwa &Pterdakwa);
void hakimWithLeastTerdakwa(listHakim L, adr_hakim &Q, int &min);
bool checkDuplicateTerdakwa(listHakim L, string NIK);

void showListHakim(listHakim L);
void menuShowHakimWithTerdakwa(listHakim L);
void menuSearchHakim(listHakim L);
void menuSearchTerdakwa(listHakim L);
void menuDeleteHakim(listHakim &L);
void menuDeleteTerdakwa(listHakim &L);
void menuInsertHakim(listHakim &L);
void menuInsertTerdakwa(listHakim &L);
void menuShowLeastTerdakwa(listHakim L);

void printHakim(adr_hakim Q);
void printTerdakwa(adr_terdakwa Q);
void mainMenu(listHakim &L);

void header();
void listKosong();
void backToMenu();

void testCase(listHakim &L);

#endif // HAKIM_H_INCLUDED
