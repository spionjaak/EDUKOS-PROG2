/*
Napišite C program koji će iz datoteke racun.txt učitati n artikala u račun.
Datoteka racun.txt je već zadana. Program treba ispisati ukupan iznos računa
na ekran u obliku: „Ukupan iznos racuna: %.2f“. Postavljen je oblik struktura,
primjetite da je unutar struktura svu memoriju za polja (bilo znakova bilo
struktura) potrebno zauzeti dinamički.
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct artikl {
    char *naziv;
    float cijena;
    int kolicina;
} Artikl;

typedef struct racun {
    char *prodavac;
    char *kupac;
    Artikl *artikli;
    int broj_artikala;
    float ukupan_iznos;
} Racun;

int main() {
    FILE *fp = fopen("racun.txt", "r");
    if (fp == NULL) {
        printf("Greška pri otvaranju datoteke.\n");
        return 1;
    }

    Racun racun;
    char buffer[256];

    
    if (fgets(buffer, sizeof(buffer), fp) == NULL) {
        printf("Greška pri čitanju prodavača.\n");
        fclose(fp);
        return 1;
    }
    buffer[strcspn(buffer, "\n")] = 0; //strcpn vraca index gdje je znak pod "", ovdje je to "\n" i mijenja s ovim na kraju a to je 0.
    racun.prodavac = (char *)malloc((strlen(buffer) + 1) * sizeof(char));
    strcpy(racun.prodavac, buffer);// kopira string buffer u racun.prodavac

    
    if (fgets(buffer, sizeof(buffer), fp) == NULL) {
        printf("Greška pri čitanju kupca.\n");
        fclose(fp);
        return 1;
    }
    buffer[strcspn(buffer, "\n")] = 0;
    racun.kupac = (char *)malloc((strlen(buffer) + 1) * sizeof(char));
    strcpy(racun.kupac, buffer);

   
    if (fgets(buffer, sizeof(buffer), fp) == NULL) {
        printf("Greška pri čitanju broja artikala.\n");
        fclose(fp);
        return 1;
    }
    racun.broj_artikala = atoi(buffer); // atoi = string -> int

    
    racun.artikli = (Artikl *)malloc(racun.broj_artikala * sizeof(Artikl));
    if (racun.artikli == NULL) {
        printf("Greška pri alokaciji memorije za artikle.\n");
        fclose(fp);
        return 1;
    }

    
    for (int i = 0; i < racun.broj_artikala; i++) {
        
        if (fgets(buffer, sizeof(buffer), fp) == NULL) {
            printf("Greška pri čitanju naziva artikla.\n");
            fclose(fp);
            return 1;
        }
        buffer[strcspn(buffer, "\n")] = 0;
        racun.artikli[i].naziv = (char *)malloc((strlen(buffer) + 1) * sizeof(char));
        strcpy(racun.artikli[i].naziv, buffer);

       
        if (fgets(buffer, sizeof(buffer), fp) == NULL) {
            printf("Greška pri čitanju cijene artikla.\n");
            fclose(fp);
            return 1;
        }
        racun.artikli[i].cijena = atof(buffer); // atof pretvara string, tj polje chara u float, nesto kao castanje

       
        if (fgets(buffer, sizeof(buffer), fp) == NULL) {
            printf("Greška pri čitanju količine artikla.\n");
            fclose(fp);
            return 1;
        }
        racun.artikli[i].kolicina = atoi(buffer); // atoi pretvara string u int
    }

    fclose(fp);

    
    racun.ukupan_iznos = 0.0;
    for (int i = 0; i < racun.broj_artikala; i++) {
        racun.ukupan_iznos += racun.artikli[i].cijena * racun.artikli[i].kolicina;
    }

    printf("Ukupan iznos racuna: %.2f\n", racun.ukupan_iznos);

    
    free(racun.prodavac);
    free(racun.kupac);
    for (int i = 0; i < racun.broj_artikala; i++) {
        free(racun.artikli[i].naziv);
    }
    free(racun.artikli);

    return 0;
}


