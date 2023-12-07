#include <string>
#include <vector>

using namespace std;

int fac(int i){
    if(i > 1){
        return i * fac(i - 1);
    }else{
        return 1;
    }
}

int solution(int n) {
    int answer = 1;
    while(fac(answer) <= n){
        answer++;
    }
    return answer - 1;
}