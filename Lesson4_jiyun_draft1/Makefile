# 프로그램이 작동하는 순서를 고려해야 한다.

# 1. gcc 컴파일러 및 플래그 설정
CC = gcc
CFLAGS = -W -Wall -std=c99

# 2. 실행파일, 디렉토리, 오브젝트 파일 정의
TARGET = main
OBJ_DIR = ./obj
OBJS = $(OBJ_DIR)/main.o

# 3. 기본 타겟 설정 -- 모든 대상 빌드할 때 main 실행 파일 생성되게
all: $(TARGET)

# 4. main 타겟 빌드 설정 -- main은 main.o에 의존
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

# 5. 오브젝트 파일 생성 정의 -- main.o는 main.c에 의존
$(OBJ_DIR)/main.o: main.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c -o $@ $<

# 6. 디렉토리 생성 정의
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# 7. 파일 삭제 정의
clean:
	rm -f $(TARGET) $(OBJS)
	rm -rf $(OBJ_DIR)
# -f 강제 삭제, 파일 존재하지 않더라도 에러 발생 X
# -rf 디렉토리 삭제
