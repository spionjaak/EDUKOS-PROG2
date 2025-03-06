//Napravite funkciju koji će omogućiti množenje matrice cijelih brojeva i cijelog broja k te vratiti
//pokazivač na matricu umnoška. U glavnom dijelu programa treba unijeti matricu reda n×m
//(2≤n≤10, 2≤m≤10) i jedan cijeli broj k. Ispisati dobivenu matricu po redcima u formatu “%d\t“.

#include <stdio.h>
#include <stdlib.h>

int** umnozak(int **mat,int n, int m, int k);

int main(){
    int n,m,k;
    
    do {
        printf("Unesi n: ");
        scanf("%d",&n);
    } while (n>10||n<2);
    do {
        printf("Unesi m: ");
        scanf("%d",&m);
    } while (m>10||m<2);
    printf("Unesi k:");
    scanf("%d",&k);
    
    int **mat = (int**)malloc(n*sizeof(int*));
    if(mat==NULL)
        exit(EXIT_FAILURE);
    for (int i = 0; i<n; i++) {
        *(mat+i) = (int*)malloc(m*sizeof(int));
        if (*(mat+i)==NULL)
            exit(EXIT_FAILURE);
    }
    for (int i = 0 ; i< n; i++) {
        for (int j = 0; j<m; j++) {
            scanf("%d",*(mat+i)+j);
        }
        
    }
    
    
    int **rezultat = umnozak(mat,n,m,k);
    if (rezultat == NULL) {
        exit(EXIT_FAILURE);
    }
    printf("\nREZULTATI:\n");
    for (int i = 0 ; i< n; i++) {
        for (int j = 0; j<m; j++) {
            printf("%d\t",rezultat[i][j]);
        }
        printf("\n");
    }
}


int **umnozak(int **mat,int n, int m,int k){
    
    int **res = (int**)malloc(n*sizeof(int*));
    if(res==NULL)
        return NULL;
    for (int i = 0; i<n; i++) {
        *(res+i) = (int*)malloc(m*sizeof(int));
        if (*(res+i)==NULL)
            return NULL;
    }
    
    for (int i = 0; i<n; i++) {
        for (int j = 0; j<m; j++) {
            res[i][j] = mat[i][j] * k;
        }
    }
    
    return res;
    
}
