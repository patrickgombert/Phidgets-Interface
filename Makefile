CXXFLAGS +=     -Wall

LIBS =		-lphidget21

OBJS =          phidgetcall.o phidgetmap.o

all: $(OBJS)

$(OBJ):
	  $(CXX) -o $(OBJS) $(LDFLAGS) $(LIBS)

clean:
	rm -f *.o
