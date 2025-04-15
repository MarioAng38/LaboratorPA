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

void visit(struct node *nod) {
    printf("%d ",nod->data);
}

void inOrderTraversal(struct node *nod) {
    if(nod != NULL) {
        inOrderTraversal(nod->leftChild);
        visit(nod);
        inOrderTraversal(nod->rightChild);
    }
}

void mirror(struct node *nod) {
    if(nod == NULL) {
        return;
    }
    struct node *tmp = nod->leftChild;
    nod->leftChild = nod->rightChild;
    nod->rightChild = tmp;
    mirror(nod->leftChild);
    mirror(nod->rightChild);
}

int main() {
    int array[7] = {27, 14, 35, 10, 19, 31, 42};
    for(int i = 0; i < 7; i++) {
        insert(array[i]);
    }
    printf("In Order Traversal inainte:");
    inOrderTraversal(root); 
    printf("\n");
    mirror(root);
    printf("In Order Traversal mirrored:");
    inOrderTraversal(root);    

    return 0;
}