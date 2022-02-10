CXX ?= g++
PROJECT = GUServer

SOURCEDIR = ./src
BUILDDIR = ./build
OBJDIR= $(BUILDDIR)/obj
TARGETDIR = $(BUILDDIR)/bin
INCLUDEDIR = ./src

CFLAG = -I $(INCLUDEDIR) -g

SOURCES = $(wildcard $(SOURCEDIR)/*.cpp $(SOURCEDIR)/Log/*.cpp)
OBJECTS = $(patsubst %.cpp,$(OBJDIR)/%.o,$(SOURCES))

# g++ -o GUServer obj/main.o
GUServer: $(SOURCES)
	$(CXX) -o $(TARGETDIR)/$@ $^ $(CFLAG)

# g++ -c main.cpp -o ./obj/main.o
# $(OBJDIR)/%.o: $(SOURCES)
# 	$(CXX) -c $< -o $(OBJECTS) $(CFLAG)

MakeBuildDir:
	mkdir -p build/obj/src build/bin

clean:
	rm -rf build