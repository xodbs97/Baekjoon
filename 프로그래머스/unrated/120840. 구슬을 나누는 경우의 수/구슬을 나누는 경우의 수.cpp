#include <string>
#include <vector>

using namespace std;

int solution(int balls, int share) {
    long long answer = 1;
    
    int n = balls;
    int m = balls - share;
    int k = share;
    if(m > k){
        int t = m;
        m = k;
        k = t;
    }
    
    while(n > k || m > 1){
        if(n > k){
            answer *= n--;
        }
        if(m > 1 && answer % m == 0){
            answer /= m--;
        }
    }
    
    return (int)answer;
}