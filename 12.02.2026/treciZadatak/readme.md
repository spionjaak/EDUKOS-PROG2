Napisati funkcije za rad s jednostruko povezanim popisom pjesama (playlist).
Svaka pjesma sadrži sljedeće podatke:

    - naslov (dinamički alocirani niz znakova)
    - izvodjac (dinamički alocirani niz znakova)
    - trajanje u sekundama (cijeli broj)
    - ocjena (realni broj u rasponu [1.0, 5.0])
    - pokazivač na sljedeći čvor u listi

Vaš zadatak je implementirati sljedeće tri funkcije:

    [1.] void inputSongData(PJESMA* s);
         – Funkcija prima pokazivač na jednu pjesmu te unosi njezine podatke s tipkovnice:
           naslov, izvodjač, trajanje i ocjena.
           Za tekstualne podatke obavezno prethodno dinamički alocirati memoriju (točna duljina!).

    [2.] void deleteNodeSLList(NODE** head, NODE* target);
         – Funkcija briše jedan zadani čvor iz liste. Ako je riječ o prvom čvoru, ažurira pokazivač na glavu liste.
           Oslobađa zauzetu memoriju za cijeli čvor, uključujući stringove u strukturi PJESMA.

    [3.] void obrisiPjesmePoOcjeni(NODE** head, float minOcjena);
         – Funkcija prolazi kroz cijelu listu i briše sve pjesme čija je ocjena manja od zadane (minOcjena).
           Za svaku obrisanu pjesmu potrebno je osloboditi zauzetu memoriju (struktura + stringovi).
           Funkcija koristi deleteNodeSLList za brisanje pojedinačnih čvorova.
         - Paziti ako obriše sve iz liste!

U potpunosti rukovati memorijom za sve varijable za koje je to nužno.

Ostale funkcije i strukture su već implementirane i dane u projektu:

    1. NODE* createSLList(void);
       – Stvara prvi čvor liste i poziva funkciju za unos podataka.

    2. NODE* insertNewNodeSLList(NODE* head);
       – Stvara novi čvor, unosi podatke i umeće ga na početak postojeće liste.

    3. void traverseSLList(NODE* head);
       – Ispisuje sve pjesme iz liste redom, s prikazom naslova, izvođača, trajanja i ocjene.

    4. float averageRating(NODE* head);
       – Vraća prosječnu ocjenu svih pjesama u listi.

    5. NODE* deleteWholeSLList(NODE* head);
       – Briše cijelu listu, čvor po čvor, i oslobađa sav zauzeti prostor.

!!!!! VAŽNO !!!!
Sva predana rješenja bit će dodatno evaluirana nakon predaje.
Za ostvarenje punog broja bodova, rješenje mora ispravno implementirati
sve tražene funkcionalnosti bez grešaka u logici ili radu s memorijom.

Djelomično riješeni zadaci mogu ostvariti djelomičan broj bodova, ovisno o kvaliteti implementacije
i stabilnosti programa.

Rješenja s ozbiljnim pogreškama (npr. curenje memorije, rušenje programa, neispravno brisanje
ili povezivanje čvorova) neće ostvariti maksimalan broj bodova,
čak i ako je dio funkcionalnosti djelomično prisutan.
