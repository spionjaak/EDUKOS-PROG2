/*
Napisati funkcije za rad s jednostruko povezanim popisom pjesama (playlist).
Svaka pjesma sadrži sljedeće podatke:

    - naslov (dinamički alocirani niz znakova)
    - izvodjac (dinamički alocirani niz znakova)
    - trajanje u sekundama (cijeli broj)
    - ocjena (realni broj u rasponu [1.0, 5.0])
    - pokazivač na sljedeći čvor u listi

Vaš zadatak je implementirati sljedeće tri funkcije:

    [1.] float averageDuration(NODE* head);
         – Funkcija prima pokazivač na glavu liste i vraća prosječno trajanje svih pjesama u sekundama.
          Ako je lista prazna, vraća 0.00.
           

    [2.] void deleteNodeSLList(NODE** head, NODE* target);
         – Funkcija briše jedan zadani čvor iz liste. Ako je riječ o prvom čvoru, ažurira pokazivač na glavu liste.
           Oslobađa zauzetu memoriju za cijeli čvor, uključujući stringove u strukturi PJESMA.

    [3.] int obrisiKratkeOdProsjeka(NODE** head, float avg);
         – Funkcija prolazi kroz cijelu listu i briše sve pjesme čije je trajanje manje od izračunatog prosjeka.
           Za brisanje pojedinačnih čvorova koristi deleteNodeSLList.
           Funkcija vraća broj obrisanih pjesama.
         - Paziti ako se obriše i prvi čvor ili čak cijela lista!

U potpunosti rukovati memorijom za sve varijable za koje je to nužno.

Ostale funkcije i strukture su već implementirane i dane u projektu:

    1. void inputSongData(PJESMA* s);
       – Funkcija prima pokazivač na jednu pjesmu te unosi njezine podatke s tipkovnice
         (naslov, izvodjač, trajanje i ocjena).
         Za tekstualne podatke obavezno se dinamički alocira memorija.

    2. NODE* createSLList(void);
       – Stvara prvi čvor liste i poziva funkciju za unos podataka.

    3. NODE* insertNewNodeSLList(NODE* head);
       – Stvara novi čvor, unosi podatke i umeće ga na početak postojeće liste.

    4. void traverseSLList(NODE* head);
       – Ispisuje sve pjesme iz liste redom, s prikazom naslova, izvođača, trajanja i ocjene.

    5. NODE* deleteWholeSLList(NODE* head);
       – Briše cijelu listu, čvor po čvor, i oslobađa sav zauzeti prostor.

!!!!! VAŽNO !!!!
Sva predana rješenja bit će dodatno evaluirana nakon predaje.
Za ostvarenje punog broja bodova, rješenje mora ispravno implementirati
sve tražene funkcionalnosti bez grešaka u logici ili radu s memorijom.

Djelomično riješeni zadaci mogu ostvariti djelomičan broj bodova, ovisno o kvaliteti implementacije
i stabilnosti programa.

Rješenja s ozbiljnim pogreškama (npr. curenje memorije, rušenje programa, neispravno brisanje
ili povezivanje čvorova) neće ostvariti maksimalan broj bodova,
čak i ako je dio funkcionalnosti djelomično prisutan.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Funkcije.h"

int main(void) {
    int n, i;
    NODE *headNode = NULL;

    printf("Koliko pjesama želiš unijeti? ");
    
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Neispravan unos.\n");
        return 0;
    }

    // unos prve pjesme
    headNode = createSLList();

    // unos ostalih pjesama (umetanje na početak)
    for (i = 0; i < n - 1; i++) {
        headNode = insertNewNodeSLList(headNode);
    }

    printf("\nSvi uneseni zapisi:\n");
    traverseSLList(headNode);

    // izračun prosječnog trajanja
    float avg = averageDuration(headNode);
    printf("\nProsječno trajanje pjesama: %.2f sekundi\n", avg);

    printf("REZULTATI:\n");
    int obrisano = obrisiKratkeOdProsjeka(&headNode, avg);
    printf("Obrisano pjesama kraćih od prosjeka: %d\n", obrisano);

    printf("Nakon brisanja:\n");
    traverseSLList(headNode);
    printf("Novo prosječno trajanje: %.2f sekundi\n", averageDuration(headNode));

    // čišćenje memorije
    headNode = deleteWholeSLList(headNode);
    return 0;
}

