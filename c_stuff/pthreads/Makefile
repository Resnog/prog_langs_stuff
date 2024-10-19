INCLUDES = -I/includes

FILE= main.c
EXAMPLE=1
default:
			@clang ${FILE} ${INCLUDES} -lpthread -o run.o -w
			@./run.o

example:
			@clang src/example${EXAMPLE}.c ${INCLUDES} -lpthread -o run.o -w
			@./run.o
