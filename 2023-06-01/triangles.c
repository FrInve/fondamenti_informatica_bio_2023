/*
Un triangolo viene caratterizzato dalla lunghezza dei suoi lati e da un id.
Definire una struttura che contenga tali informazioni.
Poi, considerare un array di triangoli, inizializzato con questi valori:
- id=0 a=2 b=4 c=4
- id=1 a=6 b=6 c=6
- id=2 a=3 b=4 c=5
1. Stampare per ogni triangolo, con un'apposita porzione di codice, se un triangolo è acutangolo, rettangolo o ottusangolo,
controllando se la somma dei quadrati dei lati più corti è rispettivamente maggiore, uguale o minore del quadrato del lato più lungo.
2. Stampare in ordine di area, dal più piccolo al più grande, gli id dei triangoli e la loro area.
L'area di un triangolo a partire dai lati si calcola con la formula di Erone: S=sqrt(p x (p-a) x (p-b) x (p-c)),
con p che indica il semiperimetro del triangolo.
*/
#define N 3
#include<stdio.h>
#include<stdlib.h>
#include<math.h>


int compara_float(const void *a,const void *b) {
    float *x = (float *) a;
    float *y = (float *) b;
    if(*x < *y){
        return -1;
    }else if(*x == *y){
        return 0;
    }else{
        return 1;
    }
}

typedef struct{
    int id;
    float a;
    float b;
    float c;
} triangle_t;

void stampa_tipo_triangolo(triangle_t t){
    float corto, medio, lungo;
    float lati[3];
    lati[0] = t.a;
    lati[1] = t.b;
    lati[2] = t.c;
    qsort(lati, 3, sizeof(float), compara_float);
    float somma_q_lati_corti = lati[0]*lati[0] + lati[1]*lati[1];
    float q_lato_lungo = lati[2] * lati[2];
    if(somma_q_lati_corti > q_lato_lungo){
        printf("Triangolo %d - acutangolo\n", t.id);
    }else if(somma_q_lati_corti == q_lato_lungo){
        printf("Triangolo %d - rettangolo\n", t.id);
    }else{
        printf("Triangolo %d - ottusangolo\n", t.id);
    }
}

void swap_triangoli(triangle_t *t1, triangle_t *t2){
    triangle_t tmp;
    tmp.id = t1->id;
    tmp.a = t1->a;
    tmp.b = t1->b;
    tmp.c = t1->c;

    t1->id = t2->id;
    t1->a = t2->a;
    t1->b = t2->b;
    t1->c = t2->c;

    t2->id = tmp.id;
    t2->a = tmp.a;
    t2->b = tmp.b;
    t2->c = tmp.c;
}

float sp(triangle_t t){
    return (t.a + t.b +t.c)/2.0;
}

float area(triangle_t t){
    return sqrt(sp(t)*(sp(t)-t.a)*(sp(t)-t.b)*(sp(t)-t.c));
}

void ordina_triangoli_per_area(triangle_t arr[], int n){
    int i, j;
    int swapped;
    for (i = 0; i < n - 1; i++) {
        swapped = 0;
        for (j = 0; j < n - i - 1; j++) {
            if (area(arr[j]) > area(arr[j + 1])) {
                swap_triangoli(&arr[j], &arr[j + 1]);
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
    triangle_t triangoli[N] = {
        {0, 2.0, 4.0, 4.0},
        {1, 6.0, 6.0, 6.0},
        {2, 3.0, 4.0, 5.0}
    };

    int i;
    for(i=0;i<N;i++){
        stampa_tipo_triangolo(triangoli[i]);
    }

    float sp_0;
    sp_0 = sp(triangoli[0]);
    float area_0;
    area_0 = area(triangoli[0]);

    ordina_triangoli_per_area(triangoli, N);
    for(i=0;i<N;i++){
        printf("Triangolo: %d con area = %.2f\n",triangoli[i].id, area(triangoli[i]));
    }
}
