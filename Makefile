CXX = g++
FLAGS = -std=c++14 -O3 -Wall -I ./src/include
TARGET = server
OBJS = src/*.cpp
LIBS = -pthread -lmysqlclient
TRASH = $(TARGET) log

all: $(OBJS)
	$(CXX) -o $(TARGET) $(FLAGS) $(OBJS) $(LIBS)

.PHONY: clean
clean:
	@rm -rf $(TRASH) 