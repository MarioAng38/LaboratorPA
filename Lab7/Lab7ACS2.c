#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
    int data;
    struct node *leftChild;
    struct node *rightChild;
}Node;

Node *root;

Node *inserareEchilibrata(int array[], int start, int end) {
    if(start > end) {
        return NULL;
    }
    int mid = (start + end) / 2;

    Node *nod = (Node *) malloc(sizeof(Node));
    nod->data = array[mid];
    nod->leftChild = inserareEchilibrata(array, start, mid - 1);
    nod->rightChild = inserareEchilibrata(array, mid + 1, end);

    return nod;
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

bool esteBST(Node* nod, int min, int max) {
    if (nod == NULL) return 1;
    if (nod->data <= min || nod->data >= max) return 0;
    return esteBST(nod->leftChild, min, nod->data) &&
           esteBST(nod->rightChild, nod->data, max);
}

int main() {
    int array[7] = {10, 20, 30, 40, 50, 60, 70};
    int n = 7;
    root = inserareEchilibrata(array, 0, n - 1);
    inOrderTraversal(root);
    if (esteBST(root, INT_MIN, INT_MAX)) {
        printf("\nArborele este binary search tree!");
    } else {
        printf("\nArborele NU este binary search tree!");
    }
    

    return 0;
}