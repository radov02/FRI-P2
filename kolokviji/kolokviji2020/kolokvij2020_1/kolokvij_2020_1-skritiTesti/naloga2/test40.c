
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
    int t1[] = {-979, -496, -775, 859, 302, -787, 154, 667, 379, -575, 900, -632, -248, 466, 183, 796, 523, 70, 312, 915, -260, 0};
    int* t2 = t1;
    int* t3 = t2;
    int* t4 = t1;
    int* t5 = t3;
    int t6[] = {667, -520, -132, 542, 416, 330, 788, -764, -424, 512, 425, 0};
    int* t7 = t4;
    int* t8 = t2;
    int* t9 = t5;
    int t10[] = {-315, 348, -416, -58, 0};
    int* t11 = t3;
    int* t12 = t1;
    int* t13 = t11;
    int* t14 = t12;
    int* t15 = t8;
    int* t16 = t10;
    int* t17 = t3;
    int* t18 = t14;
    int t19[] = {613, -603, 90, 545, 349, 0};
    int* t20 = t3;
    int* t21 = t13;
    int* t22 = t13;
    int* t23 = t1;
    int* t24 = t8;
    int* t25 = t17;

    int* t[] = {t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14, t15, t16, t17, t18, t19, t20, t21, t22, t23, t24, t25, NULL};

    pretvori(t);
    int n = sizeof(t) / sizeof(t[0]) - 1;
    izpisi(t, n);

    exit(0);
    return 0;
}
