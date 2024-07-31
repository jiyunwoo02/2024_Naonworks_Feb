#include <stdio.h>

int main() {
    for(int i =1; i<=5;i++){ // 세로
        for(int j=1;j<=5;j++){ // 가로
            if(j<=i){
                printf("*");
            }
        }
        printf("\n");
    }
return 0;
}
