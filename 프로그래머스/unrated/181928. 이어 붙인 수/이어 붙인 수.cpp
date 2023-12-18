#include <string>
#include <vector>

using namespace std;

int solution(vector<int> num_list) {
    int odd = 0, even = 0;
    
    for(int i : num_list){
        if(i % 2 != 0){
            odd *= 10;
            odd += i;
            continue;
        }
        even *= 10;
        even += i;
    }
    
    return odd + even;
}