#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "input.h"
#include <signal.h>
#include "type.h"

#define MAX_LINE 300

void clearInputBuffer() { // 버퍼 비우기
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

void handle_signal(int sig){ // ctrl c 입력시
	(void)sig; // unused parameter
	printf("\nThank you\n");
	exit(0);
}

intmax_t getPattern() { // 패턴 번호 입력
    char buffer[MAX_LINE + 1];
    intmax_t choice;

	signal(SIGINT, handle_signal); // ctrl c 입력 -- 시그널 SIGINT 발생 -- 함수 호출

    while (1) {
        printf("\n패턴 1 ~ 5 중 하나를 선택해주세요.\n");
		printf("패턴 1: 삼각형\n");
        printf("패턴 2: 역삼각형\n");
        printf("패턴 3: 다이아몬드\n");
        printf("패턴 4: 평행사변형\n");
        printf("패턴 5: 역피라미드\n\n");
        printf("번호를 입력해주세요 : ");

        if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
            if(feof(stdin)){
				printf("\n1~5 중 다시 입력해주세요.\n");
				clearerr(stdin);
				continue;
			}
			else{
				perror("fgets");
				exit(1);
			}
        }

		if(strlen(buffer) > MAX_LINE || buffer[strlen(buffer) - 1] != '\n'){
			printf("\n1~5 중 다시 입력해주세요.\n");
			clearInputBuffer();
			continue;
		}

        buffer[strcspn(buffer, "\n")] = '\0';

        int isValid = 1;
        for (int i = 0; buffer[i] != '\0'; ++i) {
            if (!isdigit(buffer[i])) {
                isValid = 0;
                printf("\n1~5 중 다시 입력해주세요.\n");
                break;
            }
        }

        if (!isValid) continue;

        choice = strtoll(buffer, NULL, 10);

        if (choice != pattern_triangle && choice != pattern_invert_triangle && 
				choice != pattern_diamond && choice != pattern_parallelogram && choice != pattern_invert_pyramid) {
            printf("\n1~5 중 다시 입력해주세요.\n");
            continue;
        }
        break;
    }
    return choice; // 패턴 번호 return 
}

intmax_t getLine(enum pattern_type choice) { // 라인 수 입력 -- enum
    char buffer[MAX_LINE + 1];
    intmax_t line;

    while (1) {
        printf("\nHow many lines? (1..100): ");

        if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
			if (feof(stdin)) {
				printf("\nInvalid input – Range 1..100\n");
				clearerr(stdin);
				continue;
			}
			else {
				perror("fgets");
				exit(1);
			}
		}

		if (strlen(buffer) > MAX_LINE || buffer[strlen(buffer) - 1] != '\n') {
			printf("\nInvalid input – Range 1..100\n");
			clearInputBuffer();
			continue;
		}

        buffer[strcspn(buffer, "\n")] = '\0';

        int isValid = 1;
        for (int i = 0; buffer[i] != '\0'; ++i) {
            if (!isdigit(buffer[i])) {
                isValid = 0;
                printf("\nInvalid input – Range 1..100\n");
                break;
            }
        }

        if (!isValid) continue;

        line = strtoll(buffer, NULL, 10);

        if (line < 1 || line > 100) {
            printf("\nInvalid input – Range 1..100\n");
            continue;
        }

        if (choice == pattern_diamond && line % 2 == 0) {
            printf("다이아몬드 패턴 3에서는 1~100 사이의 홀수를 입력해주세요.\n");
            continue;
        }
        break;
    }
    return line; // line 수 반환
}
