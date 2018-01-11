CFLAGS = -O
CC = g++

EuropeanOptionTest: EuropeanOptionTest.o EuropeanOption.o
	$(CC) $(CFLAGS) -o EuropeanOptionTest EuropeanOptionTest.o EuropeanOption.o

EuropeanOptionTest.o: EuropeanOptionTest.cpp
	$(CC) $(CFLAGS) -c EuropeanOptionTest.cpp

EuropeanOption.o: EuropeanOption.cpp
	$(CC) $(CFLAGS) -c EuropeanOption.cpp

TestSimpleBondPricing: SimpleBondPricing.o TestSimpleBondPricing.o
	$(CC) $(CFLAGS) -o TestSimpleBondPricing TestSimpleBondPricing.o SimpleBondPricing.o

TestSimpleBondPricing.o: TestSimpleBondPricing.cpp
	$(CC) $(CFLAGS) -c TestSimpleBondPricing.cpp

SimpleBondPricing.o: SimpleBondPricing.cpp
	$(CC) $(CFLAGS) -c SimpleBondPricing.cpp

clean:
	rm -f EuropeanOptionTest *.o
