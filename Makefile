##Start of Makefile##
prog4: main.o Word.o BinaryTreeWord.o LineNum.o ListLineNum.o 
	g++ -o prog4 main.o Word.o ListLineNum.o LineNum.o BinaryTreeWord.o
	make clean
main.o: main.cpp Word.h BinaryTreeWord.h
	g++ -Wall -c -g main.cpp
Word.o: Word.cpp Word.h LineNum.h ListLineNum.h
	g++ -Wall -c -g Word.cpp
BinaryTreeWord.o: BinaryTreeWord.cpp Word.h ListLineNum.h
	g++ -Wall -c -g BinaryTreeWord.cpp
LineNum.o: LineNum.cpp LineNum.h
	g++ -Wall -c -g LineNum.cpp
ListLineNum.o: ListLineNum.cpp ListLineNum.h LineNum.h
	g++ -Wall -c -g ListLineNum.cpp
clean:
	rm *.o
##End of Makefile##
