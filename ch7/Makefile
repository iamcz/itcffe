CFLAGS = -O -I ../utilities/DateAndTime
VPATH = ../utilities/DateAndTime
CC = g++

TestPersonAndEmployee: TestPersonAndEmployee.cpp DateTime.o DatasimDate.o
	$(CC) $(CFLAGS) -o TestPersonAndEmployee TestPersonAndEmployee.o PersonAndEmployee.o DateTime.o DatasimDate.o

TestPersonAndEmployee.o: TestPersonAndEmployee.cpp
	$(CC) $(CFLAGS) -c TestPersonAndEmployee.cpp

PersonAndEmployee.o: PersonAndEmployee.cpp
	$(CC) $(CFLAGS) -c PersonAndEmployee.cpp

DateTime.o: DateTime.cpp
	$(CC) $(CFLAGS) -c DateTime.cpp

DatasimDate.o: DatasimDate.cpp
	$(CC) $(CFLAGS) -c DatasimDate.cpp

temporaltype.o: temporaltype.cpp
	$(CC) $(CFLAGS) -c temporaltype.cpp
