CFLAGS = -O
CC = g++

TestComplex: TestComplex.o Complex.o
	$(CC) $(CFLAGS) -o TestComplex TestComplex.o Complex.o

TestComplex.o: TestComplex.cpp
	$(CC) $(CFLAGS) -c TestComplex.cpp

Complex.o: Complex.cpp
	$(CC) $(CFLAGS) -c Complex.cpp

clean:
	rm TestComplex *.o
