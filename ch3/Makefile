CC = g++
CFLAGS = -O
src = $(wildcard *.cpp)
eo = $(wildcard EuropeanOption*.cpp)
sbp = $(wildcard *SimpleBondPricing.cpp)

all: EuropeanOptionTest TestSimpleBondPricing

EuropeanOptionTest: $(eo:.cpp=.o)
	$(CC) $(CFLAGS) -o $@ $^

TestSimpleBondPricing: $(sbp:.cpp=.o)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm EuropeanOptionTest $(src:.cpp=.o)
