CC = g++
FLAGS = -std=c++14 -O3 -Wall -I ./src/include
OBJS = src/buffer.cpp src/epoller.cpp src/heaptimer.cpp \
	   src/httpconn.cpp src/httprequest.cpp src/httpresponse.cpp \
	   src/log.cpp src/sqlconnpool.cpp src/webserverlite.cpp
MAIN = src/main.cpp
TEST = test/test.cpp
LIBS = -pthread -lmysqlclient
TRASH = server server_test log testlog* testThreadpool

all: $(OBJS) $(MAIN)
	$(CC) -o server $(FLAGS) $(OBJS) $(MAIN) $(LIBS)

test: $(OBJS) $(TEST)
	$(CC) -o server_test $(FLAGS) $(OBJS) $(TEST) $(LIBS)

debug: $(OBJS) $(MAIN)
	$(CC) -o server $(FLAGS) -g $(OBJS) $(MAIN) $(LIBS)

.PHONY: clean
clean:
	@rm -rf $(TRASH) 