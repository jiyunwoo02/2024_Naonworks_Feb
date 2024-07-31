# 1. 컴파일러
CC = gcc

# 2. 컴파일러 플래그
# 경고 메시지를 최대한 많이 보여주는 -Wall 플래그 
# 추가적인 경고 메시지를 보여주는 -W 플래그
# C99 표준을 사용하는 -std=c99 플래그 설정
CFLAGS = -W -Wall -std=c99

# 3. 타겟(실행파일), use, use/obj, lib directory
# 생성할 실행 파일의 이름을 main으로 설정하고 
# 소스 코드 디렉토리(use)를 현재 디렉토리로
# 오브젝트 파일 디렉토리를 obj/로
# 라이브러리 디렉토리를 ../lib로 설정
TARGET = main
SRC_DIR = .
OBJ_DIR = $(SRC_DIR)/obj
LIB_DIR = ../lib

# 4. 파일 지정
# 현재 디렉토리에서 모든 .c 파일을 소스 파일로 
# 이 파일들을 컴파일한 .o 파일을 오브젝트 파일로
# 라이브러리 헤더 파일을 ../lib/draft3_run.h로
# 라이브러리 파일을 ../lib/librun.a로 설정
SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS))
DEPS = $(LIB_DIR)/draft3_run.h
LIBS = $(LIB_DIR)/librun.a

# 5. all 타겟
# 기본 타겟으로, main 실행 파일을 생성
all: $(TARGET)

# 6. main 타겟
# 오브젝트 파일과 라이브러리 파일을 링크하여 main 실행 파일 생성
# -lm 옵션은 math.h 헤더 파일에서 함수를 사용하기 위해 필요
$(TARGET): $(LIBS) $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS) $(LIBS)

# 7. 오브젝트 파일 생성
# .c 파일을 컴파일하여 .o 파일을 생성
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(DEPS) | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c -o $@ $<

# 8. obj directory 생성
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# 9. clean 타겟
# make clean시 생성된 파일 모두 삭제
clean:
	rm -f $(TARGET) $(OBJS)
	rm -rf $(OBJ_DIR)
