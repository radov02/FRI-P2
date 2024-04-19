#include <stdio.h>

int steviloDiskov;

void hanoi(int n, char zaceten, char pomozen, char koncen){
    printf("zac: %c, pom: %c, konc: %c\n", zaceten, pomozen, koncen);
    if(n == 1){
        printf("\tPREMIK: %c -> %c\n", zaceten, koncen);
        return;
    }
    printf("v odmikanje diska %d: ", n-1);
    hanoi(n-1, zaceten, koncen, pomozen);   // odmikanje diskov (od spodaj navzgor gremo, izvaja se od zgoraj navzdol - DELOVANJE PODOBNO SKLADU, SAJ SO FUNKCIJE NA SKLADU)

    hanoi(1, zaceten, pomozen, koncen);     // premik na ciljno pozicijo

    printf("PREMIK NAZAJ\n");
    hanoi(n-1, pomozen, zaceten, koncen);   // premik odmaknjenih diskov na že odmaknjene večje
}

int main()
{
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);
    steviloDiskov = n;
    hanoi(n, 'A', 'B', 'C');
    return 0;
}