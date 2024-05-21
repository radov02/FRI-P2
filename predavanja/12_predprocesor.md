# Predprocesor

izvorni program v C --> prevajalnik --> preveden program v binarni obliki

izvorni program v C --> predprocesor --> (program v C) --> prevajalnik --> (prevedena koda v binarni obliki brez standardne knjiznice) --> povezovalnik (doda knjižnice) --> preveden program v binarni obliki 

slika...

- npr. ukaz #include (prevajalnik tega ukaza nikoli ne vidi):
```c
#include <...>  // navedeno datoteko poišči na disku na sistemskem delu (kjer je prevajalnik) .. ve kje so
#include "..."  // išči datoteko na tem direktoriju .. mi določimo kje
```
- kopira kodo iz datoteke in jo vstavi

slika...

```c
# line 1000 // izpiše vrstico morebitne napake glede na podano

#define N 10
int n = N;
// ko gredo zgornji vrstici skozi predprocesor, N zamenja z 10 povsod v programu
int _N = N; // OK, ne zamenja _N z 10
int N = N;  // napaka
```

```c
int always_ten = 10;
int n = always_ten;
int N = always_ten;
int _N = always_ten;s
```

```c
# define PP ++
int n = 10;
...
n PP;   // n ++;
```

```c
# define MAIN main \
(int argc, char* argv[])
int MAIN {...}  // int main (int argx, char* argv[]) {...}
```

slike...

```c
#undef N // undefine macro
```

slike...