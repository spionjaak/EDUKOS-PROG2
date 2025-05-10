typedef struct student {
	char *ime;
	char *prezime;
	int id;
	float prosjek;
	struct student* nextNode;
}STUDENT;

void inputNodeData(STUDENT*);
float prosjekSvih(STUDENT *);
STUDENT* createSLList(void);
void traverseSLList(STUDENT*);
STUDENT* insertNewNodeSLList(STUDENT*);
STUDENT* searchSLList(STUDENT*, int);
void deleteNodeSLList(STUDENT**, STUDENT*);
STUDENT* deleteWholeSLList(STUDENT*);