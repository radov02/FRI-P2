
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
    int t4[] = {0};
    int t5[] = {0};
    int t6[] = {0};
    int t7[] = {0};
    int t8[] = {0};
    int t9[] = {0};
    int t10[] = {0};
    int t11[] = {0};
    int t12[] = {0};
    int t13[] = {0};
    int t14[] = {0};
    int t15[] = {0};
    int t16[] = {0};
    int* t17 = t14;
    int t18[] = {0};
    int t19[] = {0};
    int t20[] = {0};
    int t21[] = {0};
    int t22[] = {0};
    int t23[] = {0};
    int t24[] = {0};
    int t25[] = {0};
    int t26[] = {0};
    int t27[] = {0};
    int t28[] = {0};
    int t29[] = {0};
    int t30[] = {0};
    int t31[] = {0};

    int* t[] = {t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14, t15, t16, t17, t18, t19, t20, t21, t22, t23, t24, t25, t26, t27, t28, t29, t30, t31, NULL};

    pretvori(t);
    int n = sizeof(t) / sizeof(t[0]) - 1;
    izpisi(t, n);

    exit(0);
    return 0;
}
