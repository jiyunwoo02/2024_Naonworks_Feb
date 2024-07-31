# 컴파일러
CC = gcc

# 컴파일러 플래그
CFLAGS = -Wall

# 각 파일 이름
TARGET = main

# 디렉토리 경로

# obj 파일 정보
OBJ_MAIN =$(OBJ_DIR)/$(TARGET).o
OBJ_INPUT =$(OBJ_DIR)/$(INPUT).o

# 패턴을 통해 자동화 시킬 변수
CODE_AUTO=$(SRC_DIR)/%.c

# obj 모음집
OBJECTS = $(OBJ_MAIN) $(OBJ_INPUT)

all: $(TARGET)


$(TARGET) :
	gcc main.c -o main  -L../lib -lrun


clean : 
	@rm -f $(OBJ_DIR)/*.o  $(TARGET)
