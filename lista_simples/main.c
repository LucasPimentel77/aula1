#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "../log.h"

bool compara(void *data1, void *data2) {
    int *d1 = (int*)data1;
    int *d2 = (int*)data2;
    
    return (*d1==*d2)?true:false;
}

int equal(void *data1, void *data2){
	int *d1 = (int*)data1;
	int *d2 = (int*)data2;

	if(*d1 < *d2){
		return -1;
	}
	if(*d1 == *d2){
		return 0;
	}
	return *d2;
}

int main() {
	FILE *file = fopen("program.log","w");
	
	log_set_level(LOG_ERROR);
	log_add_fp(file, LOG_TRACE);

	LinkedList lista;
	init(&lista);
	int *numero = (int*)malloc(sizeof(int));
	*numero = 15;
	order_add(&lista, numero, equal);

	int *kw = dequeue(&lista);
		printf("%d\n",*kw);

	int *numero1 = (int*)malloc(sizeof(int));
	*numero1 = 13;
	order_add(&lista, numero1, equal);

	int *numero2 = (int*)malloc(sizeof(int));
	*numero2 = 14;
	order_add(&lista, numero2, equal);

	int *numero3 = (int*)malloc(sizeof(int));
	*numero3 = 12;
	order_add(&lista, numero3, equal);

	kw = dequeue(&lista);
		printf("%d\n",*kw);

		kw = dequeue(&lista);
		printf("%d\n",*kw);

		kw = dequeue(&lista);
		printf("%d\n",*kw);

	int *numero4 = (int*)malloc(sizeof(int));
	*numero4 = 17;
	order_add(&lista, numero4, equal);
    
	for(int i=0; i<0; i++){
		kw = dequeue(&lista);
		printf("%d\n",*kw);
	}
	free (numero);
	printf("\nprograma deu certo\n");
	return EXIT_SUCCESS;
}
