CXX := g++
CXXFLAGS := -c -Wall -std=c++20 -I./src/libs/
LD := g++
LDFLAGS := -lncursesw -I/usr/include/ncursesw ./src/libs/fmt/libfmt.a

SRCDIR := src
OBJDIR := obj

SRC := $(wildcard $(SRCDIR)/*.cpp $(SRCDIR)/components/*.cpp $(SRCDIR)/command/*.cpp $(SRCDIR)/draw/*.cpp)
OBJ := $(patsubst $(SRCDIR)/%.cpp, $(OBJDIR)/%.o, $(SRC))
EXE := quantum.out

.PHONY: all clean

all: $(EXE)

run: all
	./$(EXE)

clean:
	rm -f $(OBJ)
	rm -f $(EXE)

$(EXE): $(OBJDIR) $(OBJ)
	$(LD) $(OBJ) $(LDFLAGS) -o $@

$(OBJDIR):
	mkdir $@

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp $(SRCDIR)/%.h
	$(CXX) $(CXXFLAGS) $< -o $@

