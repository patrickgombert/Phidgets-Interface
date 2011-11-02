CXXFLAGS +=     -c -Wall

LIBS =		-lphidget21 -lfcgi -luClibc++

TARGET =	readphidget

OBJS =           main.o phidgetcall.o phidgetmap.o

all: $(TARGET)

$(TARGET): $(OBJS)
	  $(CXX) -o $(TARGET) $(OBJS) $(LDFLAGS) $(LIBS)

clean:
	rm -f *.o $(TARGET)
