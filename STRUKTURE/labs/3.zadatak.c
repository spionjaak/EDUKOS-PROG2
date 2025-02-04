#include <stdio.h>

typedef struct stan{
    
    float povrsina;
    int cijena;
    char adresa[50];
    char energetskiRazred;
    int AC;
    
}STAN;


int main(){
    
    int counter = 0;
    STAN stanovi[20];
    int n;
    
    do {
        printf("Unesi broj stanova max 20 & min 2: ");
        scanf("%d",&n);
    } while (n>20||n<2);
    
    
    for (int i = 0; i<n; i++) {
        
        printf("Unesi podatke %d. stana: ",i+1);
        printf("Povrsina: ");
        scanf("%f",&stanovi[i].povrsina);
        printf("Cijena: ");
        scanf("%d",&stanovi[i].cijena);
        printf("Adresa: ");
        scanf(" %49[^\n]", stanovi[i].adresa);
        printf("Energetski razred: ");
        scanf(" %c",&stanovi[i].energetskiRazred);
        printf("Klima [1/0]: ");
        scanf("%d",&stanovi[i].AC);
        
    }
    
    
    printf("REZULTATI:\n");
    
    for (int i = 0; i<n; i++) {

        float cijenaPoKvadratu = (float)stanovi[i].povrsina/stanovi[i].cijena;
        if(cijenaPoKvadratu>1100||cijenaPoKvadratu<900) if (stanovi[i].AC==0) {
                printf("%s, %i\n",stanovi[i].adresa,stanovi[i].cijena);
                counter++;
            }
    }
    
    if (counter==0) {
        printf("Niti jedan stan ne odgovara kriterijima");
    }
    
    return 0;
    
}
