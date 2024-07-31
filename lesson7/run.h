#ifndef RUN_H
#define RUN_H // RUN_H 심볼: 헤더 파일 중복 포함 방지 [가드 심볼로 사용된다]

#include <stdint.h>

void runPattern(intmax_t choice, intmax_t line);

#endif

// 이러한 구조는 헤더 파일이 여러 번 포함되는 것 방지한다
// + 컴파일러에게 오류 방지하는 데 도움 제공
// 만약 헤더 파일이 중복으로 포함되면?
// - 컴파일러가 중복 정의되었다는 오류 발생
// -- 가드 심벌은 중복 포함을 방지하여 프로그램의 안전성 유지
