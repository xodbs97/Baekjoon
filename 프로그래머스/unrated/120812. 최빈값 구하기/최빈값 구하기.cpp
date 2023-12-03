#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> array) {
    int answer = 0;
    vector<int> num;
    vector<int> cnt;
    for(int i : array){
        // 맨 처음에는 바로 삽입
        if(num.size() == 0){
            num.push_back(i);
            cnt.push_back(1);
        }else{
            auto idx = find(num.begin(), num.end(), i);
            // num에 존재하지 않을 시 새로운 값이므로 삽입
            if(idx == num.end()){
                num.push_back(i);
                cnt.push_back(1);
            }else{
                cnt[idx - num.begin()]++;
            }
        }
    }
    // cnt에서 최빈값의 idx 찾고 num[idx] 반환 && 최빈값을 가지는 수의 종류가 2개 이상일 경우 -1 반환
    int max = 0;
    int max_idx = 0;
    int max_cnt = 0;
    for(int i = 0; i < cnt.size(); i++){
        if(cnt[i] > max){
            max = cnt[i];
            max_idx = i;
            answer = num[max_idx];
        }
    }
    for(int i : cnt){
        if(i == max){
            ++max_cnt;
        }
    }
    if(max_cnt > 1){
        return -1;
    }else{
        return answer;
    }
}