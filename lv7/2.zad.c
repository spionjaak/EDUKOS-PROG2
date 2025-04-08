#include <stdio.h>

int main(){
    FILE *in;
    FILE *out;
    int n,m;
    in = fopen("in.txt","r");
    fscanf(in,"%d %d",&n,&m);
    fclose(in);
    float mat[n][m];
    
    for(int i = 0; i<n;i++){
        for(int j = 0;j<m;j++){
            scanf("%f",&mat[i][j]);
        }
    }
    out = fopen("out.txt","w");
    printf("REZULTATI:\n");
    
    for(int i = 0; i<n-1;i++){
        for(int j = 1;j<m;j++){
            printf("%.2f\t",mat[i][j]);
            fprintf(out,"%.2f\t",mat[i][j]);
        }
        printf("\n");
        fprintf(out,"\n");
    }
    fclose(out);
}
