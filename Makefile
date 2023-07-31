CC = g++
GG = -g
Cflags = -Wall
MFlags = -fsanitize=address,undefined

main: Huffman.o Node.o Main.o
	$(CC) -o  main Huffman.o Node.o Main.o $(Cflags) $(MFlags) $(GG)

Main.o: Huffman.hpp Node.hpp Huffman.cpp Node.cpp main.cpp
	$(CC) -c main.cpp $(Cflags) $(MFlags) $(GG)

# HuffmanTest.o: TrieTest.cpp Node.hpp Trie.hpp
# 	$(CC) -c TrieTest.cpp $(Cflags) $(MFlags) $(GG)

Huffman.o: Huffman.hpp Node.hpp Huffman.cpp Node.cpp
	$(CC) -c Huffman.cpp Node.cpp $(Cflags) $(MFlags) $(GG)

Node.o: Node.hpp Node.cpp
	$(CC)-c Node.cpp $(cflags) $(MFlags) $(GG)

clean:
	$(RM) count *.o *TrieTest

# test: HuffmanTest
# 	./HuffmanTest dictionary.txt querieTest.txt