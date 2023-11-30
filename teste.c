#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node *next;
}Node;

typedef struct LinkedList{
    int size;
    Node *first;
}LinkedList;

void initLista(LinkedList *lista){
    lista->size = 0;
    lista->first = NULL;
}

void inserir_ordenado(LinkedList *lista, int data){
    Node *novo = (Node*)malloc(sizeof(Node));
    if(novo == NULL){
        printf("ERROR:  ao alocar memória!");
    }else{
        novo->data = data;
        if(lista->size==0){
            novo->next = NULL;
            lista->first = novo;
        }else if(data < lista->first->data){
            novo->next = lista->first;
            lista->first = novo;
        }else{
            Node *aux = lista->first;
            while(aux->next  && novo->data >= aux->next->data )
                aux = aux->next;
            novo->next = aux->next;
            aux->next = novo;
        }
        lista->size++;
    }
}

int remove_inicio(LinkedList *lista){
    if(lista->size == 0){
        printf("nao e possivel remover lista vazia\n");
        return 0;
    }
    Node *aux = lista->first;
    int num = aux->data;
    //free(&aux);
    lista->first = lista->first->next;
    lista->size--;
    return num;
} 

int main(){
    LinkedList lista;

    initLista(&lista);
    inserir_ordenado(&lista, 10);
    inserir_ordenado(&lista, 9);
    inserir_ordenado(&lista, 11);
    inserir_ordenado(&lista, 8);
    inserir_ordenado(&lista, 12);
    inserir_ordenado(&lista, 7);

    for(int i=0; i<6; i++)
        printf("%d\n",remove_inicio(&lista));
    return 0;
}