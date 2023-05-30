/* Due numeri primi vengono detti gemelli quando la loro distanza è 2.
 * Ad esempio 29 e 31 sono gemelli.
 * Scrivere una porzione di codice che presi due interi N ed M,
 * stampi tutti (se esistono) i numeri primi compresi tra N ed M che hanno un gemello.
 * Ad esempio se N=28 e M=33 il programma stampa sia 29 che 31.
 */
#include <stdio.h>

int primo(int num){
    int i;
    for(i=2;i<num;i++){
        if(num%i == 0){
            return 0;
        }
    }
    return 1;
}

int gemello(int num){
    int i;
    if(!primo(num)){
        return 0;
    }
    for(i=-2;i<=2;i++){
        if(num+i<1){
            continue;
        }
        if(primo(num+i)){
            return 1;
        }
    }
    return 0;
}

void stampa_gemelli(int n, int m){
    if(n<=m){
        int i;
        for(i=n;i<m;i++){
            if(gemello(i)){
                printf("%d ",i);
            }
        }
    }
}


int main(){
    int n,m;
    n=28;
    m=33;
    stampa_gemelli(n,m);
}