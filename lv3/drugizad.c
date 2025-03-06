#include <stdio.h>
#include <stdlib.h>
int najveci (int **a, int n, int m);


int main(){
        // a je matrica, m i n su dimenzije matrice
        int **a, m, n;
        
        // zbog testinih slucajeva potrebno je prvo unijeti velicinu n, a tek zatim m
        do{
            //upis i provjera scanf-a za n
            scanf("%d",&n);
        }while(n>5||n<2);//uvjeti za n
        do{
            //upis i provjera scanf-a za m
            scanf("%d",&m);
        }while(m>8||m<2);//uvjeti za m
        
        //ovdje ide vas kod za upis dimenzija matrice i elemenata u matricu
         a = (int**)calloc(n,sizeof(int*));
         if(a== NULL) return 1;
        for(int i = 0;i<n;i++){
        *(a+i) = (int*)calloc(m,sizeof(int));
        if(*(a+i)== NULL) return 1;
        }
        for(int i = 0;i<n;i++){
            for(int j = 0; j<m;j++){
                printf("[%d][%d]: ",i+1,j+1);
                scanf("%d",*(a+i)+j);
            }
        }
        
        
        
        //pogledajte primjer 3 u LV
        
        //Ispis rezultata
        printf("\nREZULTATI:\n");
        printf("%d", najveci (a,n,m));
        
        for(int i = 0; i<n;i++){
            free(*(a+i));
        }
        free(a);
        return 0;
}
int najveci (int **a, int n, int m){
        //ova funkcija treba vratiti vrijednost najveceg elementa u predanoj matrici
       //ovdje ide vas kod
       int maxElement = **a;
       
       for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(maxElement< *(*(a+i)+j)) maxElement = *(*(a+i)+j);
        }
       }
        return maxElement;
}
