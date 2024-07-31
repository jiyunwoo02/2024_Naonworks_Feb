# Makefile --> compiling main.c
# 1) sudo apt install make, sudo apt install make-guile 실행
# 2) Makefile 파일명 유의

# 컴파일러 설정
CC = gcc 
# C 파일 컴파일 할 때 gcc, C++ 컴파일하면 g++

# 컴파일러 플래그 설정
CFLAGS = -Wall -std=c99
# -Wall 모든 경고 활성화
# -std=c99 c99 표준 사용해 컴파일

# 빌드할 대상 파일 설정
TARGET = main 
# target: 실행 파일명, 빌드할 대상 파일
OBJS = main.o 
# objs: 대상 파일에 필요한 오브젝트 파일 지정
# main.o는 main.c 컴파일하여 생성된 오브젝트 파일

# 기본 타겟 설정
all: $(TARGET) 
# all:모든 것을 빌드하는 데 사용
# all 타겟 만들기 위해 main 파일 필요 -> all 정의하면 make 명령 실행해 프로젝트 빌드 가능
# --> 모든 기본 목표 지정, target은 빌드할 대상: main이라는 실행 파일 빌드
# ==> make 명령어를 실행할 때 main이라는 실행 파일을 빌드하라

# main 타겟 빌드 설정
$(TARGET): $(OBJS) # main을 만들기 위해 main.o 사용
# -> 타겟(main) 만들기 위해 objs 정의된 파일 필요
	$(CC) $(CFLAGS) -o $@ $^ 
# main 생성
# CC: C 컴파일러, CFLAGS: 컴파일러 옵션, -o $@: 출력파일명 지정.$@는 타겟명[main]
# $^: 의존 파일 목록. $(OBJS)에 정의된 파일[main.o]
# --> main 타겟 빌드할 때, main.o 사용해 컴파일러 실행 및 최종적으로 main 실행 파일 생성

# main.o 파일을 생성하는 방법 정의
main.o: main.c # main.c 컴파일하여 main.c의 object 파일(main.o) 생성
	$(CC) $(CFLAGS) -c -o $@ $< 
# $@: 현재 목표[main.o], $<: 현재 규칙 첫 번째 종속 항목
# C 컴파일러 호출 - 컴파일러 플래그 사용 - 오브젝트 파일 생성(-c) - 출력파일명 지정(-o $@) - 현재 규칙 첫 번째 종속 항목($<)
# --> main.c 컴파일하여 main.o 생성

# clean 타겟 정의: 생성된 파일들 삭제
clean: # 생성된 실행 파일과 object 파일 삭제
	rm -f $(TARGET) $(OBJS)
# rm -f: 파일 강제 삭제, 파일 존재하지 않아도 에러 X
# 삭제할 파일 목록, TARGET은 실행 파일, OBJS는 오브젝트 파일

