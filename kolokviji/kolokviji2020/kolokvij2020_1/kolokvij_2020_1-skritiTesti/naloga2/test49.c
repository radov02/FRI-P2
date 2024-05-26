
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
    int t1[] = {42, 0};
    int* t2 = t1;
    int* t3 = t2;
    int* t4 = t2;
    int* t5 = t3;
    int* t6 = t1;
    int* t7 = t5;
    int* t8 = t1;
    int* t9 = t4;
    int* t10 = t3;
    int* t11 = t6;
    int* t12 = t7;
    int* t13 = t10;
    int* t14 = t8;
    int* t15 = t4;
    int* t16 = t4;
    int* t17 = t11;
    int* t18 = t10;
    int* t19 = t11;
    int* t20 = t19;
    int* t21 = t9;
    int* t22 = t12;
    int* t23 = t6;
    int* t24 = t6;
    int* t25 = t24;
    int* t26 = t4;
    int* t27 = t12;
    int* t28 = t23;
    int* t29 = t24;
    int* t30 = t5;
    int* t31 = t4;
    int* t32 = t31;
    int* t33 = t16;
    int* t34 = t31;
    int* t35 = t1;
    int* t36 = t13;
    int* t37 = t20;
    int* t38 = t6;
    int* t39 = t6;
    int* t40 = t39;
    int* t41 = t25;
    int* t42 = t27;
    int* t43 = t14;
    int* t44 = t17;
    int* t45 = t38;
    int* t46 = t11;
    int* t47 = t19;

    int* t[] = {t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14, t15, t16, t17, t18, t19, t20, t21, t22, t23, t24, t25, t26, t27, t28, t29, t30, t31, t32, t33, t34, t35, t36, t37, t38, t39, t40, t41, t42, t43, t44, t45, t46, t47, NULL};

    pretvori(t);
    int n = sizeof(t) / sizeof(t[0]) - 1;
    izpisi(t, n);

    exit(0);
    return 0;
}
