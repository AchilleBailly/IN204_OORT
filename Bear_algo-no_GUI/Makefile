CXX = clang++
LIBS = -lm -ltbb -lomp
CXXFLAGS = -std=c++17 -fPIC -Xpreprocessor -fopenmp
ifdef DEBUG
CXXFLAGS += -g -O0 -Wall -pedantic -Weffc++ -D_GLIBCXX_DEBUG
CXXFLAGS2 = CXXFLAGS
else
CXXFLAGS += -O3 -march=native
CXXFLAGS2 = ${CXXFLAGS} -O2 -march=native -Wall
endif

ALL = project.exe

default: help

all: $(ALL)

clean:
	@rm -fr *.o *.exe *~
	@rm -fr *.o build/*.exe *~


project.exe: src/main.cpp
	$(CXX) $(CXXFLAGS) -o build/$@ $^ $(LIBS)

help:
	@echo "Available targets:"
	@echo "    all: compile all executables"
	@echo "       $(ALL)"
	@echo "Configuration:"
	@echo "    CXX     : $(CXX)"
	@echo "    CXXFLAGS: $(CXXFLAGS)"
	@echo "Add DEBUG=yes to compile in debug"


# Rapport
%.html: %.md
	pandoc -s --toc $< --css=./github-pandoc.css -o $@
