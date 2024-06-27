all:
	@echo "************load symbol mode"
	gcc -shared -o libsum.so sum.c
	gcc -o runme1 load_symbol.c
	./runme1
	@echo "************dynamic link mode"
	gcc -o runme2 dynamic_link.c -L. -lsum
	LD_LIBRARY_PATH=. ./runme2