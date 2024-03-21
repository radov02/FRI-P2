#include <stdio.h>

int a = 10;  // statična, inicializirana na 0
extern int b;   // definirana v nekem drugem delu programa, zaradi tega jo lahko vidimo tudi tukaj
static int c;   // c je statična (private, skrita), inicializirana na 0

void f(){
    static int a = 20;
    printf("%d\n", a);    // izpis: 20
}

int main(){
    f();
    printf("%d\n", a);    // izpis: 10
}