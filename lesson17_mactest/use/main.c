#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <ctype.h>
#include <signal.h>
#include <stdint.h>
#include <string.h>

#include "../lib/draft3_run.h"

void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}
void handle_signal(int sig) {
    (void)sig;
    printf("\nThank you");
    exit(0);
}
void printInvalidMessage() {
    printf("\nInvalid input – Range 1..100\n");
}
void printChoiceMessage() {
    printf("\n1~8 중 재입력\n");
}
intmax_t getPattern() {
    char buffer[100];
    intmax_t pattern_number;
    signal(SIGINT, handle_signal);
    while (1) {
        printf("1~8 중 선택\n패턴 1:삼각형\n패턴 2:역삼각형\n패턴 3:다이아몬드\n패턴 4:평행사변형\n패턴 5:역피라미드\n패턴 6:세로삼각형\n패턴 7:가로삼각형\n패턴 8:랜덤\n패턴 타입을 입력하세요: ");
        if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
            if (feof(stdin)) {
                printChoiceMessage();
                clearerr(stdin);
                continue;
            }
            else {
                perror("fgets");
                exit(1);
            }
        }
        if (strlen(buffer) > 100 || buffer[strlen(buffer) - 1] != '\n') {
            printChoiceMessage();
            clearInputBuffer();
            continue;
        }
        buffer[strcspn(buffer, "\n")] = '\0';
        int isValid = 1;
        for (int i = 0; buffer[i] != '\0'; ++i) {
            if (!isdigit(buffer[i])) {
                isValid = 0;
                printChoiceMessage();
                break;
            }
        }
        if (!isValid) continue;
        pattern_number = strtoll(buffer, NULL, 10);
        if (pattern_number != TRI && pattern_number != REVERSE_TRI &&
            pattern_number != DIA && pattern_number != RIGHT_ALIGNED_SQUARE &&
            pattern_number != RIGHT_ALIGNED_INV_TRI && pattern_number != ASC &&
            pattern_number != STEPWISE && pattern_number != RANDOM_ASC) {
            printChoiceMessage();
            continue;
        }
        break;
    }
    return pattern_number;
}
intmax_t getLine(enum TYPE pattern_number) {
    char buffer[100];
    intmax_t line_number;
    while (1) {
        printf("라인 수를 입력하세요: ");
        if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
            if (feof(stdin)) {
                printInvalidMessage();
                clearerr(stdin);
                continue;
            }
            else {
                perror("fgets");
                exit(1);
            }
        }
        if (strlen(buffer) > 100 || buffer[strlen(buffer) - 1] != '\n') {
            printInvalidMessage();
            clearInputBuffer();
            continue;
        }
        buffer[strcspn(buffer, "\n")] = '\0';
        int isValid = 1;
        for (int i = 0; buffer[i] != '\0'; ++i) {
            if (!isdigit(buffer[i])) {
                isValid = 0;
                printInvalidMessage();
                break;
            }
        }
        if (!isValid) continue;
        line_number = strtoll(buffer, NULL, 10);
        if (line_number < 1 || line_number > 100) {
            printInvalidMessage();
            continue;
        }
        if (pattern_number == DIA && line_number % 2 == 0) {
            printf("1~100 홀수 입력\n");
            continue;
        }
        break;
    }
    return line_number;
}

int main() {
#ifdef DEBUG_FLAG
    printf("Debug Flag Enable");
#endif
    enum TYPE pattern_number;
    intmax_t line_number;

    while (1) {
        pattern_number = getPattern();
        line_number = getLine(pattern_number);
        printStars(pattern_number, line_number); // 라이브러리의 함수 사용
    }
    return 0;
}
