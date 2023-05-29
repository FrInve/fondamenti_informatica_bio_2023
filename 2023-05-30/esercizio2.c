/* Due numeri interi positivi si dicono co-primi se il loro unico divisore comune è 1.
 * Scrivere una porzione di codice, possibilmente modularizzando il codice tramite funzioni,
 * che acquisisce dell’utente due numeri N ed M maggiori di 2 (controllare che l’utente
 * inserisca i valori corretti) e stampa tutti i numeri positivi minori di M che siano coprimi con N.
 */
#include <stdbool.h>
#include <stdio.h>

bool sono_coprimi(int a, int b){
    int maggiore, minore;
    if(a>=b){
        maggiore = a;
        minore = b;
    }else{
        maggiore=b;
        minore=a;
    }
    int i=0;
    for(i=2; i<=minore;i++){
        if(maggiore%i == 0 && minore%i == 0){
            return false;
        }
    }
    return true;
}

void stampa_coprimi(int n, int m){
    int i=0;
    for(i=1;i<m;i++){
        if(sono_coprimi(n, i)){
            printf("%d ", i);
        }
    }
}

int main(){
    int n=0,m=0;

    while(n<2){
        printf("Inserisci un numero maggiore di due: ");
        //scanf("%d", &n);
        //n=11;
    }
    while(m<2){
        printf("Inserisci un altro numero maggiore di due: ");
        //scanf("%d", &m);
        //m=9;
    }
    stampa_coprimi(n,m);

}
