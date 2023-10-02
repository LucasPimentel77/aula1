all: clear ponteiro ponteiro_duplo

ola: clear
	@echo ==========================
	@echo      PROGRAMA OLA
	@echo ==========================
	@echo Compilando o programa olamundo
	@gcc olamundo.c -o ola > /dev/null 2>&1
	@echo Tornando o programa olamundo executável
	@chmod +x ola > /dev/null 2>&1
	@echo Executando o programa olamundo
	@./ola
	@echo ======================================================

ponteiro: clear
	@echo
	@echo ==========================
	@echo      PONTEIRO SIMPLES
	@echo ==========================
	@echo Compilando o programa ponteiros
	gcc ponta/pica.c -o ponteiro 
	@echo Tornando o arquivo executável
	chmod +x ponteiro 
	@echo Executando o programa ponteiros
	@echo ======================================================
	@echo
	./ponteiro

ponteiro_duplo:
	@echo
	@echo ==========================
	@echo      PONTEIRO DUPLO
	@echo ==========================
	@echo Compilando o programa ponteiro duplo
	gcc ponteiroduplo.c -o ponteiro_duplo
	@echo Tornando o arquivo executável
	chmod +x ponteiro_duplo
	@echo Executando o programa ponteiro duplo
	@echo ======================================================
	@echo
	./ponteiro_duplo

clear:

	@rm -f ponteiro
	@rm -f ponteiro_duplo
	@rm -f LinkedList
	@rm -f ola

help:
	@echo
	@echo ==========================
	@echo      	   AJUDA
	@echo ==========================
	@echo "all              | Compila e executa tudo"
	@echo "ponteiro         | Ponteiro Simples"
	@echo "ponteiro_duplo   | Ponteiro Duplo"
	@echo "clear            | Apaga todos os programas"
	@echo =================================================

lista_encadeada: clear
	@echo
	@echo =====================================
	@echo      lista simplesmente encadeada
	@echo =====================================
	@echo Compilando o programa lista encadeada
	@gcc log.c log.h lista_simples/LinkedList.c lista_simples/LinkedList.h lista_simples/main.c -o lista_encadeada
	@echo Tornando o arquivo executável
	@chmod +x lista_encadeada
	@echo Executando o programa lista simples
	@echo ======================================================
	@echo
	@./lista_encadeada
	
duplo: clear
	@echo
	@echo =====================================
	@echo      lista dupla
	@echo =====================================
	@echo Compilando o programa lista encadeada
	@gcc log.c log.h lista_dupla/doublelist.c lista_dupla/doublelist.h lista_dupla/main.c -o duplo 
	@chmod +x duplo
	@echo Executando o programa lista dupla
	@echo ======================================================
	@echo
	@./duplo
	
geral: clear
	@echo
	@echo =================================
	@echo      lista generalizada
	@echo =================================
	@echo Compilando o programa geral
	@gcc lista_generalizada/listagen.c lista_generalizada/listagen.h lista_generalizada/menugen.c log.h log.c -o geral
	@echo Tornando o arquivo executável
	@chmod +x geral
	@echo Executando o programa geral
	@echo ======================================================
	@echo
	@./geral

hash: clear
	@echo
	@echo =================================
	@echo      tabela hash
	@echo =================================
	@echo Compilando o programa hash
	@gcc tabela_hash/hash.c tabela_hash/hash.h tabela_hash/hashtest.c log.h log.c -o geral
	@echo Tornando o arquivo executável
	@chmod +x hash
	@echo Executando o programa hash
	@echo ======================================================
	@echo
	@./geral	