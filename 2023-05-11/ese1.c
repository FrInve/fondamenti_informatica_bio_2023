/*
 * Esercizatione del 2023-05-11, esercizio 1.
 * Lo sviluppo metrico di una bicicletta indica quanti metri percorre
 * la ruota posteriore ad ogni giro completo di pedale.
 * Su di esso influiscono tre fattori:
 * - il numero di denti della corona n_c;
 * - il numero di denti del pignone n_p;
 * - la circonferenza c della ruota, ottenibile dal diametro dato in pollici.
 * Esso si calcola secondo la formula: s_m = (n_c/n_p)*c.
 * 1) Scrivere un programma che, tramite un sistema di funzioni ed adeguate strutture dati,
 * calcoli lo sviluppo metrico di una bicicletta.
 * 2) Estendere il programma per ottenere la velocità in piano dato il numero
 * di pedalate al minuto.
 * vel = 3.6 * s_m * pedalate_min / 60
 */
#include <stdio.h>
#include <math.h>

#define PI 3.14159

// struttura dati per la ruota
typedef struct {
    double diametro; // in pollici
    double circonferenza; // in metri
} Ruota;

// struttura dati per la bicicletta
typedef struct {
    int n_c; // numero di denti della corona
    int n_p; // numero di denti del pignone
    Ruota ruota; // la ruota posteriore
} Bicicletta;

// funzione per calcolare la circonferenza della ruota
double calcola_circonferenza(Ruota r) {
    return PI * r.diametro;
}

// funzione per convertire pollici in centimetri
double inches_to_m(double dim){
    return dim*2.54/100;
}

// funzione per calcolare lo sviluppo metrico
double calcola_sviluppo_metrico(Bicicletta b) {
    return (b.n_c / (double)b.n_p) * inches_to_m(b.ruota.circonferenza);
}

// funzione per calcolare la velocità in piano
double calcola_velocita(double s_m, int pedalate_min) {
    return 3.6 * s_m * pedalate_min / 60;
}

int main() {
    // creazione della bicicletta
    Bicicletta b = {44, 16, {20.0, 0.0}};
    
    //b.ruota.circonferenza = calcola_circonferenza(b.ruota);
    // oppure
    Ruota *r = &(b.ruota);
    r->circonferenza = calcola_circonferenza(*r);

    // calcolo dello sviluppo metrico
    double s_m = calcola_sviluppo_metrico(b);
    printf("Lo sviluppo metrico della bicicletta è %.2f metri.\n", s_m);

    // calcolo della velocità in piano con 90 pedalate al minuto
    double vel = calcola_velocita(s_m, 90);
    printf("La velocità in piano della bicicletta è %.2f km/h.\n", vel);

    return 0;
}
