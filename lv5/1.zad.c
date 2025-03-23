

#include <stdio.h>
#include <stdlib.h>
#include <math.h>


typedef struct tocka {
    float x;
    float y;
    float z;
} Tocka;
typedef struct trokut {
    struct tocka *t1;
    struct tocka *t2;
    struct tocka *t3;
} Trokut;

void unesiTocke(Tocka*, int);
void unesiTrokute(Trokut*, Tocka*, int);
float pronadjiNajveciOpseg(Trokut*, int);

/* Ukoliko koristite dodatne funkcije mozete ih navesti nakon ovog komentara */


int main(void)
{
  int n, m;
  Tocka tocke[100];
  Trokut trokuti[100];
  float opseg;

  printf("Upisi broj tocaka koje zelis unijeti: ");
  scanf("%d", &n);

  printf("Upisi broj trokuta koje zelis unijeti: ");
  scanf("%d", &m);

  unesiTocke(tocke, n);
  unesiTrokute(trokuti, tocke, m);

  opseg = pronadjiNajveciOpseg(trokuti, m);

  printf("REZULTATI:\n");
  printf("%.2f", opseg);

	return 0;
}

void unesiTocke(Tocka *p, int n){
    for (int i = 0; i < n; i++) {
scanf("%f %f %f", &p[i].x, &p[i].y, &p[i].z); 
}
}

void unesiTrokute(Trokut *t, Tocka *p, int m){
int ind1, ind2, ind3;
for (int i = 0; i < m; i++) {
    scanf("%d %d %d", &ind1, &ind2, &ind3);
    t[i].t1 = &p[ind1];
    t[i].t2 = &p[ind2];
    t[i].t3 = &p[ind3];
}
    
}


float pronadjiNajveciOpseg(Trokut *t , int m){
    float opseg[10];
    
    for(int i = 0; i < m; i++){
        opseg[i] = 0;
        opseg[i] += sqrt(pow((t[i].t1->x - t[i].t2->x),2) + pow((t[i].t1->y - t[i].t2->y),2) + pow((t[i].t1->z - t[i].t2->z),2));
        opseg[i] += sqrt(pow((t[i].t3->x - t[i].t2->x),2) + pow((t[i].t3->y - t[i].t2->y),2) + pow((t[i].t3->z - t[i].t2->z),2));
        opseg[i] += sqrt(pow((t[i].t1->x - t[i].t3->x),2) + pow((t[i].t1->y - t[i].t3->y),2) + pow((t[i].t1->z - t[i].t3->z),2));
    }
    
    int maks = 0;
    
    for(int i = 0; i< m;i++){
        if(opseg[maks]< opseg[i]) maks = i;
    }
    return opseg[maks];
    
}




//ovdje pisete implementaciju potrebnih funkcija. 
