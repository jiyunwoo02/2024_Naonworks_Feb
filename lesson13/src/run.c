#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include "../inc/run.h"
#include "../inc/type.h"

void runPattern(enum pattern_type choice, intmax_t line) {
	switch (choice) {
        case pattern_triangle: // 패턴 1
            for (intmax_t i = 1; i <= line; i++) {
                for (intmax_t j = 1; j <= i; j++) {
                    printf("*");
                }
                printf("\n");
            }
            break;

        case pattern_invert_triangle: // 패턴 2
            for (intmax_t i = line; i >= 1; --i) {
                for (intmax_t j = 0; j < i; ++j) {
                    printf("*");
                }
                printf("\n");
            }
            break;

        case pattern_diamond: // 패턴 3 (odd)
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

        case pattern_parallelogram: // 패턴 4
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

        case pattern_invert_pyramid: // 패턴 5
            for (intmax_t i = line; i >= 1; i--) {
                for (intmax_t j = 0; j < i - 1; j++) {
                    printf(" ");
                }
                for (intmax_t k = 0; k < i; k++) {
                    printf("*");
                }
                printf("\n");
            }
            break;

		case pattern_height_triangle: // 패턴 6
            for (intmax_t h = 1; h <= line; h++) {
                for (intmax_t i = 1; i <= h; i++) {
                    for (intmax_t j = 1; j <= i; j++) {
                        printf("*");
                    }
                    printf("\n");
                }
                printf("\n");
            }
		    break;

		case pattern_length_triangle: // 패턴 7
            for (intmax_t h = 0; h < line; h++) {
                int spaces = 0.5 * h * (h + 5);
                for (intmax_t i = 0; i < spaces; i++) {
                    printf(" ");
                }
                for (intmax_t j = 0; j < line - h; j++) {
                    for (intmax_t k = 0; k <= h; k++) {
                        printf("*");
                    }
                    for (intmax_t m = 0; m < (j + 2); m++) {
                        printf(" ");
                    }
                }
                printf("\n");
            }
			break;

		case pattern_random_option: // 패턴 8
            // 1. 배열 비교 함수
            int samePattern(intmax_t arr1[], intmax_t arr2[], intmax_t size) {
                for (intmax_t i = 0; i < size; i++) {
                    if (arr1[i] != arr2[i]) { // 같은 자리끼리 비교
                        return 0; // 하나라도 다르면 1 return
                    }
                }
                return 1;
            }

            // 2. 배열에 h값 저장
            for (intmax_t h = 1; h <= line; h++) {
                h_value[h - 1] = h;
            }

            // 3. 난수 시드 설정
            srand(time(NULL));
            // rand() 함수가 랜덤한 값 생성
            // time(NULL)은 현재 시간 나타내는 값 
            // : NULL을 전달함으로써 --> time() 함수가 현재 시간을 반환
            // >> 프로그램이 실행될 때마다 다른 시간 값이 사용되어 
            // 시드 값이 변경되어 다양한 난수를 생성

            // 4. h_value, temp, result, last_result (전역변수) 에 값 저장
            while (1) {
                for (intmax_t i = line - 1; i > 0; i--) {  // h_values 요소 섞기
                    intmax_t j = rand() % (i + 1); // 0~i 사이의 난수
                    intmax_t res = h_value[i]; // [i] 값 저장
                    h_value[i] = h_value[j]; // [i]에 [j]값 대입: 현재 요소와 랜덤 선택 요소 값 교환
                    h_value[j] = res; // [j]에 이전 [i]값 대입
                }

                for (intmax_t i = 0; i < line; i++) {
                    temp[i] = result[i];
                    result[i] = h_value[i];
                    last_result[i] = temp[i];
                }

                // samePattern 함수는 같은 패턴이면 1을, 다른 패턴이면 0을 반환
                // 따라서 같은 패턴이면 다시 result를 구하고, 
                // 다른 패턴이면 while문을 빠져나가 패턴을 출력
                if (samePattern(last_result, result, line) == 1) {
                    continue;
                }
                else {
                    break;
                }
            }

            // 5. 패턴 출력
            for (intmax_t i = 0; i < line; i++) {
                intmax_t h = result[i];
                for (intmax_t i = 1; i <= h; i++) {
                    for (intmax_t j = 1; j <= i; j++) {
                        printf("*");
                    }
                    printf("\n");
                }
                printf("\n");
            }
			break;
    }
}
