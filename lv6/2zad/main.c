/*Napišite C program koji će u polje struktura artikl omogućiti unos n (n<10) artikala
(struktura ima članove ime, kolicina i cijena) te nakon toga omogućiti unos podataka za
svaki artikl u polju prema redoslijedu: ime, kolicina te cijena. U pokazivač max spremiti
memorijsku adresu najskupljeg artikla. Ispisati cijenu i količinu najskupljeg artikla.

Zadatak obavezno razdvojiti u više datoteka, prema uputama u pripremi.*/



#include "lv6-2-header.h"
#include <stdio.h>

//ovaj kod ne trebate mijenjati, vec nadopuniti lv6-2-func.c te lv6-2-header.h


int main(void)
{
  ARTIKL *max, artikli[100];
  int n;
  printf("Unesi n: ");
  scanf("%d", &n);
  
  ucitavanje(&artikli[0], n);
  max=najveci(&artikli[0], n);



  // ispis ne dirati, mora koristiti pokazivac max
  printf("REZULTATI:\n");
  printf("cijena: %.2f, kolicina: %d", max->cijena, max->kolicina);
  return 0;
}

