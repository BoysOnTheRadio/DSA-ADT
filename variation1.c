#include <stdio.h>
#define MAX 10
typedef struct{
    int elem[MAX];
    int count;
}List;

List initialize(List L);
List insertPos(List L, int data, int position);
List deletePos(List L, int position);
int locate(List L, int data);
List insertSorted(List L, int data);
void display (List L);

int main(){
    List L;
    int data, position;
    L = initialize(L);
    int choice = 1;
    while(choice != 0){
    	display(L);
    	printf("Select Operation\n1. Insert Position\n2. Delete Position\n3. Locate\n4. Insert Sorted\nSelect Choice(0 to Exit): "); scanf("%d", &choice);
	    
	    switch(choice){
	    	case 1:
	    		L = insertPos(L, data, position);
				break;
			case 2:
				L = deletePos(L, position);
				break;
			case 3:
				position = locate(L, data);
				if(position != -1) printf("Data found in Position %d", position);
				else printf("Data not found");
				getch("");
				break;
			case 4:
				L = insertSorted(L, data);
				break;
			default:
				printf("Invalid Choice.");
				break;
		}
	}
	return 0;
}

List initialize(List L){
    L.count = 0;
    int i;
    for(i=0; i<MAX; i++){
        L.elem[i] = 0;
    }
    return L;
}

List insertPos(List L, int data, int position){
    if(L.count == MAX){
        printf("\nCould not insert. Array is full.");
        return L;
    }

    printf("\n\nEnter position: "); scanf("%d", &position);
    if(position-1 > L.count){
        printf("Invalid Position.");
        return L;
    }

    printf("Enter data: "); scanf("%d", &data);
    int i;
    for(i = MAX-1; i >= 0; i--){
        L.elem[i] = L.elem[i-1];
        if(i == position-1){
            L.elem[i] = data;
            break;
        }
    }
    L.count++;
    return L;
}

List deletePos(List L, int position){
    printf("\n\nEnter position: "); scanf("%d", &position);
    if(position-1 > L.count){
        printf("Invalid Position.");
        return L;
    }

    int i;
    for(i = 0; i < MAX; i++){
        if(i >= position-1 && i != MAX-1){
        	L.elem[i] = L.elem[i+1];
		}
    }
    L.count--;
    return L;
}

int locate(List L, int data){
	printf("Enter data: "); scanf("%d", &data);
	
	int i;
	for(i = 0; i < MAX; i++){
		if(L.elem[i] == data){
			return i+1;
		}
	}
	return -1;
}

List insertSorted(List L, int data){
	if(L.count == MAX){
        printf("\nCould not insert. Array is full.");
        return L;
    }
    
    printf("Enter data: "); scanf("%d", &data);
    int i;
    int n = 0;
    for(i = 0; i < L.count; i++){
        if(L.elem[i] > data){
        	n = i;
        }
    }
    
    for(i = L.count; i > n; i--){
        L.elem[i] = L.elem[i-1];
    }
    L.elem[n] = data;
    L.count += 1;
    return L;
}

void display(List L){
	system("cls");
	printf("[");
	int i;
	for(i=0; i<MAX; i++){
	    printf("%d", L.elem[i]);
	    if(i < MAX-1) printf(", ");
	}
	printf("]\n\n");
}