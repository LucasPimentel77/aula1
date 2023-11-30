#include "doublelist.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../log.h"

void init(DoublyLinkedList *list){
    //log_trace("init ->");
   // log_info("iniciando a lista");
    Node *no = (Node*)malloc(sizeof(Node));
    if(no == NULL){
        log_error("nao ha memoria suficiente para alocar o no");
        log_debug("no: %p",no);
    }
    no->next = no;
    no->previous = no;
    no->data = NULL;
    list->first = no;
    list->size = 0;
   // log_debug("no(data,next,previous): %p(%p,%p,%p)", no, no->data, no->next, no->previous);
   // log_trace("init <-\n");
}
int enqueue(DoublyLinkedList *list, void *data){
    log_trace("enqueue ->");
    log_info("Inserindo dado no final da fila");

    Node *no = (Node*)malloc(sizeof(Node));
    if(no == NULL){
        log_error("memoria insufisciente para operação");
        log_debug("no: %p",no);
        log_trace("enqueue <-\n");
        return 0;
    }
    Node *aux = list->first->previous;
    aux->next = no;
    no->next = list->first;
    no->previous = aux;
    no->data = data;
    list->first->previous = no;

    list->size++;
    log_debug("new size: %d", list->size);
    log_debug("no(no->next,no->previous): %p(%p,%p)", no, no->next, no->previous);
    log_debug("list->first->previous: %p", list->first->previous);
    log_info("dado inserido com sucesso");
    log_trace("enqueue <-\n");
    return 1;
}
void* dequeue(DoublyLinkedList *list){
    log_trace("dequeue ->");
    log_info("removendo o primeiro dado da fila");
    if(isEmpty(list)){
        log_warn("nao é possivel remover dados com a lista vazia");
        log_trace("dequeue <-\n");
        return NULL;
    }
    Node *aux = list->first->next;
    void *data = aux->data;
    list->first->next = aux->next;
    aux->next->previous = aux->previous;
    free(aux);
    aux = NULL;
    list->size--;
    log_debug("new size: %d", list->size);
    log_info("dado removido com sucesso");
    log_trace("dequeue <-\n");
    return data;
}
void* first(DoublyLinkedList *list){
    log_trace("first ->");
    log_info("informando o primeiro elemento da lista");
    if(isEmpty(list)){
        log_warn("não ha elementos na lista");
        log_trace("first <-\n");
        return NULL;
    }

    log_debug("first: %p", list->first->next);
    log_trace("first <-\n");
    return list->first->next;
}
void* last(DoublyLinkedList *list){
    log_trace("last ->");
    log_info("informando o ultimo elemento da lista");
    if(isEmpty(list)){
        log_warn("não ha elementos na lista");
        log_trace("last <-\n");
        return NULL;
    }

    log_debug("last: %p", list->first->previous);
    log_trace("last <-\n");
    return list->first->previous;
}
int push(DoublyLinkedList *list, void *data){
    log_trace("push ->");
    log_info("inserindo no topo da pilha");
    Node *no = (Node*)malloc(sizeof(Node));
    if(no == NULL){
        log_error("memoria insufisciente para operação");
        log_debug("no: %p",no);
        log_trace("push <-\n");
        return 0;
    }
    Node *prime = list->first->next;
    no->data = data;
    no->next = prime;
    no->previous = list->first;
    prime->previous = no;
    list->first->next = no;
    list->size++;

    log_debug("new size: %d", list->size);
    log_debug("no(no->next,no->previous): %p(%p,%p)", no, no->next, no->previous);
    log_debug("list->first->next: %p", list->first->next);
    log_info("dado inserido com sucesso");
    log_trace("push <-\n");
    return 1;
}
void* pop(DoublyLinkedList *list){
    log_trace("pop ->");
    log_info("removendo o primeiro elemento da pilha");
    void *data = dequeue(list);

    log_trace("pop <-\n");
    return data;
}
void* top(DoublyLinkedList *list){
    log_trace("pop ->");
    log_info("informando o topo da pilha");
    void *data = first(list);

    log_trace("pop <-\n");
    return data;
}
bool isEmpty(DoublyLinkedList *list){
    log_trace("isEmpty ->");
    if(list==NULL){
        log_error("lista não existe");
        log_debug("list: %p", list);
        log_trace("isEmpty <-");
        return 1;
    }
    log_debug("size: %d", list->size);
    log_trace("isEmpty <-");
    if(list->size==0)
        return 1;
    return 0;
}
int indexOf(DoublyLinkedList *list,void *data, compare equal){
    log_trace("indexOf ->");
    log_info("buscando dado na lista");
    if(isEmpty(list)){
        log_warn("lista vazia não ha dados nela");
        log_trace("indexOf <-\n");
        return -1;
    }  

    Node *aux = list->first->next;
    int pos=0;
    log_debug("equal: %d", equal(aux->data,data));
    log_debug("(aux, aux->next, position): (%p, %p, %d)", aux, aux->next, pos);  

    while(pos < list->size && !equal(aux->data,data)){
        aux = aux->next;
        pos++;
        if(aux->data==NULL)
            break;
        log_debug("equal: %d", equal(aux->data,data));
        log_debug("(aux, aux->next, position): (%p, %p, %d)", aux, aux->next, pos);
        log_debug("pos, size: %d, %d", pos, list->size);
    }

    if(pos == list->size){
        log_info("não foi encontrado o valor desejado na lista");
        log_trace("indexOf <-\n");
        return -1;
    }else{
        log_info("no encontrado com sucesso");
        log_trace("indexOf <-\n");
        return pos;
    }
}
Node* getNodeByPos(DoublyLinkedList *list,int pos){
    log_trace("getNodeByPos ->");

    if(isEmpty(list) || pos>=list->size || pos<0){
        log_warn("esta posição não possui nó nenhum, por essa razao retornara trash node");
        log_trace("getNodeByPos <-");
        return list->first;
    }
    Node *aux = list->first;
    for(int cont = 0; cont<=pos; cont++, aux=aux->next )
        log_debug("(aux, aux->next): (%p, %p)", aux, aux->next);

    log_trace("getNodeByPos <-");
    return aux;
}
void* getPos(DoublyLinkedList *list,int pos){
    log_trace("getPos ->");
    log_info("buscando dado na posição %d da lista",pos);

    if(isEmpty(list) || pos>=list->size || pos<0){
        log_warn("esta posição não possui dado nenhum");
        log_trace("getPos <-\n");
        return NULL;
    }
    
    Node *aux = getNodeByPos(list, pos);

    log_trace("getPos <-\n");
    return aux->data;
}
int add(DoublyLinkedList *list, int pos, void *data){
    log_trace("add ->");
    log_info("adicionando elemento na posição %d, caso não exista sera incrementado no final", pos);
    Node *no = (Node *)malloc(sizeof(Node));
    if(no == NULL){
        log_error("espaço insuficiente na memoria para alocaçao de um novo nó");
        log_debug("no: %p", no);
        log_trace("add <-\n");
        return -1;
    }
    no->data = data;

    Node *aux = getNodeByPos(list, pos);

    aux->previous->next = no;
    no->previous = aux->previous;
    no->next = aux;
    aux->previous = no;

    list->size++;
    log_debug("new size: %d", list->size);
    log_debug("no(data,next,previous): %p(%p,%p,%p)", no, no->data, no->next, no->previous);
    log_info("dados inserido com sucesso");    
    log_trace("add <-\n");
    return 1;
}
int addAll(DoublyLinkedList *listDest, int pos, DoublyLinkedList *listSource){
    log_trace("addAll ->");
    log_info("adicionando lista na posição %d", pos);
    if(isEmpty(listSource)){
        log_warn("não é possivel inserir uma lista vazia");
        log_trace("addAll <-;\n");
        return 0;
    }

    Node *aux = getNodeByPos(listDest, pos);

    aux->previous->next = listSource->first->next;
    listSource->first->next->previous = aux->previous;
    listSource->first->previous->next = aux;
    aux->previous = listSource->first->previous;

    listDest->size = listDest->size + listSource->size;
    log_debug("new size: %d", listDest->size);
    log_debug("no->next, no->previous): (%p, %p)", listSource->first->previous->next, listSource->first->next->previous);
    log_info("dado inserido com sucesso");  
    log_trace("addAll <-\n");
    return 1;
}
void* removePos(DoublyLinkedList *list, int pos){
    log_trace("removePos ->");
    log_info("removendo dado da posição %d",pos);
    if(isEmpty(list)){
        log_warn("não é possível remover nada com a lista vazia");
        log_trace("removePos <-\n");
        return NULL;
    }
    if(pos<0 || pos>=list->size){
        log_warn("essa posição não existe");
        log_trace("removePos <-\n");
        return NULL;
    }

    Node *aux = getNodeByPos(list, pos);
    void *data = aux->data;
    aux->previous->next = aux->next;
    aux->next->previous = aux->previous;
    free(aux);
    aux = NULL;

    list->size--;
    log_debug("new size: %d", list->size);
    log_info("dado removido com sucesso");
    log_trace("removePos <-\n");
    return data;
}
bool removeData(DoublyLinkedList *list, void *data, compare equal){
    log_trace("removeData ->");
    log_info("removendo dado");
    
    int j = indexOf(list,data,equal);
    if(j >= 0){
        removePos(list,j);
        log_trace("removeData <-\n");
        return true;
    }
    log_trace("removeData <-\n");
    return false;
}
void show(DoublyLinkedList *list, printNode print){
    Node *aux = list->first->next;
    if(isEmpty(list))
        printf("LISTA VAZIA");
    
    for(int i=0; i<list->size; i++){
        print(aux->data);
        aux = aux->next;
    }
}
void showMem(DoublyLinkedList *list);