Potrebno je dovrsiti C program koji učitava zaposlenike iz binarne datoteke. Ime datoteke korisnik unosi s tipkovnice, zatim 
se unosi odjel zaposlenika za koji se zeli izracunati prosjecna dob te ime zaposlenika koji se pretrazuej i za njega 
se ispisuju sve informacije.
Prva vrijednost koja je zapisana u binarnoj datoteci je broj zaposlenika  nakon čega su zapisani podaci o njima. 
Primjer zapisa u datoteci:
3
"Marko", "Novak", 30, "IT", 2015
"Ana", "Horvat", 28, "Marketing", 2017
"Ivan", "Kovačić", 35, "IT", 2013
(datoteka je binarna te ne mozete vidjeti njen sadrzaj na ovaj nacin, no ovo bi bio redoslijed zapisa)

Funckija main() je dana te ju ne trebate mijenjati već pogledati kojim se slijedom pozivaju funkcije koje trebate zavrsiti.

U functions.c napisati definicije sljedecih funkcija:
Funkcija ucitajZaposlenike() prima ime datoteke koje je ranije uneseno s tipkovnice, a sadrzi informacije o zaposlenicima te 
pokazivac na cjelobrojnu varijablu u koju je potrebno spremiti broj zaposlenika koji su zapisani u datoteci (prva vrijednost).
Povratna vrijednost je pokazivac na polje zaposlenika koje je zauzeto unutar funkcije (obvezna provjera uspjesno zauzete memorije). 

Funkcija izracunajProsjecnuStarost() prima pokazivac na polje zaposlenika, broj zaposlenika te odjel te je potrebno izracunati 
prosjecnu starost zaposlenika tog odjela i vratiti ju povratno u main funkciju.

Funkcija prebrojiPoOdjelu() prima pokazivac na polje zaposlenika, broj zaposlenika te odjel, a cilj joj je vratiti broj ljudi 
u predanom odjelu.

Funkcija pretraziPoImenu() prima pokazivac na polje zaposlenika, broj zaposlenika te ime osobe prema koju treba pronaci 
u polju. Ukoliko je osoba pronadjena, ispsati poruku u obliku:

printf("Zaposlenik: %s %s, Starost: %d, Odjel: %s, Godina zaposljavanja: %d\n",.....);

Ukoliko osoba nije pronadjena, ispisati poruku u obliku:

printf("Zaposlenik s imenom %s nije pronaden.\n", .....);

(int strcmp (const char* str1, const char* str2); - vraca 0 ako su stringovi isti)

Deklaracije funkcija i strukture su dani u functions.h te ju nije potrebno mijenjati.
Pridrzavati se organizacije projekta.
