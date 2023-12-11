#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int ans = 1;
    int idx = 0;
    
    while(idx < n){
        if(ans % 3 == 0){ // 3의 배수
            ans++;
            continue;
        }
        if(ans < 100){ // 100 미만
            if(ans % 10 == 3 || ans / 10 == 3){
                ans++;
                continue;
            }
        }else{ // 100 이상
            if(ans % 10 == 3 || (ans - 100) / 10 == 3){
                ans++;
                continue;
            }
        }
        idx++;
        ans++;
    }
    
    return ans - 1;
}