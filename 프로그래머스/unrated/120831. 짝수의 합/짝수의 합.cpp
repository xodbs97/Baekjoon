#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    answer = (n % 2 == 0)?(n*n/4 + n/2):((n*n-1)/4);
    return answer;
}