
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
    int* t4 = t2;
    int* t5 = t3;
    int* t6 = t2;
    int* t7 = t5;
    int* t8 = t4;
    int* t9 = t5;
    int* t10 = t4;
    int* t11 = t9;
    int* t12 = t9;
    int* t13 = t5;
    int* t14 = t1;
    int t15[] = {0};
    int t16[] = {0};
    int* t17 = t10;
    int* t18 = t16;
    int t19[] = {0};
    int t20[] = {0};
    int* t21 = t5;
    int* t22 = t19;
    int t23[] = {0};
    int* t24 = t11;
    int* t25 = t10;
    int* t26 = t9;
    int* t27 = t13;
    int* t28 = t26;
    int* t29 = t27;
    int* t30 = t14;
    int* t31 = t12;
    int* t32 = t15;
    int t33[] = {0};
    int* t34 = t33;
    int* t35 = t18;
    int* t36 = t29;
    int* t37 = t6;
    int* t38 = t19;
    int* t39 = t7;
    int* t40 = t6;
    int* t41 = t28;
    int t42[] = {0};
    int* t43 = t11;
    int* t44 = t31;
    int* t45 = t36;
    int* t46 = t12;
    int* t47 = t45;

    int* t[] = {t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14, t15, t16, t17, t18, t19, t20, t21, t22, t23, t24, t25, t26, t27, t28, t29, t30, t31, t32, t33, t34, t35, t36, t37, t38, t39, t40, t41, t42, t43, t44, t45, t46, t47, NULL};

    pretvori(t);
    int n = sizeof(t) / sizeof(t[0]) - 1;
    izpisi(t, n);

    exit(0);
    return 0;
}
