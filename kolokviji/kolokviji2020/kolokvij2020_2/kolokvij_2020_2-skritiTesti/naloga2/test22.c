
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
        (int[]) {9906, 1525, 2394, 5043, -1},
        (int[]) {2527, 192, 2776, 9587, -1},
        (int[]) {800, 5684, 4077, 590, -1},
        (int[]) {4119, 497, 8564, 7871, -1},
        (int[]) {5519, 4167, 9759, 1034, -1},
        (int[]) {1306, 3911, 3735, 3760, -1},
        (int[]) {3814, 1907, 585, 1594, -1},
        (int[]) {7622, 6224, 993, 3700, -1},
        (int[]) {8668, 1911, 1878, 4006, -1},
        (int[]) {8106, 1487, 9899, 8629, -1},
        (int[]) {8433, 5576, 5930, 6065, -1},
        (int[]) {2394, 3764, 2501, 6734, -1},
        (int[]) {3544, 8167, 8097, 7800, -1},
        (int[]) {9645, 9098, 4742, 7457, -1},
        (int[]) {8256, 8899, 2660, 423, -1},
        (int[]) {7485, 1732, 6317, 9063, -1},
        (int[]) {7561, 3281, 4822, 2403, -1},
        (int[]) {2567, 6890, 2924, 3699, -1},
        (int[]) {9122, 2150, 38, 8104, -1},
        (int[]) {1692, 8508, 9988, 19, -1},
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
