/*
 * Esercitazione del 2023-05-02, esercizio 3
 * Un registro contiene i libretti di ciascuno studente.
 * Uno studente ha un id (numerico) ed ha eseguito fino ad un massimo di 20 
 *  esami (possibilmente meno); un esame è caratterizzato da un voto e da un
 *  numbero di crediti.
 * 
 * Definire le strutture dati per contenere il registro.
 * 
 * Infine scrivere una funzione che per ciascuno studente stampi 
 * la media pesata dei suoi voti:
 * media_pesata = sum( voto_esame*crediti_esame ) / sum(crediti_esame)
 * Keywords: strutture dati, funzioni
 */

#include <stdio.h>
#define MAX_ESAMI 20
#define MAX_STUD 100

typedef struct esame {
    int voto;
    int crediti;
} Esame;

typedef struct student {
    int student_id;
    Esame esami[MAX_ESAMI];
    int sostenuti;
} Student;

typedef struct registro {
    Student studenti[MAX_STUD];
    int registrati;
} Register_t;

int media_pesata(Student studente){
    int crediti_totali = 0;
    int somma_voti = 0;
    int i = 0;

    for (i=0; i<studente.sostenuti; i++){
        crediti_totali = crediti_totali + studente.esami[i].crediti;
        somma_voti = somma_voti + (studente.esami[i].voto * studente.esami[i].crediti);
    }
    int media_ponderata = somma_voti/crediti_totali;
    return media_ponderata;
}

void stampa_medie(Register_t registro){
    int i = 0;
    for(i=0; i<registro.registrati; i++){
        int mp = media_pesata(registro.studenti[i]);
        printf("Studente %d - media %d\n",registro.studenti[i].student_id, mp);
    }
}

void aggiungi_studente(Register_t *registro){
    int new_id = registro->registrati;
    printf("New student %d created\n", new_id);
    registro->studenti[new_id].student_id = new_id;
    registro->studenti[new_id].sostenuti = 0;
    registro->registrati++;
}

void registra_esame(Register_t *registro, int student_id, int voto, int crediti){
    Student* student = &(registro->studenti[student_id]);
    student->esami[student->sostenuti].voto = voto;
    student->esami[student->sostenuti].crediti = crediti;
    student->sostenuti++;
}

int main(){
    Register_t registro = {0};
    aggiungi_studente(&registro);
    registra_esame(&registro, 0,30,5);
    registra_esame(&registro, 0,30,5);
    stampa_medie(registro);
}