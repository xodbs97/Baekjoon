#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> strlist) {
    vector<int> answer(strlist.size());
    int i = 0;
    for(string str : strlist){
        answer[i] = str.length();
        ++i;
    }
    return answer;
}