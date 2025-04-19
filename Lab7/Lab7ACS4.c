#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
    int data;
    struct node *leftChild;
    struct node *rightChild;
}Node;

Node *root;
char valoriArbore[100][10];
int idx = 0;

Node* inserareEchilibrata(int array[], int start, int end) {
    if (start > end) {
        return NULL;
    }
    int mid = (start + end) / 2;
    
    Node* nod = (Node*) malloc(sizeof(Node));
    nod->data = array[mid];
    nod->leftChild = inserareEchilibrata(array, start, mid - 1);
    nod->rightChild = inserareEchilibrata(array, mid + 1, end);

    return nod;
}

void visitAndSaveStr(struct node *nod) {
    printf("%d ",nod->data);
    sprintf(valoriArbore[idx++], "%d", nod->data); //salvez ca string
}

void inOrderTraversal(struct node *nod) {
    if(nod != NULL) {
        inOrderTraversal(nod->leftChild);
        visitAndSaveStr(nod);
        inOrderTraversal(nod->rightChild);
    }
}

int main() {
    int array[7] = {10, 20, 30, 40, 50, 60, 70};
    int n = 7;

    root = inserareEchilibrata(array, 0, n - 1);
    printf("InOrder initial: ");
    inOrderTraversal(root);

    printf("\nElementele salvate in vectorul de stringuri:");
    int newArray[100];
    for(int i = 0; i < idx; i++) {
        printf("%s ", valoriArbore[i]);
        newArray[i] = atoi(valoriArbore[i]);

    }
    Node *newRoot = inserareEchilibrata(newArray, 0, idx-1);
    printf("\nInOrder de stringuri: ");
    inOrderTraversal(newRoot);
    return 0;
}