TARGET = dp191i

CXX = g++
CXXFLAGS = -std=c++11 -Wall

SRCDIR = src
BINDIR = bin

SOURCES := $(wildcard $(SRCDIR)/*.cpp)
INCLUDES := $(wildcard $(SRCDIR)/*.h)
rm = rm -f


$(BINDIR)/$(TARGET): $(SOURCES) $(INCLUDES)
	@$(CXX) $(CXXFLAGS) -o $@ $(SOURCES)

.PHONY: clean

clean:
	rm -f $(BINDIR)/$(TARGET)
