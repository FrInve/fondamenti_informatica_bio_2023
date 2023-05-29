/* Si consideri un matrice M di dimensione SxN di tipo float.
 * In molte applicazioni di Machine Learning è bene normalizzare le colonne della matrice
 * in modo che i valori sia compresi tra 0 ed 1.
 * Un metodo comunemente usato è la normalizzazione min-max, in cui ciascun elemento M[r][c] della matrice,
 * appartenente alla riga r e ed alla colonna c, subisce questa trasformazione:
 * M[r][c] = (M[r][c] − minimo(colonna c))/ (massimo(colonna c) − minimo(colonna c))
 * Scrivere una porzione di codice per effettuare la normalizzazione min-max della matrice M.
 */
#define S 4
#define N 3
#include <stdio.h>

float min_colonna(float matrice[S][N], int colonna, int num_righe){
    int i = 0;
    float local_min= matrice[0][0];
    for(i=0;i<num_righe;i++){
        if(matrice[i][colonna] < local_min){
            local_min = matrice[i][colonna];
        }
    }
    return local_min;
}
float max_colonna(float matrice[S][N], int colonna, int num_righe){
    int i = 0;
    float local_max=matrice[0][0];
    for(i=0;i<num_righe;i++){
        if(matrice[i][colonna] > local_max){
            local_max = matrice[i][colonna];
        }
    }
    return local_max;
}

void normalizza(float matrice[S][N], int righe, int colonne){
    int i,j;
    float max_col, min_col;
    for(j=0;j<colonne;j++){
        max_col = max_colonna(matrice, j, righe);
        min_col = min_colonna(matrice, j, righe);
        for(i=0;i<righe;i++){
            matrice[i][j] = (matrice[i][j]-min_col)/(max_col-min_col);
        }
    }
}

int main(){
    float m[S][N] = {
        {1,0,1},
        {3,0,0},
        {4,0,2},
        {1,5,5}
    };
    normalizza(m, S, N);
    int i,j;
    for(i=0;i<S;i++){
        for(j=0;j<N;j++)
            printf("%.2f ", m[i][j]);
        printf("\n");
    }
    return 0;
}