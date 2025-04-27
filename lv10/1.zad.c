
/*

Napišite C program koji učitava točke i trokute iz datoteke model.txt. Program
iz datoteke učitava prvo broj točaka n, zatim broj trokuta m, a zatim točke
i trokute. Potrebno je dinamički zauzeti memoriju za unos točaka i trokuta.
Pronaći i ispisati opseg trokuta koji ima najveći opseg u formatu „%.2f“.

*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct tocke{
    float x;
    float y;
    float z;
}VRHOVI;

typedef struct trokut{
    VRHOVI *p1;
    VRHOVI *p2;
    VRHOVI *p3;
}TROKUTI;


float racunajOpseg(TROKUTI *trokuti,int m);

int main(){
    FILE *file = fopen("model.txt","r");
    if(file == NULL) 
        return 1;
    int n,m;
    
    fscanf(file,"%d",&n);
    fscanf(file,"%d",&m);
    
    VRHOVI *tocke = (VRHOVI*)malloc(n*sizeof(VRHOVI));
    TROKUTI *trokuti = (TROKUTI*)malloc(m*sizeof(TROKUTI));
    
    for(int i = 0; i<n;i++){
        fscanf(file,"%f %f %f",&(tocke+i)->x,&(tocke+i)->y,&(tocke+i)->z);
    }
    
    for(int i = 0;i<m;i++){
        int temp1,temp2,temp3;
        fscanf(file,"%d %d %d",&temp1,&temp2,&temp3);
        (trokuti+i)->p1 = (tocke+temp1);
        (trokuti+i)->p2 = (tocke+temp2);
        (trokuti+i)->p3 = (tocke+temp3);
    }
    
    float opseg = racunajOpseg(trokuti,m);
    printf("REZULTATI:\n");
    printf("%.2f",opseg);
    
    
    
    free(tocke);
    free(trokuti);
    fclose(file);
}




float racunajOpseg(TROKUTI *trokuti,int m){
    float opseg[m];
    float maksOpseg = 0;
    for(int i = 0; i<m;i++){
        opseg[i]=0;
        float x1 = (trokuti+i)->p1->x;
        float y1 = (trokuti+i)->p1->y;
        float z1 = (trokuti+i)->p1->z;
        float x2 = (trokuti+i)->p2->x;
        float y2 = (trokuti+i)->p2->y;
        float z2 = (trokuti+i)->p2->z;
        float x3 = (trokuti+i)->p3->x;
        float y3 = (trokuti+i)->p3->y;
        float z3 = (trokuti+i)->p3->z;
        
        opseg[i] += sqrt(pow((x1-x2),2) + pow((y1-y2),2) + pow((z1-z2),2));
        opseg[i] += sqrt(pow((x3-x2),2) + pow((y3-y2),2) + pow((z3-z2),2));
        opseg[i] += sqrt(pow((x1-x3),2) + pow((y1-y3),2) + pow((z1-z3),2));
        
        if(maksOpseg<opseg[i]) maksOpseg=opseg[i];
        
    }
    
    return maksOpseg;
    
}
