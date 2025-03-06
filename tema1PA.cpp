#include <stdio.h>
#include <string.h>

struct abc {
    char nume[20], prenume[20], oras[20], liceu[20];
    char a[3][20];
} x;

void citire() {
    scanf("%s %s %s %s", x.nume, x.prenume, x.oras, x.liceu);
    for (int i = 0; i < 3; i++) {
        scanf("%s", x.a[i]);
    }
}

void sortAlf() {
    char aux[20];
    for (int i = 0; i < 2; i++) {
        for (int j = i + 1; j < 3; j++) {
            if (strcmp(x.a[i], x.a[j]) > 0) {
                strcpy(aux, x.a[i]);
                strcpy(x.a[i], x.a[j]);
                strcpy(x.a[j], aux);
            }
        }
    }
}

void afisare() {
    printf("%s %s %s %s\n", x.nume, x.prenume, x.oras, x.liceu);
    for (int i = 0; i < 3; i++) {
        printf("%s ", x.a[i]);
    }
    printf("\n");
}

int main() {
    citire();
    sortAlf();
    afisare();
    return 0;
}