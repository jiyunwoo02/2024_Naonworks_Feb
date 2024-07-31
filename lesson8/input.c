#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "input.h"
#include <signal.h> // ctrl c 처리하기 위해 시그널 다뤄야 함. signal() 함수 정의되어 있다! [시그널과 핸들러 함수 관리]

#define MAX_LINE 300

void clearInputBuffer() { // 버퍼 비우기
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

void handle_signal(int sig){ // ctrl c 입력시 -- SIGINT 시그널에 대한 정보를 전달받는 매개변수를 포함
	(void)sig; // error 방지
	printf("\nThank you\n"); // 메시지 출력
	exit(0); // 프로그램 종료
}
// 매개변수 sig는 시그널 핸들러 함수가 호출될 때 해당 시그널에 대한 정보 전달받는다
// signal(SIGINT, handle_signal)은 이를 실제로 설정하여 프로그램이 해당 시그널 처리할 수 있도록 한다

intmax_t getPattern() { // 패턴 번호 입력
    char buffer[MAX_LINE + 1];
    intmax_t choice;

	signal(SIGINT, handle_signal); // ctrl c 입력 -- 시그널 SIGINT 발생 -- 함수 호출
	// void (*signal(int signum, void (*handler)(int)))(int); -- signal.h에 정의되어있음
	// signum: 등록하려는 시그널의 종류, handler: 해당 시그널이 발생했을 때 호출될 핸들러 함수

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

        if (choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 5) {
            printf("\n1~5 중 다시 입력해주세요.\n");
            continue;
        }
        break;
    }

    return choice; // 패턴 번호 return 
}

intmax_t getLine(intmax_t choice) { // 라인 수 입력
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

        if (choice == 3 && line % 2 == 0) { // 패턴 번호 사용 - 함수 내의 parameter로
            printf("\n패턴 3에서는 1~100 사이의 홀수를 입력해주세요.\n");
            continue;
        }
        break;
    }

    return line; // line 수 반환
}

