
#include <stdio.h>
#include <math.h>

struct tocka{
    int x;
    int y;
};

struct trokut{
    struct tocka A;
    struct tocka B;
    struct tocka C;
};

int main(int argc, const char * argv[]) {
    
    struct trokut Trokut;
    
    printf("Unesi x i y koordinatu prve tocke:");
    scanf("%d %d",&Trokut.A.x,&Trokut.A.y);
    printf("Unesi x i y koordinatu druge tocke:");
    scanf("%d %d",&Trokut.B.x,&Trokut.B.y);
    printf("Unesi x i y koordinatu trece tocke:");
    scanf("%d %d",&Trokut.C.x,&Trokut.C.y);
    
    float opseg = (float)sqrt(pow(Trokut.A.x-Trokut.B.x, 2)+pow(Trokut.A.y-Trokut.B.y, 2)) + (float)sqrt(pow(Trokut.C.x-Trokut.B.x, 2)+pow(Trokut.C.y-Trokut.B.y, 2)) +(float)sqrt(pow(Trokut.A.x-Trokut.C.x, 2)+pow(Trokut.A.y-Trokut.C.y, 2));
    
    printf("Opseg trokuta A(%d %d) B(%d %d) C(%d %d) iznosi: %.2f ",Trokut.A.x,Trokut.A.y,Trokut.B.x,Trokut.B.y,Trokut.C.x,Trokut.C.y,opseg);
   
    
   
}
