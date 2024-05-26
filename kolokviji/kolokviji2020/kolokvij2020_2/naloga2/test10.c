
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
        (int[]) {523, 6431, 6653, 3803, 6492, 6909, 5257, -1},
        (int[]) {9254, 3614, 1048, 4277, 1504, 5829, -1},
        (int[]) {5329, 2331, 1855, 7502, -1},
        (int[]) {1207, 58, 1796, 9129, 6854, 6621, -1},
        (int[]) {2373, 481, 7026, 1227, 7152, 6753, 5053, 9450, -1},
        (int[]) {9632, 678, 5665, 5589, 879, 2955, 6630, 7078, -1},
        (int[]) {9421, 9460, 9002, 9870, 1781, 8574, -1},
        (int[]) {1616, 596, 428, 4593, 9182, 5104, 1062, 6005, 9007, 4303, -1},
        (int[]) {9969, 67, 6766, 6184, 9504, 5593, 3304, 4555, 7959, -1},
        (int[]) {3613, 1305, 6120, 5078, 1969, 6048, 5608, -1},
        (int[]) {2578, 8542, 1924, 7658, -1},
        (int[]) {4754, 1924, 4503, 4657, 5494, -1},
        (int[]) {22, 8152, 1831, 5005, 6684, 1465, -1},
        (int[]) {7182, 8211, 4844, 49, 7663, 6411, 3836, -1},
        (int[]) {6575, 9160, 7979, 9403, 7493, 6799, 8022, 4167, -1},
        (int[]) {1439, 4760, 8434, 4629, 7439, 3612, 980, 2280, 4574, -1},
        (int[]) {7258, 1116, 8783, 2227, 7111, 7559, -1},
        (int[]) {249, -1},
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
