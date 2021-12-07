
all: forth

test: interpreter.o tests.c symol_list.o command_list.o stack.o
	gcc -o test tests.c interpreter.o stack.o symol_list.o command_list.o && ./test

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

symol_list.o: symol_list.c symol_list.h
	gcc -c symol_list.c

clean:
	rm -f *.o forth test