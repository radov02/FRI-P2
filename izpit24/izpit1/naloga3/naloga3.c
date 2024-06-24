
/*
 * Zagon testne skripte ("sele potem, ko ste prepri"cani, da program deluje!):
 *
 * export name=naloga3
 * make test
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int poteza = 0;



// kolut predstavlja številko koluta od zgoraj navzdol (spodnji ima največjo)

void hanoi(char zacetni, char pomozni, char koncni, int kolut, int ignoriramo){

    if(kolut <= 1){
        poteza++;
        if(koncni == 'B' && poteza > ignoriramo && kolut == 1){     // ker samo 1. in 3. štejeta za premik, 2. pa je duplikat
            printf("%d\n", poteza);
        }
        return;
    }

    // glej sliko hanojskiStolpi.png:
    hanoi(zacetni, koncni, pomozni, kolut-1, ignoriramo);   // 1. vzamemo en kolut višje
    hanoi(zacetni, pomozni, koncni, 0, ignoriramo);    // 2. premik ko imamo le še en kolut (zgornji klic vrne)
    hanoi(pomozni, zacetni, koncni, kolut-1, ignoriramo);   // 3. 
}


int main(){

    int n, k;
    scanf("%d %d", &n, &k);

    hanoi('A', 'B', 'C', n, k);

    return 0;
}

/*
    - želimo premakniti najbolj spodnji disk na C (cilj je C)
    - VZAMEMO MANJŠI PROBLEM: pred tem moramo premakniti vse diske nad njim na B (cilj je B)
    - želimo premakniti drugi največji disk na B
    - VZAMEMO MANJŠI PROBLEM: pred tem moramo premakniti vse diske nad njim na C (cilj je C)
    - ... dokler ne pridemo do enega koluta
    - zdaj premaknemo kolut na cilj (takoj se vrne)
    - takoj se vrne funkcija in kličemo podproblem prestavljanja odmaknjenih kolutov nazaj
*/