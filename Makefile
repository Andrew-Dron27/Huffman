CC = g++
GG = -g
Cflags = -Wall
MFlags = -fsanitize=address,undefined

main: Huffman.o Node.o Main.o
	$(CC) -o  main Huffman.o Node.o Main.o $(Cflags) $(MFlags) $(GG)

Main.o: Huffman.h Node.h Huffman.cpp Node.cpp main.cpp
	$(CC) -c main.cpp $(Cflags) $(MFlags) $(GG)

# HuffmanTest.o: TrieTest.cpp Node.h Trie.h
# 	$(CC) -c TrieTest.cpp $(Cflags) $(MFlags) $(GG)

Huffman.o: Huffman.h Node.h Huffman.cpp Node.cpp
	$(CC) -c Huffman.cpp Node.cpp $(Cflags) $(MFlags) $(GG)

Node.o: Node.h Node.cpp
	$(CC)-c Node.cpp $(cflags) $(MFlags) $(GG)

clean:
	$(RM) count *.o *TrieTest

# test: HuffmanTest
# 	./HuffmanTest dictionary.txt querieTest.txt