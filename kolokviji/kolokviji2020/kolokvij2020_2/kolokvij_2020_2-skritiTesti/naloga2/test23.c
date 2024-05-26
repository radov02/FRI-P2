
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
        (int[]) {5419, 3211, 7149, 7183, 1617, 7879, 8426, 2221, 4136, 8905, 9485, 6644, 9041, 7262, 8252, 4360, 2029, 8624, 8165, 9236, 6446, 6931, -1},
        (int[]) {4774, 8709, 3371, 7323, 9026, 3687, 3989, 2409, 7583, 2623, 3000, 6640, 7562, 8974, 7030, 9789, 2062, 3300, 6554, 9413, 6465, 452, -1},
        (int[]) {8328, 3852, 4988, 4654, 9050, 7666, 9206, 9639, 3763, 3995, 92, 5741, 3973, 4739, 7601, 6400, 1915, 4604, 7920, 2993, 992, 3490, -1},
        (int[]) {3016, 1649, 2124, 1793, 2659, 79, 9968, 9176, 7770, 3754, 5009, 1075, 1485, 8948, 828, 6655, 5391, 4624, 6573, 5795, 9539, 4480, -1},
        (int[]) {9720, 7273, 164, 1614, 2545, 9674, 1842, 9104, 3254, 4684, 404, 7604, 6408, 9714, 8165, 6800, 9934, 1064, 9466, 8742, 3674, 1695, -1},
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
