
all: forth

test: symbol_list.o interpreter.o tests.c command_list.o stack.o
	gcc -o test tests.c symbol_list.o interpreter.o stack.o command_list.o && ./test

forth: main.o stack.o command_list.o interpreter.o
	gcc -o forth main.o command_list.o stack.o interpreter.o

main.o: main.c stack.h
	gcc -c main.c

interpreter.o: interpreter.c interpreter.h
	gcc -c interpreter.c

stack.o: stack.c stack.h
	gcc -c stack.c

command_list.o: command_list.c command_list.h
	gcc -c command_list.c

symbol_list.o: symbol_list.c symbol_list.h
	gcc -c symbol_list.c

clean:
	rm -f *.o forth test