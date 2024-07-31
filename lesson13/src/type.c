#include "../inc/type.h"
#include <stdint.h>

// type.h에서 선언한 전역 변수 정의 및 초기화
// --> 컴파일러가 변수들을 찾을 수 있게 된다
// --> 링크 과정에서도 정상적으로 처리된다.

intmax_t h_value[MAX_LINE];
intmax_t result[MAX_LINE];
intmax_t last_result[MAX_LINE];
intmax_t temp[MAX_LINE];