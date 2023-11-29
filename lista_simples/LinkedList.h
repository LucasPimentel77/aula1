#ifndef DataStructure_LinkedList_h
#define DataStructure_LinkedList_h
#include <stdbool.h>

typedef struct Node {
  void *data;
  struct Node *next;
}Node;

typedef struct LinkedList {
  Node *first;
  int size;
}LinkedList;

typedef bool (*compare)(void*,void*);
typedef int (*confront)(void*, void*);

void init(LinkedList *list); //iniciar a lista
int enqueue(LinkedList *list, void *data); //inserir no final (enfileirar)
void* dequeue(LinkedList *list); //retirar do começo (desenfileirar)
void* first(LinkedList *list); // vizualizar o primeiro elemento da fila
void* last(LinkedList *list); // vizualizar o último elemento da fila
int push(LinkedList *list, void *data); //insere no topo da pilha
void* pop(LinkedList *list); // remove o topo da pilha
void* top(LinkedList *list); // vizualiza o topo da pinha
int order_add(LinkedList *list, void *data, confront menor);
bool isEmpty(LinkedList *list); // verifica se a lista esta vazia
int indexOf(LinkedList *list, void *data, compare equal); // procura um elemento da lista com um dado e retorna posição
void* getPos(LinkedList *list, int pos); // procura um elemento da lista pela posição e retorna o dado
Node* getNodeByPos(LinkedList *list, int pos); // 
int add(LinkedList *list, int pos, void *data);
int addAll(LinkedList *listDest, int pos, LinkedList *listSource);
void* removePos(LinkedList *list, int pos);
bool removeData(LinkedList *list, void *data, compare equal);

#endif