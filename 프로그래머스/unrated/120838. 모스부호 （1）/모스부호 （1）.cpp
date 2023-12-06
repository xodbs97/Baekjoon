#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string letter) {
    string answer = "";
    vector<string> m = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
    
	while (letter.find(" ") != string::npos) {
		answer += 'a' + static_cast<char>(find(m.begin(), m.end(), letter.substr(0, letter.find(" "))) - m.begin());
		letter.erase(0, letter.find(" ") + 1);
	}
	answer += 'a' + static_cast<char>(find(m.begin(), m.end(), letter) - m.begin());

    return answer;
}