
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
    int t1[] = {-789, -227, 623, 928, -513, -630, -240, -219, -73, 852, 787, -396, 528, 209, 229, -457, 654, -119, -116, 829, -168, 0};
    int* t2 = t1;
    int* t3 = t2;
    int t4[] = {-625, 149, 411, 483, -902, 997, 341, -703, 647, 243, -55, 292, -400, -266, -216, 0};
    int* t5 = t1;
    int* t6 = t1;
    int* t7 = t6;
    int* t8 = t4;
    int* t9 = t3;
    int* t10 = t8;
    int* t11 = t10;
    int* t12 = t3;
    int t13[] = {768, -416, -15, 177, 58, -307, -197, -203, -10, 912, -271, 927, -150, -28, -877, -139, 800, 769, 299, 0};
    int* t14 = t4;
    int* t15 = t10;
    int* t16 = t7;
    int* t17 = t15;
    int t18[] = {-172, 893, -980, -767, -547, 954, -721, 0};
    int* t19 = t6;
    int* t20 = t13;
    int* t21 = t15;

    int* t[] = {t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14, t15, t16, t17, t18, t19, t20, t21, NULL};

    pretvori(t);
    int n = sizeof(t) / sizeof(t[0]) - 1;
    izpisi(t, n);

    exit(0);
    return 0;
}
