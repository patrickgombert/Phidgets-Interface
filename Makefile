CC =            g++

CXXFLAGS =	-g -Wall

CFLAGS =        -c -Wall

LIBS =		-lphidget21

TARGET =	readphidget

all: $(TARGET)

$(TARGET): main.o phidgetcall.o phidgetmap.o
	$(CC) $(CXXFLAGS) main.cpp phidgetcall.cpp phidgetmap.cpp -o $(TARGET) $(LIBS)

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp -o main.o

phidgetcall.o: phidgetcall.cpp
	$(CC) $(CFLAGS) phidgetcall.cpp -o phidgetcall.o

phidgetmap.o: phidgetmap.cpp
	$(CC) $(CFLAGS) phidgetmap.cpp -o phidgetmap.o

clean:
	rm -f *.o $(TARGET)
