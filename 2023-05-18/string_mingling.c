/* 
 * Pawel e Shaka sono diventati amici di recente. Credono che la loro amicizia 
 * durerà per sempre se intrecciano le loro stringhe preferite.
 * La lunghezza delle due stringhe è la stessa, n. 
 * Intrecciando due stringhe, P = 'abcd' e Q = 'xyzw', si ottiene una
 * nuova stringa R di lunghezza 2 x n con la seguente struttura:
 * R = axbyczdw.
 * Scrivere un programma che, date due stringhe P e Q, determini la 
 * stringa intrecciata R.
 * https://www.hackerrank.com/challenges/string-mingling
 */
#include<stdio.h>
#define N 10

void intreccia(char *p, char *q, char *r){
    if(*p=='\0'){                           // Se la stringa è vuota
        return;
    }else{
        r[0] = p[0];
        r[1] = q[0];
        return intreccia(p+1,q+1,r+2);
    }
}

int main(){
    char a[N] = "abcd";
    char b[N] = "xyzw";
    char result[2*N];
    intreccia(a,b,result);
    printf("%s",result);
}