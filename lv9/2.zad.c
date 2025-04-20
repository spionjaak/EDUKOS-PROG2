#include <stdio.h>  // Uključujemo standardnu biblioteku za ulaz/izlaz (printf, scanf, fopen, fprintf, itd.)

// Rekurzivna funkcija koja računa sumu znamenaka broja
int sumaZnamenki(int n) {
    // Bazni slučaj: ako je broj manji od 10, onda je to jedina znamenka pa je i sama suma
    if (n < 10)
        return n;

    // Rekurzivni slučaj:
    // 1. n % 10 dobiva zadnju znamenku broja
    // 2. n / 10 skraćuje broj (odrezuje zadnju znamenku)
    // 3. Funkcija se rekurzivno poziva na skraćenom broju
    return (n % 10) + sumaZnamenki(n / 10);
}

int main() {
    int broj;  // Varijabla za unos broja

    // Korisnik unosi cijeli broj
    printf("Unesi cijeli broj: ");
    scanf("%d", &broj);  // Učitavanje broja s tipkovnice

    // Ako je broj negativan, pretvori ga u pozitivan jer nam ne treba predznak nego znamenke samo
    if (broj < 0) {
        broj = -broj;
    }

    // Izračunaj sumu znamenaka pomoću rekurzivne funkcije
    int suma = sumaZnamenki(broj);

    // Otvaramo (ili kreiramo) datoteku "suma.txt" u načinu za pisanje ("w" = write mode)
    FILE *datoteka = fopen("suma.txt", "w");

    // Provjera je li datoteka uspješno otvorena
    if (datoteka == NULL) {
        printf("Greška pri otvaranju datoteke.\n");
        return 1;  // Završavamo program s greškom
    }

    // Zapisujemo rezultat (sumu znamenaka) u datoteku
    fprintf(datoteka, "Suma znamenaka broja je: %d\n", suma);

    // Zatvaramo tok prema datoteteci (obavezno nakon pisanja,kao free kod dinamickog alociranja memorije)
    fclose(datoteka);

    // Obavijest korisniku
    printf("Rezultat je upisan u datoteku suma.txt\n");

    return 0;  // Program završava bez grešaka
}
