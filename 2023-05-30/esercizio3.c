/* Il Run-Length Encoding (RLE) è un algoritmo di compressione di
 * sequenze di caratteri senza perdita di informazione che sostituisce
 * le sequenze di caratteri ripetuti con un'unica ripetizione e la loro lunghezza.
 * Ad esempio la sequenza:
 * AAAXAAAABBBB
 * Viene sostituita dalla sequenza:
 * A3X1A4B4
 * Scrivere una funzione di tipo void, che riceve in ingresso un array di caratteri
 * e la sua lunghezza e ne stampa a video la codifica RLE.
 */
#define LEN 20
#include <string.h>
#include <stdio.h>

void stampa_codifica_rle(char *stringa, int lunghezza){
    int i=0;
    char successivo = '\0';
    int uguali=1;
    for(i=0;i<lunghezza;i++){
        successivo = stringa[i+1];
        if(stringa[i] == successivo){
            uguali++;
        }else{
            printf("%c%d",stringa[i],uguali);
            uguali=1;
        }
    }
}

void stampa_codifica_rle_rec(char *stringa, int lunghezza, int uguali){
    if(lunghezza == 0){
        return;
    }else{
        if(stringa[0] == stringa[1]){
            return stampa_codifica_rle_rec(stringa+1,lunghezza-1,uguali+1);
        }else{
            printf("%c%d",stringa[0],uguali);
            return stampa_codifica_rle_rec(stringa+1,lunghezza-1,1);
        }
    }
}

void stampa_codifica_rle_wrapper(char *stringa, int lunghezza){
    stampa_codifica_rle_rec(stringa, lunghezza, 1);
}

int main(){
    char stringa[LEN] = "AAAXAAAABBBB";
    int lunghezza = strlen(stringa);
    stampa_codifica_rle(stringa, lunghezza);
    printf("\n");
    stampa_codifica_rle_rec(stringa, lunghezza,1);
    printf("\n");
    stampa_codifica_rle_wrapper(stringa, lunghezza);
}