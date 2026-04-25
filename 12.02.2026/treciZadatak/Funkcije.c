#include <stdlib.h>
#include<stdio.h>
#include "Funkcije.h"

void inputSongData(PJESMA* s) {
    // implementirati
}

void deleteNodeSLList(NODE** head, NODE* target) {
    // implementirati
}

void obrisiPjesmePoOcjeni(NODE** head, float minOcjena) {
    // implementirati
}

/* ================== DANO U PROJEKTU (NE MIJENJATI) ================== */

float averageRating(NODE* head) {
    int count = 0;
    float suma = 0.0f;
    while (head) {
        suma += head->song.ocjena;
        count++;
        head = head->nextNode;
    }
    return count > 0 ? suma / count : 0.0f;
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
    if (!node) { printf("(prazna lista)\n"); return; }
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