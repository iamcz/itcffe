CC = g++
CFLAGS = -O
src = $(wildcard *.cpp)
obj = $(src:.cpp=.o)
eo = $(wildcard EuropeanOption*.cpp)
eo_obj = $(eo:.cpp=.o)
sbp = $(wildcard *SimpleBondPricing.cpp)
sbp_obj = $(sbp:.cpp=.o)

all: EuropeanOptionTest TestSimpleBondPricing

EuropeanOptionTest: $(eo_obj)
	$(CC) $(CFLAGS) -o $@ $^

TestSimpleBondPricing: $(sbp_obj)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm EuropeanOptionTest $(obj)
