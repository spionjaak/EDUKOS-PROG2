/*
Napišite C program koji će u polje struktura artikl omogućiti unos n (n<10) artikala
(struktura ima članove ime, cijena i kolicina) te nakon toga omogućiti unos podataka za
svaki artikl u polju prema redoslijedu: ime, kolicina te cijena. U pokazivač max spremiti
memorijsku adresu najskupljeg artikla. Ispisati cijenu i količinu najskupljeg artikla.
*/


#include <stdio.h>

struct artikl {
  char ime[30];
  int kolicina;
  float cijena;
};

int main(void)
{
  struct artikl *max;

  //ovdje ide vas kod: definirajte polje struktura,
  //uspisite podatke u strukture, pronadjite najvecu cijenu i
  //dodjelite adresu pokazivacu max
    int n;
    struct artikl artikal[10];
     max = &artikal[0];
      scanf("%d",&n);

  
  for(int i = 0;i<n;i++){
      scanf("%30s",artikal[i].ime);
      scanf("%d",&artikal[i].kolicina);
      scanf("%f",&artikal[i].cijena);
  }
 
  for(int i = 1;i<n;i++){
      if(artikal[i].cijena>max->cijena) max = &artikal[i];
  }





  // ispis ne dirati, mora koristiti pokazivac max
  printf("REZULTATI:\n");
  printf("cijena: %.2f, kolicina: %d", max->cijena, max->kolicina);
  return 0;
}
