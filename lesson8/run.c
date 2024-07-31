#include <stdio.h>
#include "run.h" // 헤더파일

void runPattern(intmax_t choice, intmax_t line) { // 사용자가 입력한 패턴 번호와 라인 수 
    // void: 리턴할 값 없다
	switch (choice) {
        case 1: // 패턴 1
            for (intmax_t i = 1; i <= line; i++) {
                for (intmax_t j = 0; j < i; j++) {
                    printf("*");
                }
                printf("\n");
            }
            break;

        case 2: // 패턴 2
            for (intmax_t i = line; i >= 1; --i) {
                for (intmax_t j = 0; j < i; ++j) {
                    printf("*");
                }
                printf("\n");
            }
            break;

        case 3: // 패턴 3
            for (intmax_t i = 0; i < line; i++) {
                if (i <= line / 2) {
                    for (intmax_t j = line / 2; j > i; j--) {
                        printf(" ");
                    }
                    for (intmax_t k = 0; k <= i * 2; k++) {
                        printf("*");
                    }
                    printf("\n");
                } else {
                    for (intmax_t j = line / 2; j < i; j++) {
                        printf(" ");
                    }
                    for (intmax_t k = 0; k < ((line - i) * 2) - 1; k++) {
                        printf("*");
                    }
                    printf("\n");
                }
            }
            break;

        case 4: // 패턴 4
            for (intmax_t i = 0; i < line; i++) {
                for (intmax_t j = 0; j < line - i - 1; j++) {
                    printf(" ");
                }
                for (intmax_t k = 0; k < line; k++) {
                    printf("*");
                }
                printf("\n");
            }
            break;

        case 5: // 패턴 5
            for (int i = line; i >= 1; i--) {
                for (int j = 0; j < i - 1; j++) {
                    printf(" ");
                }
                for (int k = 0; k < i; k++) {
                    printf("*");
                }
                printf("\n");
            }
            break;
    }
}


// input.h와 run.h는 헤더 파일 (header file)
// 이들은 각각 input.c와 run.c 파일에서 사용되는 함수의 선언 포함 
// -- 헤더 파일을 사용하여 함수의 선언을 다른 소스 파일에서 포함하고, 이를 통해 모듈 간에 함수를 공유할 수 있다!

// 헤더 파일의 사용 용도
// 1. 함수 선언: 다른 파일에서 사용할 함수의 선언 포함 (함수명/매개변수 유형/리턴 유형 etc)
// 2. 매크로 및 상수 정의: 상수나 매크로는 프로그램 전체에서 사용되는 경우 많다, 이러한 정의들을 넣어 다른 파일에서도 공유 가능
// 3. 구조체 선언: 구조체는 데이터 묶는 데 사용, 다른 파일에서도 구조체 사용 가능
// 4. 외부 라이브러리 및 모듈 선언
// --> 코드의 가독성, 유지 보수성 상승 --> 함수 or 상수의 정의를 한 곳에서 관리하므로, 코드 수정 시 헤더 파일만 수정하면 다른 파일에서 해당 변경 사항 자동으로 반영 ok

// main.c에서 input.c와 run.c에서 사용하는 함수를 사용하려면?
// main.c에서 input.h와 run.h 헤더 파일을 include하여 해당 함수들의 선언을 가져온다
// 그러면 컴파일러가 main.c 컴파일할 때 함수의 선언을 알고, 링커가 링크 과정에서 실제 함수 정의를 찾는다

// --> 헤더 파일은 함수의 선언을 담당, 해당 함수를 사용하는 파일에서는 해당 헤더 파일을 include하여 함수를 호출할 수 있도록 한다!
