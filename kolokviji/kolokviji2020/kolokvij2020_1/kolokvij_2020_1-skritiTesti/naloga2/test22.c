
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
    int* t3 = t2;
    int t4[] = {0};
    int* t5 = t2;
    int* t6 = t3;
    int* t7 = t1;
    int* t8 = t2;
    int* t9 = t1;
    int* t10 = t9;
    int* t11 = t7;
    int* t12 = t4;
    int* t13 = t2;
    int* t14 = t13;
    int* t15 = t2;
    int* t16 = t8;
    int* t17 = t12;
    int* t18 = t17;
    int* t19 = t5;
    int* t20 = t18;
    int* t21 = t12;
    int* t22 = t16;
    int* t23 = t16;
    int* t24 = t16;
    int* t25 = t14;
    int* t26 = t16;
    int* t27 = t19;
    int* t28 = t5;
    int* t29 = t7;
    int* t30 = t18;
    int t31[] = {0};
    int* t32 = t2;
    int* t33 = t20;
    int* t34 = t7;
    int* t35 = t23;
    int* t36 = t3;
    int* t37 = t10;
    int* t38 = t29;
    int* t39 = t28;
    int* t40 = t34;
    int t41[] = {0};
    int* t42 = t35;
    int* t43 = t20;

    int* t[] = {t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14, t15, t16, t17, t18, t19, t20, t21, t22, t23, t24, t25, t26, t27, t28, t29, t30, t31, t32, t33, t34, t35, t36, t37, t38, t39, t40, t41, t42, t43, NULL};

    pretvori(t);
    int n = sizeof(t) / sizeof(t[0]) - 1;
    izpisi(t, n);

    exit(0);
    return 0;
}
