#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "naloga.h"

int poisciStudenta(Student** studentje, int stStudentov, int vpisna){

    for(int i = 0; i < stStudentov; i++){
        if(studentje[i]->vpisna == vpisna){
            return i;
        }
    }
    return -1;
}

int poisciPO(Student* student, char* predmet){

    struct _PO* tabelaParov = student->po;

    for(int i = 0; i < student->stPO; i++){
        if(strcmp(tabelaParov[i].predmet, predmet) == 0){
            return i;
        }
    }
    return -1;
}

int dodaj(Student** studentje, int stStudentov, int vpisna, char* predmet, int ocena){

    int i = poisciStudenta(studentje, stStudentov, vpisna);
    int retStStudentov = -1;

    if(i >= 0){ // ce je ze v evidenci
        Student* student = studentje[i];
        int j = poisciPO(student, predmet);
        if(j >= 0){  // ce ze ima zapis za ta predmet
            student->po[j].ocena = ocena;
        }
        else{
            PO* novPar = malloc(sizeof(PO));
            //novPar->predmet = predmet;  // NE!!!
            strcpy(novPar->predmet, predmet);
            novPar->ocena = ocena;
            student->po[student->stPO] = *novPar;
            student->stPO++;

            /* PO* tabelaPOjev = student->po;  // Lahko predpostavite, da je tabela dovolj velika.
            strcpy(tabelaPOjev[student->stPO].predmet, predmet);
            tabelaPOjev[student->stPO].ocena = ocena;
            student->stPO++; */
        }
        retStStudentov = stStudentov;
    }
    else{
        Student* novi = malloc(sizeof(Student));
        novi->vpisna = vpisna;
        novi->stPO = 1;
        novi->po = malloc(10 * sizeof(PO));
        novi->po[0].ocena = ocena;
        strcpy(novi->po[0].predmet, predmet);

        studentje[stStudentov] = novi;
        retStStudentov = ++stStudentov;
    }

    return retStStudentov;
}

#ifndef test
int main(){

    
    return 0;
}
#endif