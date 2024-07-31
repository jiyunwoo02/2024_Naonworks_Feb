CC = gcc
CFLAGS = -W -Wall -std=c99

TARGET = main

SRC_DIR = src
OBJ_DIR = src/obj
INC_DIR = inc

# type.o 추가
OBJS = $(OBJ_DIR)/main.o $(OBJ_DIR)/input.o $(OBJ_DIR)/run.o $(OBJ_DIR)/type.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -DDEBUG_FLAG -o $@ $^

$(OBJ_DIR)/main.o: $(SRC_DIR)/main.c $(INC_DIR)/input.h $(INC_DIR)/run.h $(INC_DIR)/type.h | $(OBJ_DIR)
	$(CC) $(CFLAGS) -DDEBUG_FLAG -c -o $@ $<

$(OBJ_DIR)/input.o: $(SRC_DIR)/input.c $(INC_DIR)/input.h $(INC_DIR)/type.h | $(OBJ_DIR)
	$(CC) $(CFLAGS) -DDEBUG_FLAG -c -o $@ $<

$(OBJ_DIR)/run.o: $(SRC_DIR)/run.c $(INC_DIR)/run.h $(INC_DIR)/type.h | $(OBJ_DIR)
	$(CC) $(CFLAGS) -DDEBUG_FLAG -c -o $@ $<

$(OBJ_DIR)/type.o: $(SRC_DIR)/type.c $(INC_DIR)/type.h | $(OBJ_DIR)
	$(CC) $(CFLAGS) -DDEBUG_FLAG -c -o $@ $<

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	rm -f $(TARGET) $(OBJS)
	rm -rf $(OBJ_DIR)
