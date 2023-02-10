# Makefile

all: 
	gcc -o clox-vm *.c

clean:
	rm -f clox-vm