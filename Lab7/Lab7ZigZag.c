#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
    int data;
    struct node *leftChild;
    struct node *rightChild;
}Node;

Node *root;
int maxZigZag = 0;

Node* inserareEchilibrata(int array[], int start, int end) {
    if(start > end) {
        return NULL;
    }
    int mid = (start + end) / 2;

    Node* nod = (Node*) malloc(sizeof(Node));
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

void longestZigZag(struct node *nod, bool directie, int nivel) {
    //0 - stanga
    //1 - dreapta
    if(nod == NULL) {
        return;
    }

    if(nivel > maxZigZag) {
        maxZigZag = nivel;
    }

        if(directie) {
            longestZigZag(nod->leftChild, false, nivel + 1);
            longestZigZag(nod->rightChild, true, 1);
        }
        else {
            longestZigZag(nod->rightChild, true, nivel + 1);
            longestZigZag(nod->leftChild, false, 1);
        }
}

int main() {
    int array[15] = {10, 15, 20, 25, 30, 35, 40, 50, 60, 70, 80, 90, 100, 110, 120};
    int n = 15;

    root = inserareEchilibrata(array, 0, n - 1);
    printf("InOrder: ");
    inOrderTraversal(root);

    longestZigZag(root->leftChild, false, 1);
    longestZigZag(root->rightChild, true, 1);
    printf("\nLungimea maxima a zigzag-ului este: %d\n", maxZigZag);

    return 0;
}