#include <stdio.h>
#include <stdlib.h>

int main(){
    int p[500],trazeni,pronaden=0,brk;
    FILE *file = fopen("in1.txt","r");
    if(file == NULL) exit(EXIT_FAILURE);
    for(int i=0;i<500;i++){
        fscanf(file,"%d",&p[i]);
    }
    scanf("%d",&trazeni);
    for(int i = 0; i< 500;i++){
        if(trazeni==p[i]){
            brk = i+1;
            pronaden = 1;
            break;
        }
    }
    
    printf("REZULTATI:\n");
    if(pronaden) printf("Broj %d je pronadjen nakon %d koraka.",trazeni,brk);
    else printf("Broj %d nije pronadjen.",trazeni);
    
    
    fclose(file);
    return 0;
}
