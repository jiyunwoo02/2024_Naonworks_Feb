#include "../inc/draft3_run.h"
#include <stdbool.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// 현재 나오려는 순서에 중복된 값이 나오는지 검증하기 위한 배열
short remind[105]; // 이전 랜덤 순서가 어떻게 진행됬었는지 검증하는 배열
short postInputNum; // 이전 입력값이 동일하게 나오게 되었는지 -> 해당 경우는 지속
short seq[105];
int arr_sizeX, arr_sizeY;
void printRandomAscendingTrinangle(int n);
void printStepWiseTriangle(int n);
void printAscendingTriangle(int n);
void printTriangle(int n);
void printReverseTriangle(int n);
void printDiamond(int n);
void printRightAlignedSquare(int n);
void printRightAlignedInvertedTriangle(int n);



void printStars(enum TYPE pattern, int line_number){

    switch (pattern)
    {
        case TRI:
            printTriangle(line_number);
            break;

        case REVERSE_TRI:
            printReverseTriangle(line_number);
            break;

        case DIA:
            if(line_number %2 ==1)
                printDiamond(line_number);
            else
                printf("Error : diamond pattern cannot accept even number inputs.\n");    
            break;

        case RIGHT_ALIGNED_SQUARE:
            printRightAlignedSquare(line_number);
            break;
        case RIGHT_ALIGNED_INV_TRI:
            printRightAlignedInvertedTriangle(line_number);
            break;
        case ASC:
            printAscendingTriangle(line_number);
            break;

        case STEPWISE:
            printStepWiseTriangle(line_number);
            break;
        case RANDOM_ASC:
            printRandomAscendingTrinangle(line_number);
            break;
    };
}








void initSeq() {
    for (int i = 0; i < 105; i++)
        seq[i] = 0;
}
// 아이디어 현재 코드에서 내가 볼 때는 음... print 함수들 합쳐서 처리? 하는거 말고는 막 임팩트있게 어떻게 줄여야 할 지 감이 안옴. 내일 보고 더 생각해야함. 1.18
bool dupChk(int randomNum, int nowIndex, int max) {
    for (int i = 0; i < nowIndex; i++) {
        if (seq[i] == randomNum)
            return true;
    }
    return false;
}
bool isWrongSeq(int n, bool superPass) {
    bool isNotSame=false;
    for (int i = 0; i < n; i++) {
        while (true) {
            int randomNum = 1 + rand() % n;
            if (dupChk(randomNum, i, n)) {
                continue;
            }
            seq[i] = randomNum;
            if (superPass) {
                isNotSame = true;
                break;
            }
            if (!isNotSame && remind[i] != 0 && seq[i] != remind[i]) {
                isNotSame = true;
            }
            break;
        }
    }

    return !isNotSame && !superPass;
}

void printRandomAscendingTrinangle(int n) {

    bool superPass = false; // 이전 입력값과 다르기때문에 숫자 배열 관련해서만 검증하면 됨.
    if (postInputNum != n) {
        superPass = true;
    }
    bool success = false;
    do {
        initSeq();
        srand(time(NULL));
        if(n!=1 && isWrongSeq(n, superPass)){
            continue;
        }
        else if(n==1){
            seq[0]=1;
        }
        for (int i = 0; i < n; i++) {
            printTriangle(seq[i]);
            remind[i] = seq[i];
            printf("\n");
        }
        success = true;
        postInputNum = n;
    } while (!success);
}

void printStepWiseTriangle(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            for (int k = 0; k <= n; k++) {
                printf(" ");
            }
        }
        for (int j = i; j < n; j++) {
            for (int k = 0; k <= i; k++) {
                printf("*");
            }
            for (int k = i; k < n; k++) {
                printf(" ");
            }
        }
        printf("\n");
    }
}

void printAscendingTriangle(int n) {

    for (int i = 1; i <= n; i++) {
        printTriangle(i);
        if (i == n) {
            continue;
        }
        printf("\n");
    }
}

void printTriangle(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            printf("*");
        }
        printf("\n");
    }
}

void printReverseTriangle(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i; j++) {
            printf("*");
        }
        printf("\n");
    }
}

void printDiamond(int n) {
    for (int i = 0; i < n / 2 + 1; i++) {
        for (int j = i; j < n / 2; j++) {
            printf(" ");
        }

        for (int j = 0; j < 2 * i + 1; j++) {
            printf("*");
        }
        printf("\n");
    }

    for (int i = n / 2 - 1; i >= 0; i--) {
        for (int j = 0; j < n / 2 - i; j++) {
            printf(" ");
        }
        for (int j = 0; j < 2 * i + 1; j++) {
            printf("*");
        }
        printf("\n");
    }
}

void printRightAlignedSquare(int n) {

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            printf(" ");
        }
        for (int j = 0; j < n; j++) {
            printf("*");
        }
        printf("\n");
    }
}

void printRightAlignedInvertedTriangle(int n) {

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            printf(" ");
        }
        for (int j = 0; j < n - i; j++) {
            printf("*");
        }
        printf("\n");
    }
}

