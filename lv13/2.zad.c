#include <stdio.h>
#include <stdlib.h>

#define MAKRO(dg, gg) (((dg) + (gg)) / 2) 

int main() {
    int V[500];  
    FILE *file = fopen("in.txt", "r");

   
    if (file == NULL) {
        printf("Greška pri otvaranju datoteke.\n");
        return 1;
    }

   
    for (int i = 0; i < 500; i++) {
        if (fscanf(file, "%d", &V[i]) != 1) {
            printf("Greška pri čitanju broja na indeksu %d.\n", i);
            fclose(file);
            return 1;
        }
    }
    fclose(file);

   
    int x;
    printf("Unesite broj koji tražite (u intervalu [1, 1000]): ");
    scanf("%d", &x);

    int dg = 0, gg = 499, s;
    int nadjen = 0;

    
    while (dg <= gg) {
        s = MAKRO(dg, gg);

        if (x == V[s]) {
            printf("Broj je nađen.\n");
            nadjen = 1;
            break;
        } else if (x > V[s]) {
            dg = s + 1;
        } else {
            gg = s - 1;
        }
    }

   
    if (!nadjen) {
        printf("Broj nije pronađen.\n");
    }

    return 0;
}
