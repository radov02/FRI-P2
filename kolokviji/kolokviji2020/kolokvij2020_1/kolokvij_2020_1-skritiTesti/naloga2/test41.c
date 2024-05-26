
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
    int t1[] = {-700, -330, 312, -281, 478, -537, 492, 985, 947, -471, 644, 381, 240, 687, 206, -870, 461, 761, 755, 744, 683, -621, 170, 0};
    int* t2 = t1;
    int* t3 = t1;
    int* t4 = t3;
    int* t5 = t3;
    int* t6 = t1;
    int* t7 = t1;
    int* t8 = t3;
    int* t9 = t4;
    int t10[] = {150, 654, -453, -957, 687, 447, -58, 887, 688, 378, 949, -437, -222, 785, -653, -813, 215, -310, 903, -475, 196, -536, -773, 999, -471, -523, -352, 0};
    int* t11 = t6;
    int* t12 = t5;
    int t13[] = {713, -328, 691, 834, -234, 290, 717, 146, 572, 614, 865, 0};
    int* t14 = t5;
    int* t15 = t1;
    int* t16 = t5;
    int* t17 = t2;
    int* t18 = t10;
    int* t19 = t11;
    int* t20 = t18;
    int* t21 = t20;
    int* t22 = t16;
    int* t23 = t5;
    int* t24 = t4;
    int* t25 = t8;
    int* t26 = t22;
    int* t27 = t4;
    int* t28 = t2;

    int* t[] = {t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14, t15, t16, t17, t18, t19, t20, t21, t22, t23, t24, t25, t26, t27, t28, NULL};

    pretvori(t);
    int n = sizeof(t) / sizeof(t[0]) - 1;
    izpisi(t, n);

    exit(0);
    return 0;
}
