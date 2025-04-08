#include <stdio.h>
#include <ctype.h>  // ovo nam treba za funkciju toupper da ne moramo rucno to raditi, tj preko ASCII tablice

int main() {
    FILE *ulaznaDatoteka, *izlaznaDatoteka;
    char znak;

    
    ulaznaDatoteka = fopen("Prva.txt", "r");
    if (ulaznaDatoteka == NULL) {
        perror("Greska pri otvaranju ulazne datoteke");
        return 1;
    }

    
    izlaznaDatoteka = fopen("Druga.txt", "w");
    if (izlaznaDatoteka == NULL) {
        perror("Greska pri kreiranju izlazne datoteke");
        fclose(ulaznaDatoteka);
        return 1;
    }

    
    while ((znak = fgetc(ulaznaDatoteka)) != EOF) {
        fputc(toupper(znak), izlaznaDatoteka);
    }

    
    fclose(ulaznaDatoteka);
    fclose(izlaznaDatoteka);

    return 0;
}
