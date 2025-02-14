path = "casos_teste_v3/caso_teste_muito_pequeno_1.txt"

all:
	clear
	make comp
	bin/prog

comp:
	clear
	gcc -lm *.c -o bin/prog

val:
	clear
	make comp
	valgrind bin/prog