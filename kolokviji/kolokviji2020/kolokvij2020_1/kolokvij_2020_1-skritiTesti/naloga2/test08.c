
#include <stdio.h>
#include <stdlib.h>
#include "naloga2.h"

void izpisi(int** t, int n) {
    for (int i = 0;  i < n;  i++) {
        int* p = t[i];
        while (*p != 0) {
            printf("%d ", *p);
            p++;
        }
        printf("0\n");
    }
    for (int i = 0;  i < n;  i++) {
        for (int j = 0;  j < n;  j++) {
            printf("%d", t[i] == t[j]);
        }
        printf("\n");
    }
}

int __main__() {
    int t1[] = {0};
    int t2[] = {0};
    int* t3 = t2;
    int t4[] = {0};
    int* t5 = t3;
    int* t6 = t5;
    int* t7 = t2;
    int* t8 = t1;
    int* t9 = t6;
    int* t10 = t5;
    int* t11 = t2;
    int t12[] = {0};
    int* t13 = t12;

    int* t[] = {t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, NULL};

    pretvori(t);
    int n = sizeof(t) / sizeof(t[0]) - 1;
    izpisi(t, n);

    exit(0);
    return 0;
}
