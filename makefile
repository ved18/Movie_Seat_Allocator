CXX = g++
IDIR = ./include
OBJDIR = ./obj
CXXFLAGS = -I$(IDIR)
SRC = ./src

main: $(SRC)/main.o $(SRC)/theatre.o $(SRC)/io.o
	$(CXX) $(CXXFLAGS) -o main $(SRC)/main.o $(SRC)/theatre.o $(SRC)/io.o


clean:
	rm -f $(SRC)/*.o $(SRC)/main

