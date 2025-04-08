//Datoteka Dat.txt iz koje cete citati vec je stvorena, ali njen sadrzaj
//nemojte mijenjati, inace nece proci testcaseovi

#include <stdio.h>

int main(){
    FILE *dat;
    FILE *studenti;
    char ime[20],prezime[20];
    int n;
    
    dat = fopen("Dat.txt","r");
    fscanf(dat,"%d",&n);
    fclose(dat);
    
    studenti = fopen("Studenti.txt","w");
    for(int i = 0; i <n; i++){
        scanf("%s %s",ime,prezime);
        fprintf(studenti,"%s %s\n",ime,prezime);
        printf("%s %s\n",ime,prezime);
        
    }
    fclose(studenti);
    return 0;
}
