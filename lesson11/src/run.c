#include <stdio.h>
#include "../inc/run.h"
#include "../inc/type.h"

void runPattern(enum pattern_type choice, intmax_t line) { // 사용자 입력 -- enum, intmax 
	switch (choice) {
        case pattern_triangle: // 패턴 1
            for (intmax_t i = 1; i <= line; i++) {
                for (intmax_t j = 0; j < i; j++) {
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

        case pattern_diamond: // 패턴 3
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

		case pattern_height_triangle: // 패턴 6
            for (int h = 1; h <= line; h++) {
                for (int i = 1; i <= h; i++) {
                    for (int j = 1; j <= i; j++) {
                        printf("*");
                    }
                    printf("\n");
                }
                printf("\n");
            }
		    break;
    }
}
