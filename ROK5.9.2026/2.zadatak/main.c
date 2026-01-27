/*
Potrebno je dovršiti C program koji učitava informacije o pjesmama iz binarne datoteke.
Ime datoteke korisnik unosi s tipkovnice. Nakon toga unosi se žanr za koji se 
želi izračunati prosječno trajanje pjesama, te se unosi naslov pjesme koja se pretražuje i za nju se ispisuju sve informacije.

Prva vrijednost zapisana u datoteci je broj pjesama, a zatim slijede zapisi o svakoj pjesmi.
Primjer logičkog zapisa (datoteka je binarna, ovo je samo redoslijed polja):
3
"SmellsLikeTeenSpirit", "Nirvana", "Rock", 1991, 301
"ShapeOfYou", "EdSheeran", "Pop", 2017, 234
"OneMoreTime", "DaftPunk", "Electronic", 2000, 320


Funckija main() je dana te ju ne trebate mijenjati već pogledati kojim se slijedom pozivaju funkcije koje trebate zavrsiti.
Header datoteka je, također, napisana te ju ne morate mijenjati.

Funkcije koje treba implementirati u functions.c

1. ucitajPjesme()

    - Prima ime datoteke i pokazivač na cjelobrojnu varijablu.
    - Vraća pokazivač na dinamički zauzeto polje pjesama.
    - Ako datoteka ne postoji, vraća NULL.

2. izracunajProsjecnoTrajanje()

    - Prima pokazivač na polje pjesama, broj pjesama i žanr.
    - Vraća prosječno trajanje pjesama tog žanra.
    
3. prebrojiPoZanru()

    - Prima pokazivač na polje pjesama, broj pjesama i žanr.
    - Vraća broj pjesama u zadanom žanru.

4. pretraziPoNaslovu()

    - Prima pokazivač na polje pjesama, broj pjesama i naslov.
    - Ako se pjesma pronađe, ispisuje sve informacije:
    printf("Pjesma: %s, Izvodac: %s, Zanr: %s, Godina: %d, Trajanje: %d sekundi\n", ...);
    - Ako nije pronađena:
    printf("Pjesma s naslovom %s nije pronadena.\n", ...);

*/

#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

int main() {
    int brojPjesama;
    char imeDatoteke[100];
    char zanr[50];
    char naslov[100];
    
    printf("Unesite ime datoteke: ");
    scanf("%s", imeDatoteke);

    PJESMA* pjesme = ucitajPjesme(imeDatoteke, &brojPjesama);

    
    printf("Unesite zanr za prosjecno trajanje: ");
    scanf("%s", zanr);

    printf("Unesite naslov pjesme za pretragu: ");
    scanf("%s", naslov);

    printf("REZULTATI:\n");
    
    if (pjesme == NULL) {
        printf("Datoteka ne postoji.\n");
        return 1;
    }
    
    float prosjecnoTrajanje = izracunajProsjecnoTrajanje(pjesme, brojPjesama, zanr);
    printf("Prosjecno trajanje pjesama u zanru %s je %.2f sekundi.\n", zanr, prosjecnoTrajanje);

    int brojPoZanru = prebrojiPoZanru(pjesme, brojPjesama, zanr);
    printf("Broj pjesama u zanru %s: %d\n", zanr, brojPoZanru);

    pretraziPoNaslovu(pjesme, brojPjesama, naslov);

    free(pjesme);
    pjesme = NULL;
    return 0;
}
