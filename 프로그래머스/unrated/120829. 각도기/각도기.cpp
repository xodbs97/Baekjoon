#include <string>
#include <vector>

using namespace std;

int solution(int angle) {
    int answer = (angle >90)?((angle == 180)?4:3):((angle==90)?2:1);
    return answer;
}