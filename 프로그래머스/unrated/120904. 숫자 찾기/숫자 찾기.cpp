#include <string>
#include <vector>

using namespace std;

int solution(int num, int k) {
    int answer = -1;
    int size = 0;
    int idx = 0;
    while(num){
        if(num % 10 == k){
            answer = idx;
        }
        num /= 10;
        idx++;
        size++;
    }
    return answer == -1 ? answer : size - answer;
}