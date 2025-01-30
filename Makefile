path = "casos_teste_v3/caso_teste_muito_pequeno_1.txt"

all:
	clear
	make comp
	./prog

comp:
	gcc *.c -o prog

valg: 
	make comp
	valgrind prog