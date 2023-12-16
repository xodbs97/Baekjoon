#include <string>
#include <vector>

using namespace std;

int solution(int a, int b) {
    int answer = 0;
    int t = b, m = 1;
    while(t){
        t /= 10;
        m *= 10;
    }
    return a * m + b > 2 * a * b ? a * m + b : 2 * a * b;
}