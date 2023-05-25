/*
 * Definiamo la supercifra di un intero x con le seguenti regole:
 * Se x ha solo 1 cifra, la sua super cifra è x.
 * Altrimenti, la super cifra di x è uguale alla supercifra della sua somma delle cifre.
 * Per esempio:
 * supercifra(9875) = supercifra(9+8+7+5) =
 *                  = supercifra(29) = 
 *                  = supercifra(2+9) =
 *                  = supercifra(11) =
 *                  = supercifra(1+1) = 
 *                  = supercifra(2) = 
 *                  = 2
 */
#include<stdio.h>

int sommacifre(int num){
    if(num/10 == 0){
        return num;
    }else{
        return num % 10 + sommacifre(num/10);
    }
}

int supercifra(int num){
    if(num / 10 == 0){
        return num;
    } else {
        return supercifra(sommacifre(num));
    }
}


int main(){
    printf("%d", supercifra(9875));
    return 0;
}