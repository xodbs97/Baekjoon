#include <string>
#include <vector>

using namespace std;

int solution(vector<int> sides) {
    for(int i = 0; i < sides.size(); i++){
        for(int j = i + 1; j < sides.size(); j++){
            if(sides[i] < sides[j]){
                auto temp = sides[i];
                sides[i] = sides[j];
                sides[j] = temp;
            }
        }
    }
    return sides[0] >= sides[1] + sides[2] ? 2 : 1;
}