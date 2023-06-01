/*
Si vuole scrivere un programma per monitorare il consumo
di inchiostro di una stampante b/n.
L'inchiostro necessario per stampare un'immagine dipende
dall'intensità del colore di quell'immagine in ogni punto.
Ogni immagine è rappresentata da due interi, larghezza e lunghezza,
e da una matrice[R][C] di pixel.
Ogni pixel è formato da tre interi da 0 a 255 che indicano
l'intensità di rosso, verde e blu.
Definire le strutture dati necessarie per rappresentare queste informazioni.
Poi, sapendo che l'inchiostro disponibile è in una variabile globale avail_ink=100,
e che l'inchiostro per stampare un pixel è 0.1 * intensità_media_pixel,
scrivere una porzione di codice che restituisca 1 se c'è abbastanza inchiostro
per stampare l'immagine, altrimenti 0.
Se è possibile stampare l'immagine, copiarla in una variabile globale "buffer" del tipo
definito per l'immagine e stampare l'inchiostro rimanente.
*/
#include<stdio.h>
#define R 5
#define C 4
#define INK_PER_PIXEL 0.1

typedef struct{
    int r;
    int g;
    int b;
} pixel_t;

typedef struct immagine
{
    int larghezza;
    int lunghezza;
    pixel_t pixels[R][C];
} immagine_t;

float avail_ink = 100;
immagine_t buffer;

int intensita_media_pixel(pixel_t p){
    return (p.r + p.b + p.g)/3;
}

float inchiostro_necessario(immagine_t imm){
    int i,j;
    float ink = 0;
    for(i=0;i<imm.lunghezza;i++){
        for(j=0;j<imm.larghezza;j++){
            ink += INK_PER_PIXEL * intensita_media_pixel(imm.pixels[i][j]);
        }
    }
    return ink;
}

int stampabile(immagine_t imm){
    float ink=0;
    ink=inchiostro_necessario(imm);
    if(ink <= avail_ink){
        return 1;
    }else{
        return 0;
    }
}

void copia_immagine(immagine_t src, immagine_t *dest){
    dest->larghezza = src.larghezza;
    dest->lunghezza = src.lunghezza;
    int i,j;
    for(i=0;i<src.lunghezza;i++){
        for(j=0;j<src.larghezza;j++){
            dest->pixels[i][j].b = src.pixels[i][j].b;
            dest->pixels[i][j].r = src.pixels[i][j].r;
            dest->pixels[i][j].g = src.pixels[i][j].g;
        }
    }
}

int main(){
    immagine_t immagine = {
        R, C
    };
    immagine.pixels[0][0] = (pixel_t){255,255,0};
    immagine.pixels[1][1] = (pixel_t){127,127,127};
    immagine.pixels[2][2] = (pixel_t){0,255,0};

    if(stampabile(immagine)){
        copia_immagine(immagine, &buffer);
        printf("Stampato!\n");
        avail_ink = avail_ink-inchiostro_necessario(immagine);
        printf("Inchiostro rimasto: %.2f", avail_ink);
    }
}

