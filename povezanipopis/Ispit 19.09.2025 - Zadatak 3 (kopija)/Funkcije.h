#ifndef FUNKCIJE_H
#define FUNKCIJE_H

typedef struct pjesma {
    char* naslov;
    char* izvodjac;
    int   trajanje_s;
    float ocjena;
} PJESMA;

typedef struct node {
    PJESMA song;
    struct node* nextNode;
} NODE;


/* FUNKCIJE KOJE MORATE IMPLEMENTIRATI */
float averageDuration(NODE* head);
void deleteNodeSLList(NODE** head, NODE* target);
int obrisiKratkeOdProsjeka(NODE** head, float avg);

/* GOTOVE FUNKCIJE (dane u projektu) */
void inputSongData(PJESMA* s);
NODE* createSLList(void);
NODE* insertNewNodeSLList(NODE* head);
void traverseSLList(NODE* head);
NODE* deleteWholeSLList(NODE* head);



#endif
