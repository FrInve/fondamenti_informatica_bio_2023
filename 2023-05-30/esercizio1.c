/* In un torneo di scacchi l’organizzazione mantiene aggiornato un array di P partite.
 * Ciascuna partita è rappresentata da una struttura dati di tipo partita_t.
 *  typedef struct { int id_giocatore_bianco;
 *                  int id_giocatore_nero;
 *                  int scacchiera[8][8];
 *                } partita_t;
 * ...
 * partita_t partite[P];
 * ...
 * Il campo scacchiera è una matrice riempita in modo che ogni elemento assume valore: - 0, se la cella corrispondente non è occupata da alcun pezzo
 * - Valore positivo, se la cella è occupata da un pezzo bianco (1 pedone, 3 alfiere o cavallo, 5 torre,
 * 9 regina)
 * - Valore negativo, se la cella è occupata da un pezzo nero (-1 pedone, -3 alfiere o cavallo, -5
 * torre, -9 regina)
 * Il giocatore bianco sta vincendo se il valore assoluto della somma dei valori positivi supera il valore assoluto della somma dei valore negativi,
 * il giocatore nero sta vincendo se il valore assoluto della somma dei valori negativi
 * supera il valore assoluto della somma dei valore positivi i due giocatori stanno pareggiando se la somma dei valori assoluti si equivale.
 * Creare 3 array di tipo partita (definire la dimensione degli array in modo opportuno); il primo conterrà le partite in cui il bianco vince,
 * il secondo le partite in cui il nero vince ed il terzo le partite in parità. Riempire i tre array senza lasciare buchi.
*/
#define P 3

typedef struct {int id_giocatore_bianco;
                int id_giocatore_nero;
                int scacchiera[8][8];
                } Partita;


int chi_vince(Partita p){
    int punti = 0;
    int i,j;
    for(i=0;i<8;i++){
        for(j=0;j<8;j++){
            punti += p.scacchiera[i][j];
        }
    }

    if(punti>0){
        return 1;
    }else if(punti == 0){
        return 0;
    }else{
        return -1;
    }
}

void copia_partita(Partita src, Partita *dest){
    dest->id_giocatore_bianco = src.id_giocatore_bianco;
    dest->id_giocatore_nero = src.id_giocatore_nero;
    int i,j;
    for(i=0;i<8;i++){
        for(j=0;j<8;j++){
            dest->scacchiera[i][j] = src.scacchiera[i][j];
        }
    }
}

int main(){
    Partita partite[P] = {
        {0,2,
            {
                {0,0,0,0,0,0,0,0},
                {5,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,0},
                {0,0,0,0,0,-9,0,0},
                {0,0,0,0,0,0,0,0},
            }
        },
        {0,1,
            {
                {0,0,0,0,0,0,0,0},
                {1,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,0},
                {0,0,0,0,0,-1,0,0},
                {0,0,0,0,0,0,0,0},
            }
        },
        {1,2,
            {
                {0,0,0,0,0,0,0,0},
                {5,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,0},
                {0,0,0,0,0,-1,0,0},
                {0,0,0,0,0,0,0,0},
            }
        }
    };
    Partita vince_bianco[P];
    Partita vince_nero[P];
    Partita pari[P];
    int contatore_bianco=0, contatore_nero=0, contatore_pari=0;

    int i=0;
    int esito;

    for(i=0;i<P;i++){
        esito = chi_vince(partite[i]);
        switch(esito){
            case -1:
                copia_partita(partite[i], &(vince_nero[contatore_nero]));
                contatore_nero++;
                break;
            case 0:
                copia_partita(partite[i], &(pari[contatore_pari]));
                contatore_pari++;
                break;
            case 1:
                copia_partita(partite[i], &(vince_bianco[contatore_bianco]));
                contatore_bianco++;
                break;
            default:
                continue;
        }
    }


}
