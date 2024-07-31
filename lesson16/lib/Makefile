CC = gcc
AR = ar
CFLAGS = -W -Wall -std=c99
TARGET = librun.a
SRC_DIR = src
HDR_DIR = inc
OBJ_DIR = $(SRC_DIR)/obj

all: $(TARGET)

SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS))
DEPS = $(wildcard $(HDR_DIR)/*.h)

$(TARGET): $(OBJS)
	$(AR) rcs $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(DEPS) | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c -o $@ $<

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	rm -f $(TARGET) $(OBJS)
	rm -rf $(OBJ_DIR)
