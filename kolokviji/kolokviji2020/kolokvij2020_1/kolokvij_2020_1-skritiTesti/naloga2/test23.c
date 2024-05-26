
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
    int t3[] = {0};
    int* t4 = t1;
    int t5[] = {0};
    int* t6 = t1;
    int* t7 = t5;
    int* t8 = t4;
    int* t9 = t1;
    int* t10 = t1;
    int t11[] = {0};
    int t12[] = {0};
    int t13[] = {0};
    int* t14 = t8;
    int* t15 = t1;
    int t16[] = {0};
    int* t17 = t10;
    int* t18 = t17;
    int t19[] = {0};
    int* t20 = t7;
    int* t21 = t15;
    int t22[] = {0};
    int t23[] = {0};
    int* t24 = t23;
    int* t25 = t18;
    int* t26 = t7;
    int* t27 = t2;
    int* t28 = t17;
    int* t29 = t28;
    int t30[] = {0};
    int t31[] = {0};
    int t32[] = {0};
    int* t33 = t11;
    int* t34 = t25;
    int* t35 = t23;
    int t36[] = {0};
    int* t37 = t34;
    int* t38 = t27;
    int t39[] = {0};
    int* t40 = t19;
    int* t41 = t32;
    int* t42 = t34;
    int* t43 = t32;
    int* t44 = t19;
    int* t45 = t42;

    int* t[] = {t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14, t15, t16, t17, t18, t19, t20, t21, t22, t23, t24, t25, t26, t27, t28, t29, t30, t31, t32, t33, t34, t35, t36, t37, t38, t39, t40, t41, t42, t43, t44, t45, NULL};

    pretvori(t);
    int n = sizeof(t) / sizeof(t[0]) - 1;
    izpisi(t, n);

    exit(0);
    return 0;
}
