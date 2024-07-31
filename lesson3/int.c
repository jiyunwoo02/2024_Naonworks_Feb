#include <stdio.h>
#include <stdint.h>

int main() {
    // intmax_t는 시스템에서 가장 큰 정수형을 나타냅니다.
    // uintmax_t는 부호 없는 가장 큰 정수형을 나타냅니다.
    intmax_t largestInt = INTMAX_MAX;
    uintmax_t largestUInt = UINTMAX_MAX;

    printf("Largest signed integer: %jd\n", largestInt);
    printf("Largest unsigned integer: %ju\n", largestUInt);

    return 0;
}

