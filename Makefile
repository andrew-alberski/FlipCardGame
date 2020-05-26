CardFlip: flipHeaderSource.o main.o
	g++ flipHeaderSource.o main.o -o CardFlip
flipHeaderSource.o: flipHeaderSource.cpp flipHeader.h
	g++ -g -Wall -c flipHeaderSource.cpp
main.o: main.cpp flipHeader.h
	g++ -g -Wall -c main.cpp
clean: 
	rm main.o flipHeaderSource.o CardFlip 
