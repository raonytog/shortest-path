path = "casos_teste_v3/caso_teste_muito_pequeno_1.txt"

all:
	clear
	make comp
	make run

comp: *.c
	clear
	@ gcc -lm *.c -o bin/prog

run:
	clear
	make comp
	@ bin/prog

time:
	clear
	make comp
	time bin/prog

val:
	clear
	make comp
	valgrind bin/prog