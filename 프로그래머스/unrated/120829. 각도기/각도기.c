#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int angle) {
    int answer = 0;
    answer = (angle >90)?((angle == 180)?4:3):((angle==90)?2:1);
    return answer;
}