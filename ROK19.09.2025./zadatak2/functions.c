#include <stdio.h>
#include <string.h>
#include "functions.h"
static void print_student(const Student *s) {
    printf("%s %s, ocjena: %d\n", s->ime, s->prezime, s->ocjena);
}

void ispisiStudente(const char* imeDat) {
    printf("REZULTATI:\n");
    FILE *fp = fopen(imeDat, "r");
    if (fp == NULL) {
        printf("Datoteka ne postoji!\n");
        return;
    }
    Student s;
    while (fscanf(fp, "%49s %49s %d", s.ime, s.prezime, &s.ocjena) == 3) {
        print_student(&s);
    }
    fclose(fp);
}

void dodajStudenta(const char* imeDat) {
    printf("REZULTATI:\n");
    FILE *fp = fopen(imeDat, "a");
    if (fp == NULL) {
        printf("Datoteka ne postoji!\n");
        return;
    }
    Student s;
    if (scanf("%49s %49s %d", s.ime, s.prezime, &s.ocjena) != 3) {
        fclose(fp);
        return;
    }
    fprintf(fp, "%s %s %d\n", s.ime, s.prezime, s.ocjena);
    fclose(fp);
    ispisiStudente(imeDat);
}

void pretraziStudenta(const char* imeDat, const char* trazenoPrezime) {
    printf("REZULTATI:\n");
    FILE *fp = fopen(imeDat, "r");
    if (fp == NULL) {
        printf("Datoteka ne postoji!\n");
        return;
    }
    Student s;
    int found = 0;
    while (fscanf(fp, "%49s %49s %d", s.ime, s.prezime, &s.ocjena) == 3) {
        if (strcmp(s.prezime, trazenoPrezime) == 0) {
            print_student(&s);
            found = 1;
        }
    }
    if (!found) {
        printf("Student s prezimenom %s nije pronadjen.\n", trazenoPrezime);
    }
    fclose(fp);
}

void prosjecnaOcjena(const char* imeDat) {
    printf("REZULTATI:\n");
    FILE *fp = fopen(imeDat, "r");
    if (fp == NULL) {
        printf("Datoteka ne postoji!\n");
        return;
    }
    Student s;
    long long sum = 0;
    int count = 0;
    while (fscanf(fp, "%49s %49s %d", s.ime, s.prezime, &s.ocjena) == 3) {
        sum += s.ocjena;
        count++;
    }
    if (count == 0) {
        printf("Nema studenata u datoteci.\n");
    } else {
        double avg = (double)sum / count;
        printf("Prosjecna ocjena: %.2f\n", avg);
    }
    fclose(fp);
}

