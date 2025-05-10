#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"



STUDENT* createSLList(void){
STUDENT *headNode = (STUDENT*)malloc(sizeof(STUDENT));

if (headNode == NULL ){

perror("Kreiranje");
return NULL;
}


else {
headNode->nextNode = NULL;
inputNodeData(headNode);
}

return headNode;
}


STUDENT* insertNewNodeSLList(STUDENT* headNode) {
STUDENT *newNode = (STUDENT*)malloc( sizeof(STUDENT));
if (newNode == NULL) {
perror("Kreiranje");
return headNode;
}
else {

inputNodeData(newNode);
newNode->nextNode=headNode;
}
return newNode;
}


void traverseSLList(STUDENT* headNode) {
STUDENT *currentNode = headNode;
while (currentNode != NULL){
printf("ID: %d - %s %s, prosjek: %.2f\n",currentNode->id, currentNode->ime, currentNode->prezime, currentNode->prosjek);
currentNode = currentNode->nextNode;

}

}

STUDENT* searchSLList(STUDENT* traverseNode, int criteria){
while(traverseNode){
if(traverseNode->id == criteria){
return traverseNode;
}
traverseNode = traverseNode->nextNode;
}

return NULL;
}

void deleteNodeSLList(STUDENT** headNode, STUDENT* targetNode){
if (targetNode == NULL){
printf("Ne postoji čvor za brisanje.\n");
return;
}

if (*headNode == targetNode){
*headNode = (*headNode)->nextNode;
free(targetNode->ime);
free(targetNode->prezime);
free(targetNode);
}
else{
STUDENT* traverseNode=*headNode;
while (traverseNode->nextNode){
if (traverseNode->nextNode == targetNode){
traverseNode->nextNode = targetNode->nextNode;
free(targetNode->ime);
free(targetNode->prezime);
free(targetNode);
break;
}
traverseNode = traverseNode->nextNode;
}
}

}


void inputNodeData(STUDENT *student){



printf("Unesite ID studenta: ");
scanf("%d",&student->id);

student->ime=(char*)malloc(40*sizeof(char));
scanf("%s",student->ime);

student->prezime=(char*)malloc(40*sizeof(char));
scanf("%s",student->prezime);

printf("Unesite prosjek studenta: ");
scanf("%f",&student->prosjek);

}

float prosjekSvih(STUDENT* headNode){

if (headNode == NULL){

return 0.0;
}

int count = 0;
float sum = 0.0;
STUDENT* currentNode = headNode;

while (currentNode != NULL){
sum+=currentNode->prosjek;
count++;
currentNode = currentNode->nextNode;
}

return (count > 0) ? (sum / count) : 0.0;
}

STUDENT* deleteWholeSLList(STUDENT* traverseNode) {
STUDENT* deleteNode = NULL;
while (traverseNode) {
deleteNode = traverseNode;

traverseNode = traverseNode->nextNode;
free(deleteNode->ime);
free(deleteNode->prezime);
free(deleteNode);

}
return NULL;
}

