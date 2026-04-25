/* 
Napišite program u C jeziku koji koristi strukturu za pohranu matrice dimenzija najviše 10 × 10. 
Struktura treba sadržavati dva cjelobrojna podatka koji predstavljaju broj redaka i broj stupaca (rows, cols) te statički deklarirano dvodimenzionalno polje double a[10][10].

Struktura se mora dinamički zauzeti pomoću malloc ili calloc, dok se njezini članovi ne smiju dodatno dinamički zauzimati – polje za matricu mora biti dio strukture. 

Nakon što se s tipkovnice unesu broj redaka i stupaca (obavezno iz intervala [1,10]), 
potrebno je popuniti elemente matrice pseudo‑slučajnim realnim brojevima iz intervala [-50, 50], 
pri čemu se isključivo koristi inicijalizacija generatora >>>>srand(0)<<<<. 
Funkcijom fillRandom() popuniti matricu pseudo-slučajnim vrijednostima.

Zatim je potrebno pronaći stupac koji sadrži najviše pozitivnih brojeva, ako više stupaca ima jednak broj pozitivnih vrijednosti, 
treba odabrati onaj s najmanjim indeksom (prvi po redu).
Program mora ispisati indeks tog stupca te sve njegove vrijednosti, svaku u novom retku. 
Funkcija bestPositiveCol() provjerava koji stupac ima najviše pozitivnih vrijednosti i ispisuje index stupca i sve vrijednosti tog stupca, svaku u svom redu.

Nakon završetka rada, potrebno je osloboditi dinamički zauzetu memoriju za strukturu, 
pri čemu funkcija zadužena za oslobađanje mora na standardni izlaz ispisati poruku na engleskom jeziku: memory freed.
Funkcijom freeMatrix() oslobađa se moemorija i ispisuje poruka "memory freed".

Program organizirati u datoteke (module).
Ne koristiti VLA polja!

Primjer ulaznih podataka:
3
4
4.44	39.87	-12.19	11.06
47.29	25.49	-29.89	-7.35
12.98	-37.29	38.28	10.30

Primjer ispisa:
REZULTATI:
0
4.44
47.29
12.98

Napisani kôd ne mijenjati!
*/

    
     
int main(void){
    
    srand(0);
    
    //Ispisati rješenje nakon stringa: REZULTATI:\n!!!
    printf("REZULTATI:\n");
    
    return 0;
    
}