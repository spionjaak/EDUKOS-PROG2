#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"

PJESMA* ucitajPjesme(const char* imeDatoteke, int* brojPjesama) {
    if (brojPjesama == NULL || imeDatoteke == NULL) {
        return NULL;
    }

    FILE* f = fopen(imeDatoteke, "rb");
    if (!f) {
        return NULL;
    }

    int n = 0;
    if (fread(&n, sizeof(int), 1, f) != 1 || n <= 0) {
        fclose(f);
        return NULL;
    }

    PJESMA* pjesme = (PJESMA*)malloc(sizeof(PJESMA) * (size_t)n);
    if (!pjesme) {
        fclose(f);
        return NULL;
    }

    int readCount = fread(pjesme, sizeof(PJESMA), n, f);
    fclose(f);
    if (readCount != n) {
        free(pjesme);
        return NULL;
    }

    *brojPjesama = n;
    return pjesme;
}

float izracunajProsjecnoTrajanje(PJESMA* pjesme, int brojPjesama, const char* zanr) {
    if (!pjesme || brojPjesama <= 0 || !zanr) {
        return 0.0f;
    }

    long long suma = 0;
    int broj = 0;
    for (int i = 0; i < brojPjesama; ++i) {
        if (strcmp(pjesme[i].zanr, zanr) == 0) {
            suma += pjesme[i].trajanje;
            ++broj;
        }
    }
    if (broj == 0) return 0.0f;
    return (float)suma / (float)broj;
}

int prebrojiPoZanru(PJESMA* pjesme, int brojPjesama, const char* zanr) {
    if (!pjesme || brojPjesama <= 0 || !zanr) {
        return 0;
    }
    int broj = 0;
    for (int i = 0; i < brojPjesama; ++i) {
        if (strcmp(pjesme[i].zanr, zanr) == 0) {
            ++broj;
        }
    }
    return broj;
}

void pretraziPoNaslovu(PJESMA* pjesme, int brojPjesama, const char* naslov) {
    if (!pjesme || brojPjesama <= 0 || !naslov) {
        printf("Pjesma s naslovom %s nije pronadena.\n", naslov ? naslov : "(null)");
        return;
    }
    for (int i = 0; i < brojPjesama; ++i) {
        if (strcmp(pjesme[i].naslov, naslov) == 0) {
            printf("Pjesma: %s, Izvodac: %s, Zanr: %s, Godina: %d, Trajanje: %d sekundi\n",
                   pjesme[i].naslov, pjesme[i].izvodac, pjesme[i].zanr, pjesme[i].godina, pjesme[i].trajanje);
            return;
        }
    }
    printf("Pjesma s naslovom %s nije pronadena.\n", naslov);
}

