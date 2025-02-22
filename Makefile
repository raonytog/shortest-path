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

input = $(path8)
output = "saida.txt"

all:
	clear
	make compPQ
	make runPQ

compPQ:
	@ gcc -lm main.c PQ.c node.c utils.c djikstraPQ.c -o bin/progPQ

compList:
	@ gcc -lm main.c list.c node.c utils.c djikstraList.c -o bin/progList

runPQ:
	clear
	@ bin/progPQ $(input) $(output)

runList:
	clear
	@ bin/progList $(input) $(output)

valPQ:
	clear
	make compPQ
	valgrind bin/progPQ $(input) $(output)

valList:
	clear
	make compList
	valgrind bin/progList $(input) $(output)