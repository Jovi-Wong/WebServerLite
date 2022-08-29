CXX = g++
FLAGS = -std=c++14 -O3 -Wall -I ./src/include

TARGET = server
OBJS = src/*.cpp
LIBS = -pthread -lmysqlclient
all: $(OBJS)
	$(CXX) -o $(TARGET) $(FLAGS) $(OBJS) $(LIBS)