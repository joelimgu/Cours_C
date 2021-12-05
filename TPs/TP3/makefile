
all: forth

test: main.o stack.o command_list.o
	gcc -o forth main.o command_list.o stack.o

forth: main.o stack.o command_list.o
	gcc -o forth main.o command_list.o stack.o

main.o: main.c stack.h
	gcc -c main.c

stack.o: stack.c stack.h
	gcc -c stack.c

command_list.o: command_list.c command_list.h
	gcc -c command_list.c

clean:
	rm *.o forth