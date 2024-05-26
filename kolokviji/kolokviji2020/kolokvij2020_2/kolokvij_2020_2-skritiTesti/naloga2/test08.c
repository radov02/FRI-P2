
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
        (int[]) {8898, 7994, 4922, 159, 173, 8483, 9693, 7737, 9215, 8688, 3138, 7106, 2155, 5174, 294, 4787, 4896, 1124, 652, 7425, 3234, 8386, 4488, 8941, 8908, 5674, 6119, 6998, 4396, 4793, 8726, 5399, 4661, 2860, 3437, 8281, 8752, 9266, 4388, 3706, 7806, 4268, 6951, 8090, 8897, 7689, 6115, 247, 3097, 3888, 2340, 8242, 2966, 9794, 4214, 7591, 2999, 5631, 4596, 6267, 2411, 8823, 3863, 8336, 6244, 8777, 1166, 4629, 7053, 6765, 8256, 1556, 3306, 1005, 2037, 3358, 370, 2530, 3890, 2184, 2437, 5914, 9130, 1925, 1337, 2074, 7044, 1284, 9052, 6889, 7407, 1421, -1},
        (int[]) {170, 2292, 7264, 3302, 8440, 2130, 5304, 16, 7691, 3974, 2825, 7820, 7038, 6669, 6828, 4008, 8901, 4573, 6192, 8040, 2821, 1486, 9277, 5438, 3623, 1315, 3528, 5090, 2639, 3207, 669, 9690, 9577, 1624, 5566, 8212, 4081, 3331, 5971, 6657, 7016, 6961, 5556, 1642, 5693, 4114, 1932, 3005, 9771, 4271, 1592, 9560, 6911, 8877, 5714, 8751, 6246, 5283, 6950, 5838, 1051, 5803, 658, 2885, 3143, 6846, 4321, 2930, 8003, 8853, 1495, 9211, 6021, 8631, 3811, 7149, 8369, 5293, 4861, 5528, 6345, 8445, 6758, 4701, 4091, 3069, 6651, 5567, 1403, 8195, 2105, 7514, -1},
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
