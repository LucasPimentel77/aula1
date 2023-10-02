#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "LinkedList.h"
#include "../log.h"

void init(LinkedList *list){
    log_trace("init ->");
    log_info("iniciando a lista");
    list->first = NULL;
    list->size = 0;
    log_debug("list->first: %p",list->first);
    log_debug("list->size: %d",list->size);
    log_trace("init <-\n");
}
int enqueue(LinkedList *list, void *data){
    log_trace("enqueue ->");
    log_info("adicionando na lista");
    Node  *no = (Node*)malloc(sizeof(Node));
    if(no==NULL){
        log_debug ("no = %p", no);
        log_error ("memória insuficiente para operação");
        log_trace("enqueue <-\n");
        return 0;
    }
    no->next = NULL;
    no->data = data;

    if(isEmpty(list))
        list->first = no;
    else{
        Node *aux = (Node*)malloc(sizeof(Node));
        aux = list->first;
        log_debug ("(aux,aux->next) = (%p,%p)", aux, aux->next);
        while(aux->next !=NULL){
            log_debug ("(aux,aux->next) = (%p,%p)", aux, aux->next);    
            aux = aux->next;
        }
        aux->next = no;
        log_debug ("(aux,aux->next): (%p,%p)", aux, aux->next);
    }    
    list->size++;
    log_debug("no(data,next): %p(%p,%p)", no, no->data, no->next);
    log_debug("new size: %d", list->size);
    log_info("dado inserido com sucesso");
    log_trace ("enqueue <-\n");
    return 1;    
} 
void* dequeue(LinkedList *list){
    log_trace("dequeue ->");
    log_info("Removendo o primeiro dado da fila");

    if(isEmpty(list)){
        log_warn("AVISO: não é possível retirar elementos com a lista vazia");
        log_trace("dequeue <-");
        return NULL;
    }
    log_debug("list->first: %p", list->first);
    Node *aux = list->first;
    void *data = aux->data;
    list->first = list->first->next;
    list->size--;
    free(aux);
    log_debug("no removido: %p", data);
    log_debug("new size: %d", list->size);
    log_info("dado removido com sucesso");
    log_trace("dequeue <-\n");
    return data;
} 
void* first(LinkedList *list){
    log_trace("first ->");
    log_info("mostrando o primeiro elemnto da fila");
    if(isEmpty(list)){
        log_warn("lista está vazia");
        log_trace("first <-");
        return NULL;
    }
    log_debug("first: %p", list->first);
    log_trace("first <-\n");
    return list->first->data;
} 
void* last(LinkedList *list){
    log_trace("last ->");
    log_info("mostrando o ultimo elemnto da fila");
    if(isEmpty(list)){
        log_warn("lista está vazia");
        log_trace("last <-");
        return NULL;
    }
    Node *aux = list->first;
    while(aux->next!=NULL){
        log_debug("(aux,aux->next): (%p,%p)", aux, aux->next);
        aux = aux->next;
    }    
    log_debug("last: %p", aux->data);
    log_trace("last <-\n");
    return aux->data;
} 
int push(LinkedList *list, void *data){
    log_trace("push ->");
    log_info("adicionando no topo da pilha");
    Node *no = malloc(sizeof(Node));
    if(no==NULL){
        log_debug ("no = %p", no);
        log_error ("memória insuficiente para operação");
        log_trace("enqueue <-\n");
        return 0;
    }
    no->data = data;

    Node *aux = list->first;
    list->first = no;
    no->next = aux;

    list->size++;
    log_debug("no(data,next): %p(%p,%p)", no, no->data, no->next);
    log_debug("new size: %d", list->size);
    log_info("dado inserido com sucesso");
    log_trace("push <-\n");
}
void* pop(LinkedList *list){
    log_trace("pop ->");
    log_info("removendo o topo da pilha");

    void *aux = dequeue(list);

    log_trace("pop <-\n");
    return(aux);
}
void* top(LinkedList *list){
    log_trace("top ->");
    log_info("mostrando o topo da pilha");
    void *aux = first(list);

    log_trace("top <-\n");
    return(aux);
}

bool isEmpty(LinkedList *list){
    log_trace("isEmpty ->");
    if(list==NULL){
        log_error("parâmetro inválido");
        log_debug("lista: %p",list);
        log_trace("isEmpty <-");
        return true;
    }
    log_debug("list->size = %d",list->size);
    log_trace("isEmpty <-");
    if(list->size==0)
        return true;
    return false;
}

int indexOf(LinkedList *list, void *data, compare equal);
void* getPos(LinkedList *list, int pos);
Node* getNodeByPos(LinkedList *list, int pos);
int add(LinkedList *list, int pos, void *data);
int addAll(LinkedList *listDest, int pos, LinkedList *listSource);
void* removePos(LinkedList *list, int pos);
bool removeData(LinkedList *list, void *data, compare equal);
