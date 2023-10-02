#include <stdio.h>
#include <stdlib.h>
#include "hash.h"
#include "../lista_dupla/doublelist.h"

void initHash(HashStruct *hashStruct){
    log_trace("initHash ->");
    for(int i=0;i<=MAX; i++)
        init(&())
    log_trace("initHash <-\n");
}
bool isHashEmpty(HashStruct *hashStruct);
int hash(char *key);
int put(HashStruct *hashStruct, char *key, void *data, compare equal);
bool containsKey(HashStruct *hashStruct, char *key, compare equal);
void* get(HashStruct *hashStruct, char *key, compare equal);
void* removeKey(HashStruct *hashStruct, char *key, compare equal);
void showHashStruct(HashStruct *hashStruct);