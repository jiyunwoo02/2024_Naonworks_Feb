#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdint.h>
#include "../inc/run.h"
#include "../inc/type.h"

#define STAR "*"
#define SPACE " "
#define NEWLINE "\n"

int samePattern(intmax_t arr1[], intmax_t arr2[], intmax_t size) {
    for (intmax_t i = 0; i < size; i++) if (arr1[i] != arr2[i]) return 0;
    return 1;
}
void printStar(intmax_t num) {
    for (intmax_t i = 0; i < num; ++i) {
        printf(STAR);
    }
}
void printSpace(intmax_t num) {
    for (intmax_t i = 0; i < num; ++i) {
        printf(SPACE);
    }
}
void runPattern(enum pattern_type choice, intmax_t line) {
    switch (choice) {
    case pattern_triangle:
        for (intmax_t i = 1; i <= line; i++) {
            printStar(i);
            printf(NEWLINE);
        }
        break;
    case pattern_inv_triangle:
        for (intmax_t i = line; i >= 1; --i) {
            printStar(i);
            printf(NEWLINE);
        }
        break;
    case pattern_diamond:
        for (intmax_t i = 0; i < line; i++) {
            if (i <= line / 2) {
                printSpace(line / 2 - i);
                printStar(i * 2 + 1);
                printf(NEWLINE);
            }
            else {
                printSpace(i - line / 2);
                printStar((line - i) * 2 - 1);
                printf(NEWLINE);
            }
        }
        break;
    case pattern_parallelogram:
        for (intmax_t i = 0; i < line; i++) {
            printSpace(line - i - 1);
            printStar(line);
            printf(NEWLINE);
        }
        break;
    case pattern_inv_pyramid:
        for (intmax_t i = line; i >= 1; i--) {
            printSpace(i - 1);
            printStar(i);
            printf(NEWLINE);
        }
        break;
    case pattern_he_triangle:
        for (intmax_t h = 1; h <= line; h++) {
            for (intmax_t i = 1; i <= h; i++) {
                printStar(i);
                printf(NEWLINE);
            }
            printf(NEWLINE);
        }
        break;
    case pattern_le_triangle:
        for (intmax_t h = 0; h < line; h++) {
            printSpace(0.5 * h * (h + 5));
            for (intmax_t j = 0; j < line - h; j++) {
                printStar(h + 1);
                printSpace(j + 2);
            }
            printf(NEWLINE);
        }
        break;
    case pattern_random_op:
        intmax_t h_val[100], res[100], last_res[100], tmp[100];
        for (intmax_t h = 1; h <= line; h++) h_val[h - 1] = h;
        srand(time(NULL));
        while (1) {
            for (intmax_t i = line - 1; i > 0; i--) {
                intmax_t j = rand() % (i + 1);
                intmax_t cmp = h_val[i];
                h_val[i] = h_val[j];
                h_val[j] = cmp;
            }
            for (intmax_t i = 0; i < line; i++) {
                tmp[i] = res[i];
                res[i] = h_val[i];
                last_res[i] = tmp[i];
            }
            if (samePattern(last_res, res, line) == 1) continue;
            else break;
        }
        for (intmax_t i = 0; i < line; i++) {
            intmax_t res_index = res[i];
            for (intmax_t j = 1; j <= res_index; j++) {
                printStar(j);
                printf(NEWLINE);
            }
            printf(NEWLINE);
        }
        break;
    }
}
