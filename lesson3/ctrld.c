#include <stdio.h>
#include <stdlib.h>

int main() {
    char buffer[100];
    int validInput = 0;

    while (!validInput) {
        printf("How many lines? (1..100) ");

        if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
            if (feof(stdin)) {
                printf("\nInvalid input – Range 1..100\n");
                clearerr(stdin); // 오류 플래그를 지움
            }
            else {
                perror("fgets");
                exit(1);
            }
        }
        else {
            validInput = 1;
        }
    }

    // 유효한 입력 처리
    int lines = atoi(buffer);
    printf("입력된 라인 수: %d\n", lines);

    return 0;
}
