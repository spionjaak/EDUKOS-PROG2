
#include <stdio.h>
#include <math.h>

struct datum{
    int dan;
    int mjesec;
    int godina;
};

typedef struct ucenik{
    char ime[10];
    char prezime[10];
    char JMBG[13];
    float prosjek;
    struct datum datumRodenja;
}UCENIK;

int main(){
    UCENIK ucenici[40];
    int n;
    do{
        printf("Unesi broj ucenika do maksimalno 40: ");
        scanf("%d",&n);
    }while(n>40);

    for (int i=0; i<n; i++) {
        printf("\nPodatci o %d. uceniku\n",i+1);
        printf("Ime: ");
        scanf("%s", ucenici[i].ime);
        printf("Prezime: ");
        scanf("%s", ucenici[i].prezime);
        printf("JMBG: ");
        scanf("%s", ucenici[i].JMBG);
        printf("Prosjek: ");
        scanf("%f", &ucenici[i].prosjek);
        printf("Datum rodenja: ");
        scanf("%d.%d.%d",&ucenici[i].datumRodenja.dan,&ucenici[i].datumRodenja.mjesec,&ucenici[i].datumRodenja.godina);
        
    }
    int maxProsjekIndex = 0;
    
    for (int i = 1; i<n; i++) {
        
        if(ucenici[i].prosjek>ucenici[maxProsjekIndex].prosjek)maxProsjekIndex = i;
        
    }
    printf("REZULTATI:\n");
    printf("%s %s\n",ucenici[maxProsjekIndex].ime, ucenici[maxProsjekIndex].prezime);
}
