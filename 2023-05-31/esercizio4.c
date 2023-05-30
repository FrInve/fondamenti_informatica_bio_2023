/* Si consideri una matrice di interi NxM.
 * Vogliamo scrivere una porzione di codice che la riduca ad una matrice NxT,
 * con T << M, dove ciascuna riga della nuova matrice contiene i più piccoli T elementi nella matrice originale.
 * Esempio:
 * T=2
 * I = {{2,4,5,1},
 *     {1,1,4,3},
 *     {3,0,1,5}}
 * O = {{1,2},
 *      {1,1},
 *      {0,1}}
 */
#define N 3
#define M 4
#define T 2

void copia(int *src, int *dest, int size){
    int i;
    for(i=0;i<size;i++){
        dest[i] = src[i];
    }
}

void swap(int* xp, int* yp){
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
 
void bubble_sort(int arr[], int n){
    int i, j;
    int swapped;
    for (i = 0; i < n - 1; i++) {
        swapped = 0;
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
                swapped = 1;
            }
        }
 
        // If no two elements were swapped by inner loop,
        // then break
        if (swapped == 0)
            break;
    }
}

int main(){
    int I[N][M] = {
        {2,4,5,1},
        {1,1,4,3},
        {3,0,1,5}
    };

    int O[N][T] = {};

    int temp[M] = {};

    int i,j;
    for(i=0;i<N;i++){
        copia(I[i], temp, M);
        bubble_sort(temp, M);
        copia(temp, O[i], T);
    }
}