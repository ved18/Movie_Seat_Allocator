CXX = g++
IDIR = ../include
OBJDIR = ../obj
CXXFLAGS = -I$(IDIR)

main: main.o theatre.o io.o
	$(CXX) $(CXXFLAGS) -o main main.o theatre.o io.o

$(OBJDIR)/%.o: %.c
	$(CXX) $(CXXFLAGS) -c -o $@ $<

clean:
	rm *.o main