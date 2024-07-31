#include "../../lib/inc/run.h"
#include <stdio.h>
#include <stdbool.h>

#define TYPE_SIZE 8

void error()
{
    printf("Invalid input – Range 1..100\n\n");
    printf("How many lines? (1..100) : ");
}

void error_diamond()
{
    printf("Invalid input – Please Odd  Number\n\n");
    printf("How many lines? (1..100) - Press Odd Number :  ");
}


void printInputTypeNumberFormat(){
    printf("Press Number (1...%d)\n", TYPE_SIZE);
    printf("(1 : TRI 2 : R_TRI 3 : DIA 4 : RightAlignedSquare 5 : RightAlignedReverse 6 : Asc 7 : Stepwise 8 : RandomAsc)\n");
    printf("End key is (ctr + c)\nInput >>  ");
}



void error_input_type()
{
    printf("Invalid input - Choose (1~%d) \n\n", TYPE_SIZE);
    printInputTypeNumberFormat();
}


int inputCheckType()
{

    int counter = 0;
    int result = 0;
    bool wrongCase = false;
    bool postIsBlank = false;   // 숫자 사이에 blank가 온 경우를 확인하기 위한 flag
    bool isNumberStart = false; // 숫자가 시작된 시점을 알기 위한 flag

    printInputTypeNumberFormat();

    while (1)
    {
        char ch = getchar();

        if (ch == ' ' || ch=='\t') // 공백인 경우 (만약 허용한다면) 앞 뒤 공백 다 무시하고 바로 넘어가면서 진행
        {
            postIsBlank = true;
            continue;
        }

       

        if (ch == EOF) // eof checking eof는 예외 케이스여서 따로 먼저 처리를 해줬습니다.
        {
            printf("\n");
            error_input_type();
            result = 0;
            counter = 0;
            wrongCase = false;
            //isZeroStarter = false;
            isNumberStart = false;
            postIsBlank = false;
            clearerr(stdin);
            continue;
        }

        if ((ch >= '0' && ch <= '0'+TYPE_SIZE))
        {   
            if (isNumberStart && postIsBlank)
                wrongCase = true;
            if (!wrongCase)
            {
                if (!isNumberStart && ch == '0')
                {
                    isNumberStart = true;
                    postIsBlank = false;
                    continue;
                }
                if (result == 0 && ch != '0')
                {
                    isNumberStart = true;
                }
                result = result * 10 + (ch - '0');
                postIsBlank = false;
                counter++;
            }
            continue;
        }
        else if (result < 1 || result > TYPE_SIZE)
        { // 결과가 1, TYPE_SIZE 사이가 아닌 경우
            wrongCase = true;
        }
        else if (ch != '\n')
        { // 숫자, enter 및 다른 것들이 문자들이 오는 경우 확인
            wrongCase = true;
        }
        if(ch=='\n'){
            if (!wrongCase) // 잘못된 case가 없었고 정상적으로 입력된 enter면 이후 과정 진행
            {
                break;
            }
            else if (wrongCase)
            { // 잘못된 입력의 case
                error_input_type();
                result = 0;
                counter = 0;
                wrongCase = false;
                isNumberStart = false;
                postIsBlank = false;
            }
        }
    }

    return result;
}

int inputCheckNum(enum TYPE typeNumber)
{   
    int counter=0;
    int result=0;
    bool wrongCase = false;
    bool postIsBlank = false;   // 숫자 사이에 blank가 온 경우를 확인하기 위한 flag
    bool isNumberStart = false; // 숫자가 시작된 시점을 알기 위한 flag
    char ch;
    while (1)
    {
        ch = getchar();

        if (ch == ' ' || ch == '\t') // 공백인 경우 (만약 허용한다면) 앞 뒤 공백 다 무시하고 바로 넘어가면서 진행
        {
            postIsBlank = true;
            continue;
        }

        if (ch == EOF) // eof checking eof는 예외 케이스여서 따로 먼저 처리를 해줬습니다.
        {
            printf("\n");    
            if(typeNumber==DIA){
                error_diamond();
            }
            else{
                error();
            }
            result = 0;
            counter = 0;
            wrongCase = false;
            isNumberStart = false;
            postIsBlank = false;
            clearerr(stdin);
            continue;
        }

        if ((ch >= '0' && ch <= '9'))
        {
            if (isNumberStart && postIsBlank)
            {
                wrongCase = true;
            }
        
            if (!wrongCase)
            {
                if (ch == '0')
                {
                    isNumberStart = true;
                    result = result * 10 + (ch - '0');
                    postIsBlank = false;
                    continue;
                }
                if (result == 0 && ch != '0')
                {
                    isNumberStart = true;
                }
                result = result * 10 + (ch - '0');
                postIsBlank = false;
                counter++;
            }
            continue;
        }

        if (!wrongCase)
        {
            if (counter > 3)
            { // 세자리 숫자 이상 되는 경우
                wrongCase = true;
            }
            else if (result > 100 || result == 0)
            { // result 0 인 경우 only 공백 100 이상이 될 경우 확인
                wrongCase = true;
            }
            else if (ch != '\n')
            {
                wrongCase = true;
            }
        }

        if (ch == '\n' && !wrongCase) // 잘못된 case가 없었고 정상적으로 입력된 enter면 이후 과정 진행
        {
            if (typeNumber == DIA && result % 2 == 0) // 다이아몬드인데 짝수인 경우
            {
                error_diamond();
                result = 0;
                counter = 0;
                wrongCase = false;
                isNumberStart = false;
                postIsBlank = false;
                continue;
            }
            break;
        }
        else if (ch == '\n' && wrongCase)
        {                        // 잘못된 입력의 case 시 재시작을 위한 초기화
            if (typeNumber == DIA) // 다이아인 경우는 따로 출력!
            {
                error_diamond();
            }
            else
            {
                error();
            }
            result = 0;
            counter = 0;
            postIsBlank = false;
            wrongCase = false;
            isNumberStart = false;
        }
    }

    return result;
}
