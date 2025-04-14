#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Kako bi autograder mogao uspjesno upisati strukturu u datoteku
morate koristiti ovako definirane strukture
*/

struct podaci
{		
	char prezime[20];
	char ime[20];
	int sifra;
	char adresa[100];
	int br_tel;
};

void kreiraj(){
    FILE *datoteka;
    datoteka=fopen("clanovi.txt","wb");
    if(datoteka==NULL){
        exit(1);
    }
    fclose(datoteka);
}

void citaj(){
    struct podaci r[100];
    FILE *datoteka = fopen("clanovi.txt","r");
    fseek(datoteka,0L,SEEK_END);
    int c=ftell(datoteka)/sizeof(struct podaci);
    rewind(datoteka);
    fread(r, sizeof(struct podaci), c, datoteka);
}

void dodaj(){
    struct podaci clan={};
    memset(&clan,0,sizeof(clan));
    FILE *datoteka = fopen("clanovi.txt","ab");
    if(datoteka==NULL){
        exit(1);
    }
    scanf(" %[^\n]",clan.prezime);
    scanf(" %[^\n]",clan.ime);
    scanf("%d",&clan.sifra);
    scanf(" %[^\n]",clan.adresa);
    scanf("%d",&clan.br_tel);
    fwrite(&clan,sizeof(struct podaci),1,datoteka);
    fclose(datoteka);
}

void zavrsi(){
    
    exit(1);
}

int main(void){
    int n;
    FILE *datoteka;
    do{
        scanf("%d",&n);
        switch(n){
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
                zavrsi();
        }
    }while(n!=4);
    
    return 0;
}
