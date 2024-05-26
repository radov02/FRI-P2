
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
        (int[]) {5102, 7338, 466, 8895, 5833, 545, 7938, 3822, 2984, 5544, 7347, 1246, 9632, 1327, 1061, 8248, 9309, 9728, 4483, 3677, 3036, 3798, 3439, 1338, 6112, 1813, 9020, 3320, 3294, 7163, -1},
        (int[]) {3062, 9348, 7626, 4360, 8878, 9076, 211, 6228, 2989, 9850, 6303, 2850, 1299, 9195, 9999, 1414, 3462, 2979, 9475, 819, 781, 736, 4279, 2866, 3684, 1758, 9232, 7332, 2327, 4457, 8572, 4789, 885, 356, 7990, 9207, 3586, 5377, 986, 7034, 3260, 1014, 7548, 454, 6418, 3945, -1},
        (int[]) {1146, 9110, 3053, 7916, 1914, 4953, 8236, 25, 5868, 991, 1414, 4586, 2011, 8610, 2405, 7290, 8080, 2285, 7294, 2916, 4693, 2105, 1915, 2930, 3084, 2143, 640, 9102, 7908, 5768, 1681, 1318, 9607, 2133, 663, 1567, 2352, 8291, 9383, 1646, 774, 9862, 1652, 6354, 8227, 7486, 6046, 910, 6084, 8744, 3058, 7905, 9145, 9548, 4029, 929, 2839, 1657, 1498, 1979, 9785, 2296, 2381, 820, -1},
        (int[]) {3635, 3940, 337, 8200, 5102, 6050, 1948, 3702, 9463, 6025, 4574, 734, 5396, 7050, 2786, 3398, 362, 5393, 4907, 5337, 903, 1202, 3326, 4426, 9976, 3053, 2827, 7458, 4563, 7295, 6260, 7485, 3377, 6639, 1136, 6573, 5116, 5519, 4768, 4564, 2751, 8748, 5322, 7660, 2959, 4212, 8382, 7032, 4753, 8648, -1},
        (int[]) {7826, 5882, 1399, 3174, 456, 5219, 9401, 1078, 7009, 8375, 6606, 4650, 563, 2218, 903, 2824, 3374, 984, 71, 7024, 410, 2461, 9223, 4469, 6930, 9583, 6163, -1},
        (int[]) {1033, 6912, 9438, 8199, 8225, 7771, 8470, 3036, 2152, 2646, 4733, 5194, 4167, 6543, 4311, 59, 7078, 2320, 6692, 7196, 7766, 3667, 6688, 1993, 8510, 8776, 4451, 5348, 6590, 8156, 5059, 1856, 5950, 1267, 2608, 4281, 1151, 5802, 1535, 2148, 7653, 8123, 7402, 728, 7407, 7205, 1968, 33, 3518, 9018, 1973, 3034, 5053, 3129, 2490, 8018, 497, 9985, 6557, 7599, 4366, 4614, 1370, 7445, 2525, 5443, 8213, 3741, 5325, 3046, 535, 9806, 5726, 6150, 7327, 5302, 294, 4233, 8552, 4841, 870, 1490, 2188, -1},
        (int[]) {7078, 5502, 8271, 9633, -1},
        (int[]) {9113, 9063, 3789, 3240, 5529, 7061, 8737, 861, 4862, 9572, 4446, 4306, 9605, 5168, 2431, 7120, 7915, 1785, 6355, 9791, 7138, 5865, 3249, 7530, 7951, 7627, 879, 5912, 8565, 9427, 1417, 4216, 3029, 1122, 1503, 143, 8297, 1618, 8647, 4481, 4670, 1072, 3953, 7857, 8041, 405, 5958, 1558, 2399, 9002, 3143, 4384, 4355, 4095, 9637, 8112, 7672, 8447, 9883, 2858, 1861, 1402, 942, 151, 622, 5954, 2149, 5468, 7542, 2606, 6510, 7853, -1},
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
