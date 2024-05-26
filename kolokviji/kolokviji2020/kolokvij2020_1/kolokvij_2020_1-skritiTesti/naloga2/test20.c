
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
    int t3[] = {0};
    int* t4 = t1;
    int* t5 = t4;
    int* t6 = t1;
    int t7[] = {0};
    int* t8 = t1;
    int* t9 = t6;
    int* t10 = t7;
    int* t11 = t3;
    int t12[] = {0};
    int* t13 = t9;
    int* t14 = t9;
    int t15[] = {0};
    int* t16 = t9;
    int* t17 = t11;
    int* t18 = t12;
    int* t19 = t5;
    int t20[] = {0};
    int* t21 = t9;
    int* t22 = t15;
    int* t23 = t21;
    int* t24 = t8;
    int* t25 = t24;
    int* t26 = t21;
    int* t27 = t8;
    int t28[] = {0};
    int* t29 = t4;
    int* t30 = t1;
    int* t31 = t30;
    int* t32 = t25;
    int t33[] = {0};
    int t34[] = {0};
    int t35[] = {0};
    int t36[] = {0};

    int* t[] = {t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14, t15, t16, t17, t18, t19, t20, t21, t22, t23, t24, t25, t26, t27, t28, t29, t30, t31, t32, t33, t34, t35, t36, NULL};

    pretvori(t);
    int n = sizeof(t) / sizeof(t[0]) - 1;
    izpisi(t, n);

    exit(0);
    return 0;
}
