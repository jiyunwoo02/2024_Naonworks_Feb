#include <stdio.h> // 입출력 관련 함수
#include <stdlib.h> // 일반 유틸리티 함수
#include <string.h> // 문자열 처리 함수
#include <ctype.h> // 문자 형태 판단 함수
#include <limits.h> // 정수 자료형의 최댓값 및 최솟값을 정의
#include <stdint.h> // 정수 자료형을 표준화된 크기로 정의하기 위한 헤더

#define MAX_LINE 300 // 300자 이상 입력 시 오류 처리, 입력 버퍼 최대길이 300

void clearInputBuffer() { // 입력 버퍼 비우기: 입력 버퍼에 남아있는 모든 문자들을 읽어들여 처리하지 않고 버리는 역할
    int c;

    while ((c = getchar()) != '\n' && c != EOF) {}
    // getchar() 함수를 사용하여 입력 버퍼에서 문자를 하나씩 읽어들이면서, --> 읽어들인 문자는 c 변수에 저장
    // 개행 문자('\n')가 나오고, 파일의 끝(EOF)에 도달할 때까지 반복문이 실행
    // 반복문이 실행되는 동안 입력 버퍼에 있는 문자들은 무시되고 넘어가게 되므로, 입력 버퍼를 비우는 효과
}

int main() {
    intmax_t line; // int의 범위를 초과할 수 있는 intmax_t으로 변경!, 사용자가 입력할 라인 수
    char buffer[MAX_LINE + 1]; // 입력 버퍼 크기를 최대 길이 + 1로 설정, +1은 널문자 고려
    int validInput = 0; // 입력이 유효한가

    while (!validInput) { // while(1) 무한 루프
        printf("How many lines? (1..100) ");

        // 사용자로부터 입력 받기
        // ctrl d 처리 - EOF - NULL
        if (fgets(buffer, sizeof(buffer), stdin) == NULL) { // 표준입력에서 최대 사이즈만큼 문자 읽어와서 버퍼에 저장
            // 실패하면 [사용자 입력 없거나 오류 발생] 이면 null
            if (feof(stdin)) { // true, 파일의 끝 검사, 표준입력스트림 stdin이 파일 끝에 도달했는지 여부 확인
                printf("\nInvalid input – Range 1..100\n");
                clearerr(stdin); // 입력 버퍼의 오류 플래그를 지움
                // *플래그: 프로그램 동작 제어하거나 상태 나타내는 변수, 입출력스츠림-EOF,오류 플래그
                // stdin에서 이런 플래그 설정해 입출력 동작 상태 추적, 처리 수행

                // stdin의 eof 플래그와 에러 플래그 모두 초기화, 사용자가 ctrl d 입력하면 fgets는 null 반환-eof 플래그 설정
                // 이를 지우기 위해 사용 - 다시 입력 요구하게
                continue; // while문 처음으로 돌아감, 입력 다시 요구
            }
            else { // false 반환 경우
                perror("fgets"); // fgets와 관련된 에러 메시지 출력, stderr 스트림에 오류 메시지 출력 - 디버깅 유용
                exit(1); // 비정상 종료
            }
        }
        // 추가 설명
        // 사용자가 ctrl d 입력하면 - stdin에서 EOF 의미하는 특수 문자 입력됨 - fgets가 인식 - fgets는 eof 만나면 null 반환
        // fgets가 null 반환하는 경우 -> 사용자가 입력 종료(ctrl d) or 파일 끝 도달 (실행)
        // feof(stdin) 함수 사용: 파일 끝 도달하면 true(1) 반환
        // true 반환하면 - 사용자가 ctrl d 입력해 입력 종료했음 - 메시지 출력..

        // 300자 이상 입력 시 오류
        // 1) MAX 넘어가면 오류 출력 -> 버퍼 비우고 -> 다시 질문
        // 2) 마지막 입력 문자가 개행 문자인가 - 사용자는 마지막으로 엔터 입력 - 엔터 안 누른 거면 입력 완료X -> (동일)
        if (strlen(buffer) > MAX_LINE || buffer[strlen(buffer) - 1] != '\n') {
            printf("Invalid input – Range 1..100\n");
            clearInputBuffer();
            continue;
        }

        // 버퍼에 개행 문자 제거
        // 사용자가 입력한 엔터: 버퍼에 남아있음 -> 개행 찾아 null로 대체, 문자열 끝으로 나타낸다
        buffer[strcspn(buffer, "\n")] = '\0';

        // 입력 문자열이 숫자로만 이루어져 있는가
        int isValid = 1;
        for (int i = 0; buffer[i] != '\0'; ++i) { // 문자열 끝까지
            if (!isdigit(buffer[i])) { // 숫자가 아니라면?
                isValid = 0;
                printf("Invalid input – Range 1..100\n");
                break;
            }
        }

        if (!isValid) continue; // 입력 유효 X면 다시 입력 요구

        // 문자열 -> intmax_t로 변환
        line = strtoll(buffer, NULL, 10);

        // 입력 값이 유효범위(1-100)를 초과하는지 확인
        if (line < 1 || line > 100) {
            printf("Invalid input – Range 1..100\n");
            continue; // 입력 다시 요구
        }

        validInput = 1; // 입력 유효하다 --> 반복문 종료
    }

    // 별 정상 출력
    for (intmax_t i = 1; i <= line; i++) {
        for (intmax_t j = 0; j < i; j++) {
            printf("*");
        }
        printf("\n");
    }

    return 0;
}
