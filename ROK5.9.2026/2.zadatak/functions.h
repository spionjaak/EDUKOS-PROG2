#ifndef mojHeader
#define mojHeader


// Definicija strukture 
typedef struct {
    char naslov[100];
    char izvodac[50];
    char zanr[50];
    int godina;
    int trajanje; // u sekundama
} PJESMA;


// Deklaracije funkcija

PJESMA* ucitajPjesme(const char* imeDatoteke, int* brojPjesama);
float izracunajProsjecnoTrajanje(PJESMA* pjesme, int brojPjesama, const char* zanr);
int prebrojiPoZanru(PJESMA* pjesme, int brojPjesama, const char* zanr);
void pretraziPoNaslovu(PJESMA* pjesme, int brojPjesama, const char* naslov);


#endif // !mojHeader






