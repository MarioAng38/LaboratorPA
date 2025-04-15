#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *leftChild;
    struct node *rightChild;
};

struct node *root = NULL;

void insert(int data) {
    struct node *tempNode = (struct node *) malloc(sizeof(struct node));
    struct node *current;
    struct node *parent;

    tempNode->data = data;
    tempNode->leftChild = NULL;
    tempNode->rightChild = NULL;

    if(root == NULL) {
        root = tempNode;
    }
    else {
        current = root;
        parent = NULL;
    
    while(1) {
        parent = current;
        if(data < parent->data) {
            current = current->leftChild;
            if(current == NULL) {
                parent->leftChild = tempNode;
                return;
            }
        }
        else {
            current = current->rightChild;
            if(current == NULL) {
                parent->rightChild = tempNode;
                return;
            }
        }
    }
}
}
int sumaArbore(struct node *nod,int *suma) {
    if(nod != NULL) {
        sumaArbore(nod->leftChild,suma);
        sumaArbore(nod->rightChild,suma);
        *suma += nod->data;
    }
}

int main() {
    int array[7] = {27, 14, 35, 10, 19, 31, 42};
    int suma = 0;
    for(int i = 0; i < 7; i++) {
        insert(array[i]);
    }
    sumaArbore(root, &suma);
    printf("Suma valorilor din arbore este: %d",suma);


    return 0;
}