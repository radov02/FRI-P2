
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "naloga.h"

// rocno testiranje: gcc -D test test01.c naloga.c

int poisciStudenta(Student** studentje, int stStudentov, int vpisna) {
    
    for(int i = 0; i < stStudentov; i++){
        if((*studentje[i]).vpisna == vpisna){
            return i;
        }
    }
    return -1;
}

int poisciPO(Student* student, char* predmet) {
    for(int i = 0; i < student->stPO; i++){     // isto kot (*student).stPO
        if(strcmp(student->po[i].predmet, predmet) == 0){
            return i;
        }
    }
    return -1;
}

int dodaj(Student** studentje, int stStudentov, int vpisna, char* predmet, int ocena) {
    
    int indeksStudenta = poisciStudenta(studentje, stStudentov, vpisna);
    // ce ze obstaja student:
    if(indeksStudenta != -1){
        int indeksPredmeta = poisciPO(studentje[indeksStudenta], predmet);
        // ce predmet ze obstaja:
        if(indeksPredmeta != -1){
            studentje[indeksStudenta]->po[indeksPredmeta].ocena = ocena;
        }
        else{   // ce ne obstaja, ga dodamo na konec:
            strcpy(studentje[indeksStudenta]->po[studentje[indeksStudenta]->stPO].predmet, predmet);    // ne moremo kopirati s prirejanjem - skopirati moramo vsebino niza
            studentje[indeksStudenta]->po[studentje[indeksStudenta]->stPO].ocena = ocena;
            studentje[indeksStudenta]->stPO++;
        }
        return stStudentov;
    }

    // ce se ne obstaja, naredimo novega:
    // Student novi; novi.vpisna = vpisna; ... // USTVARI SE NA SKLADU - NI VEC DOSTOPNO PO KONCU FUNKCIJE (deluje pa v mainu, ker se z zakljuckom maina zakljuci tudi program in takrat je ok ce Student ni vec dostopen)
    Student* novi = malloc(sizeof(Student));   // ustvarimo na kopici; naredimo kazalec nanj, ker ga rabimo za postavljanje na konec tabele
    novi->vpisna = vpisna;
    novi->po = malloc(10 * sizeof(PO));
    // (*novi).po[0].predmet = predmet;   // NI OK, ker ne moremo kopirati s prirejanjem - skopirati moramo vsebino niza
    strcpy(novi->po[0].predmet, predmet);
    novi->po[0].ocena = ocena;
    novi->stPO = 1;

    studentje[stStudentov] = novi;
    return ++stStudentov;
}

#ifndef test

int main() {
    // koda za ro"cno testiranje (po "zelji)

    return 0;
}

#endif
