#include <stdio.h>
#include <stdlib.h>
#include "../log.h"
#include "hash.h"

void initHash(HashStruct *hashStruct){
    log_trace("initHash ->");
    for(int i=0;i<=MAX; i++)
        init(&(hashStruct->hashes[i]));
    hashStruct->size=0;
    log_trace("initHash <-\n");
}
bool isHashEmpty(HashStruct *hashStruct){
    return (hashStruct->size==0);
}
int hash(char *key){
    int som = 0;
    for(int i=0; key[i]!=0; i++)
        som += key[i] * (i+1);
    return som%MAX;
}
int put(HashStruct *hashStruct, char *key, void *data, compare equal){
    if (!containsKey(hashStruct, key, equal)) {
        int res = enqueue(&hashStruct->hashes[hash(key)],data);
        hashStruct->size+=res;
        return res;
    }
    return 0;
}
bool containsKey(HashStruct *hashStruct, char *key, compare equal){
    int hashvalue = hash(key);
    int pos = indexOf(&hashStruct->hashes[hashvalue], key, equal);
    return (pos!=-1)?true:false;
}
void* get(HashStruct *hashStruct, char *key, compare equal){

}
void* removeKey(HashStruct *hashStruct, char *key, compare equal);
void showHashStruct(HashStruct *hashStruct);