#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "../log.h"

bool compara(void *data1, void *data2) {
    int *d1 = (int*)data1;
    int *d2 = (int*)data2;
    
    return (*d1==*d2)?true:false;
}

int main() {
	FILE *file = fopen("program.log","w");
	
	log_set_level(LOG_INFO);
	log_add_fp(file, LOG_TRACE);

	LinkedList lista;
	init(&lista);
	int *numero = malloc(sizeof(int));
	*numero = 10;
	enqueue(&lista, numero);

	printf("%p\n",(&lista)->first->next);
	int *numero1 = malloc(sizeof(int));
	*numero1 = 11;
	enqueue(&lista, numero1);

	*numero1 = 12;
	push(&lista, numero1);
    
    numero = (int*)first(&lista);
	printf("%d\n", *numero );
	printf("%p\n",(&lista)->first->next);

	numero = (int*)last(&lista);
	printf("%d\n", *numero );

	numero = (int*)pop(&lista);
	printf("%d removido\n", *numero);

	free (numero);
	printf("\nprograma deu certo\n");
	return EXIT_SUCCESS;
}
