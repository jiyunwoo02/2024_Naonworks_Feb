#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include "../inc/run.h"
#include "../inc/type.h"

int samePattern(intmax_t arr1[], intmax_t arr2[], intmax_t size) {
    for (intmax_t i = 0; i < size; i++) {
        if (arr1[i] != arr2[i]) {
            return 0;
        }
    }
    return 1;
}

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
            // 2. 배열에 h값 저장
            for (intmax_t h = 1; h <= line; h++) {
                h_value[h - 1] = h;
            }

            // 3. 난수 시드 설정
            srand(time(NULL));

            // 4. 전역변수에 값 저장
            while (1) {
                for (intmax_t i = line - 1; i > 0; i--) {
                    intmax_t j = rand() % (i + 1);
                    intmax_t res = h_value[i];
                    h_value[i] = h_value[j];
                    h_value[j] = res;
                }

                for (intmax_t i = 0; i < line; i++) {
                    temp[i] = result[i];
                    result[i] = h_value[i];
                    last_result[i] = temp[i];
                }

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
