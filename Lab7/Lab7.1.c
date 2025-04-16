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

void preOrderTraversal(struct node *nod) {
    if(nod != NULL) {
        visit(nod);
        preOrderTraversal(nod->leftChild);
        preOrderTraversal(nod->rightChild);
    }
}

void postOrderTraversal(struct node *nod) {
    if(nod != NULL) {
        postOrderTraversal(nod->leftChild);
        postOrderTraversal(nod->rightChild);
        visit(nod);
    }
}

int main() {
    int array[11] = {50, 30, 70, 20, 40, 60, 80, 15, 25, 35, 45};
    for(int i = 0; i < 11; i++) {
        insert(array[i]);
    }
    printf("In Order Traversal:");
    inOrderTraversal(root); 
    printf("\n");
    printf("Pre Order Traversal:");
    preOrderTraversal(root);    
    printf("\n");
    printf("Post Order Traversal:");
    postOrderTraversal(root);


    return 0;
}