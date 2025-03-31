#include <stdio.h>
#include <stdlib.h>
#include "lv6-2-header.h"

void ucitavanje(ARTIKL *A, int n){
    for(int i = 0; i<n;i++){
        scanf("%s", A[i].ime);
        scanf("%d",&A[i].kolicina);
        scanf("%f",&A[i].cijena);
        
    }
}
ARTIKL* najveci(ARTIKL *A,int n){
   int max = 0;
    for(int i = 0; i<n;i++){
        if(A[max].cijena<A[i].cijena){
            max = i;
        }
    }
    
    return A+max;
    
}
    


