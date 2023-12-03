#include <string>
#include <vector>

using namespace std;

int solution(vector<int> common) {
    // 등차, 등비 판별 후 각각의 경우에 대한 다음 값 반환
    if(common[2] - common[1] == common[1] - common[0]){
        return common.back() + common[1] - common[0];
    }else{
        return common.back() * (common[1] / common[0]);
    }
}