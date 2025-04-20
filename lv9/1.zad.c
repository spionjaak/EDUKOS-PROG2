/*Rekurzija prima jednu cjelobrojnu vrijednost koja je visina piramide. 
U datoteku piramida.txt, koju ćete kreiratiiz programa,  „nacrtati“ piramidu od znakova '*' koja može imati maksimalnu visinu 30 redova. 
U main() dijelu učitati visinu piramide te pozvati rekurziju. Primjer piramide je prikazan niže.
n=5
     *
    *** 
   *****
  *******
 *********
 */


#include <stdio.h>
#include <stdlib.h>

// Deklaracija rekurzivne funkcije
void ispisiRed(FILE *fp, int trenutniRed, int visina);

// Glavna funkcija
int main() {
    int visina;

    // Unos visine piramide
    printf("Unesite visinu piramide (maksimalno 30): ");
    scanf("%d", &visina);

    // Provjera da li je visina u dozvoljenom opsegu
    if (visina < 1 || visina > 30) {
        printf("Greska: visina mora biti izmedju 1 i 30.\n");
        return 1; // Greška, prekid programa
    }

    // Otvaranje datoteke za pisanje
    FILE *fp = fopen("piramida.txt", "w");

    // Provjera da li je datoteka uspješno otvorena
    if (fp == NULL) {
        printf("Greska pri otvaranju datoteke.\n");
        return 1;
    }

    // Pozivanje rekurzivne funkcije za crtanje piramide
    ispisiRed(fp, 1, visina);

    // Zatvaranje toka prema datoteci
    fclose(fp);

    printf("Piramida je uspjesno upisana u piramida.txt\n");

    return 0;
}

// Funkcija za ispis jednog reda piramide koristeći rekurziju
void ispisiRed(FILE *fp, int trenutniRed, int visina) {
    // Baza rekurzije: ako je trenutni red veći od visine, prekidamo, jer smo ispisali cijelu piramidu
    if (trenutniRed > visina)
        return;

    // Ispis razmaka: broj razmaka je visina - trenutni red
    for (int i = 0; i < visina - trenutniRed; i++) {
        fputc(' ', fp); // Ispis jednog razmaka u datoteku
    }

    // Ispis zvjezdica: broj zvjezdica je 2 * trenutniRed - 1
    for (int i = 0; i < 2 * trenutniRed - 1; i++) {
        fputc('*', fp); // Ispis jedne zvjezdice u datoteku
    }

    // Prelazak u novi red
    fputc('\n', fp);

    // Rekurzivni poziv za sljedeći red
    ispisiRed(fp, trenutniRed + 1, visina);
}
