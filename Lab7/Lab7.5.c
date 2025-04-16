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
    } else {
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
            } else {
                current = current->rightChild;
                if(current == NULL) {
                    parent->rightChild = tempNode;
                    return;
                }
            }
        }
    }
}

void adancimiArbore(struct node *nod, int nivel, int *adancimi) {
    if(nod == NULL) {
        return;
    }
    adancimi[nod->data] = nivel;
    adancimiArbore(nod->leftChild, nivel + 1, adancimi);
    adancimiArbore(nod->rightChild, nivel + 1, adancimi);
}

struct node* cautareParinte(int data) {
    struct node *current = root;
    struct node *parent = NULL;

    while(current != NULL) {
        if(current->data == data) {
            return parent;
        }
        parent = current;
        if(data < current->data) {
            current = current->leftChild;
        } else {
            current = current->rightChild;
        }
    }
    return NULL;
}

void suntVeri(int *valori, int n) {
    int adancimi[1000] = {0};
    adancimiArbore(root, 1, adancimi);

    printf("Perechile de veri sunt:\n");
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            int a = valori[i];
            int b = valori[j];
            if(adancimi[a] == adancimi[b]) {
                struct node *p1 = cautareParinte(a);
                struct node *p2 = cautareParinte(b);
                if(p1 != NULL && p2 != NULL && p1 != p2) {
                    printf("(%d,%d) ", a, b);
                }
            }
        }
    }
    printf("\n");
}

int main() {
    int array[11] = {50, 30, 70, 20, 40, 60, 80, 15, 25, 35, 45};
    int n = 11;
    for(int i = 0; i < n; i++) {
        insert(array[i]);
    }

    suntVeri(array, n);

    return 0;
}
