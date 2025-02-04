
#include <stdio.h>
#include <math.h>

typedef struct complex{
    float re;
    float im;
}COMPLEX;

int main(){
    COMPLEX a,b;
    printf("Unesi podatke za prvi kompleksni broj:");
    scanf("%f %f",&a.re,&a.im);
    printf("Unesi podatke za drugi kompleksni broj:");
    scanf("%f %f",&b.re,&b.im);
    printf("REZULTATI:");
    printf("%.3f, %.3f*i\n",a.re+b.re,a.im+b.im);
   printf("%.3f, %.3f*i\n",a.re-b.re,a.im-b.im);
}
