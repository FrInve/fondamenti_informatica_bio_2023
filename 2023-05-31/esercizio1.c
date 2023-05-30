/* Una applicazione di e-commerce memorizza le recensioni ricevute dai suoi P prodotti in un array
 * prodotti_t prodotti[P];
 * Dove il tipo di dato prodotti_t è definito come
 * typedef struct {
 *      int prod_id;
 *      int voti[MAX];
 * } prodotti_t;
 * Se un prodotto ha ricevuto N < MAX voti, allora i primi N elementi sono voti compresi tra 1 e 5
 * e i successivi elementi fino alla fine del vettore hanno valore uguale a -1, in modo da poterli distinguere.
 * Si vuole migrare l’applicazione verso una più comoda struttura dati in cui ciascun prodotto è rappresentato da proprio id,
 * da un vettore di MAX voti e da un intero che indica il numero di voti ricevuti.
 * Definire il tipo di dato necessario e l’array per contenere i P prodotti nel nuovo formato.
 * Inoltre scrivere una porzione di codice che copia i valori dal primo formato al nuovo formato.
 * Infine, supponendo che il nuovo array sia definito come una variabile globale,
 * scrivere una funzione int add_review(int id, int voto) che:
 * - se il voto è compreso tra 1 e 5, un prodotto con tale id esiste, il prodotto ha meno di MAX voti
 * aggiunge il voto e ritorna 1;
 * - Altrimenti ritorna 0.
 */
#define MAX 5
#define MAX_PRODOTTI 5

typedef struct {
    int prod_id;
    int voti[MAX];
} prodotti_t;

typedef struct {
    int prod_id;
    int voti[MAX];
    int voti_ricevuti;
} prodotti_stack_t;
    
prodotti_t prodotti[MAX_PRODOTTI] = {
    {0,                 // Suppongo che prod_id sia uguale alla posizione nell'array prodotti
    {5,5,5,-1,-1}}
};
prodotti_stack_t prodotti_upgrade[MAX_PRODOTTI];

void copia_prodotto(prodotti_t *vecchio, prodotti_stack_t *nuovo){
    nuovo->prod_id = vecchio->prod_id;
    int i;
    for(i=0;i<MAX;i++){             // Non molto efficiente, sarebbe meglio un ciclo while...
        if(vecchio->voti[i] > -1){
            nuovo->voti[i] = vecchio->voti[i];
            nuovo->voti_ricevuti++;
        }
    }
}

void copia_prodotto_by_id(int id){
    prodotti_upgrade[id].prod_id = prodotti[id].prod_id;
    int i;
    for(i=0;i<MAX;i++){
        if(prodotti[id].voti[i] > -1){
            prodotti_upgrade[id].voti[i] = prodotti[id].voti[i];
            prodotti_upgrade[id].voti_ricevuti++;
        }
    }
}

int add_review(int id, int voto){
    if(voto<1 || voto>5){
        return 0;
    }
    if(id >= MAX_PRODOTTI){
        return 0;
    }
    if(prodotti_upgrade[id].voti_ricevuti>=MAX){
        return 0;
    }
    prodotti_upgrade[id].voti[prodotti_upgrade[id].voti_ricevuti] = voto;
    prodotti_upgrade[id].voti_ricevuti++;
    return 1;
}

int main(){

    //copia_prodotto(&(prodotti[0]), &(prodotti_upgrade[0]));
    copia_prodotto_by_id(0);
    add_review(0, 3);
}