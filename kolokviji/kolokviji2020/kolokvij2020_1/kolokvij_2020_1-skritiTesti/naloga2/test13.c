
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
    int* t2 = t1;
    int* t3 = t1;
    int* t4 = t3;
    int* t5 = t3;
    int* t6 = t3;
    int* t7 = t1;
    int* t8 = t6;
    int* t9 = t8;
    int* t10 = t2;
    int* t11 = t7;
    int* t12 = t11;
    int* t13 = t3;
    int* t14 = t7;
    int* t15 = t4;
    int* t16 = t14;
    int* t17 = t4;
    int* t18 = t9;
    int* t19 = t8;
    int* t20 = t17;
    int* t21 = t7;
    int* t22 = t17;

    int* t[] = {t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14, t15, t16, t17, t18, t19, t20, t21, t22, NULL};

    pretvori(t);
    int n = sizeof(t) / sizeof(t[0]) - 1;
    izpisi(t, n);

    exit(0);
    return 0;
}
