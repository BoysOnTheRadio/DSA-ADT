#include <stdio.h>
#include <stdbool.h>

typedef struct {
    unsigned int field : 8;   
} Set;

void initialize(Set *set);
void insert(Set *set, int element);
void deleteElement(Set *set, int element);
bool find(Set set, int element);
Set Union(Set A, Set B);
Set intersections(Set A, Set B);
Set difference(Set A, Set B);
void display(unsigned int set);

int main() {
    Set A, B;

    initialize(&A);
    initialize(&B);

    insert(&A, 0);
    insert(&A, 1);
    insert(&A, 2);
    insert(&A, 3);
    display(A.field);

    insert(&B, 5);
    insert(&B, 6);
    insert(&B, 7);
    display(B.field);

    Set newUnion = Union(A, B);
    display(newUnion.field);

    insert(&B, 3);
    Set newIntersection = intersections(A, B);
    display(newIntersection.field);

    Set newDifference = difference(A, B);
    display(newDifference.field);

    if (find(A, 1)) {
        printf("1 is found\n");
    }

    if (find(A, 6)) {
        printf("6 found\n");
    } else {
        printf("6 not found :(\n");
    }

    return 0;
}

void initialize(Set *set) {
    set->field = 0;
}

void insert(Set *set, int element) {
    if (element >= 0 && element < 8) {
        set->field |= (1U << element);
        printf("Inserted %d\n", element);
    } else {
        printf("Invalid insert\n");
    }
}

void deleteElement(Set *set, int element) {
    if (element >= 0 && element < 8) {
        set->field &= ~(1U << element);
        printf("Deleted %d\n", element);
    } else {
        printf("Invalid delete\n");
    }
}

bool find(Set set, int element) {
    if (element < 0 || element >= 8) {
        return false;
    }
    return (set.field & (1U << element)) != 0;
}

Set Union(Set A, Set B) {
    Set result;
    result.field = A.field | B.field;
    return result;
}

Set intersections(Set A, Set B) {
    Set result;
    result.field = A.field & B.field;
    return result;
}

Set difference(Set A, Set B) {
    Set result;
    result.field = A.field & ~B.field;
    return result;
}

void display(unsigned int set) {
    printf("Set: ");
    for (int i = 0; i < 8; i++) {
        if ((set >> i) & 1U) {
            printf("%d ", i);
        }
    }
    printf("\n\n");
}
