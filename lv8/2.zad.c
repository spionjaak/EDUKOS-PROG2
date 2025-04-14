#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct podaci {
    char prezime[20];
    char ime[20];
    int sifra;
    char adresa[100];
    int br_tel;
};

struct posudba {
    char ime_filma[50];
    int dan_u_godini;
    int sifra_clana;
};

void kreiraj() {
    FILE *datoteka = fopen("clanovi.txt", "wb");
    if (datoteka == NULL) {
        printf("Greška pri kreiranju datoteke!\n");
        exit(1);
    }
    fclose(datoteka);
    printf("Datoteka 'clanovi.txt' kreirana.\n");
}

void citaj() {
    struct podaci r[100];
    FILE *datoteka = fopen("clanovi.txt", "rb");
    if (datoteka == NULL) {
        printf("Datoteka ne postoji.\n");
        return;
    }

    fseek(datoteka, 0L, SEEK_END);
    int c = ftell(datoteka) / sizeof(struct podaci);
    rewind(datoteka);

    fread(r, sizeof(struct podaci), c, datoteka);
    for (int i = 0; i < c; i++) {
        printf("Prezime: %s, Ime: %s, Sifra: %d, Adresa: %s, Telefon: %d\n",
               r[i].prezime, r[i].ime, r[i].sifra, r[i].adresa, r[i].br_tel);
    }

    fclose(datoteka);
}

void dodaj() {
    struct podaci clan = {};
    memset(&clan, 0, sizeof(clan));
    FILE *datoteka = fopen("clanovi.txt", "ab");
    if (datoteka == NULL) {
        printf("Greška pri otvaranju datoteke!\n");
        exit(1);
    }
    printf("Unesite prezime: ");
    scanf(" %[^\n]", clan.prezime);
    printf("Unesite ime: ");
    scanf(" %[^\n]", clan.ime);
    printf("Unesite šifru: ");
    scanf("%d", &clan.sifra);
    printf("Unesite adresu: ");
    scanf(" %[^\n]", clan.adresa);
    printf("Unesite broj telefona: ");
    scanf("%d", &clan.br_tel);

    fwrite(&clan, sizeof(struct podaci), 1, datoteka);
    fclose(datoteka);
    printf("Član uspješno dodan.\n");
}

int broj_posudbi(int sifra) {
    FILE *f = fopen("posudbe.txt", "rb");
    if (!f) return 0;

    struct posudba p;
    int count = 0;
    while (fread(&p, sizeof(struct posudba), 1, f)) {
        if (p.sifra_clana == sifra)
            count++;
    }
    fclose(f);
    return count;
}

void posudba_filma() {
    int broj;
    printf("Koliko filmova želite posuditi (max 4)? ");
    scanf("%d", &broj);
    if (broj < 1 || broj > 4) {
        printf("Neispravan broj filmova.\n");
        return;
    }

    struct posudba nova;
    FILE *f = fopen("posudbe.txt", "ab+");
    if (f == NULL) {
        printf("Greška pri otvaranju/kreiranju datoteke posudbe.txt!\n");
        exit(1);
    }

    for (int i = 0; i < broj; i++) {
        printf("Unesite ime filma: ");
        scanf(" %[^\n]", nova.ime_filma);
        printf("Unesite dan u godini (1-365): ");
        scanf("%d", &nova.dan_u_godini);
        printf("Unesite šifru člana: ");
        scanf("%d", &nova.sifra_clana);

        int trenutno = broj_posudbi(nova.sifra_clana);
        if (trenutno >= 4) {
            printf("Član sa šifrom %d je već posudio 4 filma.\n", nova.sifra_clana);
            continue;
        }

        fwrite(&nova, sizeof(struct posudba), 1, f);
        printf("Film '%s' posuđen.\n", nova.ime_filma);
    }

    fclose(f);
}

void zavrsi() {
    printf("Zatvaranje programa...\n");
    exit(0);
}

int main(void) {
    int n;
    do {
        printf("\n--- IZBORNIK ---\n");
        printf("1 - Kreiranje datoteke clanovi.txt\n");
        printf("2 - Čitanje iz datoteke clanovi.txt\n");
        printf("3 - Dodavanje novih članova\n");
        printf("4 - Posudba filma\n");
        printf("5 - Kraj programa\n");
        printf("Unesite opciju: ");
        scanf("%d", &n);

        switch (n) {
            case 1:
                kreiraj();
                break;
            case 2:
                citaj();
                break;
            case 3:
                dodaj();
                break;
            case 4:
                posudba_filma();
                break;
            case 5:
                zavrsi();
                break;
            default:
                printf("Nepoznata opcija!\n");
        }
    } while (n != 5);

    return 0;
}
