#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
    int data;
    struct node *leftChild;
    struct node *rightChild;
}Node;

Node *root;

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

bool esteEchilibrat(Node *nod, int *adancime) {
    if (nod == NULL) {
        *adancime = 0;
        return true;
    }

    int adancimeStanga = 0, adancimeDreapta = 0;

    bool echilibratSt = esteEchilibrat(nod->leftChild, &adancimeStanga);
    bool echilibratDr = esteEchilibrat(nod->rightChild, &adancimeDreapta);

    *adancime = (adancimeStanga > adancimeDreapta ? adancimeStanga : adancimeDreapta) + 1;

    if (!echilibratSt || !echilibratDr) {
        return false;
    }

    if (abs(adancimeStanga - adancimeDreapta) > 1) {
        return false;
    }

    return true;
}

 


int main() {
    int array[7] = {10, 20, 30, 40, 50, 60, 70};
    int n = 7;

    root = inserareEchilibrata(array, 0, n - 1);
    int adancime = 0;
    
    if (esteEchilibrat(root, &adancime)) {
        printf("Arborele este echilibrat!\n");
    } else {
        printf("Arborele nu este echilibrat!\n");
    }

    return 0;
}