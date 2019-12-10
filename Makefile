CXX = g++

CXXFLAGS = -g

BINARY = hw08

TARFILE = hw08.tar

all: $(BINARY)

$(BINARY):
	$(CXX) $(CXXFLAGS) hw08.cpp -o $(BINARY)
clean:
	rm -rf $(BINARY) $(TARFILE)
tar:
	tar cf $(TARFILE) Makefile hw08.scr hw08.cpp