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

Node* gasireStramos(Node* stramos, int data1, int data2) {
    if(stramos == NULL) {
        return 0;
    }
    if(data1 < stramos->data && data2 < stramos->data) {
        return gasireStramos(stramos->leftChild, data1, data2);
    }
    if(data1 > stramos->data && data2 > stramos->data) {
        return gasireStramos(stramos->rightChild, data1, data2);
    }

    return stramos;
}

int main() {
    int array[15] = {10, 15, 20, 25, 30, 35, 40, 50, 60, 70, 80, 90, 100, 110, 120};
    int n = 15;

    root = inserareEchilibrata(array, 0, n - 1);
    inOrderTraversal(root);

    int n1,n2;
    printf("\nIntroduceti 2 noduri pentru cautarea stramosului:\n");
    scanf("%d",&n1);
    scanf("%d",&n2);
    printf("Stramosul cel mai apropiat al nodurlor (%d , %d) este: %d",n1,n2,gasireStramos(root, n1, n2)->data);
    

    return 0;
}