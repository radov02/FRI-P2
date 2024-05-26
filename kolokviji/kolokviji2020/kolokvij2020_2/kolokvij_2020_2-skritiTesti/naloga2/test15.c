
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
        (int[]) {2460, 6032, 2408, 6767, 2219, 3024, 1713, 6785, 4348, 2520, 5833, 2751, 67, 3805, 8526, 5182, 7540, 2505, 1846, 6036, 5891, 4703, 5099, 1194, 1516, 1434, 8558, 9073, 2666, 3698, 6344, 791, 5701, 8462, 8242, 4062, 226, 5539, 7925, 9543, 4422, 886, 2462, 4509, 1877, 4138, 4588, 4494, 6355, 4519, 3405, 1231, 2482, 8542, 8343, 7581, 920, 7633, 9706, 203, 3549, 3351, 7730, 6370, 5397, 603, 9923, 2527, 8727, 6556, 5355, 6069, 6805, 1030, 8160, 7951, 7421, 384, 5935, 6858, 238, 4015, 9499, 1309, 151, 9455, 740, 9113, 6378, 4929, 8669, 8395, 9862, 2819, 9890, 9387, 3500, 9165, 6544, 7259, 4921, 6904, 4316, 3294, 589, 6956, 9143, 1117, 1422, 7199, 2713, 9490, 2508, 9316, 8464, 6304, 621, 2573, 4566, 118, 8990, -1},
        (int[]) {7, 4853, 3088, 6471, 8615, 4009, 6674, 6192, 7461, 8192, 8458, 3935, 3228, 6935, 602, 3523, 306, 9061, 5487, 7909, 2296, 4441, 6028, 8448, 6755, 4531, 75, 6140, 5824, 470, 25, 1556, 8925, 5989, 4039, 7919, 6265, 2961, 1965, 8810, 8782, 8386, 4231, 6280, 323, 6671, 7965, 5763, 4746, 6407, 8247, 2829, 2268, 3738, 9409, 2993, 8786, 6528, 6301, 9859, 2578, 9780, 3114, 5942, 418, 1736, 482, 7963, 3530, 5144, 2917, 1687, 3161, 4867, 9680, 9505, 6171, 7205, 9222, 3441, 3673, 3559, 8916, 8731, 2183, 1817, 655, 5050, 5058, 6889, 9343, 4789, 633, 9341, 3829, 4296, 4699, 1383, 553, 1413, 972, 1839, 1949, 2097, 5906, 3571, 1886, 1059, 3781, 7195, 6599, 5591, 195, 4380, 4276, 2759, 9794, 5125, 3316, 5528, 4073, -1},
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
