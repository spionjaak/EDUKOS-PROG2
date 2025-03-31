#include <stdio.h>
#include <stdlib.h>

int** allocateMatrix(int n,int m){
int** mat = NULL;
mat = (int**)malloc(n * sizeof(int*));
if (mat == NULL) {
return NULL;
}

for (int i = 0; i < n; i++) {
mat[i] = (int*)malloc(m * sizeof(int));
if (mat[i] == NULL) {
return NULL;
}
}
return mat;
    
}
void inputMatrix(int **M,int n,int m){
    
    int i, j;
for (i = 0; i < n; i++) {
for (j = 0; j < m; j++) {
scanf("%d", (*(M + i) + j));
}
}
}
void matrixTimesK(int **M,int n,int m,int K){
    int i, j;
    
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            M[i][j] *= K;
        }
    }
    
    
}
void printMatrix(int **M,int n,int m){
    int i, j;
for (i = 0; i < n; i++) {
for (j = 0; j < m; j++) {
printf("%d\t", M[i][j]);
}
printf("\n");
}
}
