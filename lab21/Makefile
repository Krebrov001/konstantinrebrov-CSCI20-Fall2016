CC=g++

lab21.exe : lab21.o MyClass.o
	$(CC) lab21.o MyClass.o -o lab21.exe

lab21.o : lab21.cpp allIncludes.h randomNumberFunction.cpp MyClass.h
	$(CC) -Wall -c lab21.cpp

MyClass.o : MyClass.cpp MyClass.h
	$(CC) -Wall -c MyClass.cpp

clean :
	rm *.o lab21.exe
