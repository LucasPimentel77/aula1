#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "doublelist.h"
#include "log.h"

bool compara(void *data1, void *data2) {
	int *d1 = (int*)data1;
	int *d2 = (int*)data2;
	return (*d1==*d2)?true:false;
}

void impressao(void *data) {
	int *dado = (int*)data;
	printf("%d - ",*dado);
}

int main() {
	FILE *file = fopen("program.log","w");
	
	log_set_level(LOG_INFO);
	log_add_fp(file, LOG_TRACE);

	DoublyLinkedList lista;
	init(&lista);
	int *numero = malloc(sizeof(int));
	*numero = 10;
	enqueue(&lista, numero);

	int *numero1 = malloc(sizeof(int));
	*numero1 = 11;
	push(&lista, numero1);

	int *numero2 = malloc(sizeof(int));
	*numero2 = 13;
	add(&lista, 3, numero2);

	int *n1 = malloc(sizeof(int));
	int *n2 = malloc(sizeof(int));
	*n1 = 14;
	*n2 = 11;

	int lst = indexOf(&lista,n1,compara);
	if(lst>=0)
		printf("posição: %d\n\n", lst);
	else{
		printf("elemento nao encontrado\n\n");
	}

	int fst = indexOf(&lista,n2,compara);
	printf("posição: %d\n\n",fst );

	numero = dequeue(&lista);
	printf("numero: %d\n\n", *numero);

	numero = pop(&lista);
	printf("numero: %d\n\n", *numero);

	
	free (numero);
	printf("programa deu certo\n");
	return 0;
}
