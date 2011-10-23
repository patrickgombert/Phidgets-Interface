CC =            g++

CXXFLAGS =	-g -Wall

LIBS =		-lphidget21

TARGET =	readphidget

all: $(TARGET)

$(TARGET): main.cpp phidgetcall.cpp phidgetmap.cpp
	$(CC) $(CXXFLAGS) main.cpp phidgetcall.cpp phidgetmap.cpp -o $(TARGET) $(LIBS)

clean:
	rm -f $(TARGET)
