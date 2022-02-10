CXX ?= g++
PROJECT = GUServer

SOURCEDIR = ./src

BUILDDIR = ./build
OBJDIR= $(BUILDDIR)/obj

TARGETDIR = $(BUILDDIR)/bin

SOURCES = $(wildcard $(SOURCEDIR)/*.cpp)
OBJECTS = $(patsubst %.cpp,$(OBJDIR)/%.o,$(SOURCES))

# g++ -o GUServer obj/main.o
GUServer: $(OBJECTS)
	$(CXX) -o $(TARGETDIR)/$@ $^

# g++ -c main.cpp -o ./obj/main.o
$(OBJDIR)/%.o: $(SOURCES)
	$(CXX) -c $< -o $(OBJECTS)

MakeBuildDir:
	mkdir -p build/obj/src build/bin

clean:
	rm -rf build