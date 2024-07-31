

CC = gcc


CFLAGS = -Wall


TARGET = librun

SRC_DIR=./src
OBJ_DIR = $(SRC_DIR)/obj

LIB=./librun.a

AR=ar rsc

RUN = run


all : $(TARGET)



$(TARGET) :$(RUN)
	$(AR) $(LIB) $(OBJ_DIR)/$(RUN).o 



$(RUN) : $(OBJ_DIR)
	$(CC) -c $(CFLAGS) $(SRC_DIR)/$(RUN).c -o $(OBJ_DIR)/$(RUN).o

$(OBJ_DIR) : 
	mkdir -p $@






clean : 
	@rm -f $(LIB)
	@rm -f $(OBJ_DIR)/$(RUN).o


