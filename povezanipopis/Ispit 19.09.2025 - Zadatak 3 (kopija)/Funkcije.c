#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Funkcije.h"

/* 
   [1.] Funkcija vraća prosječno trajanje svih pjesama u listi.
    Ako je lista prazna, vraća 0.00.
   
*/
float averageDuration(NODE* head) {
    if(head==NULL) return 0.00;
    int brojac=0;
    int trajanje=0;
    while(head){
        brojac++;
        trajanje += head->song.trajanje_s;
        head = head->nextNode;
    }
    float avg = (float)trajanje/brojac;
    return avg;
}

/* 
   [2.] Funkcija briše zadani čvor iz liste.
   Ako je riječ o prvom čvoru, ažurira se pokazivač na glavu liste.
   Oslobađa se memorija za naslov, izvođača i sam čvor.
*/
void deleteNodeSLList(NODE** head, NODE* target) {
    
    if(*head==target){
        *head=head->nextNode;
        free(target->song.naslov);
        free(target->song.izvodjac);
        free(target);
        return;
    }
    
    NODE* traverserNode = *head;
    while(traverserNode->nextNode){
        if(traverserNode->nextNode==target){
            traverserNode->nextNode=target->nextNode
            free(target->song.naslov);
            free(target->song.izvodjac);
            free(target);
            return;
        }
    }
    
}

/* 
   [3.] Funkcija prolazi listu i briše sve pjesme čije je trajanje manje od prosjeka.
   Koristi deleteNodeSLList za pojedinačna brisanja.
   Vraća broj obrisanih pjesama.
*/
int obrisiKratkeOdProsjeka(NODE** head, float avg) {
    int brojac = 0;
    NODE* traverserNode = *head;
    while (traverserNode) {
        if(traverserNode->song.trajanje_s<avg){
            deleteNodeSLList(head,traverserNode);
            brojac++;
        }
        traverserNode = traverserNode->nextNode;
    }
    
    return brojac;
    
}


/* ============= DANO U PROJEKTU - NE MIJENJATI ============ */




void inputSongData(PJESMA* s) {
    if (!s) return;

    s->naslov = (char*)malloc(256);
    if (!s->naslov) {
        perror("malloc naslov");
        exit(EXIT_FAILURE);
    }
    scanf(" %255[^\n]", s->naslov);

    s->izvodjac = (char*)malloc(256);
    if (!s->izvodjac) {
        perror("malloc izvodjac");
        free(s->naslov); // Oslobodi alocirani naslov ako ovaj malloc zakaže
        exit(EXIT_FAILURE);
    }
    scanf(" %255[^\n]", s->izvodjac);

    scanf("%d", &s->trajanje_s);
    scanf("%f", &s->ocjena);
}


NODE* createSLList(void) {
    NODE* head = (NODE*)calloc(1, sizeof(NODE));
    if (!head) {
        perror("Kreiranje");
        return NULL;
    }
    inputSongData(&head->song);
    head->nextNode = NULL;
    return head;
}

NODE* insertNewNodeSLList(NODE* head) {
    NODE* newNode = (NODE*)calloc(1, sizeof(NODE));
    if (!newNode) {
        perror("Kreiranje");
        return head;
    }
    inputSongData(&newNode->song);
    newNode->nextNode = head;
    return newNode;
}

void traverseSLList(NODE* node) {
    if (!node) {printf("(prazna lista)");  return; }
    while (node) {
        printf("Naslov: %s, Izvođač: %s, Trajanje: %d s, Ocjena: %.2f\n",
               node->song.naslov, node->song.izvodjac,
               node->song.trajanje_s, node->song.ocjena);
        node = node->nextNode;
    }
}

NODE* deleteWholeSLList(NODE* head) {
    NODE* tmp = NULL;
    while (head) {
        tmp = head;
        head = head->nextNode;
        free(tmp->song.naslov);
        free(tmp->song.izvodjac);
        free(tmp);
    }
    return NULL;
}
