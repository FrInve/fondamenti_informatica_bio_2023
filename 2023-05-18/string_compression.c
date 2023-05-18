/*
 * Joseph e Jane partecipano a una gara per scimpanzè.
 * Durante il processo, devono comunicare frequentemente tra di loro.
 * Dato che non sono esattamente umani, non sanno parlare benissimo.
 * Devono mandarsi dei messaggi usando dei bigliettini di piccole dimensioni.
 * Per risparmiare spazio sui bigliettini, usano un algoritmo di compressione delle stringhe.
 *      Se un carattere c si ripete per n>1 volte, esso sarà
 *      rappresentato da cn, dove n è il numero di volte che si ripete.
 *      Se il carattere c occorre una sola volta, esso sarà rappresentato da c.
 * Aiutate Joseph e Jane a comunicare nella gara (tramite un programma con funzioni ricorsive);
 * https://www.hackerrank.com/challenges/string-compression
 */
#include <stdio.h>
#include <string.h>

void compress(char *source, char *dest, char lastChar, int counter){
    if(source[0]!=lastChar){
        if(counter>1){
            dest[0] = counter + '0'; // Massimo 9 ripetizioni! Altrimenti usare strlen ed sprintf per gestire la lunghezza della stringa
            dest[1] = source[0];
            return compress(source+1,dest+2,source[0],1);
        }
        dest[0] = source[0];
        return compress(source+1,dest+1,source[0],1);
    }else if(source[0]=='\0'){
        return;
    }else{
        return compress(source+1,dest, source[0], counter+1);
    }
}

int main(){
    char src[100] = {"aabbcccc"};
    char dest[100];
    compress(src,dest, '0', 0);
    printf("%s",dest);
}