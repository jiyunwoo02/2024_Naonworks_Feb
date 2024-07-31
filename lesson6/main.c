#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>
#include <stdint.h>

#define MAX_LINE 300

void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

int main() {
#ifdef DEBUG_FLAG
    printf("Debug Flag Enable\n");
#endif

    intmax_t line; // 라인 수
    char buffer[MAX_LINE + 1];
    intmax_t choice; // 패턴 번호

    while (1) { // 종료되지 않도록
        // 패턴 입력 파트
        while (1) {
            printf("\n패턴 1 ~ 5 중 하나를 선택해주세요. \n");
            printf("패턴 1: 삼각형\n");
            printf("패턴 2: 역삼각형\n");
            printf("패턴 3: 다이아몬드\n");
            printf("패턴 4: 평행사변형\n");
            printf("패턴 5: 역피라미드\n\n");
            // printf(">> 종료하려면 'q'를 입력해주세요.\n\n");
            printf("번호를 입력해주세요 : ");

            if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
                if (feof(stdin)) {
                    printf("\n1~5 중 다시 입력해주세요.\n");
                    clearerr(stdin);
                    continue;
                }
                else {
                    perror("fgets");
                    exit(1);
                }
            }

            if (strlen(buffer) > MAX_LINE || buffer[strlen(buffer) - 1] != '\n') {
                printf("\n1~5 중 다시 입력해주세요.\n");
                clearInputBuffer();
                continue;
            }

            buffer[strcspn(buffer, "\n")] = '\0';

            // 프로그램 종료
            /* if (strcmp(buffer, "q") == 0) {
                printf("\n프로그램을 종료합니다.\n");
                return 0;
            }*/

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

        // line 입력 파트
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

            if (choice == 3 && line % 2 == 0) { // 패턴3 -- line 짝수 입력시
                printf("\n패턴 3에서는 1~100 사이의 홀수를 입력해주세요.\n");
                continue;
            }
            break;
        }

        // 패턴 출력 파트
        switch (choice) {
        case 1: // Pattern 1
            for (intmax_t i = 1; i <= line; i++) {
                for (intmax_t j = 0; j < i; j++) {
                    printf("*");
                }
                printf("\n");
            }
            break;

        case 2: // Pattern 2
            for (intmax_t i = line; i >= 1; --i) {
                for (intmax_t j = 0; j < i; ++j) {
                    printf("*");
                }
                printf("\n");
            }
            break;

        case 3: // Pattern 3
            for (intmax_t i = 0; i < line; i++) {
                if (i <= line / 2) {  // top half
                    for (intmax_t j = line / 2; j > i; j--) {
                        printf(" ");
                    }
                    for (intmax_t k = 0; k <= i * 2; k++) {
                        printf("*");
                    }
                    printf("\n");
                }
                else { // bottom half
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

        case 4: // Pattern 4
			for (intmax_t i = 0; i < line; i++){
				for (intmax_t j = 0; j < line - i - 1; j++){
					printf(" ");
				}
				for (intmax_t k = 0; k < line; k++){
					printf("*");
				}
				printf("\n");
			}	
            break;

        case 5: // Pattern 5
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
        }
    }

    return 0;
}
