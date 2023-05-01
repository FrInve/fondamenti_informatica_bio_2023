/*
 * Esercitazione del 2023-05-02, esercizio 1
 * Keywords: funzioni, puntatori
 * Scrivere un programma che definisce e inizializza un array di floats.

 * Poi, mediante un sistema di funzioni, calcola la normalizzazione
 * MinMax del vettore. Ovvero ogni elemento del vettore viene trasformato 
 * secondo la formula:
 *  new_elem = (elem - min_array) / (max_array - min_array)
 */

#include <stdio.h>
#define MAX 10

float max(float*, int);
float min(float*, int);
void maxmin(float*, int, float*, float*);
void normalize(float *, int);

float max(float* arr, int size){
    float max = arr[0];
    int i;

    for(i=0;i<size;i++){
        if (arr[i] > max){
            max = arr[i];
        }
    }
    return max;
}

float min(float* arr, int size){
    float min = arr[0];
    int i;

    for(i=0;i<size;i++){
        if (arr[i] < min){
            min = arr[i];
        }
    }
    return min;
}

void maxmin(float* arr, int size, float* maximum, float* minimum){
    *minimum = min(arr, size);
    *maximum = max(arr, size);
}

void normalize(float* arr, int size){
    float imin, imax;
    int i;

    maxmin(arr, size, &imax, &imin);
    for (i=0;i<size;i++){
        arr[i] = (arr[i]-imin)/(imax - imin);
    }
}

int main()
{
    float a[MAX] = {5, -2.5, 10, 5, 2, 1, 10, 6, 0, 1};
    float max, min;
    int i = 0;
    
    normalize(a, MAX);
    for(i = 0; i < MAX; i ++){
        printf("%f ", a[i]);
    }
   
}