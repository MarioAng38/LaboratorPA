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

int adancimeArbore(struct node *nod) {
    if(nod == NULL) {
        return 0;
    }
    int leftDepth = adancimeArbore(nod -> leftChild);
    int rightDepth = adancimeArbore(nod -> rightChild);
    return (leftDepth > rightDepth ? leftDepth : rightDepth) + 1; //returneaza maximul
}

int main() {
    int array[7] = {27, 14, 35, 10, 19, 31, 42};
    for(int i = 0; i < 7; i++) {
        insert(array[i]);
    }
    printf("Adancimea arborelui este: %d",adancimeArbore(root));

    return 0;
}