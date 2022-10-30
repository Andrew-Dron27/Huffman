CC = g++
GG = -g
Cflags = -Wall
MFlags = -fsanitize=address,undefined

Huffman: Huffman.o Node.o
	$(CC) -o  Huffman.o Node.o $(Cflags) $(MFlags) $(GG)

# HuffmanTest.o: TrieTest.cpp Node.h Trie.h
# 	$(CC) -c TrieTest.cpp $(Cflags) $(MFlags) $(GG)

Huffman.o: Huffman.h Node.h Huffman.cpp Node.cpp
	$(CC) -c Trie.cpp Node.cpp $(Cflags) $(MFlags) $(GG)

Node.o: Node.h Node.cpp
	$(CC)-c Node.cpp $(cflags) $(MFlags) $(GG)

clean:
	$(RM) count *.o *TrieTest

# test: HuffmanTest
# 	./HuffmanTest dictionary.txt querieTest.txt