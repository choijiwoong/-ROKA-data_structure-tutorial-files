#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Person.h"

int GetSSN(Person* p){ return p->ssn; }
void ShowPerInfo(Person* p){ printf("id: %d \nname: %s \naddress: %d \n", p->ssn, p->name, p->addr); }

Person* MakePersonData(int ssn, char* name, char* addr){
	Person* newP=(Person*)malloc(sizeof(Person));
	newP->ssn=ssn;
	strcpy(newP->name, name);
	strcpy(newP->addr, addr);
	
	return newP;
}
