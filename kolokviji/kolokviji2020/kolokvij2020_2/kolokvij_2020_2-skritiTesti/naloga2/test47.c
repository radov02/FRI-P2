
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "naloga2.h"

#define MAX_ST_NASLOVOV 1000000

Vozlisce* izdelaj(int* t, long* naslovi, int* stNaslovov) {
    if (*t < 0) {
        return NULL;
    }
    Vozlisce* v = malloc(sizeof(Vozlisce));
    naslovi[(*stNaslovov)++] = (long) v;
    v->podatek = *t;
    v->naslednje = izdelaj(t + 1, naslovi, stNaslovov);
    return v;
}

void izpisi(Vozlisce* v) {
    printf("[");
    Vozlisce* p = v;
    while (p != NULL) {
        if (p != v) {
            printf(", ");
        }
        printf("%d", p->podatek);
        p = p->naslednje;
    }
    printf("]\n");
}

void pocisti(Vozlisce* v) {
    if (v != NULL) {
        pocisti(v->naslednje);
        free(v);
    }
}

int primerjalnik(const void* pa, const void* pb) {
    long a = *(long*) pa;
    long b = *(long*) pb;
    return (a < b) ? (-1) : ((a > b) ? 1 : 0);
}

bool preveri(Vozlisce* seznam, long* naslovi, int stNaslovov) {
    Vozlisce* p = seznam;
    while (p != NULL) {
        long naslov = (long) p;
        if (bsearch(&naslov, naslovi, stNaslovov, sizeof(long), primerjalnik) != NULL) {
            return false;
        }
        p = p->naslednje;
    }
    return true;
}

int __main__() {
    int* t[] = {
        (int[]) {4989, 3669, 2332, 5863, 8547, 3869, 1121, 3250, 7405, 7115, 1497, 7949, 8767, 243, 1771, 3107, 1681, 6739, 9420, 5964, 8437, 2831, -1},
        (int[]) {8641, 1117, 3501, 4853, 4931, 9834, 5742, 3516, 4733, 4386, 4744, 199, 4603, 5550, 4992, 429, 7805, 2825, 7499, 2502, 6143, 3197, 999, 2692, 1819, 2450, 9908, 7731, 4268, 8955, 3953, 2242, 6770, 592, 6181, 9825, 441, 495, 3333, 1382, 4144, 8076, 7677, 805, 8868, 6147, 3047, 1032, 9682, 25, 8568, 3563, 6648, 2351, 5809, 8216, 1493, 3171, 2732, 7157, 6850, 3256, 3509, 3723, 5798, 8828, 5433, -1},
        (int[]) {5267, 3543, 8373, 7425, 1154, 6752, 7487, 3090, 9530, 1043, 3756, 6, 5140, 960, 5971, 9266, 3230, 6527, 2900, 5535, 2196, 2752, 6370, 8123, 8185, 604, 6740, 8897, 2454, 3822, 5375, 2275, 3034, 7432, 8646, 5072, 6862, 8567, 1995, 4954, 3824, 8778, 7511, 2095, 746, 3295, 9925, 1953, -1},
        (int[]) {170, 9840, 2231, 7701, 2733, 4030, 8088, 2121, 1806, 9312, 1998, 7738, 8884, 348, 7726, 6002, 5794, 1918, 388, 2875, 9065, 6710, 8905, 4425, 5194, 4279, 7731, 5169, 6810, 3831, 3877, 6490, 9499, 6936, 1561, 4401, 6016, 5635, 4471, 1033, 7881, 3453, 8988, 2710, 5501, 7636, 4234, 9390, 5796, 6898, 8191, 8106, 3815, 4413, 8801, 7715, 6608, 6621, 6979, 1211, 1791, 5003, 136, 2731, 1493, 1107, 1319, 6123, 6078, 7060, 6495, 3403, 6282, -1},
        (int[]) {5706, 6202, 4367, 4731, 7192, 9169, 9155, 227, 6318, 9709, 6082, 6516, 4383, 6597, 8849, 8870, 3017, 4938, 973, 1661, 3185, 108, 1441, 6185, 5802, 7592, 1026, 922, 9818, 8060, 8020, 7440, 9898, 3741, 835, 6157, 885, 352, 3341, 3563, 3135, 5838, 7146, 7533, -1},
        (int[]) {6426, 9342, 5268, 1213, 4896, 4917, 4187, 529, 4709, 4204, 5255, -1},
    };
    int n = sizeof(t) / sizeof(int*);

    Vozlisce** seznami = malloc(n * sizeof(Vozlisce*));
    long* naslovi = malloc(MAX_ST_NASLOVOV * sizeof(long));
    int stNaslovov = 0;
    for (int i = 0;  i < n;  i++) {
        seznami[i] = izdelaj(t[i], naslovi, &stNaslovov);
    }
    qsort(naslovi, stNaslovov, sizeof(long), primerjalnik);

    Vozlisce* prepleten = prepleti(seznami, n);
    if (!preveri(prepleten, naslovi, stNaslovov)) {
        printf("NAPAKA!\n");
        printf("Vsa vozlisca prepletenega seznama morajo biti kopije vozlisc originalnih seznamov.\n");
    }
    izpisi(prepleten);
    pocisti(prepleten);

    for (int i = 0;  i < n;  i++) {
        pocisti(seznami[i]);
    }
    free(seznami);
    free(naslovi);

    exit(0);
    return 0;
}
