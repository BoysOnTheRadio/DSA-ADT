#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define MAX 10
typedef struct{
    int elem[MAX];
    int count;
}List, *EPtr;

void initialize(EPtr *L);
void insertPos(EPtr L, int data, int position);
void deletePos(EPtr L, int position);
int locate(EPtr L, int data);
int retrieve(EPtr L, int position);
void insertSorted(EPtr L, int data);
void display (EPtr L);
void makeNULL(EPtr L);

int main(){
    EPtr L = NULL;
    int data, position;
    initialize(&L);
    int choice = 1;
    while(choice != 0){
        
    	printf("Select Operation\n1. Insert Position\n2. Delete Position\n3. Locate\n4. Insert Sorted\n5. Display\nSelect Choice(0 to Exit): "); scanf("%d", &choice);
	    
	    switch(choice){
            
	    	case 1:
                printf("Enter data: "); scanf("%d", &data);
	    		insertPos(L, data, position);
				break;
			case 2:
				deletePos(L, position);
				break;
			case 3:
				position = locate(L, data);
				if(position != -1) printf("Data found in Position %d", position);
				else printf("Data not found");
				getchar();
				break;
			case 4:
				insertSorted(L, data);
				break;
            case 5:
                display(L);
                break;
			default:
				printf("Invalid Choice.");
				break;
		}
	}

    makeNULL(L);
	return 0;
}

void initialize(EPtr *L){
    *L = (EPtr)malloc(sizeof(List));
    (*L)->count = 0;
    int i;
    for(i=0; i<MAX; i++){
        (*L)->elem[i] = 0;
    }
}

void insertPos(EPtr L, int data, int position){
    if(L->count == MAX){
        printf("\nCould not insert. Array is full.");
        return;
    }

    printf("\n\nEnter position: "); scanf("%d", &position);
    if(position-1 > L->count){
        printf("Invalid Position.");
        return;
    }

    int i;
    for(i = L->count; i >= position; i--){
        L->elem[i] = L->elem[i-1];
        }
    
    L->elem[position] = data;
    L->count++;
}

void deletePos(EPtr L, int position){
    printf("\n\nEnter position: "); scanf("%d", &position);
    if(position-1 > L->count){
        printf("Invalid Position.");
        return;
    }

    int i;
    for(i = 0; i < MAX; i++){
        if(i >= position && i != MAX-1){
        	L->elem[i] = L->elem[i+1];
		}
    }
    L->count--;
}

int locate(EPtr L, int data){
	printf("Enter data: "); scanf("%d", &data);
	
	int i;
	for(i = 0; i < MAX; i++){
		if(L->elem[i] == data){
			return i+1;
		}
	}
	return -1;
}

int retrieve(EPtr L, int position){
    if(position-1 > L->count){
        printf("Invalid Position.");
        return -1;
    }
    return L->elem[position-1];
}


void insertSorted(EPtr L, int data){
	if(L->count == MAX){
        printf("\nCould not insert. Array is full.");
        return;
    }
    
    printf("Enter data: "); scanf("%d", &data);
    int i;
    int n = 0;
    for(i = 0; i < L->count; i++){
        if(L->elem[i] > data){
        	n = i;
        }
    }
    
    for(i = L->count; i > n; i--){
        L->elem[i] = L->elem[i-1];
    }
    L->elem[n] = data;
    L->count += 1;
}

void display(EPtr L){
	printf("[");
	int i;
	for(i=0; i < L->count; i++){
	    printf("%d", L->elem[i]);
	    if(i < MAX-1) printf(", ");
	}
	printf("]\n\n");
}

void makeNULL(EPtr L){
    free(L);
}