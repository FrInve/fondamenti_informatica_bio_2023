/*
 * Data una stringa di lunghezza pari, scrivere una funzione ricorsiva 'scambia'
 * che scambi i caratteri nelle posizioni pari con i rispettivi successivi nelle
 * posizioni dispari.
 * Per esempio:
 * scambia("cane") -> "acen"
 * scambia("az") -> "za"
 */
#include <string.h>
#include <stdio.h>

void scambia(char* stringa){
    if(*stringa == '\0'){
        return;
    }else{
        char tmp;
        tmp = stringa[0];
        stringa[0] = stringa[1];
        stringa[1] = tmp;
        return scambia(stringa+2);
    }
}

int main(){
    char stringa[10] = "az";
    printf("%s\n",stringa);
    scambia(stringa);
    printf("%s\n",stringa);
}