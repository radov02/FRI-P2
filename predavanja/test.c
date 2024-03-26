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

int main(){

    int b = 10;
    f(b);
    printf("%d\n", b);
    f2(&b);
    printf("%d\n", b);
    printf("lokacija b: %d\n", &b);
    f3(&b);
    printf("%d\n", b);

    f4(&b);
    f4(b);
    printf("%d\n", b);  // vrne to kar je v a v funkciji f4 - to je naslov od b-ja

    return 0;
}