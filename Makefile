
roomarrangement: Classes.o main.o
	g++ -Wall -ansi -g -o roomarrangement Classes.o main.o 

Classes.o: Classes.cpp Classes.h Student.h 
	g++ -Wall -ansi -g -c Classes.cpp

main.o: main.cpp Classes.h Student.h
	g++ -Wall -ansi -g -c main.cpp

clean: 
	rm -f roomarrangement Classes.o Student.o main.o 

