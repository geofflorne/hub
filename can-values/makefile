program: can_values.o hiredis.o main.o
	gcc -o can_values.o hiredis.o main.o

main.o: main.c main.h hiredis.h
	gcc -c main.c

hiredis.o: hiredis.c hiredis.h
	gcc -c hiredis.c -I /usr/local/include/hiredis/ -L /usr/local/lib/ -l hiredis

can_values.o: can_values.c
	gcc -c can_values.c

make clean:
	rm program
