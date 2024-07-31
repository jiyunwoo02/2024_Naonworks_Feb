#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include "../../lib/inc/run.h"


void signal_callback_handler(int signum){
    printf("\nThank You\n");
    exit(signum);
}
int main()
{
    signal(SIGINT, signal_callback_handler);
    while (true)
    {
        enum TYPE type = inputCheckType();
        if(type == DIA){ printf("How many lines? (1..100) - Press Odd Number : ");}
        else{printf("How many lines? (1..100) ");}

        switch (type)
        {
            case TRI:
                printTriangle(inputCheckNum(type));
                break;

            case REVERSE_TRI:
                printReverseTriangle(inputCheckNum(type));
                break;

            case DIA:
                printDiamond(inputCheckNum(type));
                break;

            case RIGHT_ALIGNED_SQUARE:
                printRightAlignedSquare(inputCheckNum(type));
                break;
            case RIGHT_ALIGNED_INV_TRI:
                printRightAlignedInvertedTriangle(inputCheckNum(type));
                break;
            case ASC:
                printAscendingTriangle(inputCheckNum(type));
                break;

            case STEPWISE:
                printStepWiseTriangle(inputCheckNum(type));
                break;
            case RANDOM_ASC:
                printRandomAscendingTrinangle(inputCheckNum(type));
                break;
        };
        printf("\nSuccess\n");
    }
    return 0;
}
