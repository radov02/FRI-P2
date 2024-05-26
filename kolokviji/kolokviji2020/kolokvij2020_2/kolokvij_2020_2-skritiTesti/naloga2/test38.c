
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
        (int[]) {7662, 8062, 7893, 2685, 1492, 3902, 2754, 2477, 3910, 6781, 7022, 740, 9775, 3574, 4400, 1917, 553, 508, 3310, 1522, 8693, 3501, 5381, 9085, 1295, 3797, 576, 1986, 6766, 7828, 8157, 71, 8514, 9716, 7377, 5097, 5044, 9021, 1001, 3425, 1560, 2574, 1515, 8096, 55, 5385, 2202, 6947, 9728, 6711, 7075, 6125, 9254, 9264, 1139, -1},
        (int[]) {9607, 8963, 1555, 163, 8769, 2705, 672, 36, 464, 4836, 4674, 226, 3438, 1375, 7380, -1},
        (int[]) {5645, 3600, 2995, 3519, 7305, 4433, 8057, 6976, 3471, 1205, 429, 4724, 6933, 4276, 3753, 7996, 5947, 3427, 3334, 7836, 8860, 6198, 5202, 3292, 9568, 9631, 4995, 5978, 9438, 7980, 2396, 8454, 5395, 3707, 984, 2664, 4111, 7835, 7591, 6803, 3357, 6942, 4588, 8277, 9853, 2937, 9447, 3621, 4128, 1666, 7952, 805, 5986, 1423, 9179, 3438, 1457, 2581, 2361, 7680, 9587, 4309, 7279, 6085, 7049, 9664, 4469, 4662, 6304, 2742, 5663, 1727, 5205, 1915, 9244, 2381, -1},
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
