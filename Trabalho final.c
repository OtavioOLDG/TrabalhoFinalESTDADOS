#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define TAM 53

typedef struct Nodo{
	char* name;
	struct Nodo* next;
	struct Nodo* prev;
} Nodo;

typedef struct{
	struct Nodo* head;
	struct Nodo* tail;
	int size;
}List;

void InitializeHashTable(List** hashTable);
int hashFunction(char*);
Nodo* createNodo(char*);
List* createList();
int emptyList(List*);
void insertList(List**, char*);
int removeList(List**, char*);
void errorTreatment(int);
void printList(List**);
Nodo* nodoName(List**, char*);
void isThereTheName(Nodo*);
void toLowerName(char*);
void toUpperName(char*);

int main(){
	
	List** hashTable;
	hashTable = (List**)malloc(TAM * sizeof(List*));
	InitializeHashTable(hashTable);
	FILE *file;
	file = fopen("C:\\Users\\AmoCP\\OneDrive\\Documentos\\Nomes\\nomes.txt", "r");
	if(file == NULL){
		printf("No file found\n");
		getchar();
		exit(0);
	}
	
	char line[20];
	
	while (fgets(line, sizeof(line), file) != NULL) {
	       // Remover a quebra de linha do final da linha
	       if (line[strlen(line) - 1] == '\n') {
	       	line[strlen(line) - 1] = '\0';
	       }
		
		toLowerName(line);
		toUpperName(line);
	       // Agora, 'linha' cont�m o nome lido do arquivo
	       insertList(hashTable, line);
	}

	isThereTheName(nodoName(hashTable, "Otavio"));
	isThereTheName(nodoName(hashTable, "Lucas"));
	printList(hashTable);
}

void InitializeHashTable(List** hashTable){
	int i;
	
	for(i = 0; i < TAM; i++)
		hashTable[i] = createList();
}

int hashFunction(char* name){
	int i, lenght = strlen(name);
	unsigned int hash = 0;
	
	for(i = 0; i < lenght; i++)
		hash += (name[i] * (i+1));
		
	return hash % TAM;
}

Nodo* createNodo(char* name){
	Nodo* newNodo;
	newNodo = (Nodo*) malloc (sizeof(Nodo));
	if(newNodo != NULL){
		newNodo->name = strdup(name); 
		newNodo->next = NULL;
		newNodo->prev = NULL;
	}
	return newNodo;
}

List* createList(){
	List* list;
	list = (List*) malloc(sizeof(List));
	if(list != NULL){
		list->head = NULL;
		list->tail = NULL;
		list->size = 0;
	}
	return list;
}

int emptyList(List* list){
	if(list->size == 0){
		return 1;
	}
	return 0;
}

void errorTreatment(int error){
	if(error == -1){
		printf("\nEmpty Listn");	
	}
	else if(error == -2){
		printf("\nList End\n");	
	}
}

void insertList(List** hashTable, char* name){
	int hash = hashFunction(name);
	Nodo* newName;
	newName = createNodo(name);
	
	if(emptyList(hashTable[hash])){
		hashTable[hash]->head = newName;
		hashTable[hash]->tail = newName;
		newName->next = NULL;
		newName->prev = NULL;
	}
	else{
		hashTable[hash]->tail->next = newName;
		newName->prev = hashTable[hash]->tail;
		hashTable[hash]->tail = newName;
		newName->next = NULL;
	}
	hashTable[hash]->size++;
}


int removeList(List** hashTable, char* name){
	int hash = hashFunction(name);
	Nodo* oldElement;
	Nodo* nodo = hashTable[hash]->head;
	
	if(emptyList(hashTable[hash])){
		return -1;
	}
	
	while(nodo!=NULL && (strcmp(name, nodo->name) != 0)){
		nodo = nodo->next;
	}

	if(nodo == NULL || nodo == hashTable[hash]->head){
		oldElement = hashTable[hash]->head;
		if(hashTable[hash]->head->next != NULL){
			hashTable[hash]->head->next->prev = NULL;
		}
		hashTable[hash]->head = hashTable[hash]->head->next;
		if(oldElement->next == NULL){
			hashTable[hash]->tail = NULL;
		}
	} else if(nodo->next == NULL){
		oldElement = nodo;
		if(hashTable[hash]->tail->prev != NULL){
			hashTable[hash]->tail->prev->next = NULL;
		}
		hashTable[hash]->tail = hashTable[hash]->tail->prev;
		if(oldElement->prev == NULL){
			hashTable[hash]->head = NULL;
		}
	} else{
		oldElement = nodo;
		oldElement->prev->next = oldElement->next;
		oldElement->next->prev = oldElement->prev;
	}
	free(oldElement);
	hashTable[hash]->size--;
}

void printList(List** hashTable){
	int i;
	for(i = 0; i < TAM; i++){
		Nodo* nodo;
		nodo = hashTable[i]->head;
		if (nodo != NULL)
			printf("Hashing %i: ", i+1);
			
		while(nodo != NULL){
			if(nodo->next != NULL){
				printf("%s, ", nodo->name);
			} else{
				printf("%s;\n\n", nodo->name);
			}
			nodo = nodo->next;
		}
	}
}

Nodo* nodoName(List** hashTable, char* name){
	int hash = hashFunction(name);
	Nodo* nodo;
	nodo = hashTable[hash]->head;
	while(nodo != NULL){
		if(strcmp(name, nodo->name) == 0)
			return nodo;
		nodo = nodo->next;
	}
	return NULL;
}

void isThereTheName(Nodo* name){
	if(name == NULL)
		printf("No name found;\n");
	else 
		printf("Name found: %s;\n", name->name);
}

void toLowerName(char* name){
	int i;
	for(i = 0; i < strlen(name); i++)
		name[i] = tolower(name[i]);
}

void toUpperName(char* name){
	name[0] = toupper(name[0]);
}













