#include <string>
#include <vector>

using namespace std;

string solution(string my_string, string overwrite_string, int s) {
    string answer = "";
    string s1 = my_string.substr(0, s);
    string s2 = my_string.substr(s + overwrite_string.length());
    answer = s1 + overwrite_string + s2;
    return answer;
}