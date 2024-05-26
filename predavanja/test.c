#include <stdio.h>

void f(int a){
    a = a + 1;
}

void f2(int *a){
    a = a + 10;
}

void f3(int *a){
    *a = a + 11;
}

void f4(int *a){
    // &a ... naslov kjer se nahaja pointer *a
    // *a ... vsebina na naslovu a - v tem primeru lokacija od argumenta (b)
    // a ... naslov na katerega kaže kazalec *a
    printf("f4:\n&a number: %d, pointer: %p,\n*a number: %d, pointer: %p,\na number: %d, pointer: %p\n", &a, &a, *a, *a, a, a);
    *a = &a + 1;
}

struct complex_c{
    double x;
    double y;
};

typedef struct node {
	int value;
	nodee* next;
} nodee;

int main(){

    struct complex_c c1, c2, c3;    // spremenljivke so tipa struct complex_c
    struct complex_c* c4;

    c1.x = 1.2;
    c4->x = -3.5;

    FILE* dat = fopen("dat.txt", "wt");
    FILE* dato = fopen("dat.txt", "rt");


    /* int b = 10;
    f(b);
    printf("%d\n", b);
    f2(&b);
    printf("%d\n", b);
    printf("lokacija b: %d\n", &b);
    f3(&b);
    printf("%d\n", b);

    f4(&b);
    f4(b);
    printf("%d\n", b);  // vrne to kar je v a v funkciji f4 - to je naslov od b-ja */

    /* int first = 10; 
    int second = 0; 
    printf("sdagfs");
    printf("[%d]\n", first / second); 
    printf("konec"); */

    return 0;
}