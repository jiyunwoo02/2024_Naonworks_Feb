#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <signal.h>
#include <stdint.h>
#include <string.h>
#include "input.h"
#include "../lib/inc/type.h"

void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}
void handle_signal(int sig){
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
    intmax_t choice;
    signal(SIGINT, handle_signal);
    while (1) {
        printf("1~8 중 선택\n패턴 1:삼각형\n패턴 2:역삼각형\n패턴 3:다이아몬드\n패턴 4:평행사변형\n패턴 5:역피라미드\n패턴 6:세로삼각형\n패턴 7:가로삼각형\n패턴 8:랜덤\n번호 입력: ");
        if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
            if(feof(stdin)){
                printChoiceMessage();
				clearerr(stdin);
				continue;
			}
			else{
				perror("fgets");
				exit(1);
			}
        }
		if(strlen(buffer) > 100 || buffer[strlen(buffer) - 1] != '\n'){
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
        choice = strtoll(buffer, NULL, 10);
        if (choice != pattern_triangle && choice != pattern_inv_triangle && 
				choice != pattern_diamond && choice != pattern_parallelogram &&
				choice != pattern_inv_pyramid && choice != pattern_he_triangle && 
				choice != pattern_le_triangle && choice != pattern_random_op) {
            printChoiceMessage();
            continue;
        }
        break;
    }
    return choice;
}
intmax_t getLine(enum pattern_type choice) {
    char buffer[100];
    intmax_t line;
    while (1) {
        printf("How many lines? (1..100) ");
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
        line = strtoll(buffer, NULL, 10);
        if (line < 1 || line > 100) {
            printInvalidMessage();
            continue;
        }
        if (choice == pattern_diamond && line % 2 == 0) {
            printf("1~100 홀수 입력\n");
            continue;
        }
        break;
    }
    return line;
}
