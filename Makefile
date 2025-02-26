# opcoes de caminho
path1 = "casos_teste_v3/caso_teste_muito_pequeno_1.txt"
path2 = "casos_teste_v3/caso_teste_muito_pequeno_2.txt"
path3 = "casos_teste_v3/caso_teste_pequeno_1.txt"
path4 = "casos_teste_v3/caso_teste_pequeno_2.txt"
path5 = "casos_teste_v3/caso_teste_pequeno_3.txt"
path6 = "casos_teste_v3/caso_teste_pequeno_4.txt"
path7 = "casos_teste_v3/caso_teste_medio_1.txt"
path8 = "casos_teste_v3/caso_teste_medio_2.txt"
path8 = "casos_teste_v3/caso_teste_medio_3.txt"
path8 = "casos_teste_v3/caso_teste_medio_4.txt"

# entrada e saida
input = $(path8)
output = "saida.txt"

all:
	clear
	make compPQ
	make runPQ

# Compila a fila de prioridade
compPQ:
	@ gcc -lm main.c PQ.c node.c utils.c djikstraPQ.c -o bin/progPQ

# Compila a lista
compList:
	@ gcc -lm main.c list.c node.c utils.c djikstraList.c -o bin/progList

# executa o codigo da fila de prioridade
runPQ:
	clear
	@ bin/progPQ $(input) $(output)

# executa o codigo da lista
runList:
	clear
	@ bin/progList $(input) $(output)

# valgrind da fila de prioridade
valPQ:
	clear
	make compPQ
	valgrind bin/progPQ $(input) $(output)

# valgrind da lista
valList:
	clear
	make compList
	valgrind bin/progList $(input) $(output)