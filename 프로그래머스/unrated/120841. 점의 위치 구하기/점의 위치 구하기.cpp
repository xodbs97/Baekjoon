#include <string>
#include <vector>

using namespace std;

int solution(vector<int> dot) {
    bool x = dot[0] > 0 ? true : false;
    bool y = dot[1] > 0 ? true : false;
    if(x){
        return y ? 1 : 4;
    }else{
        return y ? 2 : 3;
    }
}