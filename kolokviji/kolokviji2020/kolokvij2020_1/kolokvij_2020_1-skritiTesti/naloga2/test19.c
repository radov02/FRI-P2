
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
    int* t6 = t1;
    int* t7 = t4;
    int t8[] = {0};
    int* t9 = t5;
    int* t10 = t6;
    int* t11 = t5;
    int* t12 = t8;
    int* t13 = t4;
    int* t14 = t6;
    int* t15 = t6;
    int* t16 = t14;
    int* t17 = t4;
    int* t18 = t5;
    int* t19 = t2;
    int* t20 = t5;
    int* t21 = t16;
    int* t22 = t6;
    int* t23 = t15;
    int* t24 = t3;
    int* t25 = t8;
    int* t26 = t9;
    int* t27 = t4;
    int* t28 = t23;
    int* t29 = t11;
    int* t30 = t6;
    int* t31 = t27;
    int* t32 = t29;
    int* t33 = t22;

    int* t[] = {t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14, t15, t16, t17, t18, t19, t20, t21, t22, t23, t24, t25, t26, t27, t28, t29, t30, t31, t32, t33, NULL};

    pretvori(t);
    int n = sizeof(t) / sizeof(t[0]) - 1;
    izpisi(t, n);

    exit(0);
    return 0;
}
