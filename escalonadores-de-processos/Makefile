CC = gcc

all: programa

programa: lib/queue/queue.c lib/queue/queue.h lib/utils.c lib/utils.h rr/rr.c rr/rr.h main.c
	$(CC) -o programa main.c

clean:
	rm -f programa