#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int n) {
    int num = 1;
    while(true){
        if(num * num == n){
            return 1;
        }else if(num * num > n){
            return 2;
        }
        num++;
    }
}