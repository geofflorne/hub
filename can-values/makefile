make can: main.c hiredis_server.c
	gcc hiredis_server.c main.c -I /usr/local/include/hiredis/ -L /usr/local/lib/ -l hiredis -o can

make clean:
	rm can
