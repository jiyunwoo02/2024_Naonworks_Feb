#include <stdio.h>
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

		case pattern_length_triangle: // 패턴 7: 가로로 접근하자
            for (intmax_t h = 0; h < line; h++) {

                // 좌측 공백 by 등차수열: 0,3,7,12,...
                int spaces = 0.5 * h * (h + 5);

                for (intmax_t i = 0; i < spaces; i++) {
                    printf(" ");
                }

                // 별 출력
                for (intmax_t j = 0; j < line - h; j++) {
                    
                    for (intmax_t k = 0; k <= h; k++) {
                        printf("*");
                    }

                    // 우측 공백: 2,3,4...
                    for (intmax_t m = 0; m < (j + 2); m++) {
                        printf(" ");
                    }
                }
                printf("\n");
            }
			break;
    }
}
