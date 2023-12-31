#include "hakim.h"
#include "hakim.cpp"

int main()
{
    listHakim L;
    createListHakim(L);
    header();
    mainMenu(L);
    return 0;
}
