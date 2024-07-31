#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "input.h" // 헤더파일
// #include "input.h" --> input.h에서 가드 심볼을 사용하여 오류 발생 X
// 가드 심볼을 사용해 헤더 파일이 이미 include되어 있는지 확인
// 포함되어 있지 않았다면 헤더 파일 include
// 같은 헤더 파일을 여러 번 포함해도 컴파일러가 한 번만 처리한다!

// 하지만 C 컴파일러 대부분은 헤더 파일 여러 번 포함해도 오류 발생 X
// why? 컴파일러가 헤더 파일 처리 여부 추적하고 있다

#define MAX_LINE 300

void clearInputBuffer() { // 버퍼 비우기
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

intmax_t getPattern() { // 패턴 번호 입력
    char buffer[MAX_LINE + 1];
    intmax_t choice;

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

