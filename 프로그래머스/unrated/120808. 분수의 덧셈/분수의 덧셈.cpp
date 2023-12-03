#include <string>
#include <vector>

using namespace std;

vector<int> solution(int numer1, int denom1, int numer2, int denom2) {
    vector<int> answer(2);
    answer[0] = numer1 * denom2 + numer2 * denom1;
    answer[1] = denom1 * denom2;
    
    int gcf = 0;
    int a = 0;
    int b = 0;
    if(answer[0] > answer[1]){
        a = answer[0];
        b = answer[1];
    }else{
        a = answer[1];
        b = answer[0];
    }
    
    while(true){
        if(a % b == 0){
            gcf = b;
            break;
        }else{
            int temp = a % b;
            a = b;
            b = temp;
        }   
    }

    answer[0] = answer[0] / gcf;
    answer[1] = answer[1] / gcf;
    return answer;
}