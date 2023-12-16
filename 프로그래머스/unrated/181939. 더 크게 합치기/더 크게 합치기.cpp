#include <string>
#include <vector>

using namespace std;

int solution(int a, int b) {
    int answer = 0;
    int t1 = a, t2 = b, i1 = 1, i2 = 1;
    while(t1){
        t1 /= 10;
        i1 *= 10;
    }
        while(t2){
        t2 /= 10;
        i2 *= 10;
    }
    
    return a * i2 + b > b * i1 + a ? a * i2 + b : b * i1 + a;
}