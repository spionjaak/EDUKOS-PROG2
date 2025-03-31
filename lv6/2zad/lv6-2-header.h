#ifndef HEADER_H
#define HEADER_H


typedef struct artikli {
    char ime[20];
    int kolicina;
    float cijena;
}ARTIKL;
void ucitavanje(ARTIKL*, int );
ARTIKL* najveci(ARTIKL*,int );

#endif


