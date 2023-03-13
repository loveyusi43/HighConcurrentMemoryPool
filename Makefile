CXX = g++
TARGET = MemoryPool.out
SRC = $(wildcard *.cc)
OBJ = $(patsubst %.cc, %.o, $(SRC))

CXXFLAGS = -c -Wall -std=c++11
$(TARGET): $(OBJ)
	$(CXX) -o $@ $^ -pthread -Wl,--no-as-needed

%.o: %.cc
	$(CXX) $(CXXFLAGS) $<

.PHONY:clean
clean:
	rm -f $(OBJ) $(TARGET)