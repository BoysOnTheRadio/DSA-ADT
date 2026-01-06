#include <stdio.h>
#include <string.h>

#define MAX 20
#define Empty " "
#define Delete -1

typedef struct {
    char code[3];
    int next;
} Cell, HeapSpace[MAX];

typedef struct VHeap{
    HeapSpace H;
    int avail;
} VHeap;

int hash(char code[3]);
void initialize(VHeap *V);
int allocSpace(VHeap *V);

int main(){
    VHeap *V;

    initialize(V);
}


int hash(char *code){
    return ((code[0] - 'A') * 26 * 26 + (code[1] - 'A') * 26 + (code[2] - 'A') % 10);
}

void initialize(VHeap *V){
    V->avail = MAX/2 - 1;
    
    for(int i = 0; i <= MAX - 1; i++){ 
        if(i < MAX/2 || i == MAX - 1){
            strcpy(V->H[i].code, Empty);
            V->H[i].next = -1;
        } else {
            strcpy(V->H[i].code, Empty);
            V->H[i].next = i;
        }
    }
}

int allocSpace(VHeap* V){
    if(V->avail >= MAX){
        return -1;
    }

    return V->avail++;
}

void insert(VHeap *V, char *code){
    int key = hash(code);

    if(strcmp(V->H[key].code, Empty) == 0){
        strcpy(V->H[key].code, code);
    } else {
        //In case of collisions, use secondary space
        int curr = key;
        while(V->H[curr].next != -1){
            curr = V->H[curr].next;
        }

        int newIndex = allocSpace(V);
    }
}

