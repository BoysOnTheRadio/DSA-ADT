#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 10

typedef struct{
    int arr[MAX];
    int size;
} Heap;

void swap (int *a, int *b);
void insert(Heap *BH, int value);
void upheapify(Heap *BH);
void downheapify(Heap *BH);
void print(Heap *BH);

int main(){
    Heap *BH = malloc(sizeof(Heap));
    BH->size = 0;

    insert(BH, 10);
    insert(BH, 7);
    insert(BH, 5);
    insert(BH, 9);

    print(BH);
}

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void insert(Heap *BH, int value){
    
    BH->arr[BH->size] = value;
    BH->size++;

    upheapify(BH);
}

void upheapify(Heap *BH){
    int i = BH->size - 1;
    
    while(i > 0){
        int parent = (i - 1) / 2;

        if(BH->arr[parent] <= BH->arr[i]) break;

        swap(&BH->arr[i], &BH->arr[parent]);
        i = parent;
        
    }
}

void heapifyDown(Heap *BH, int i){
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if(left < BH->size && BH->arr[left] > BH->arr[largest]){
        largest = left;
    }

    if(right < BH->size && BH->arr[right] > BH->arr[largest]){
        largest = right;
    }

    if(largest != i){
        swap(&BH->arr[i], &BH->arr[largest]);
        heapifyDown(BH, largest);
    }
}

void print(Heap *BH){
            for(int i = 0;i < BH->size; i++){
                printf("Index %d | Data %d\n", i, BH->arr[i]);
            }
        }