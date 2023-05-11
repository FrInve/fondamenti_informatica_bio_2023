/*
 * Scrivere in C un programma "dizionario" che implementi,
 * con un sistema di funzioni, le seguenti specifiche.
 * Data una stringa contenente varie parole separate da spazi,
 * salvare ogni parola nel dizionario, tenendo conto della frequenza di ogni parola.
 * Alla fine della computazione, stampare la parola più frequente.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 50
#define MAX_DICT_ENTRIES 100

// struttura per rappresentare una voce del dizionario
typedef struct {
    char word[MAX_WORD_LENGTH];
    int frequency;
} DictEntry;

// struttura per rappresentare il dizionario
typedef struct {
    DictEntry entries[MAX_DICT_ENTRIES];
    int num_entries;
} Dictionary;

// funzione per rimuovere i caratteri di punteggiatura da una parola
void remove_punctuation(char *word) {
    char *src = word, *dst = word;
    while (*src) {
        if (ispunct((unsigned char)*src)) {
            src++;
        } else if (src == dst) {
            src++;
            dst++;
        } else {
            *dst++ = *src++;
        }
    }
    *dst = '\0';
}

// funzione per trovare una voce del dizionario per parola
DictEntry *find_entry(Dictionary *dict, const char *word) {
    for (int i = 0; i < dict->num_entries; i++) {
        if (strcmp(dict->entries[i].word, word) == 0) {
            return &dict->entries[i];
        }
    }
    return NULL;
}

// funzione per aggiungere una parola al dizionario
void add_word(Dictionary *dict, const char *word) {
    DictEntry *entry = find_entry(dict, word);
    if (entry == NULL) {
        // la parola non esiste ancora nel dizionario
        if (dict->num_entries < MAX_DICT_ENTRIES) {
            // c'è ancora spazio per una nuova voce nel dizionario
            entry = &dict->entries[dict->num_entries++];
            strcpy(entry->word, word);
            entry->frequency = 1;
        } else {
            // il dizionario è pieno, non possiamo aggiungere altre voci
            fprintf(stderr, "Errore: il dizionario è pieno\n");
            exit(EXIT_FAILURE);
        }
    } else {
        // la parola esiste già nel dizionario, incrementiamo la frequenza
        entry->frequency++;
    }
}

// funzione per trovare la parola più frequente nel dizionario
char *find_most_frequent_word(Dictionary *dict) {
    char *most_frequent_word = NULL;
    int max_frequency = 0;
    for (int i = 0; i < dict->num_entries; i++) {
        if (dict->entries[i].frequency > max_frequency) {
            most_frequent_word = dict->entries[i].word;
            max_frequency = dict->entries[i].frequency;
        }
    }
    return most_frequent_word;
}

int main() {
    char input_string[1000];
    printf("Inserisci una stringa di parole: ");
    fgets(input_string, sizeof(input_string), stdin);

    Dictionary dict = {0};

    // separiamo la stringa in parole e aggiungiamole al dizionario
    char *word = strtok(input_string, " ");
    while (word != NULL) {
        remove_punctuation(word);
        add_word(&dict, word);
        word = strtok(NULL, " ");
    }

    // troviamo la parola più frequente nel dizionario e la stampiamo
    char *most_frequent_word = find_most_frequent_word(&dict);
    printf("%s",most_frequent_word);
}
