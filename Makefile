path = "casos_teste_v3/caso_teste_muito_pequeno_1.txt"

all:
	clear
	make comp
	bin/prog

comp:
	gcc *.c -o bin/prog

valg: 
	make comp
	valgrind prog