/*
Napišite C program koji omogućuje unos dva broja n i m, gdje n predstavlja broj točaka, a m predstavlja broj trokuta.
Nakon toga unijeti koordinate svih točaka te indekse točaka koji čine trokute. Pronaći i ispisati trokut koji ima najveći opseg.
Pretpostaviti da n i m neće biti veći od 10.
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>


struct tocka{
    int x;
    int y;
    int z;
};

struct trokut{
    struct tocka *p1;
    struct tocka *p2;
    struct tocka *p3;
};

float opsegF(struct tocka *p1,struct tocka *p2,struct tocka *p3);

int main(){
    int n,m;
    int indeks;
    float opseg[10];
    float maxOpseg = 0;
    
    struct tocka tocke[10];
    struct trokut trokuti[10];
    
    
    do{
        scanf("%d",&n);
    }while(n>10);
    do{
        scanf("%d",&m);
    }while(m>10);
    
    for(int i = 0;i<n;i++){
        scanf("%d",&tocke[i].x);
        scanf("%d",&tocke[i].y);
        scanf("%d",&tocke[i].z);
    }
    
    for(int i = 0;i<m;i++){
        scanf("%d",&indeks);
        trokuti[i].p1 = &tocke[indeks];
       scanf("%d",&indeks);
        trokuti[i].p2 = &tocke[indeks];
        scanf("%d",&indeks);
        trokuti[i].p3 = &tocke[indeks];
    }
    
for(int i = 0; i< m;i++){
    opseg[i] = opsegF(trokuti[i].p1,trokuti[i].p2,trokuti[i].p3);
    if(opseg[i]>maxOpseg) maxOpseg = opseg[i];
}
 printf("\nREZULTATI:\n");
 printf("%.2f\n",maxOpseg);
 
 return 0;
}



float opsegF(struct tocka *p1,struct tocka *p2,struct tocka *p3){
    float opseg = 0;
    opseg += sqrt(pow((p1->x-p2->x),2)+pow((p1->y-p2->y),2)+pow((p1->z-p2->z),2));
    opseg += sqrt(pow((p3->x-p2->x),2)+pow((p3->y-p2->y),2)+pow((p3->z-p2->z),2));
    opseg += sqrt(pow((p1->x-p3->x),2)+pow((p1->y-p3->y),2)+pow((p1->z-p3->z),2));
    
    return opseg;
}
