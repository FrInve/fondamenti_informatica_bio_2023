/* Scrivere una funzione ricorsiva che prende in ingresso due array di lunghezza N di interi
 * che rappresentano due numeri binari (in cui il bit più significativo corrisponde alla posizione con indice 0).
 * La funzione restituisce (per riferimento) un vettore di lunghezza N+1 che rappresenta la somma dei due numeri binari.
 */

#define N 4
#include <stdio.h>

void somma(int *x, int *y, int *res, int size, int carry){
    if(size == 0){
        res[size] = carry;
        return;
    }
    int somma_uno = x[size-1]+y[size-1]+carry;
    switch (somma_uno)
    {
    case 0:
        res[size] = 0;
        return somma(x,y,res,size-1,0);
        break;
    case 1:
        res[size] = 1;
        return somma(x,y,res,size-1,0);
        break;
    case 2:
        res[size] = 0;
        return somma(x,y,res,size-1,1);
        break;
    case 3:
        res[size] = 1;
        return somma(x,y,res,size-1,1);
        break;
    default:
        break;
    }
}

int main(){
    int x[N] = {1,0,0,0};
    int y[N] = {1,0,0,1};
    int res[N+1];

    somma(x,y,res,N,0);

    int i;
    for(i=0;i<N+1;i++){
        printf("%d", res[i]);
    }
    printf("\n");
}