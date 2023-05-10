/*
 * Esercitazione del 2023-05-11, esercizio 2.
 * Un automobile monta per ogni ruota un sensore di pressione, che ha generato un
 * vettore di 10 misurazioni in bar.
 * Scrivere un programma che calcoli media e scarto quadratico medio
 * (o deviazione standard) per ogni ruota.
 * 
 * Si definisce come evento anomalo quando una misurazione dista più di due 
 * deviazioni standard dal valore medio.
 * Scrivere una funzione che indichi se per qualche ruota si è verificato 
 * un evento anomalo.
 */
#include <stdio.h>
#include <math.h>
#define NUM_MISURE 10

typedef struct{
    float pressione[NUM_MISURE];
    float media;
    float deviazione_standard;
    int anomalia;
} Pneumatico;

typedef struct {
    Pneumatico front_right;
    Pneumatico front_left;
    Pneumatico rear_right;
    Pneumatico rear_left;
} Automobile;

float calcola_media(float *array, int size){
    float sum = 0.0;
    int i = 0;
    for(i=0;i<size;i++){
        sum += array[i];
    }
    return sum/size;
}

float calcola_dev_std(float *array, int size, float media){
    float sum_of_squares = 0.0;
    int i=0;
    for(i=0;i<size;i++){
        sum_of_squares += pow(array[i]-media,2);
    }
    return sqrt(sum_of_squares/(size));
}

int esiste_anomalia(float *array, int size, float *mean, float *std_dev, float *valore_anomalo){
    int i=0;
    for(i=0;i<size;i++){
        if(fabs(array[i]-*mean) > 2*(*std_dev)){
            valore_anomalo = array+i;
            return 1;
        }
    }
    return 0;
}

float *trova_anomalia(Pneumatico *r){
    float *pointer_to_valore_anomalo;
    r->media = calcola_media(r->pressione, NUM_MISURE);
    r->deviazione_standard = calcola_dev_std(r->pressione, NUM_MISURE, r->media);
    r->anomalia = esiste_anomalia(r->pressione, NUM_MISURE, &(r->media), &(r->deviazione_standard), pointer_to_valore_anomalo);
    return pointer_to_valore_anomalo;
}

int check_automobile(Automobile *a){
    trova_anomalia(&(a->front_left));
    trova_anomalia(&(a->front_right));
    trova_anomalia(&(a->rear_left));
    trova_anomalia(&(a->rear_right));
    return a->front_left.anomalia || a->front_right.anomalia || a->rear_left.anomalia || a->rear_right.anomalia;
}

int main(){
    Automobile a = {
        {{2.04, 2.04, 2.04, 2.05, 2.04, 2.05, 2.04, 2.05, 2.04, 2.05}, 0,0,0}, //front_right
        {{2.04, 2.05, 2.04, 2.05, 2.04, 2.05, 2.04, 2.05, 2.04, 2.05}, 0,0,0}, //front_left
        {{2.04, 2.05, 2.04, 2.05, 2.04, 2.05, 2.04, 2.05, 2.04, 2.05}, 0,0,0}, //rear_right
        {{2.04, 2.04, 2.04, 2.04, 2.04, 2.04, 2.04, 2.04, 2.04, 1.90}, 0,0,0}  //rear_left
    };

    /* // Da evitare!
     * float *pointer_to_valore_anomalo;
     * a.front_right.media = calcola_media(a.front_right.pressione, NUM_MISURE);
     * a.front_right.deviazione_standard = calcola_dev_std(a.front_right.pressione, NUM_MISURE, a.front_right.media);
     * a.front_right.anomalia = esiste_anomalia(a.front_right.pressione, NUM_MISURE, &(a.front_right.media), &(a.front_right.deviazione_standard), pointer_to_valore_anomalo);
     */

    if(check_automobile(&a)){
        printf("Anomalia!");
    }else{
        printf("Non si sono verificate anomalie");
    }
}