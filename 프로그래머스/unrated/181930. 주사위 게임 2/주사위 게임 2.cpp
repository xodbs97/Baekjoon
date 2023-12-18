#include <string>
#include <vector>

using namespace std;

int solution(int a, int b, int c) {
    if(a == b){
        if(b == c){
            return (a + b + c) * (a * a + b * b + c * c) * (a * a * a + b * b * b + c * c * c);
        }
        return (a + b + c) * (a * a + b * b + c * c);
    }
    if(b == c || a == c){
        return (a + b + c) * (a * a + b * b + c * c);
    }
    return a + b + c;
}