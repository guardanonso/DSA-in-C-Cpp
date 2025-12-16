CC=gcc
CFLAGS=-I.

build/binTrees: obj/trees.o binTrees.c
	$(CC) obj/trees.o binTrees.c -o build/binTrees $(CFLAGS)

obj/trees.o: src/trees.c
	$(CC) -c src/trees.c -o obj/trees.o $(CFLAGS)

clean:
	rm -f obj/* build/*