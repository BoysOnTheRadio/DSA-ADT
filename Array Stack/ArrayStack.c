#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 10

typedef struct {
    int items[MAX];
    int top;
} Stack;

Stack* initialize();
bool isFull(Stack* s);
bool isEmpty(Stack* s);
void push(Stack* s, int value);
int pop(Stack* s);
int peek(Stack* s);
int top(Stack *s);
void display(Stack* s);

int main(){
    int data, position;
    initialize();
    int choice = 1;
    while(choice != 0){
    	printf("Select Operation\n1. Insert Position\n2. Delete Position\n3. Locate\n4. Insert Sorted\nSelect Choice(0 to Exit): "); scanf("%d", &choice);
	    
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
			default:
				printf("Invalid Choice.");
				break;
		}
	}
	return 0;
}

Stack *initialize(){
    Stack* s = (Stack*)malloc(sizeof(Stack));
    s->top = -1;

    return s;
}

bool isFull(Stack* s){
    return s->top == MAX - 1;
}

bool isEmpty(Stack* s){
    return s->top == -1;
}

void push(Stack* s, int value){
    if(isFull(s)){
        printf("Stack is full!");
        return;
    }

    s->top++;
    s->items[s->top];
}

int pop(Stack* s){
    if(isEmpty(s)){
        printf("Stack is empty!");
        return -1;
    }

    int temp = s->items[s->top];
    s->top--;

    return temp;
}

int peek(Stack* s){
    if(isEmpty(s)){
        printf("Stack is empty!");
        return -1;
    }

    return s->items[s->top];
}

int top(Stack *s){
    return s->top;
}

void display(Stack *s){
    if(isEmpty(s)){
        printf("Stack is empty!");
        return;
    }

    printf("[");
	for(int i = 0; i < s->top; i++){
	    printf("%d", s->items[i]);
	    if(i < MAX-1) printf(", ");
	}
	printf("]\n\n");
}