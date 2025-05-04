#include <stdio.h>
#include <stdlib.h>

int sekvencijalnoPretrazivanje(int *niz,int n,int target){
    for (int i = 0; i<500; i++) {
        if (niz[i]==target) {
            return i;
        }
    }
    return -1;
}

int binarnoPretrazivanje(int *niz,int n,int target){
    
    int dg = 0;
    int gg = n-1;
    int s;
    int brojKoraka = 1;
    while(dg<gg){
        s=(gg-dg)/2;
        if(niz[s]==target)return brojKoraka;
        if(target>niz[s]) dg = s+1;
        if(target<niz[s]) gg = s-1;
    }
    
    return -1;
    
    
}

int main(){
    FILE *file;
    int korisnickiBrojevi[5];
    int brojeviIzDatoteke[500];
    int brojKorakaBin = 0;
    int brojPronadenihBin = 0;
    int brojKorakaSekv = 0;
    int brojPronadenihSekv = 0;
    int temp;
    
    for (int i = 0; i<5; i++) {
        do {
            scanf("%d",&korisnickiBrojevi[i]);
        } while (korisnickiBrojevi[i]<1||korisnickiBrojevi[i]>1000);
    }
    
    file = fopen("in1.txt","r");
    if(file==NULL) exit(EXIT_FAILURE);
    for (int i = 0; i<500; i++) {
        fscanf(file, "%d",&brojeviIzDatoteke[i]);
    }
    printf("REZULTATI:\nSekvencijalno:\n");
    for (int i = 0; i<5; i++) {
        if((temp = sekvencijalnoPretrazivanje(brojeviIzDatoteke, 500, korisnickiBrojevi[i]))!=-1){
            printf("%d. broj %d je pronadjen u %d koraka.\n",i+1,korisnickiBrojevi[i],temp+1);
            brojKorakaSekv += temp + 1;
            brojPronadenihSekv++;
        }
        else printf("%d. broj %d nije pronaden.\n",i+1,korisnickiBrojevi[i]);
    }
    printf("Binarno:\n");
    for (int i = 0; i<5; i++) {
        if((temp = binarnoPretrazivanje(brojeviIzDatoteke, 500, korisnickiBrojevi[i]))!=-1){
            printf("%d. broj %d je pronadjen u %d koraka.\n",i+1,korisnickiBrojevi[i],temp+1);
            brojKorakaBin += temp + 1;
            brojPronadenihBin++;
            
        }
        else printf("%d. broj %d nije pronaden.\n",i+1,korisnickiBrojevi[i]);
    }
    
    printf("Srednji broj koraka za sekvencijalno pretrazivanje je: %.2f",(float)brojKorakaSekv/brojPronadenihSekv);
    printf("Srednji broj koraka za sekvencijalno pretrazivanje je: %.2f",(float)brojKorakaBin/brojPronadenihBin);
}
