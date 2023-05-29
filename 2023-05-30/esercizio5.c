/* Si scriva una funzione ricorsiva che prende in input due array
 * della stessa dimensione A e B, i cui elementi sono solo numeri 0 ed 1
 * e calcola la loro distanza di Manhattan. La distanza di Manhattan è definita
 * come il numero di elementi diversi nei due array.
 * Ad esempio, gli array:
 * 1,0,1,1,0,1
 * 0,1,1,1,0,1
 * Hanno distanza di Manhattan uguale a 2.
 */
#define LEN 6
#include <stdio.h>

int manhattan_iter(int *a, int *b, int lunghezza){
    int i = 0;
    int differenze = 0;
    for(i=0;i<lunghezza;i++){
        if(a[i] != b[i]){
            differenze++;
        }
    }
    return differenze;
}

int manhattan(int *a, int *b, int lunghezza){
    if(lunghezza == 0){
        return 0;
    }else{
        if(*a == *b){
            return 0 + manhattan(a+1,b+1,lunghezza-1);
        }else{
            return 1 + manhattan(a+1,b+1,lunghezza-1);
        }
    }
}

int manhattan_tail(int *a, int *b, int lunghezza, int differenze){
    if(lunghezza == 0){
        return differenze;
    }else{
        if(*a == *b){
            return manhattan_tail(a+1,b+1,lunghezza-1,differenze);
        }else{
            return manhattan_tail(a+1,b+1,lunghezza-1,differenze+1);
        }
    }
}

int manhattan_wrapper(int *a, int *b, int lunghezza){
    return manhattan_tail(a,b,lunghezza,0);
}

int main(){
    int a[LEN] = {1,0,1,1,0,1};
    int b[LEN] = {0,1,1,1,0,1};
    printf("%d", manhattan_wrapper(a,b,LEN));
}