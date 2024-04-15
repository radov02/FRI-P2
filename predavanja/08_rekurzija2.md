# Rekurzija 2

```c
int f(int *p[10]) {...}
int main(int argx, char *args[]) {...}

int p;  // spremenljivka tipa int
int p[10];  // p je tabela 10 intov
int *p[10]; /* je isto kot */ int *(p[10]); // p je tabela 10 kazalcev na int
int (*p)[10];   // p je pointer na tabelo 10 intov
```

## Towers of Hanoi (Hanojski stolpi)

- odmikamo na sredino (n-1 obročev)
- če jih odmikamo (**n-1 je sodo**) sodo, gre prvi na C
- če jih odmikamo (**n-1 je liho**) liho gre prvi na B
- število potez je 2<sup>n</sup>-1
- osnovno nalogo razgradimo na dele za rekurzijo

<img src="5b5fb2670c9a185b2666637461e40c805fcc9ea5.png" alt="5b5fb2670c9a185b2666637461e40c805fcc9ea5.png" style="width:430px;"/>

### 5 obročev: A -> C preko B
- 4 obroče A -> B preko C  (obroč 1 gre na C)
- 1 obroč A -> C
- 4 obroče B -> C (obroč 1 gre na A)

```c
void hanoi(int n, char zaceten, char pomozen, char koncen){
    if(n == 1){
        printf("%c -> %c\n", zaceten, koncen);
        return;
    }

    hanoi(n-1, zaceten, koncen, pomozen);
    hanoi(1, zaceten, pomozen, koncen);
    hanoi(n-1, pomozen, zaceten, koncen);
}

int main(){

    hanoi(5, 'A', 'B', 'C');
    hanoi(4, 'A', 'C', 'B');
    hanoi(1, 'A', 'B', 'C');
    hanoi(4, 'B', 'A', 'C');
}
```

...naredi da funkcija vrne število potez
...naredi da vrne kateri obroč premaknemo kam
...naredi da izpiše:

5 4</br>
3</br>
2 1</br>

... program

## Množenje matrik

n matrik: m<sub>1</sub> x m<sub>2</sub>, m<sub>2</sub> x m<sub>3</sub>, m<sub>3</sub> x m<sub>4</sub>, ... , m<sub>n</sub> x m<sub>n+1</sub></br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;M<sub>1</sub>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;M<sub>2</sub>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;M<sub>3</sub>&nbsp;&nbsp;&nbsp;&nbsp; ... &nbsp;&nbsp;&nbsp;&nbsp;M<sub>n</sub>

m x m, m x m --> m x m  ... m<sup>3</sup> množenj

m<sub>1</sub> x m<sub>2</sub>, m<sub>2</sub> x m<sub>3</sub> --> m<sub>1</sub> x m<sub>3</sub> ... m<sub>1</sub>m<sub>2</sub>m<sub>3</sub> množenj

(AB)C = A(BC)

((M<sub>1</sub> M<sub>2</sub>) M<sub>3</sub>) M<sub>4</sub></br>
(M<sub>1</sub> M<sub>2</sub>) (M<sub>3</sub> M<sub>4</sub>)</br>
(M<sub>1</sub> (M<sub>2</sub> M<sub>3</sub>)) M<sub>4</sub></br>
...</br>
...slika

...slika

```c
#include <limits.h>

int st_mnozenj(int m[], int n){
    if(n == 1)
        return 0;

    int min = INT_MAX;
    for(int i = 1; i <= n-1; i++){  // i je število matrik na levi strani
        int l = st_mnozenj(&(m[0]), i); // &(m[0]) je isto kot m
        int d = st_mnozenj(&(m[i]), n-i);
        int vsehPriI = m[0] * m[i] * m[n] + l + d;
        if(vsehPriI < min){
            min = vsehPriI;
        }
    }
    return min;
}
```
...sliki (mali m so dimenzije matrik)

```c
int m[] = {...};
int n;
int memo[1000][1000];

int st_mnozenj(int zac, int n){
    if(n == 1)
        return 0;
    if(memo[zac][n] != 0){
        return memo[zac][n];
    }
    int min = INT_MAX;
    for(int i = 1; i <= n-1; i++){
        int l = st_mnozenj(zac, i);
        int d = st_mnozenj(zac+i, n-i);
        int vsehPriI = m[zac] * m[zac+i] * m[zac+n] + l + d;
        if(vsehPriI < min){
            min = vsehPriI;
        }
    }
    printf("# %d %d %d\n", zac, n, min);
    memo[zac][n] = min;
    return min;
}
```

... slika

$ ./matrike | grep '#' | sort | wc
$ ./matrike | grep '#' | sort -u | wc
// z memoizacijo lahko prihranimo toliko časa
$ time ./matrike

- s permutacijami:
... slika