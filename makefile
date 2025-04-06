CC=g++
DEV=-Wall -Werror -g -std=c++14  # added -Werror
OPT=-O3 -std=c++14
# gcc -g -Wall -Werror -o sortedverification.cxx sortedverification.exe

JSON=json.hpp

all: BloodSugarProgram

BloodSugarProgram: main.cpp
	g++ -g -std=c++14 timealgorithms.cxx insertionsort.o mergesort.o quicksort.o -o timealgorithms

insertionsort.o: insertionsort.cpp insertionsort.h json.hpp
	g++ -std=c++14 -c insertionsort.cpp

mergesort.o: mergesort.cpp mergesort.h json.hpp
	g++ -std=c++14 -c mergesort.cpp

quicksort.o: quicksort.cpp quicksort.h json.hpp
	g++ -std=c++14 -c quicksort.cpp

clean:
	rm -f *.o
	rm -rf *.dSYM
	rm -f consistentresultverification
	rm -f sortedverification
	rm -f timealgorithms