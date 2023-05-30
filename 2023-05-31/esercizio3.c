/* Si consideri un array A di N interi.
 * Definire una funzione
 * int conta(int* arr, int key, int size)
 * Che restituisce il numero di occorrenze dell’intero key nel vettore arr.
 * Usare la funzione per identificare e stampare il numero che occorre più di frequente in A ed il numero di occorrenze.
 * Esempio:
 * A = {-1,0,-10,6,4,6,-2}
 * Output: numero = 6, occorrenze = 2
 */
#define N 7
#include <stdio.h>

int min(int *arr, int size){
    int i, local_min=arr[0];
    for(i=0;i<size;i++){
        if(arr[i]<local_min){
            local_min = arr[i];
        }
    }
    return local_min;
}

int max(int *arr, int size){
    int i, local_max=arr[0];
    for(i=0;i<size;i++){
        if(arr[i]>local_max){
            local_max = arr[i];
        }
    }
    return local_max;
}

int conta(int *arr, int key, int size){
    int i, occorrenze=0;
    for(i=0;i<size;i++){
        if(arr[i] == key){
            occorrenze++;
        }
    }
    return occorrenze;
}

int main(){
    int A[N] = {-1,0,-10,6,4,6,-2};
    int key_max=A[0], occorrenze_max=conta(A,A[0],N);
    
    int i;
    for(i=min(A, N); i<=max(A, N); i++){
        if(conta(A,i,N) > occorrenze_max){
            key_max = i;
            occorrenze_max = conta(A,i,N);
        }
    }
    printf("numero = %d, occorrenze = %d\n",key_max, occorrenze_max);
}