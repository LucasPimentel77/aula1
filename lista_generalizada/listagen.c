#include <stdio.h>
#include <stdlib.h>
#include "listagen.h"

int addAtom(Node **list, int data){
    log_trace("addAtom ->");
    Node *no = (Node *)malloc(sizeof(Node));
    if(no==NULL){
    log_warn("memoria insuficiente"); 
    log_trace("addAtom <-\n"); 
    return -1;
    }
    no->type = 0;
    no->atomList.atom = data;
    no->tail = NULL;

    if(*list==NULL)
        *list->tail = no;
    else{
        Node *aux = NULL;
        for(aux = *list; aux->tail != NULL; aux = aux->tail);
        aux->tail = no;
    }

    log_trace("addAtom <-\n");
    return 1;
}
int addList(Node **list, Node **subList){
    log_trace("addList ->");
    
    log_trace("addList <-\n");
}
Node* head(Node *list);
Node* tail(Node *list);
void showGeneralizedList(Node *list);
int depth(Node *list);