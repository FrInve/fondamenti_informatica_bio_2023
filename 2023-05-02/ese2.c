/*
 * Esercitazione del 2023-05-02, esercizio 2 
 * 
 * Definire una struttura dati stack. 
 * Una struttura dati stack (tradotto letteralmente come "pila") è una collezione di elementi in cui l'accesso ad ogni elemento è limitato all'ultimo elemento inserito, chiamato cima dello stack. In altre parole, è possibile aggiungere nuovi elementi solo in cima allo stack e rimuovere solo l'ultimo elemento inserito (LIFO, ovvero "Last In First Out").
 * 
 * In una struttura dati stack, è possibile eseguire due operazioni principali:
 * - Push: aggiunge un nuovo elemento in cima allo stack
 * - Pop: rimuove l'ultimo elemento inserito (cioè l'elemento in cima allo stack)
 * - Peek: restituisce il valore in cima allo stack
*/

#include <stdio.h>
#define MAX 10

typedef struct {
    int elem[MAX];
    int presenti;
} stack_t;

void print_stack(stack_t);
int push(int, stack_t*, int);
int pop(int*, stack_t*);
int peek(stack_t);

void print_stack(stack_t s){
    int i;
    printf("num elementi: %d\n", s.presenti);
    printf("Elementi: ");
    for(i = 0; i<s.presenti; i++) {
        printf("%d ", s.elem[i]);
    }
    printf("\n");
}

int push(int elem, stack_t* s, int max){
    if ((*s).presenti == max){
        return 1;
    }
    else{
        (*s).elem[(*s).presenti] = elem;
        (*s).presenti += 1;
        return 0;
    }
}

int pop(int* elem, stack_t* s){
    if ((*s).presenti == 0){
        return 1;
    }
    else{
        *elem = (*s).elem[(*s).presenti - 1];
        (*s).presenti -= 1;
        return 0;
    }
}

int peek(stack_t s){
    if (s.presenti == 0){
        return -1;
    }
    else{
        return s.elem[s.presenti-1];
    }
}

void print_top(stack_t s){
    printf("Elem on top: %d\n",peek(s));
}

int main()
{
    stack_t stack;
    stack.presenti = 0;
    int elem;
    
    print_stack(stack);
    push(1, &stack, MAX);
    print_stack(stack);
    push(2, &stack, MAX);
    print_stack(stack);
    print_top(stack);
    if(pop(&elem, &stack) == 0){
        printf("\npop1: \n");
        print_stack(stack);
        printf("elem: %d\n\n", elem);
    }
    if(pop(&elem, &stack) == 0){
        printf("\npop2: \n");
        print_stack(stack);
        printf("elem: %d\n\n", elem);
    }
    if(pop(&elem, &stack) == 0){
        printf("\npop3: \n");
        print_stack(stack);
        printf("elem: %d\n\n", elem);
    }

}