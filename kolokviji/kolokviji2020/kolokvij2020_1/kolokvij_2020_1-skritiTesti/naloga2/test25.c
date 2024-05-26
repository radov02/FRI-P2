
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
    int t7[] = {0};
    int* t8 = t7;
    int* t9 = t4;
    int t10[] = {0};
    int* t11 = t1;
    int* t12 = t6;
    int* t13 = t4;
    int* t14 = t5;
    int* t15 = t2;
    int* t16 = t11;
    int* t17 = t5;
    int* t18 = t9;
    int* t19 = t13;
    int* t20 = t18;
    int* t21 = t1;
    int t22[] = {0};
    int* t23 = t8;
    int* t24 = t11;
    int* t25 = t1;
    int* t26 = t16;
    int t27[] = {0};
    int* t28 = t7;
    int* t29 = t16;
    int* t30 = t23;
    int t31[] = {0};
    int* t32 = t23;
    int* t33 = t12;
    int* t34 = t1;
    int* t35 = t34;
    int t36[] = {0};
    int* t37 = t31;
    int* t38 = t13;
    int* t39 = t10;
    int* t40 = t16;
    int* t41 = t13;
    int* t42 = t18;
    int* t43 = t42;
    int t44[] = {0};
    int* t45 = t7;
    int* t46 = t15;
    int* t47 = t7;
    int* t48 = t22;
    int* t49 = t23;
    int* t50 = t45;

    int* t[] = {t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14, t15, t16, t17, t18, t19, t20, t21, t22, t23, t24, t25, t26, t27, t28, t29, t30, t31, t32, t33, t34, t35, t36, t37, t38, t39, t40, t41, t42, t43, t44, t45, t46, t47, t48, t49, t50, NULL};

    pretvori(t);
    int n = sizeof(t) / sizeof(t[0]) - 1;
    izpisi(t, n);

    exit(0);
    return 0;
}
