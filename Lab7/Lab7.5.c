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

    tempNode -> data = data;
    tempNode -> leftChild = NULL;
    tempNode -> rightChild = NULL;

    if(root == NULL) {
        root = tempNode;
    }
    else {
        current = root;
        parent = NULL;  
    
    while(1) {
        parent = current;
        if(data < parent -> data) {
            current = current -> leftChild;
            if(current == NULL) {
                parent -> leftChild = tempNode;
                return;
            }
        }
        else {
            current = current->rightChild;
            if(current == NULL) {
                parent -> rightChild = tempNode;
                return;
            }
        }
    }
}
}

int adancimeArbore(struct node *nod,int nivel,int *adancimi) {
    if(nod == NULL) {
        return 0;
    }
    adancimi[nod->data] = nivel;
    adancimeArbore(nod -> leftChild, nivel + 1, adancimi);
    adancimeArbore(nod -> rightChild,nivel + 1, adancimi);
}

int main() {
    int array[7] = {27, 14, 35, 10, 19, 31, 42};
    int adancimi[1000] = {0};
    for(int i = 0; i < 7; i++) {
        insert(array[i]);
    }
    adancimeArbore(root,1,adancimi);
    for(int i = 0; i < 1000; i++) {
        if(adancimi[i] != 0) {
            printf("Nodul %d are adancimea %d\n", i , adancimi[i]);
        }
    }
    
    

    return 0;
}