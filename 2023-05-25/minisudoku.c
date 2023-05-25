/* 
 * Nel minisudoku si devono riempire le celle di una matrice 4x4
 * con le cifre da 1 a 4, evitando ripetizioni in righe, colonne e riquadri 2x2.
 * Scrivere una funzione risolvi che, data una partita di minisudoku, provi a risolvere lo schema.
 */
#include <stdio.h>
#include <stdbool.h>
#define DIM 4

void stampa_schema(int m[DIM][DIM]) {
    int i,j;
    for(i=0;i<DIM;i++) {
        for(j=0;j<DIM;j++) {
            printf("%i\t", m[i][j]);
        }
        printf("\n");
    }
}

bool possibile(int schema[DIM][DIM], int riga, int colonna, int num){
    int i;
    for(i=0;i<DIM;i++){
        if(schema[riga][i]==num || schema[i][colonna] == num){
            return false;
        }
    }

    int i_riga = riga - riga%2;
    int i_colonna = colonna - colonna%2;
    int j;
    for(i=0;i<2;i++){
        for(j=0;j<2;j++){
            if(schema[i_riga + i][i_colonna + j] == num){
                return false;
            }
        }
    }

    return true;
}

bool risolvi(int schema[DIM][DIM], int riga, int colonna){
    if (riga == DIM){
        return true;
    }

    if(schema[riga][colonna] != 0){
        if (colonna == DIM-1){
            return risolvi(schema, riga+1,0);
        } else{
            return risolvi(schema, riga, colonna+1);
        }
    }

    int num;
    for(num = 1;num<=DIM;num++){
        if(possibile(schema,riga,colonna,num)){
            schema[riga][colonna] = num;
        
            if(colonna==DIM-1){
                if(risolvi(schema, riga+1,0)){
                    return true;
                } 
            } else {
                if(risolvi(schema,riga,colonna+1)){
                    return true;
                }
            }
        }
        schema[riga][colonna] = 0;
    }

    return false;
}


int main(){
    int schema[DIM][DIM] = {{0,1,0,0},
                            {0,0,0,1},
                            {1,0,0,0},
                            {0,0,1,0}};
        
    stampa_schema(schema);
    risolvi(schema,0,0);
    printf("\n");
    stampa_schema(schema);

    return 0;
}