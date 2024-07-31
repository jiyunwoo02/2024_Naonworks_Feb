CC = gcc
CFLAGS = -W -Wall -std=c99

TARGET = main
OBJ_DIR = ./obj
OBJS = $(OBJ_DIR)/main.o $(OBJ_DIR)/input.o $(OBJ_DIR)/run.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -DDEBUG_FLAG -o $@ $^

$(OBJ_DIR)/main.o: main.c input.h run.h type.h | $(OBJ_DIR)
	$(CC) $(CFLAGS) -DDEBUG_FLAG -c -o $@ $<

$(OBJ_DIR)/input.o: input.c input.h type.h | $(OBJ_DIR)
	$(CC) $(CFLAGS) -DDEBUG_FLAG -c -o $@ $<

$(OBJ_DIR)/run.o: run.c run.h type.h | $(OBJ_DIR)
	$(CC) $(CFLAGS) -DDEBUG_FLAG -c -o $@ $<

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	rm -f $(TARGET) $(OBJS)
	rm -rf $(OBJ_DIR)
