
#include <stdio.h>
#include <math.h>

struct tocka{
    int x;
    int y;
};

int main(int argc, const char * argv[]) {
    
    struct tocka A,B;
    
    printf("Unesi x i y koordinatu prve tocke:");
    scanf("%d %d",&A.x,&A.y);
    printf("Unesi x i y koordinatu druge tocke:");
    scanf("%d %d",&B.x,&B.y);
    float d = (float)sqrt(pow(A.x-B.x, 2)+pow(A.y-B.y, 2));
    printf("\nDijagonala izmedu tocaka A(%d,%d) i B(%d,%d) iznosi %f",A.x,A.y,B.x,B.y,d);
   
}
