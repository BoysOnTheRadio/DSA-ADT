#include <stdio.h>
#define MAX 4

typedef struct{
    int elem;
    int next;
} Cell, HeapSpace[MAX];

typedef struct {
    HeapSpace H;
    int avail;

} VHeap;

typedef int List;
List *L = -1;

void initialize(VHeap *V);
int allocSpace(VHeap *V);
void deallocSpace(VHeap* V, int index);
void insertFirst(int *L, VHeap* V, int elem);
void insertLast(int *L, VHeap* V, int elem);
void insertSorted(int* L, VHeap* V, int elem);
void delete(int* L, VHeap* V, int elem);
void deleteAllOccurrence(int *L, VHeap* V, int elem);
void display(int L, VHeap V);

int main(){
    VHeap V;
    initialize(&V);
}

void initialize(VHeap *V){
    V->avail = 0;
    for(int i = 0; i < MAX; V->H[i].next = i + 1, i++){
        if(i = MAX - 1){
            V->H[i].next = -1;
        }
    }
}

int allocSpace(VHeap* V){
    if(V->avail == -1){
        return -1;
    }

    int ret = V->avail; 
    V->avail = V->H[ret].next;
    return ret;
}

void deallocSpace(VHeap *V, int index){

    V->H[index].next = V->avail;
    V->avail = index;

}

void insertFirst(int *L, VHeap *V, int elem){
    int newCell = allocSpace(V);

    if(newCell != -1){
        V->H[newCell].elem = elem;
        V->H[newCell].next = *L;

        *L = newCell;
    }
}

void inserLast(int* L, VHeap *V, int elem){
    int newCell = allocSpace(V);

    if(newCell != -1){
        V->H[newCell].elem = elem;
        V->H[newCell].next = -1;

        int *trav = L;
        while(*trav != -1){
            trav = &V->H[*trav].next;
        }

        *trav = newCell;

    }
}

