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

void init(LinkedList *list); //iniciar a lista
int enqueue(LinkedList *list, void *data); //inserir no final (enfileirar)
void* dequeue(LinkedList *list); //retirar do começo (desenfileirar)
void* first(LinkedList *list); // vizualizar o primeiro elemento da lista
void* last(LinkedList *list); // vizualizar o último elemento da lista
int push(LinkedList *list, void *data); //
void* pop(LinkedList *list);
void* top(LinkedList *list);
bool isEmpty(LinkedList *list);
int indexOf(LinkedList *list, void *data, compare equal);
void* getPos(LinkedList *list, int pos);
Node* getNodeByPos(LinkedList *list, int pos);
int add(LinkedList *list, int pos, void *data);
int addAll(LinkedList *listDest, int pos, LinkedList *listSource);
void* removePos(LinkedList *list, int pos);
bool removeData(LinkedList *list, void *data, compare equal);

#endif