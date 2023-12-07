#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = n;
    vector<int> pn = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 93, 97};
    for(int i : pn){
        answer--;
        if(i > n){
            break;
        }
    }
    
    return answer;
}