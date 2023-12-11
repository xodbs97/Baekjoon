#include <string>
#include <vector>

using namespace std;

int solution(vector<int> sides) {
    int a = sides[0] + sides[1];
    int b = sides[0] - sides[1] > 0 ? sides[0] - sides[1] : sides[1] - sides[0];
    
    return a - b - 1;
}