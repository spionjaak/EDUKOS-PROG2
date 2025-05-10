// ovo je main datoteka koja sadrži pozive svih potrebnih funkcija, nju ne trebate dirati

#include <stdio.h>
#include "header.h"


int  main() {
	int n, i, x;
	
	STUDENT *headNode = NULL;
	STUDENT *targetNode = NULL;
	
	printf("Koliko studenata zelis unijeti? ");
	scanf("%d", &n);

	headNode = createSLList();                      // kreiranje povezanog popisa i umetanje prvog člana

	for (i = 0; i < n-1; i++)
	{
		headNode = insertNewNodeSLList(headNode);   // umetanje sljedećih n-1 članova
	}

	printf("Unesite ID studenta kojeg trazite\n");  // unos ID-a studenta kojeg tražimo i brišemo
	scanf("%d", &x);
	
	printf("REZULTATI:\n");
	
	traverseSLList(headNode);                       // obilazak povezanog popisa i ispis svih članova
	printf("Ukupan prosjek svih studenata je: %.2f\n", prosjekSvih(headNode)); // izračun prosjeka svih studenata

	targetNode = searchSLList(headNode, x);         // traženje studenta preko ID-a

	if (targetNode == NULL) {
		printf("Student s trazenim ID-em nije pronadjen!\n");   // ispis poruke ako nije pronadjen
	}
	else {                                                      // ako je pronadjen
		deleteNodeSLList(&headNode, targetNode);                // brisanje studenta
		traverseSLList(headNode);                               // ponovni obilazak povezanog popisa i ispis svih članova
		printf("Ukupan prosjek svih studenata je: %.2f\n", prosjekSvih(headNode)); // ponovni izračun prosjeka svih preostalih studenata
	}
	headNode = deleteWholeSLList(headNode);                     // oslobađanje memorije za cijeli povezani popis

	return 0;
}
