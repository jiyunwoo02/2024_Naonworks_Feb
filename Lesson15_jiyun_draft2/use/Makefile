CC = gcc
CFLAGS = -W -Wall -std=c99 -DDEBUG_FLAG
TARGET = main
SRC_DIR = .
OBJ_DIR = $(SRC_DIR)/obj
LIB_DIR = ../lib

SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS))
DEPS = $(wildcard $(INC_DIR)/*.h) $(LIB_DIR)/inc/run.h
LIBS = $(LIB_DIR)/librun.a

all: $(TARGET)

$(TARGET): $(OBJS) $(LIBS)
	$(CC) $(CFLAGS) -o $@ $(OBJS) $(LIBS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(DEPS) | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c -o $@ $<

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	rm -f $(TARGET) $(OBJS)
	rm -rf $(OBJ_DIR)
