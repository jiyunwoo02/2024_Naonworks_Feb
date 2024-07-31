#include <stdio.h>
#include <stdlib.h>
#include "input.h" // 헤더파일 (1)
#include "run.h" // 헤더파일 (2)

int main() {
#ifdef DEBUG_FLAG
	printf("Debug Flag Enable");
#endif

    intmax_t choice;
    intmax_t line;

    while (1) { // 무한 루프: 입력과 출력
        choice = getPattern(); // 패턴 번호 입력 -- return choice
        line = getLine(choice); // 라인 수 입력 -- return line
        runPattern(choice, line); // 해당하는 패턴 출력
    }

    return 0;
}

// main() 함수가 사용자가 입력한 패턴 번호와 라인 수 사용하려면
// 두 함수 호출해야 한다
// 함수를 호출하려면 -- 함수가 어떻게 선언되었는지 알아야 한다
// 헤더 파일(.h)을 include하여 함수의 선언을 사용한다!
// --> 컴파일러에게 함수의 형식을 알려준다
// 헤더파일과 c파일이 서로 연결되어 프로그램이 동작하도록 한다
// 또한, 함수의 선언과 정의를 일치시켜야 한다
