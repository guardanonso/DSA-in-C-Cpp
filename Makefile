CC = gcc
CFLAGS = -I.

build/binTrees: | build obj
build/binTrees: obj/trees.o binTrees.c
	$(CC) obj/trees.o binTrees.c -o build/binTrees $(CFLAGS)

build/linkedLists: | build obj
build/linkedLists: obj/lists.o linkedLists.c
	$(CC) obj/lists.o linkedLists.c -o build/linkedLists $(CFLAGS)

obj/trees.o: | obj
obj/trees.o: src/trees.c
	$(CC) -c src/trees.c -o obj/trees.o $(CFLAGS)

obj/lists.o: | obj
obj/lists.o: src/lists.c
	$(CC) -c src/lists.c -o obj/lists.o $(CFLAGS)

obj:
	mkdir -p obj

build:
	mkdir -p build

clean:
	rm -f obj/* build/*
