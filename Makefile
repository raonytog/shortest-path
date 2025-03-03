# Compila o codigo APENAS para execução do djikstra com a heap
all:
	clear
	make compPQ

# Compila a fila de prioridade
compPQ: main.c PQ.c node.c utils.c djikstraPQ.c
	@ gcc -lm main.c PQ.c node.c utils.c djikstraPQ.c -o trab1

# Compila a lista
compList: main.c PQ.c node.c utils.c djikstraList.c
	@ gcc -lm main.c list.c node.c utils.c djikstraList.c -o trab1

# 	Todos os macros abaixo funcionam a partir da entrada e saida estabelecida como padrão no
# arquivo makefile. Caso queira mudar o arquivo de saida, altere a variavel output com o nome
# desejado. 
# 	O mesmo para vale para a entrada, basta alterar a variavel input. Ambos alteraveis 
# logo abaixo, com as entradas e saidas pré estabelecidas 

# opcoes de caminho de entradas padroes liberadas 
path1 = "casos_teste_v3/caso_teste_muito_pequeno_1.txt"
path2 = "casos_teste_v3/caso_teste_muito_pequeno_2.txt"
path3 = "casos_teste_v3/caso_teste_pequeno_1.txt"
path4 = "casos_teste_v3/caso_teste_pequeno_2.txt"
path5 = "casos_teste_v3/caso_teste_pequeno_3.txt"
path6 = "casos_teste_v3/caso_teste_pequeno_4.txt"
path7 = "casos_teste_v3/caso_teste_medio_1.txt"
path8 = "casos_teste_v3/caso_teste_medio_2.txt"
path9 = "casos_teste_v3/caso_teste_medio_3.txt"
path10 = "casos_teste_v3/caso_teste_medio_4.txt"

# entrada e saida
input = $(path9)
output = "saida.txt"

# executa o codigo da fila de prioridade
runPQ: trab1
	clear
	@ trab1 $(input) $(output)

# executa o codigo da lista
runList: trab1
	clear
	@ trab1 $(input) $(output)


# valgrind da fila de prioridade
valpq:
	clear
	make compPQ
	valgrind trab1 $(input) $(output)

# valgrind da lista
vallist:
	clear
	make compList
	valgrind trab1 $(input) $(output)


# compila e executa diretamente
pq:
	make compPQ
	make runPQ

list:
	make compList
	make runList