#include "hakim.h"

void createListHakim(listHakim &L) {
    first(L) = NULL;
    last(L) = NULL;
}

void createListTerdakwa(listTerdakwa &L) {
    first(L) = NULL;
}

adr_hakim alokasiHakim(dataHakim x) {
    adr_hakim P = new elemenHakim;
    info(P).nama = x.nama;
    info(P).NIP = x.NIP;
    info(P).jabatan = x.jabatan;
    info(P).pangkat = x.pangkat;
    info(P).alamat = x.alamat;
    info(P).noTelp = x.noTelp;
    nextHakim(P) = NULL;
    nextTerdakwa(P) = NULL;
    return P;
}