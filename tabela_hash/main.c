#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../log.h"
#include "hash.h"
#define ALTURA 100
#define LARGURA 300

bool compara(void *data1, void *data2) {
	int d1 = strcmp((char*)data1,(char*)data2);
	return (d1==0)?true:false;
}

void impressao(void *data) {
	char *dado = (char*)data;
	printf("%s - ",dado);
}

int main(){
    HashStruct lista;
    int i = 0;

    FILE *words = fopen("ListaDePalavrasPT.txt","r");
    FILE *teste = fopen("imagem.ppm","w");
	
	log_set_level(LOG_ERROR);


    initHash(&lista);

    
    char verso[50];
    char bala[30000][50];
    while(fgets(verso,50,words) != NULL){
        fscanf(words,"%s",bala[i]);
        put(&lista, bala[i], bala[i], compara);
        i++;
    }

    int maior = 0;

    fprintf(teste,"P3\n%d %d\n255\n",LARGURA, ALTURA);
    for(i=0; i<MAX;i++){
        if((&lista)->hashes[i].size > maior)
            maior = (&lista)->hashes[i].size;
    }
    printf("maior numero de colisões: %d \n",maior);

    for(i=0; i<(ALTURA*LARGURA);i++){
        int t = (255/maior)*(&lista)->hashes[i].size;
        fprintf(teste,"%d 0 100 \n",t);
    }

return 0;
}