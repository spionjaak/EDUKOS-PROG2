#include <stdio.h>
int main(){

char *mjeseci[]={ "sijecanj", "veljaca", "ozujak", "travanj", "svibanj", "lipanj", "srpanj", "kolovoz", "rujan", "listopad", "studeni", "prosinac"};
int mjesec;

//Ovdje ide vas kod

scanf("%d",&mjesec);
printf("REZULTATI:\n");
if(mjesec>12||mjesec<1)printf("Nekorektan broj mjeseca");
else printf("%s",*(mjeseci+mjesec-1));

return 0;
}
