// 1.	Korisnik treba unijeti cjelobrojnu vrijednost u rasponu od 1 do 7, 
//pri čemu 1 predstavlja ponedjeljak, a 7 nedjelju. 
//Ispisati poruku „Vikeeeend!“ ako je unesen broj koji označava neradne dane ili
//poruku „Radis jos %d dana do vikenda.“ ako je unesen broj koji označava radne dane.
//Za dane u tjednu koristiti enumeraciju.


#include <stdio.h>

enum tjedan {ponedjeljak=1,utorak,srijeda,cetvrtak,petak,subota,nedjelja};

int main(){
    int n;
    scanf("%d",&n);
    printf("REZULTATI:\n");
    if(n==subota || n==nedjelja) printf("Vikeeeend!");
    else printf("Radis jos %d dana do vikenda.",petak-n);
    
}
