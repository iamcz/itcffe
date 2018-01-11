CFLAGS = -O
CC = g++

TestPoint: TestPoint.o Point.o
	$(CC) $(CFLAGS) -o TestPoint TestPoint.o Point.o

TestPoint.o: TestPoint.cpp
	$(CC) $(CFLAGS) -c TestPoint.cpp

Point.o: Point.cpp
	$(CC) $(CFLAGS) -c Point.cpp

TestLineSegment: TestLineSegment.o Point.o LineSegment.o
	$(CC) $(CFLAGS) -o TestLineSegment TestLineSegment.o Point.o LineSegment.o

TestLineSegment.o: TestLineSegment.cpp
	$(CC) $(CFLAGS) -c TestLineSegment.cpp

LineSegment.o: LineSegment.cpp
	$(CC) $(CFLAGS) -c LineSegment.cpp

clean:
	rm TestPoint *.o
