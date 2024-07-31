# main.c input.c run.c 반영한 수정된 Makefile

# 1. gcc 컴파일러 및 플래그
CC = gcc
CFLAGS = -W -Wall -std=c99

# 2. 실행파일, 디렉토리, 오브젝트 파일
TARGET = main
OBJ_DIR = ./obj
OBJS = $(OBJ_DIR)/main.o $(OBJ_DIR)/input.o $(OBJ_DIR)/run.o

# 3. 기본 타겟 설정 -- 대상 빌드할 때 main 실행 파일 생성
all: $(TARGET)

# 4. main 타겟 빌드 설정 -- main은 main.o에 의존
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -DDEBUG_FLAG -o $@ $^

# 5. 오브젝트 파일 생성 -- c 파일과 h 파일에 의존
$(OBJ_DIR)/main.o: main.c input.h run.h | $(OBJ_DIR)
	$(CC) $(CFLAGS) -DDEBUG_FLAG -c -o $@ $<

$(OBJ_DIR)/input.o: input.c input.h | $(OBJ_DIR)
	$(CC) $(CFLAGS) -DDEBUG_FLAG -c -o $@ $<

$(OBJ_DIR)/run.o: run.c run.h | $(OBJ_DIR)
	$(CC) $(CFLAGS) -DDEBUG_FLAG -c -o $@ $<

# 6. 오브젝트 디렉토리 생성
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# 7. 파일 삭제
clean:
	rm -f $(TARGET) $(OBJS)
	rm -rf $(OBJ_DIR)
