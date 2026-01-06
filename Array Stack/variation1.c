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
    Stack * s = initialize();
    push(s, 5);
    printf("\n%d data\n", s->items[0]);
    push(s, 10);
        printf("\n%d data\n", s->items[1]);
    push(s, 15);

    push(s, 20);
    display(s);
    int num = pop(s);
    num = pop(s);
    display(s);
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